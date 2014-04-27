/*
 * mcode_command.c
 *
 *  Created on: 2014. 3. 31.
 *      Author: dimo
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <alt_types.h>
#include <io.h>
#include <math.h>
#include <time.h>
#include "system.h"
#include "../inc/configure.h"
#include "../inc/DevBoard_3D_CNC.h"
#include "../inc/gcode_command.h"

static int m1_command( char *command_string);
static int m82_command( char *command_string);
static int m83_command( char *command_string);
static int m84_command( char *command_string);
static int m104_command( char *command_string);
static int m105_command( char *command_string);
static int m106_command( char *command_string);
static int m107_command( char *command_string);
static int m109_command( char *command_string);
static int m114_command( char *command_string);
static int m115_command( char *command_string);
static int m119_command( char *command_string);
static int m140_command( char *command_string);
static int m141_command( char *command_string);
static int m143_command( char *command_string);
static int m190_command( char *command_string);
static int m201_command( char *command_string);
static int m202_command( char *command_string);
static int m203_command( char *command_string);
static int m206_command( char *command_string);
static int m552_command( char *command_string);
static int m553_command( char *command_string);
static int m554_command( char *command_string);
static int m999_command( char *command_string);

struct command_struct m_command_array [] = {
		{    1, m1_command },
		{   18, m84_command },
		{   82, m82_command },
		{   83, m83_command },
		{   84, m84_command },
		{  104, m104_command },
		{  105, m105_command },
		{  106, m106_command },
		{  107, m107_command },
		{  109, m109_command },
		{  114, m114_command },
		{  115, m115_command },
		{  119, m119_command },
		{  140, m140_command },
		{  141, m141_command },
		{  143, m143_command },
		{  190, m190_command },
		{  201, m201_command },
		{  202, m202_command },
		{  203, m203_command },
		{  206, m206_command },
		{  552, m552_command },
		{  553, m553_command },
		{  554, m554_command },
		{  999, m999_command },
		{ NULL, NULL }
};

int ExtruderAbsolute = 0; // 0 = 고정타입, 1 = 가변타입

static int m1_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {

		printf("M1 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M82: set extruder to absolute mode
static int m82_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		ExtruderAbsolute = 0;
		//printf("M82 Command Detected( %s )\n", command_string);
		EndofCommand();
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M83: set extruder to relative mode
static int m83_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		ExtruderAbsolute = 1;
		//printf("M83 Command Detected( %s )\n", command_string);
		EndofCommand();
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M84: Stop idle hold
static int m84_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		printf("M84 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M104: Set Extruder Temperature
static int m104_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		int Temperature = -1;
		int ToolNum = -1;

		if( strchr(command_string, 'T') != NULL ) {
			ToolNum = GetStringToValue( 'T', command_string ) ;
		} else {
			ToolNum = GetExtruderNum(DEVCORE_3D_CNC_BASE);
		}
		if( strchr(command_string, 'S') != NULL ) {
			Temperature = GetStringToValue( 'S', command_string ) ;

			if( Temperature != 0) {
				alt_u8 FlagBit = 0;

				IOWR_16DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_SET_TEMP, MAX31855TemperatureToHex( Temperature ));

				FlagBit = IORD_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG );
				IOWR_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG, FlagBit | (DevBoard_3D_CNC_EXTRUDER_CONFIG_PWM_ENABLE_MSK) );

			} else {
				alt_u8 FlagBit = 0;

				FlagBit = IORD_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG );
				IOWR_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG, FlagBit & (~DevBoard_3D_CNC_EXTRUDER_CONFIG_PWM_ENABLE_MSK) );
			}
		}
		EndofCommand();
		//printf("M104 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M105: Get Extruder Temperature
static int m105_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		char StringBuffer[2048];
		double Temperature = 0.0;
		int ToolNum = -1;

		if( strchr(command_string, 'T') != NULL ) {
			ToolNum = GetStringToValue( 'T', command_string ) ;
		} else {
			ToolNum = GetExtruderNum(DEVCORE_3D_CNC_BASE);
		}
		Temperature = MAX31855HexToTemperature( IORD_16DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_SET_TEMP ) );
		sprintf( StringBuffer, "T:%.2f\n\r", Temperature );
		printf( StringBuffer );
		write( gcode_uart, StringBuffer, strlen( StringBuffer ) );
		EndofCommand();
		//printf("M105 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M106: Fan On
static int m106_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		int ToolNum = FAN_EXTRUDER_NUM;

		if( strchr(command_string, 'S') != NULL ) {
			int Speed = 0;
			alt_u8 FlagBit = 0;

			Speed = GetStringToValue( 'S', command_string ) ;

			IOWR_16DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_PWM_VALUE, Speed );

			FlagBit = IORD_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG );

			if( Speed != 0) {
				IOWR_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG, FlagBit | (DevBoard_3D_CNC_EXTRUDER_CONFIG_PWM_ENABLE_MSK) );
			} else {
				IOWR_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG, FlagBit & (~DevBoard_3D_CNC_EXTRUDER_CONFIG_PWM_ENABLE_MSK) );
			}
		}
		EndofCommand();
		//printf("M106 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M107: Fan Off
static int m107_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		alt_u8 FlagBit = 0;
		int ToolNum = FAN_EXTRUDER_NUM;

		IOWR_16DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_PWM_VALUE, 0 );

		FlagBit = IORD_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG );
		IOWR_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG, FlagBit & (~DevBoard_3D_CNC_EXTRUDER_CONFIG_PWM_ENABLE_MSK) );
		EndofCommand();
		//printf("M107 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M109: Set Extruder Temperature and Wait
static int m109_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		int Temperature = -1;
		int NowTemperature = -1;
		int ToolNum = -1;
		int CheckingCount = 0;

		if( strchr(command_string, 'T') != NULL ) {
			ToolNum = GetStringToValue( 'T', command_string ) ;
		} else {
			ToolNum = GetExtruderNum(DEVCORE_3D_CNC_BASE);
		}
		if( strchr(command_string, 'S') != NULL ) {
			Temperature = GetStringToValue( 'S', command_string ) ;

			if( Temperature != 0) {
				alt_u8 FlagBit = 0;

				IOWR_16DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_SET_TEMP, MAX31855TemperatureToHex( Temperature ));

				FlagBit = IORD_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG );
				IOWR_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG, FlagBit | (DevBoard_3D_CNC_EXTRUDER_CONFIG_PWM_ENABLE_MSK) );

				NowTemperature = (int)MAX31855HexToTemperature( IORD_16DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_SET_TEMP ) );

				while( Temperature != NowTemperature ) {
					NowTemperature = (int)MAX31855HexToTemperature( IORD_16DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_SET_TEMP ) );
					usleep(100);
					CheckingCount++;
					if( CheckingCount == 0 ) {
						char StringBuffer[2048];
						double DisplayTemperature = MAX31855HexToTemperature( IORD_16DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_SET_TEMP ) );

						sprintf( StringBuffer, "T:%.2f\n\r", DisplayTemperature );
						printf( StringBuffer );
						write( gcode_uart, StringBuffer, strlen( StringBuffer ) );
					}
				}
			} else {
				alt_u8 FlagBit = 0;

				FlagBit = IORD_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG );
				IOWR_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG, FlagBit & (~DevBoard_3D_CNC_EXTRUDER_CONFIG_PWM_ENABLE_MSK) );
			}
		}
		EndofCommand();
		//printf("M109 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M114: Get Current Position
static int m114_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		double PositionX = 0.0;
		double PositionY = 0.0;
		double PositionZ = 0.0;
		double PositionE = 0.0;
		char StringBuffer[2048];

		PositionX = (double)IORD_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_MOVE_X) / MotorUnit_X;
		PositionY = (double)IORD_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_MOVE_Y) / MotorUnit_Y;
		PositionZ = (double)IORD_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_MOVE_Z) / MotorUnit_Z;
		PositionE = (double)IORD_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_EXTRUDER_POS) / MotorUnit_E[GetExtruderNum(DEVCORE_3D_CNC_BASE)];

		sprintf( StringBuffer, "X:%.2f Y:%.2f Z:%.2f E:%.2f\n\rok\n\r", PositionX, PositionY, PositionZ, PositionE);
		//printf("M114 Command Detected( %s )\n", command_string);
		printf( StringBuffer );
		write( gcode_uart, StringBuffer, strlen( StringBuffer ) );
		EndofCommand();
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M115: Get Firmware Version and Capabilities
static int m115_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		printf("M140 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M119: Get Endstop Status
static int m119_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		printf("M140 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M140: Bed Temperature (Fast)
static int m140_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		int Temperature = -1;
		int ToolNum = BED_EXTRUDER_NUM;

		if( strchr(command_string, 'S') != NULL ) {
			Temperature = GetStringToValue( 'S', command_string ) ;

			if( Temperature != 0) {
				alt_u8 FlagBit = 0;

				IOWR_16DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_SET_TEMP, MAX31855TemperatureToHex( Temperature ));

				FlagBit = IORD_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG );
				IOWR_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG, FlagBit | (DevBoard_3D_CNC_EXTRUDER_CONFIG_PWM_ENABLE_MSK) );

			} else {
				alt_u8 FlagBit = 0;

				FlagBit = IORD_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG );
				IOWR_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG, FlagBit & (~DevBoard_3D_CNC_EXTRUDER_CONFIG_PWM_ENABLE_MSK) );
			}
		}
		EndofCommand();
		//printf("M140 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M141: Chamber Temperature (Fast)
static int m141_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		int Temperature = -1;
		int ToolNum = CHAMBER_EXTERUDER_NUM;

		if( strchr(command_string, 'S') != NULL ) {
			Temperature = GetStringToValue( 'S', command_string ) ;

			IOWR_16DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_SET_TEMP, MAX31855TemperatureToHex( Temperature ));
		}
		EndofCommand();
		//printf("M140 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M143: Maximum hot-end temperature
static int m143_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		printf("M143 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M190: Wait for bed temperature to reach target temp
static int m190_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		int Temperature = -1;
		int NowTemperature = -1;
		int ToolNum = BED_EXTRUDER_NUM;
		int CheckingCount = 0;

		if( strchr(command_string, 'S') != NULL ) {
			Temperature = GetStringToValue( 'S', command_string ) ;

			if( Temperature != 0) {
				alt_u8 FlagBit = 0;

				IOWR_16DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_SET_TEMP, MAX31855TemperatureToHex( Temperature ));

				FlagBit = IORD_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG );
				IOWR_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG, FlagBit | (DevBoard_3D_CNC_EXTRUDER_CONFIG_PWM_ENABLE_MSK) );

				NowTemperature = (int)MAX31855HexToTemperature( IORD_16DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_SET_TEMP ) );

				while( Temperature != NowTemperature ) {
					NowTemperature = (int)MAX31855HexToTemperature( IORD_16DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_SET_TEMP ) );
					usleep(100);
					CheckingCount++;
					if( CheckingCount == 0 ) {
						char StringBuffer[2048];
						double DisplayTemperature = MAX31855HexToTemperature( IORD_16DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_SET_TEMP ) );

						sprintf( StringBuffer, "T:%.2f\n\r", DisplayTemperature );
						printf( StringBuffer );
						write( gcode_uart, StringBuffer, strlen( StringBuffer ) );
					}
				}
			} else {
				alt_u8 FlagBit = 0;

				FlagBit = IORD_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG );
				IOWR_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + ToolNum * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG, FlagBit & (~DevBoard_3D_CNC_EXTRUDER_CONFIG_PWM_ENABLE_MSK) );
			}
		}
		EndofCommand();
		//printf("M190 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M201 - Set max printing acceleration
static int m201_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		printf("M201 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M202 - Set max travel acceleration
static int m202_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		printf("M202 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M203 - Set maximum feedrate
static int m203_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		int ToolNum = -1;

		if( strchr(command_string, 'X') != NULL ) {
			MotorUnit_X = lround( GetStringToValue_d( 'X', command_string ) );
		}
		if( strchr(command_string, 'Y') != NULL ) {
			MotorUnit_Y = lround( GetStringToValue_d( 'Y', command_string ) );
		}
		if( strchr(command_string, 'Z') != NULL ) {
			MotorUnit_Z = lround( GetStringToValue_d( 'Z', command_string ) );
		}
		if( strchr(command_string, 'T') != NULL ) {
			ToolNum = GetStringToValue( 'T', command_string ) ;
		} else {
			ToolNum = GetExtruderNum(DEVCORE_3D_CNC_BASE);
		}
		if( strchr(command_string, 'E') != NULL ) {
			MotorUnit_E[ToolNum] = lround( GetStringToValue_d( 'E', command_string ) );
		}

		EndofCommand();
		//printf("M203 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}

// M206: set home offset
static int m206_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		if( strchr(command_string, 'X') != NULL ) {
			alt_32 PrePosition;
			PrePosition = lround( GetStringToValue_d( 'X', command_string ) * MotorUnit_X );
			IOWR_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_PREPOS_X, PrePosition );
		}
		if( strchr(command_string, 'Y') != NULL ) {
			alt_32 PrePosition;
			PrePosition = lround( GetStringToValue_d( 'Y', command_string ) * MotorUnit_Y );
			IOWR_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_PREPOS_Y, PrePosition );
		}
		if( strchr(command_string, 'Z') != NULL ) {
			alt_32 PrePosition;
			PrePosition = lround( GetStringToValue_d( 'Z', command_string ) * MotorUnit_Z );
			IOWR_32DIRECT(DEVCORE_3D_CNC_BASE, DevBoard_3D_CNC_MOTOR_PREPOS_Z, PrePosition );
		}
		EndofCommand();
		//printf("M206 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}

// M552: Set IP address
static int m552_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		printf("M552 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M553: Set Netmask
static int m553_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		printf("M553 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M554: Set Gateway
static int m554_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		printf("M554 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
// M999: Restart after being stopped by error
static int m999_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		printf("M999 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
