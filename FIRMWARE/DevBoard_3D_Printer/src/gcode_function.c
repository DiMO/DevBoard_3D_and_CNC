/*
 * gcode_function.c
 *
 *  Created on: 2014. 3. 21.
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
#include "../inc/buffer_operation.h"

static int g1_command( char *command_string);
static int g2_command( char *command_string);
static int g3_command( char *command_string);
static int g4_command( char *command_string);
static int g10_command( char *command_string);
static int g11_command( char *command_string);
static int g20_command( char *command_string);
static int g21_command( char *command_string);
static int g28_command( char *command_string);
static int g29_command( char *command_string);
static int g30_command( char *command_string);
static int g90_command( char *command_string);
static int g91_command( char *command_string);
static int g92_command( char *command_string);

struct command_struct g_command_array [] = {
		{    0, g1_command },
		{    1, g1_command },
		{    2, g2_command },
		{    3, g3_command },
		{    4, g4_command },
		{   10, g10_command },
		{   11, g11_command },
		{   20, g20_command },
		{   21, g21_command },
		{   28, g28_command },
		{   29, g29_command },
		{   30, g30_command },
		{   90, g90_command },
		{   91, g91_command },
		{   92, g92_command },
		{ NULL, NULL }
};

static alt_u32 RunningMode = 0; // 0 = ������ ���, 1 = ������ ���


static double ParseAxis( char Type, char *string, double axis_unit, double *PosData)
{
	double ReturnValue = -1.0;

	if( string != NULL ) {

		if( strchr( string, Type ) != NULL ) {
			// ���� �̵�
			// ������ ����
			if( PosData != NULL ) {
				ReturnValue = *(PosData) = GetStringToValue_d( Type, string ) * axis_unit;
			}
		}
	}
	return ReturnValue;
}

// G0  -> G1 ��ġ����
// G1  - Coordinated Movement X Y Z E ��������
static int g1_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		double SettingFeedRate = 0.0;
		double Value_X = 0.0;
		double Value_Y = 0.0;
		double Value_Z = 0.0;
		double Value_E = 0.0;
		alt_8  ToolNo = -1;

		if( strchr(command_string, 'F') != NULL ) {
			// �ӵ� ������ ȹ��
			// ���� ��쿡�� ������ ���� ����մϴ�.
			SettingFeedRate = GetStringToValue_d( 'F', command_string ) / 60.0;
		}
		//SettingFeedRate = CurrentFeedRate;
		// X�� ���� ȹ��
		ParseAxis( 'X', command_string, MotorUnit_X, &Value_X);
		// Y�� ���� ȹ��
		ParseAxis( 'Y', command_string, MotorUnit_Y, &Value_Y);
		// Z�� ���� ȹ��
		ParseAxis( 'Z', command_string, MotorUnit_Z, &Value_Z);
		// �ͽ�Ʈ��� ���� ȹ��
		ParseAxis( 'E', command_string, MotorUnit_E[GetExtruderNum(DEVCORE_3D_CNC_BASE)], &Value_E );
		// Tool Change Value
		if( strchr( command_string, 'T' ) != NULL ) {
			ToolNo = GetStringToValue( 'T', command_string );
		}
		while ( buffer_command_g1( RunningMode, Value_X, Value_Y, Value_Z, Value_E, SettingFeedRate, ToolNo) != -1 );
		EndofCommand();
//		printf("G0/G1 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
} // static int g1_command( char *command_string)

// G2  - CW ARC ��ȣ����/�︮�� ����(�ð����)
static int g2_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		double SettingFeedRate = 0.0;
		double Value_X = 0.0;
		double Value_Y = 0.0;
		double Value_Z = 0.0;
		double Value_E = 0.0;
		double Value_I = 0.0;
		double Value_J = 0.0;
		alt_8  ToolNo = -1;

		if( strchr(command_string, 'F') != NULL ) {
			// �ӵ� ������ ȹ��
			// ���� ��쿡�� ������ ���� ����մϴ�.
			SettingFeedRate = GetStringToValue_d( 'F', command_string ) / 60.0;
		}
		//SettingFeedRate = CurrentFeedRate;
		// X�� ���� ȹ��
		ParseAxis( 'X', command_string, MotorUnit_X, &Value_X);
		// Y�� ���� ȹ��
		ParseAxis( 'Y', command_string, MotorUnit_Y, &Value_Y);
		// Z�� ���� ȹ��
		ParseAxis( 'Z', command_string, MotorUnit_Z, &Value_Z);
		// Z�� ���� ȹ��
		ParseAxis( 'I', command_string, MotorUnit_Z, &Value_I);
		// Z�� ���� ȹ��
		ParseAxis( 'J', command_string, MotorUnit_Z, &Value_J);
		// �ͽ�Ʈ��� ���� ȹ��
		ParseAxis( 'E', command_string, MotorUnit_E[GetExtruderNum(DEVCORE_3D_CNC_BASE)], &Value_E );
		// Tool Change Value
		if( strchr( command_string, 'T' ) != NULL ) {
			ToolNo = GetStringToValue( 'T', command_string );
		}
		while ( buffer_command_g2( RunningMode, Value_X, Value_Y, Value_Z, Value_I, Value_J, Value_E, SettingFeedRate, ToolNo) != -1 );
		EndofCommand();
//		printf("G2 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}

// G3  - CCW ARC ��ȣ����/�︮�� ����(�ݽð����)
static int g3_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		double SettingFeedRate = 0.0;
		double Value_X = 0.0;
		double Value_Y = 0.0;
		double Value_Z = 0.0;
		double Value_E = 0.0;
		double Value_I = 0.0;
		double Value_J = 0.0;
		alt_8  ToolNo = -1;

		if( strchr(command_string, 'F') != NULL ) {
			// �ӵ� ������ ȹ��
			// ���� ��쿡�� ������ ���� ����մϴ�.
			SettingFeedRate = GetStringToValue_d( 'F', command_string ) / 60.0;
		}
		//SettingFeedRate = CurrentFeedRate;
		// X�� ���� ȹ��
		ParseAxis( 'X', command_string, MotorUnit_X, &Value_X);
		// Y�� ���� ȹ��
		ParseAxis( 'Y', command_string, MotorUnit_Y, &Value_Y);
		// Z�� ���� ȹ��
		ParseAxis( 'Z', command_string, MotorUnit_Z, &Value_Z);
		// Z�� ���� ȹ��
		ParseAxis( 'I', command_string, MotorUnit_Z, &Value_I);
		// Z�� ���� ȹ��
		ParseAxis( 'J', command_string, MotorUnit_Z, &Value_J);
		// �ͽ�Ʈ��� ���� ȹ��
		ParseAxis( 'E', command_string, MotorUnit_E[GetExtruderNum(DEVCORE_3D_CNC_BASE)], &Value_E );
		// Tool Change Value
		if( strchr( command_string, 'T' ) != NULL ) {
			ToolNo = GetStringToValue( 'T', command_string );
		}
		while ( buffer_command_g3( RunningMode, Value_X, Value_Y, Value_Z, Value_I, Value_J, Value_E, SettingFeedRate, ToolNo) != -1 );
		EndofCommand();
		printf("G3 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}

// G4  - Dwell S<seconds> or P<milliseconds> ����(����)/�̱���Ʈ ����
static int g4_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		int DelayTime = 0;

		if( strchr(command_string, 'P') != NULL ) {
			DelayTime = (int)( GetStringToValue_d( 'P', command_string ) * 1000.0 );
		}
		if( strchr(command_string, 'S') != NULL ) {
			DelayTime += (int)( GetStringToValue_d( 'P', command_string ) * 1000000.0 );
		}
		if( DelayTime != 0 ) {
		    usleep( DelayTime );
		    EndofCommand();
		    ReturnValue = 0;
		}
    }
	return ReturnValue;
}

// G10 - retract filament according to settings of M207 ������ ����
static int g10_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		printf("G10 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}

// G11 - retract recover filament according to settings of M208 ������ ���� ��� ���
static int g11_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		printf("G11 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}

static int g20_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		MotorUnit_X = MOTOR_X_UNIT * 25.4;
		MotorUnit_Y = MOTOR_Y_UNIT * 25.4;
		MotorUnit_Z = MOTOR_Z_UNIT * 25.4;
		MotorUnit_E[0] = MOTOR_E0_UNIT * 25.4;
		MotorUnit_E[1] = MOTOR_E1_UNIT * 25.4;
		MotorUnit_E[2] = MOTOR_E2_UNIT * 25.4;
		MotorUnit_E[3] = MOTOR_E3_UNIT * 25.4;
		MotorUnit_E[4] = MOTOR_E4_UNIT * 25.4;
		MotorUnit_E[5] = MOTOR_E5_UNIT * 25.4;
		MotorUnit_E[6] = MOTOR_E6_UNIT * 25.4;
		MotorUnit_E[7] = MOTOR_E7_UNIT * 25.4;
		MotorUnit_E[8] = MOTOR_E8_UNIT * 25.4;
		MotorUnit_E[9] = MOTOR_E9_UNIT * 25.4;
		MotorUnit_E[10] = MOTOR_E10_UNIT * 25.4;
		MotorUnit_E[11] = MOTOR_E11_UNIT * 25.4;
		MotorUnit_E[12] = MOTOR_E12_UNIT * 25.4;
		MotorUnit_E[13] = MOTOR_E13_UNIT * 25.4;
		MotorUnit_E[14] = MOTOR_E14_UNIT * 25.4;
		MotorUnit_E[15] = MOTOR_E15_UNIT * 25.4;
		EndofCommand();
		// printf("G20 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}

static int g21_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		MotorUnit_X = MOTOR_X_UNIT;
		MotorUnit_Y = MOTOR_Y_UNIT;
		MotorUnit_Z = MOTOR_Z_UNIT;
		MotorUnit_E[0] = MOTOR_E0_UNIT ;
		MotorUnit_E[1] = MOTOR_E1_UNIT ;
		MotorUnit_E[2] = MOTOR_E2_UNIT ;
		MotorUnit_E[3] = MOTOR_E3_UNIT ;
		MotorUnit_E[4] = MOTOR_E4_UNIT ;
		MotorUnit_E[5] = MOTOR_E5_UNIT ;
		MotorUnit_E[6] = MOTOR_E6_UNIT ;
		MotorUnit_E[7] = MOTOR_E7_UNIT ;
		MotorUnit_E[8] = MOTOR_E8_UNIT ;
		MotorUnit_E[9] = MOTOR_E9_UNIT ;
		MotorUnit_E[10] = MOTOR_E10_UNIT ;
		MotorUnit_E[11] = MOTOR_E11_UNIT ;
		MotorUnit_E[12] = MOTOR_E12_UNIT ;
		MotorUnit_E[13] = MOTOR_E13_UNIT ;
		MotorUnit_E[14] = MOTOR_E14_UNIT ;
		MotorUnit_E[15] = MOTOR_E15_UNIT ;
		EndofCommand();
		// printf("G21 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}

// G28 - Home all Axis �ڵ���������
static int g28_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		double SettingFeedRate = 0.0;
		double Value_X = 0.0;
		double Value_Y = 0.0;
		double Value_Z = 0.0;
		double Value_E = 0.0;
		alt_8  ToolNo = -1;

		if( strchr(command_string, 'F') != NULL ) {
			// �ӵ� ������ ȹ��
			// ���� ��쿡�� ������ ���� ����մϴ�.
			SettingFeedRate = GetStringToValue_d( 'F', command_string ) / 60.0;
		}
		//SettingFeedRate = CurrentFeedRate;
		// X�� ���� ȹ��
		ParseAxis( 'X', command_string, MotorUnit_X, &Value_X);
		// Y�� ���� ȹ��
		ParseAxis( 'Y', command_string, MotorUnit_Y, &Value_Y);
		// Z�� ���� ȹ��
		ParseAxis( 'Z', command_string, MotorUnit_Z, &Value_Z);
		// �ͽ�Ʈ��� ���� ȹ��
		ParseAxis( 'E', command_string, MotorUnit_E[GetExtruderNum(DEVCORE_3D_CNC_BASE)], &Value_E );
		// Tool Change Value
		if( strchr( command_string, 'T' ) != NULL ) {
			ToolNo = GetStringToValue( 'T', command_string );
		}
		while ( buffer_command_g28( RunningMode, Value_X, Value_Y, Value_Z,  SettingFeedRate ) != -1 );
		EndofCommand();
		//printf("G28 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}

// G29 - Detailed Z-Probe, probes the bed at 3 points.  You must de at the home position for this to work correctly.
//       �������� ����
static int g29_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		printf("G28 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}

// G30 - Single Z Probe, probes bed at current XY location.
//       ��2,3,4���� ����
static int g30_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		printf("G28 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}

// G90 - Use Absolute Coordinates ��������
static int g90_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		RunningMode = 0;
		EndofCommand();
		//printf("G90 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}

// G91 - Use Relative Coordinates ��������
static int g91_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		RunningMode = 1;
		EndofCommand();
		//printf("G91 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}

// G92 - Set current position to cordinates given
//       �����ְ�ȸ���ӵ� ����,���۹� ��ǥ���Ǻ���[Work ��ǥ�� ����]

static int g92_command( char *command_string)
{
	int ReturnValue = -1;

	if( command_string != NULL ) {
		printf("G92 Command Detected( %s )\n", command_string);
		ReturnValue = 0;
    }
	return ReturnValue;
}
