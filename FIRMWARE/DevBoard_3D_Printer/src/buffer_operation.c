/*
 * buffer_operation.c
 *
 *  Created on: 2014. 4. 8.
 *      Author: dimo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <alt_types.h>
#include <io.h>
#include <math.h>
#include <altera_avalon_mutex.h>
#include "system.h"
#include "sys/alt_irq.h"
#include "../inc/configure.h"
#include "../inc/DevBoard_3D_CNC.h"
#include "../inc/gcode_command.h"
#include "../inc/buffer_operation.h"

struct buffer_unknown_command {
	alt_u8	Command_Type; // Must be 'G'
	alt_u16 Command_Number;
};

struct buffer_g1_command {
	alt_u8	Command_Type; // Must be 'G'
	alt_u16 Command_Number;
	alt_u8  AxisType; // 0 = 고정 좌표, 1 = 가변 좌표
	double DataX;
	double DataY;
	double DataZ;
	double DataE;
	double FeedRate;
	alt_u8 SelectTool;
};

struct buffer_g2_command {
	alt_u8	Command_Type; // Must be 'G'
	alt_u16 Command_Number;
	alt_u8  AxisType; // 0 = 고정 좌표, 1 = 가변 좌표
	double DataX;
	double DataY;
	double DataZ;
	double DataE;
	double DataI;
	double DataJ;
	double FeedRate;
	alt_u8 SelectTool;
};

struct buffer_g28_command {
	alt_u8	Command_Type; // Must be 'G'
	alt_u16 Command_Number;
	double PreX;
	double PreY;
	double PreZ;
	double FeedRate;
};

struct buffer_t_command {
	alt_u8	Command_Type; // Must be 'G'
	alt_u16 Command_Number;
};

union buffer_struct {
	struct buffer_unknown_command 	unknown;
	struct buffer_g1_command 		g1;
	struct buffer_g2_command 		g2;
	struct buffer_g2_command 		g3;
	struct buffer_g28_command 		g28;
	struct buffer_t_command			t;
};

struct buffer_array {
	union buffer_struct *data;
	struct buffer_array *next;
};

static struct buffer_array *buffer_start = NULL;
static struct buffer_array *buffer_end = NULL;

static double CurrentFeedRate = 0.0; // 주의 : 해당 값은 초당의 값이다. G Code의 입력은 분당임.

#ifdef ALT_ENHANCED_INTERRUPT_API_PRESENT
void buffer_interrupt_latency_irq (void* base);
#else
void buffer_interrupt_latency_irq (void* base, alt_u32 id);
#endif

static int buffer_run_g1 ( union buffer_struct *g1_data);
static int buffer_run_g2 ( union buffer_struct *g2_data);
static int buffer_run_g3 ( union buffer_struct *g3_data);
static int buffer_run_g28 ( union buffer_struct *g28_data);
static int buffer_run_t ( union buffer_struct *t_data);

inline int CheckingMotorRunning(void)
{
	int ReturnValue = -1;

	if( IORD_8DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_RUNNING) == 0x00) {
		ReturnValue = 0;
	} else {
		ReturnValue = 1;
	}
	return ReturnValue;
}

/*
 * * get the mutex device handle */
//alt_mutex_dev* mutex = altera_avalon_mutex_open( “/dev/mutex” ); /* acquire the mutex, setting the value to one */
//altera_avalon_mutex_lock( mutex, 1 );
/*
* Access a shared resource here.
*/
/* release the lock */
//altera_avalon_mutex_unlock( mutex );

alt_mutex_dev* buffer_mutex = NULL;


#ifdef ALT_ENHANCED_INTERRUPT_API_PRESENT
void buffer_interrupt_latency_irq (void* context)
#else
void buffer_interrupt_latency_irq (void* context, alt_u32 id)
#endif
{
	union buffer_struct *Index = NULL;
	struct buffer_array *FreePos = NULL;

	IOWR_8DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_RUNNING, 0);
	FreePos = buffer_start;
	Index = buffer_start->data;

	altera_avalon_mutex_lock( buffer_mutex, 0x1000 );
	buffer_start = buffer_start->next;
	if( buffer_start == NULL ) {
		buffer_end = NULL;
	}
	altera_avalon_mutex_unlock( buffer_mutex );

	free( FreePos );

	switch ( Index->unknown.Command_Type) {
		case 'G' : {
			switch( Index->unknown.Command_Number) {
			    case 1: {
			    	buffer_run_g1( Index );
			    	break;
			    }
			    case 2: {
			    	buffer_run_g2( Index );
			    	break;
			    }
			    case 3: {
			    	buffer_run_g3( Index );
			    	break;
			    }
			    case 28: {
			    	buffer_run_g28( Index );
			    	break;
			    }
			}
			break;
		}
		case 'M' : {
			break;
		}
		case 'T' : {
			break;
		}
		case 'K' : {
			break;
		}
		default : {
			break;
		}
	}
	free( Index );
}

int buffer_init( char *DeviceName )
{
	int ReturnValue = -1;

	if( DeviceName != NULL ) {
		buffer_mutex = altera_avalon_mutex_open( DeviceName );
		if( buffer_mutex != NULL ) {
			ReturnValue = 0;
		}
#ifdef ALT_ENHANCED_INTERRUPT_API_PRESENT
		alt_ic_isr_register( DEVCORE_3D_CNC_IRQ_INTERRUPT_CONTROLLER_ID, DEVCORE_3D_CNC_IRQ, buffer_interrupt_latency_irq, buffer_start, 0x0);
#else
		alt_irq_register(DEVCORE_3D_CNC_IRQ, buffer_start, buffer_interrupt_latency_irq);
#endif
	}
	return ReturnValue;
}

static double GetMinMoving( double MoveX, double MoveY, double MoveZ, double MoveE )
{
	double ReturnValue = 0.0;

	if( fabs(MoveX) < fabs(MoveY) ) {
		if( MoveX != 0.0) {
			ReturnValue = fabs(MoveX);
		} else {
			ReturnValue = fabs(MoveY);
		}
	}
	if( ReturnValue > fabs(MoveZ) ) {
		if( MoveZ != 0.0 ) {
			ReturnValue = fabs(MoveZ);
		}
	}
	if( ReturnValue > fabs(MoveE) ) {
		if( MoveE != 0.0 ) {
			ReturnValue = fabs(MoveE);
		}
	}
	return ReturnValue;
}

int buffer_command_g1( alt_u8 AxisType, double DataX, double DataY, double DataZ, double DataE, double FeedRate, alt_8 SelectTool )
{
	int ReturnValue = -1;
	union buffer_struct *Addin = NULL;

	Addin = (union buffer_struct *)malloc( sizeof( union buffer_struct ) );
	if( Addin != NULL ) {
		struct buffer_array * InsertData = NULL;

		InsertData = (struct buffer_array *)malloc( sizeof( struct buffer_array ) );
		if( InsertData != NULL ) {
			Addin->g1.Command_Type = 'G';
			Addin->g1.Command_Number = 1;
			Addin->g1.AxisType = AxisType;
			Addin->g1.DataX = DataX;
			Addin->g1.DataY = DataY;
			Addin->g1.DataZ = DataZ;
			Addin->g1.DataE = DataE;
			Addin->g1.FeedRate = FeedRate;
			Addin->g1.SelectTool = SelectTool;

			InsertData->data = Addin;
			InsertData->next = NULL;

			if( CheckingMotorRunning() == 1 ) {
				altera_avalon_mutex_lock( buffer_mutex, 0x1001 );

				if( buffer_start != NULL ) {
					buffer_end->next = InsertData;
					buffer_end = InsertData;
				} else {
					// 초기 삽입
					buffer_start = InsertData;
					buffer_end = InsertData;
				}
				altera_avalon_mutex_unlock( buffer_mutex );
			} else {
				buffer_run_g1( Addin );
				free( Addin );
				free( InsertData );
			}
			ReturnValue = 0;
		} else {
		    free( Addin );
		}
	}
	return ReturnValue;
}

int buffer_command_g2( alt_u8 AxisType, double DataX, double DataY, double DataZ, double DataI, double DataJ, double DataE, double FeedRate, alt_8 SelectTool )
{
	int ReturnValue = -1;
	union buffer_struct *Addin = NULL;

	Addin = (union buffer_struct *)malloc( sizeof( union buffer_struct ) );
	if( Addin != NULL ) {
		struct buffer_array * InsertData = NULL;

		InsertData = (struct buffer_array *)malloc( sizeof( struct buffer_array ) );
		if( InsertData != NULL ) {
			Addin->g2.Command_Type = 'G';
			Addin->g2.Command_Number = 2;
			Addin->g2.AxisType = AxisType;
			Addin->g2.DataX = DataX;
			Addin->g2.DataY = DataY;
			Addin->g2.DataZ = DataZ;
			Addin->g2.DataI = DataI;
			Addin->g2.DataJ = DataJ;
			Addin->g2.DataE = DataE;
			Addin->g2.FeedRate = FeedRate;
			Addin->g2.SelectTool = SelectTool;

			InsertData->data = Addin;
			InsertData->next = NULL;

			if( CheckingMotorRunning() == 1 ) {
				altera_avalon_mutex_lock( buffer_mutex, 0x1001 );

				if( buffer_start != NULL ) {
					buffer_end->next = InsertData;
					buffer_end = InsertData;
				} else {
					// 초기 삽입
					buffer_start = InsertData;
					buffer_end = InsertData;
				}
				altera_avalon_mutex_unlock( buffer_mutex );
			} else {
				buffer_run_g2( Addin );
				free( Addin );
				free( InsertData );
			}
			ReturnValue = 0;
		} else {
		    free( Addin );
		}
	}
	return ReturnValue;
}

int buffer_command_g3( alt_u8 AxisType, double DataX, double DataY, double DataZ, double DataI, double DataJ, double DataE, double FeedRate, alt_8 SelectTool )
{
	int ReturnValue = -1;
	union buffer_struct *Addin = NULL;

	Addin = (union buffer_struct *)malloc( sizeof( union buffer_struct ) );
	if( Addin != NULL ) {
		struct buffer_array * InsertData = NULL;

		InsertData = (struct buffer_array *)malloc( sizeof( struct buffer_array ) );
		if( InsertData != NULL ) {
			Addin->g3.Command_Type = 'G';
			Addin->g3.Command_Number = 3;
			Addin->g3.AxisType = AxisType;
			Addin->g3.DataX = DataX;
			Addin->g3.DataY = DataY;
			Addin->g3.DataZ = DataZ;
			Addin->g3.DataI = DataI;
			Addin->g3.DataJ = DataJ;
			Addin->g3.DataE = DataE;
			Addin->g3.FeedRate = FeedRate;
			Addin->g3.SelectTool = SelectTool;

			InsertData->data = Addin;
			InsertData->next = NULL;

			if( CheckingMotorRunning() == 1 ) {
				altera_avalon_mutex_lock( buffer_mutex, 0x1001 );

				if( buffer_start != NULL ) {
					buffer_end->next = InsertData;
					buffer_end = InsertData;
				} else {
					// 초기 삽입
					buffer_start = InsertData;
					buffer_end = InsertData;
				}
				altera_avalon_mutex_unlock( buffer_mutex );
			} else {
				buffer_run_g3( Addin );
				free( Addin );
				free( InsertData );
			}
			ReturnValue = 0;
		} else {
		    free( Addin );
		}
	}
	return ReturnValue;
}

int buffer_command_g28( alt_u8 AxisType, double PreX, double PreY, double PreZ, double FeedRate )
{
	int ReturnValue = -1;
	union buffer_struct *Addin = NULL;

	Addin = (union buffer_struct *)malloc( sizeof( union buffer_struct ) );
	if( Addin != NULL ) {
		struct buffer_array * InsertData = NULL;

		InsertData = (struct buffer_array *)malloc( sizeof( struct buffer_array ) );
		if( InsertData != NULL ) {
			Addin->g28.Command_Type = 'G';
			Addin->g28.Command_Number = 28;
			Addin->g28.PreX = PreX;
			Addin->g28.PreY = PreY;
			Addin->g28.PreZ = PreZ;
			Addin->g28.FeedRate = FeedRate;

			InsertData->data = Addin;
			InsertData->next = NULL;

			if( CheckingMotorRunning() == 1 ) {
				altera_avalon_mutex_lock( buffer_mutex, 0x1001 );

				if( buffer_start != NULL ) {
					buffer_end->next = InsertData;
					buffer_end = InsertData;
				} else {
					// 초기 삽입
					buffer_start = InsertData;
					buffer_end = InsertData;
				}
				altera_avalon_mutex_unlock( buffer_mutex );
			} else {
				buffer_run_g28( Addin );
				free( Addin );
				free( InsertData );
			}
			ReturnValue = 0;
		} else {
		    free( Addin );
		}
	}
	return ReturnValue;
}

int buffer_command_t( alt_u8 ToolNum )
{
	int ReturnValue = -1;
	union buffer_struct *Addin = NULL;

	Addin = (union buffer_struct *)malloc( sizeof( union buffer_struct ) );
	if( Addin != NULL ) {
		struct buffer_array * InsertData = NULL;

		InsertData = (struct buffer_array *)malloc( sizeof( struct buffer_array ) );
		if( InsertData != NULL ) {
			Addin->t.Command_Type = 'T';
			Addin->t.Command_Number = ToolNum;

			InsertData->data = Addin;
			InsertData->next = NULL;

			if( CheckingMotorRunning() == 1 ) {
				altera_avalon_mutex_lock( buffer_mutex, 0x1001 );

				if( buffer_start != NULL ) {
					buffer_end->next = InsertData;
					buffer_end = InsertData;
				} else {
					// 초기 삽입
					buffer_start = InsertData;
					buffer_end = InsertData;
				}
				altera_avalon_mutex_unlock( buffer_mutex );
			} else {
				buffer_run_t( Addin );
				free( Addin );
				free( InsertData );
			}
			ReturnValue = 0;
		} else {
		    free( Addin );
		}
	}
	return ReturnValue;
}

static int buffer_run_g1 ( union buffer_struct *g1_data)
{
	int ReturnValue = -1;

	if( g1_data != NULL ) {
		alt_u8 RunningFlag = 0;
		double MoveValue_X = 0.0, MoveValue_Y = 0.0, MoveValue_Z = 0.0, MoveValue_E = 0.0 ;
		double MoveValue = 0.0;
		double SettingFeedRate = 0.0;

		MoveValue_X = g1_data->g1.DataX - (double)IORD_32DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CURRENT_POS_X );
		MoveValue_Y = g1_data->g1.DataY - (double)IORD_32DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CURRENT_POS_Y );
		MoveValue_Z = g1_data->g1.DataZ - (double)IORD_32DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CURRENT_POS_Z );
		if( ExtruderAbsolute == 0 ) {
		    MoveValue_E = g1_data->g1.DataE - (double)IORD_32DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_EXTRUDER_POS );
		} else {
			MoveValue_E = fabs(g1_data->g1.DataE);
		}

		MoveValue = GetMinMoving( MoveValue_X, MoveValue_Y, MoveValue_Z, MoveValue_E);

		if( g1_data->g1.FeedRate != 0.0 ) {
			CurrentFeedRate = g1_data->g1.FeedRate;
		}
		SettingFeedRate = CurrentFeedRate;

		if( MoveValue != 0.0 ) {
			if( MoveValue_X != 0.0 ) {
				double CalcValue = 0.0;
				alt_u16 SettingDiv = 0;

				if( MaxFeedRate_X < SettingFeedRate ) {
					// 속도의 설정은 장비의 상태를 고려해야 하기 때문에 익스트루더의 속도에 맞춘다.
					SettingFeedRate = MaxFeedRate_X;
				} else {
					SettingFeedRate = CurrentFeedRate;
				}
				RunningFlag |= DevBoard_3D_CNC_RUNNING_X_MSK;

				CalcValue = SettingFeedRate * fabs(MoveValue_X) / MoveValue ;

				SettingDiv = ( DevBoard_3D_CNC_MOTOR_CLOCK / (alt_u32)CalcValue ) << 1 ;
				IOWR_16DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CLK_DIV_X, SettingDiv );
				IOWR_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_MOVE_X, (alt_u32)g1_data->g1.DataX );
			}
			if( MoveValue_Y != 0.0 ) {
				double CalcValue = 0.0;
				alt_u16 SettingDiv = 0;

				if( MaxFeedRate_Y < SettingFeedRate ) {
					// 속도의 설정은 장비의 상태를 고려해야 하기 때문에 익스트루더의 속도에 맞춘다.
					SettingFeedRate = MaxFeedRate_Y;
				} else {
					SettingFeedRate = CurrentFeedRate;
				}
				RunningFlag |= DevBoard_3D_CNC_RUNNING_Y_MSK;

				CalcValue = SettingFeedRate * fabs(MoveValue_Y) / MoveValue ;

				SettingDiv = ( DevBoard_3D_CNC_MOTOR_CLOCK / (alt_u32)CalcValue ) << 1 ;
				IOWR_16DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CLK_DIV_Y, SettingDiv );
				IOWR_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_MOVE_Y, (alt_u32)g1_data->g1.DataY );
			}
			if( MoveValue_Z != 0.0 ) {
				double CalcValue = 0.0;
				alt_u16 SettingDiv = 0;

				if( MaxFeedRate_Z < SettingFeedRate ) {
					// 속도의 설정은 장비의 상태를 고려해야 하기 때문에 익스트루더의 속도에 맞춘다.
					SettingFeedRate = MaxFeedRate_Z;
				} else {
					SettingFeedRate = CurrentFeedRate;
				}
				RunningFlag |= DevBoard_3D_CNC_RUNNING_Z_MSK;

				CalcValue = SettingFeedRate * fabs(MoveValue_Z) / MoveValue ;

				SettingDiv = ( DevBoard_3D_CNC_MOTOR_CLOCK / (alt_u32)CalcValue ) << 1 ;
				IOWR_16DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CLK_DIV_Z, SettingDiv );
				IOWR_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_MOVE_Z, (alt_u32)g1_data->g1.DataZ );
			}
			if( MoveValue_E != 0.0 ) {
				double CalcValue = 0.0;
				alt_u16 SettingDiv = 0;
				int ExtruderIndex = 0;

				if( MaxFeedRate_E[GetExtruderNum(DEVCORE_3D_CNC_BASE)] < SettingFeedRate ) {
					// 속도의 설정은 장비의 상태를 고려해야 하기 때문에 익스트루더의 속도에 맞춘다.
					SettingFeedRate = MaxFeedRate_E[GetExtruderNum(DEVCORE_3D_CNC_BASE)];
				} else {
					SettingFeedRate = CurrentFeedRate;
				}
				RunningFlag |= DevBoard_3D_CNC_RUNNING_E_MSK;

				ExtruderIndex = GetExtruderNum(DEVCORE_3D_CNC_BASE);

				CalcValue = SettingFeedRate * fabs(MoveValue_E) / MoveValue ;
				SettingDiv = ( DevBoard_3D_CNC_MOTOR_CLOCK / (alt_u32)CalcValue ) << 1 ;
				IOWR_16DIRECT(DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + (0x10 * ExtruderIndex), DevBoard_3D_CNC_EXTRUDER_MOTOR_CLK_DIV, SettingDiv );

				if( ExtruderAbsolute == 0 ) {
				    IOWR_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_EXTRUDER_MOVE, (alt_u32)g1_data->g1.DataE );
				} else {
					IOWR_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_EXTRUDER_MOVE, (alt_u32)g1_data->g1.DataE + IORD_32DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_EXTRUDER_POS ) );
				}
			}
			IOWR_8DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_RUNNING, 0);
			usleep( 1000 );
			IOWR_8DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_RUNNING, RunningFlag);
			usleep( 1000 );
		}
		ReturnValue = 0;
	}
	return ReturnValue;
}
static int buffer_run_g2 ( union buffer_struct *g1_data)
{
	int ReturnValue = -1;

	if( g1_data != NULL ) {
		alt_u8 RunningFlag = 0;
		double MoveValue_X = 0.0, MoveValue_Y = 0.0, MoveValue_Z = 0.0, MoveValue_E = 0.0 ;
		double MoveValue = 0.0;
		double SettingFeedRate = 0.0;

		MoveValue_X = g1_data->g1.DataX - (double)IORD_32DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CURRENT_POS_X );
		MoveValue_Y = g1_data->g1.DataY - (double)IORD_32DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CURRENT_POS_Y );
		MoveValue_Z = g1_data->g1.DataZ - (double)IORD_32DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CURRENT_POS_Z );
		if( ExtruderAbsolute == 0 ) {
		    MoveValue_E = g1_data->g1.DataE - (double)IORD_32DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_EXTRUDER_POS );
		} else {
			MoveValue_E = fabs(g1_data->g1.DataE);
		}

		MoveValue = GetMinMoving( MoveValue_X, MoveValue_Y, MoveValue_Z, MoveValue_E);

		if( g1_data->g1.FeedRate != 0.0 ) {
			CurrentFeedRate = g1_data->g1.FeedRate;
		}
		SettingFeedRate = CurrentFeedRate;

		if( MoveValue != 0.0 ) {
			if( MoveValue_X != 0.0 ) {
				double CalcValue = 0.0;
				alt_u16 SettingDiv = 0;

				if( MaxFeedRate_X < SettingFeedRate ) {
					// 속도의 설정은 장비의 상태를 고려해야 하기 때문에 익스트루더의 속도에 맞춘다.
					SettingFeedRate = MaxFeedRate_X;
				} else {
					SettingFeedRate = CurrentFeedRate;
				}
				RunningFlag |= DevBoard_3D_CNC_RUNNING_X_MSK;

				CalcValue = SettingFeedRate * fabs(MoveValue_X) / MoveValue ;

				SettingDiv = ( DevBoard_3D_CNC_MOTOR_CLOCK / (alt_u32)CalcValue ) << 1 ;
				IOWR_16DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CLK_DIV_X, SettingDiv );
				IOWR_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_MOVE_X, (alt_u32)g1_data->g1.DataX );
			}
			if( MoveValue_Y != 0.0 ) {
				double CalcValue = 0.0;
				alt_u16 SettingDiv = 0;

				if( MaxFeedRate_Y < SettingFeedRate ) {
					// 속도의 설정은 장비의 상태를 고려해야 하기 때문에 익스트루더의 속도에 맞춘다.
					SettingFeedRate = MaxFeedRate_Y;
				} else {
					SettingFeedRate = CurrentFeedRate;
				}
				RunningFlag |= DevBoard_3D_CNC_RUNNING_Y_MSK;

				CalcValue = SettingFeedRate * fabs(MoveValue_Y) / MoveValue ;

				SettingDiv = ( DevBoard_3D_CNC_MOTOR_CLOCK / (alt_u32)CalcValue ) << 1 ;
				IOWR_16DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CLK_DIV_Y, SettingDiv );
				IOWR_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_MOVE_Y, (alt_u32)g1_data->g1.DataY );
			}
			if( MoveValue_Z != 0.0 ) {
				double CalcValue = 0.0;
				alt_u16 SettingDiv = 0;

				if( MaxFeedRate_Z < SettingFeedRate ) {
					// 속도의 설정은 장비의 상태를 고려해야 하기 때문에 익스트루더의 속도에 맞춘다.
					SettingFeedRate = MaxFeedRate_Z;
				} else {
					SettingFeedRate = CurrentFeedRate;
				}
				RunningFlag |= DevBoard_3D_CNC_RUNNING_Z_MSK;

				CalcValue = SettingFeedRate * fabs(MoveValue_Z) / MoveValue ;

				SettingDiv = ( DevBoard_3D_CNC_MOTOR_CLOCK / (alt_u32)CalcValue ) << 1 ;
				IOWR_16DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CLK_DIV_Z, SettingDiv );
				IOWR_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_MOVE_Z, (alt_u32)g1_data->g1.DataZ );
			}
			if( MoveValue_E != 0.0 ) {
				double CalcValue = 0.0;
				alt_u16 SettingDiv = 0;
				int ExtruderIndex = 0;

				if( MaxFeedRate_E[GetExtruderNum(DEVCORE_3D_CNC_BASE)] < SettingFeedRate ) {
					// 속도의 설정은 장비의 상태를 고려해야 하기 때문에 익스트루더의 속도에 맞춘다.
					SettingFeedRate = MaxFeedRate_E[GetExtruderNum(DEVCORE_3D_CNC_BASE)];
				} else {
					SettingFeedRate = CurrentFeedRate;
				}
				RunningFlag |= DevBoard_3D_CNC_RUNNING_E_MSK;

				ExtruderIndex = GetExtruderNum(DEVCORE_3D_CNC_BASE);

				CalcValue = SettingFeedRate * fabs(MoveValue_E) / MoveValue ;
				SettingDiv = ( DevBoard_3D_CNC_MOTOR_CLOCK / (alt_u32)CalcValue ) << 1 ;
				IOWR_16DIRECT(DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + (0x10 * ExtruderIndex), DevBoard_3D_CNC_EXTRUDER_MOTOR_CLK_DIV, SettingDiv );

				if( ExtruderAbsolute == 0 ) {
				    IOWR_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_EXTRUDER_MOVE, (alt_u32)g1_data->g1.DataE );
				} else {
					IOWR_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_EXTRUDER_MOVE, (alt_u32)g1_data->g1.DataE + IORD_32DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_EXTRUDER_POS ) );
				}
			}
			IOWR_8DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_RUNNING, 0);
			usleep( 1000 );
			IOWR_8DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_RUNNING, RunningFlag);
			usleep( 1000 );
		}
		ReturnValue = 0;
	}
	return ReturnValue;
}
static int buffer_run_g3 ( union buffer_struct *g1_data)
{
	int ReturnValue = -1;

	if( g1_data != NULL ) {
		alt_u8 RunningFlag = 0;
		double MoveValue_X = 0.0, MoveValue_Y = 0.0, MoveValue_Z = 0.0, MoveValue_E = 0.0 ;
		double MoveValue = 0.0;
		double SettingFeedRate = 0.0;

		MoveValue_X = g1_data->g1.DataX - (double)IORD_32DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CURRENT_POS_X );
		MoveValue_Y = g1_data->g1.DataY - (double)IORD_32DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CURRENT_POS_Y );
		MoveValue_Z = g1_data->g1.DataZ - (double)IORD_32DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CURRENT_POS_Z );
		if( ExtruderAbsolute == 0 ) {
		    MoveValue_E = g1_data->g1.DataE - (double)IORD_32DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_EXTRUDER_POS );
		} else {
			MoveValue_E = fabs(g1_data->g1.DataE);
		}

		MoveValue = GetMinMoving( MoveValue_X, MoveValue_Y, MoveValue_Z, MoveValue_E);

		if( g1_data->g1.FeedRate != 0.0 ) {
			CurrentFeedRate = g1_data->g1.FeedRate;
		}
		SettingFeedRate = CurrentFeedRate;

		if( MoveValue != 0.0 ) {
			if( MoveValue_X != 0.0 ) {
				double CalcValue = 0.0;
				alt_u16 SettingDiv = 0;

				if( MaxFeedRate_X < SettingFeedRate ) {
					// 속도의 설정은 장비의 상태를 고려해야 하기 때문에 익스트루더의 속도에 맞춘다.
					SettingFeedRate = MaxFeedRate_X;
				} else {
					SettingFeedRate = CurrentFeedRate;
				}
				RunningFlag |= DevBoard_3D_CNC_RUNNING_X_MSK;

				CalcValue = SettingFeedRate * fabs(MoveValue_X) / MoveValue ;

				SettingDiv = ( DevBoard_3D_CNC_MOTOR_CLOCK / (alt_u32)CalcValue ) << 1 ;
				IOWR_16DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CLK_DIV_X, SettingDiv );
				IOWR_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_MOVE_X, (alt_u32)g1_data->g1.DataX );
			}
			if( MoveValue_Y != 0.0 ) {
				double CalcValue = 0.0;
				alt_u16 SettingDiv = 0;

				if( MaxFeedRate_Y < SettingFeedRate ) {
					// 속도의 설정은 장비의 상태를 고려해야 하기 때문에 익스트루더의 속도에 맞춘다.
					SettingFeedRate = MaxFeedRate_Y;
				} else {
					SettingFeedRate = CurrentFeedRate;
				}
				RunningFlag |= DevBoard_3D_CNC_RUNNING_Y_MSK;

				CalcValue = SettingFeedRate * fabs(MoveValue_Y) / MoveValue ;

				SettingDiv = ( DevBoard_3D_CNC_MOTOR_CLOCK / (alt_u32)CalcValue ) << 1 ;
				IOWR_16DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CLK_DIV_Y, SettingDiv );
				IOWR_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_MOVE_Y, (alt_u32)g1_data->g1.DataY );
			}
			if( MoveValue_Z != 0.0 ) {
				double CalcValue = 0.0;
				alt_u16 SettingDiv = 0;

				if( MaxFeedRate_Z < SettingFeedRate ) {
					// 속도의 설정은 장비의 상태를 고려해야 하기 때문에 익스트루더의 속도에 맞춘다.
					SettingFeedRate = MaxFeedRate_Z;
				} else {
					SettingFeedRate = CurrentFeedRate;
				}
				RunningFlag |= DevBoard_3D_CNC_RUNNING_Z_MSK;

				CalcValue = SettingFeedRate * fabs(MoveValue_Z) / MoveValue ;

				SettingDiv = ( DevBoard_3D_CNC_MOTOR_CLOCK / (alt_u32)CalcValue ) << 1 ;
				IOWR_16DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CLK_DIV_Z, SettingDiv );
				IOWR_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_MOVE_Z, (alt_u32)g1_data->g1.DataZ );
			}
			if( MoveValue_E != 0.0 ) {
				double CalcValue = 0.0;
				alt_u16 SettingDiv = 0;
				int ExtruderIndex = 0;

				if( MaxFeedRate_E[GetExtruderNum(DEVCORE_3D_CNC_BASE)] < SettingFeedRate ) {
					// 속도의 설정은 장비의 상태를 고려해야 하기 때문에 익스트루더의 속도에 맞춘다.
					SettingFeedRate = MaxFeedRate_E[GetExtruderNum(DEVCORE_3D_CNC_BASE)];
				} else {
					SettingFeedRate = CurrentFeedRate;
				}
				RunningFlag |= DevBoard_3D_CNC_RUNNING_E_MSK;

				ExtruderIndex = GetExtruderNum(DEVCORE_3D_CNC_BASE);

				CalcValue = SettingFeedRate * fabs(MoveValue_E) / MoveValue ;
				SettingDiv = ( DevBoard_3D_CNC_MOTOR_CLOCK / (alt_u32)CalcValue ) << 1 ;
				IOWR_16DIRECT(DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + (0x10 * ExtruderIndex), DevBoard_3D_CNC_EXTRUDER_MOTOR_CLK_DIV, SettingDiv );

				if( ExtruderAbsolute == 0 ) {
				    IOWR_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_EXTRUDER_MOVE, (alt_u32)g1_data->g1.DataE );
				} else {
					IOWR_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_EXTRUDER_MOVE, (alt_u32)g1_data->g1.DataE + IORD_32DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_EXTRUDER_POS ) );
				}
			}
			IOWR_8DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_RUNNING, 0);
			usleep( 1000 );
			IOWR_8DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_RUNNING, RunningFlag);
			usleep( 1000 );
		}
		ReturnValue = 0;
	}
	return ReturnValue;
}
static int buffer_run_g28 ( union buffer_struct *g28_data)
{
	int ReturnValue = -1;

	if( g28_data != NULL ) {
		alt_u8 RunningFlag = 0;
		double MoveValue = 0.0;
		double SettingFeedRate = 0.0;

		if( g28_data->g28.PreX != 0.0 ) {
			alt_u8 flag = 0;
			alt_u32 data = 0;
			alt_u16 SettingDiv = 0;

			flag = IORD_8DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOVE_ZERO );
			flag |= DevBoard_3D_CNC_MOVE_ZERO_X_MSK;
			IOWR_8DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOVE_ZERO, flag );
			data = lround( g28_data->g28.PreX );
			IOWR_32DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_PREPOS_X, data );

			SettingDiv = ( DevBoard_3D_CNC_MOTOR_CLOCK / (alt_u32)HomeFeedRate_X ) << 1 ;
			IOWR_16DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CLK_DIV_X, SettingDiv );
		}
		if( g28_data->g28.PreY != 0.0 ) {
			alt_u8 flag = 0;
			alt_u32 data = 0;
			alt_u16 SettingDiv = 0;

			flag = IORD_8DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOVE_ZERO );
			flag |= DevBoard_3D_CNC_MOVE_ZERO_Y_MSK;
			IOWR_8DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOVE_ZERO, flag );
			data = lround( g28_data->g28.PreY );
			IOWR_32DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_PREPOS_Y, data );

			SettingDiv = ( DevBoard_3D_CNC_MOTOR_CLOCK / (alt_u32)HomeFeedRate_Y ) << 1 ;
			IOWR_16DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CLK_DIV_Y, SettingDiv );
		}
		if( g28_data->g28.PreZ != 0.0 ) {
			alt_u8 flag = 0;
			alt_u32 data = 0;
			alt_u16 SettingDiv = 0;

			flag = IORD_8DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOVE_ZERO );
			flag |= DevBoard_3D_CNC_MOVE_ZERO_Z_MSK;
			IOWR_8DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOVE_ZERO, flag );
			data = lround( g28_data->g28.PreZ );
			IOWR_32DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_PREPOS_Z, data );

			SettingDiv = ( DevBoard_3D_CNC_MOTOR_CLOCK / (alt_u32)HomeFeedRate_Z ) << 1 ;
			IOWR_16DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CLK_DIV_Z, SettingDiv );
		}
		if( (g28_data->g28.PreX == 0.0) && (g28_data->g28.PreX == 0.0) && (g28_data->g28.PreX == 0.0) ) {
			alt_u8 flag = 0;
			alt_u16 SettingDiv = 0;

			flag = IORD_8DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOVE_ZERO );
			flag |= DevBoard_3D_CNC_MOVE_ZERO_X_MSK;
			flag |= DevBoard_3D_CNC_MOVE_ZERO_Y_MSK;
			flag |= DevBoard_3D_CNC_MOVE_ZERO_Z_MSK;
			IOWR_8DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOVE_ZERO, flag );

			SettingDiv = ( DevBoard_3D_CNC_MOTOR_CLOCK / (alt_u32)HomeFeedRate_X ) << 1 ;
			IOWR_16DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CLK_DIV_X, SettingDiv );
			SettingDiv = ( DevBoard_3D_CNC_MOTOR_CLOCK / (alt_u32)HomeFeedRate_Y ) << 1 ;
			IOWR_16DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CLK_DIV_Y, SettingDiv );
			SettingDiv = ( DevBoard_3D_CNC_MOTOR_CLOCK / (alt_u32)HomeFeedRate_Z ) << 1 ;
			IOWR_16DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_CLK_DIV_Z, SettingDiv );
		}

		IOWR_8DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_RUNNING, 0);
		usleep( 1000 );
		IOWR_8DIRECT( DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_RUNNING, RunningFlag);
		usleep( 1000 );
		ReturnValue = 0;
	}
	return ReturnValue;
}
static int buffer_run_t ( union buffer_struct *t_data)
{
	int ReturnValue = -1;

	if( t_data != NULL ) {
		alt_u8 RunningFlag = 0;
		double MoveValue = 0.0;
		double SettingFeedRate = 0.0;

		IOWR_8DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_SELECT_EXTRUDER, t_data->t.Command_Number );
		ReturnValue = 0;
	}
	return ReturnValue;
}
