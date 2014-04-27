/*
 * DevBoard_3D_CNC.c
 *
 *  Created on: 2014. 4. 1.
 *      Author: dimo
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <alt_types.h>
#include <io.h>
#include "system.h"
#include "../inc/configure.h"
#include "../inc/DevBoard_3D_CNC.h"

static int ExtruderPosSetting( int base_addr );
static int MotorEncorderSetting( int base_addr );
static int CoolingFanSetting( int base_addr );

int DevBoard_3D_CNC_init ( int base_addr )
{
	int ReturnValue = -1;

	ExtruderPosSetting( base_addr );
	MotorEncorderSetting( base_addr );
	CoolingFanSetting( base_addr );

	return ReturnValue;
}

static int ExtruderPosSetting( int base_addr )
{
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER0, DevBoard_3D_CNC_EXTRUDER_PWM_CLK_DIV, EXTRUDER0_PWM_DIV );
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER0, DevBoard_3D_CNC_EXTRUDER_X_POS, EXTRUDER0_X_POS);
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER0, DevBoard_3D_CNC_EXTRUDER_Y_POS, EXTRUDER0_Y_POS);

	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER1, DevBoard_3D_CNC_EXTRUDER_PWM_CLK_DIV, EXTRUDER1_PWM_DIV );
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER1, DevBoard_3D_CNC_EXTRUDER_X_POS, EXTRUDER1_X_POS);
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER1, DevBoard_3D_CNC_EXTRUDER_Y_POS, EXTRUDER1_Y_POS);

	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER2, DevBoard_3D_CNC_EXTRUDER_PWM_CLK_DIV, EXTRUDER2_PWM_DIV );
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER2, DevBoard_3D_CNC_EXTRUDER_X_POS, EXTRUDER2_X_POS);
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER2, DevBoard_3D_CNC_EXTRUDER_Y_POS, EXTRUDER2_Y_POS);

	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER3, DevBoard_3D_CNC_EXTRUDER_PWM_CLK_DIV, EXTRUDER3_PWM_DIV );
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER3, DevBoard_3D_CNC_EXTRUDER_X_POS, EXTRUDER3_X_POS);
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER3, DevBoard_3D_CNC_EXTRUDER_Y_POS, EXTRUDER3_Y_POS);

	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER4, DevBoard_3D_CNC_EXTRUDER_PWM_CLK_DIV, EXTRUDER4_PWM_DIV );
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER4, DevBoard_3D_CNC_EXTRUDER_X_POS, EXTRUDER4_X_POS);
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER4, DevBoard_3D_CNC_EXTRUDER_Y_POS, EXTRUDER4_Y_POS);

	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER5, DevBoard_3D_CNC_EXTRUDER_PWM_CLK_DIV, EXTRUDER5_PWM_DIV );
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER5, DevBoard_3D_CNC_EXTRUDER_X_POS, EXTRUDER5_X_POS);
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER5, DevBoard_3D_CNC_EXTRUDER_Y_POS, EXTRUDER5_Y_POS);

	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER6, DevBoard_3D_CNC_EXTRUDER_PWM_CLK_DIV, EXTRUDER6_PWM_DIV );
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER6, DevBoard_3D_CNC_EXTRUDER_X_POS, EXTRUDER6_X_POS);
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER6, DevBoard_3D_CNC_EXTRUDER_Y_POS, EXTRUDER6_Y_POS);

	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER7, DevBoard_3D_CNC_EXTRUDER_PWM_CLK_DIV, EXTRUDER7_PWM_DIV );
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER7, DevBoard_3D_CNC_EXTRUDER_X_POS, EXTRUDER7_X_POS);
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER7, DevBoard_3D_CNC_EXTRUDER_Y_POS, EXTRUDER7_Y_POS);

	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER8, DevBoard_3D_CNC_EXTRUDER_PWM_CLK_DIV, EXTRUDER8_PWM_DIV );
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER8, DevBoard_3D_CNC_EXTRUDER_X_POS, EXTRUDER8_X_POS);
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER8, DevBoard_3D_CNC_EXTRUDER_Y_POS, EXTRUDER8_Y_POS);

	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER9, DevBoard_3D_CNC_EXTRUDER_PWM_CLK_DIV, EXTRUDER9_PWM_DIV );
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER9, DevBoard_3D_CNC_EXTRUDER_X_POS, EXTRUDER9_X_POS);
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER9, DevBoard_3D_CNC_EXTRUDER_Y_POS, EXTRUDER9_Y_POS);

	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER10, DevBoard_3D_CNC_EXTRUDER_PWM_CLK_DIV, EXTRUDER10_PWM_DIV );
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER10, DevBoard_3D_CNC_EXTRUDER_X_POS, EXTRUDER10_X_POS);
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER10, DevBoard_3D_CNC_EXTRUDER_Y_POS, EXTRUDER10_Y_POS);

	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER11, DevBoard_3D_CNC_EXTRUDER_PWM_CLK_DIV, EXTRUDER11_PWM_DIV );
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER11, DevBoard_3D_CNC_EXTRUDER_X_POS, EXTRUDER11_X_POS);
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER11, DevBoard_3D_CNC_EXTRUDER_Y_POS, EXTRUDER11_Y_POS);

	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER12, DevBoard_3D_CNC_EXTRUDER_PWM_CLK_DIV, EXTRUDER12_PWM_DIV );
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER12, DevBoard_3D_CNC_EXTRUDER_X_POS, EXTRUDER12_X_POS);
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER12, DevBoard_3D_CNC_EXTRUDER_Y_POS, EXTRUDER12_Y_POS);

	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER13, DevBoard_3D_CNC_EXTRUDER_PWM_CLK_DIV, EXTRUDER13_PWM_DIV );
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER13, DevBoard_3D_CNC_EXTRUDER_X_POS, EXTRUDER13_X_POS);
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER13, DevBoard_3D_CNC_EXTRUDER_Y_POS, EXTRUDER13_Y_POS);

	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER14, DevBoard_3D_CNC_EXTRUDER_PWM_CLK_DIV, EXTRUDER14_PWM_DIV );
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER14, DevBoard_3D_CNC_EXTRUDER_X_POS, EXTRUDER14_X_POS);
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER14, DevBoard_3D_CNC_EXTRUDER_Y_POS, EXTRUDER14_Y_POS);

	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER15, DevBoard_3D_CNC_EXTRUDER_PWM_CLK_DIV, EXTRUDER15_PWM_DIV );
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER15, DevBoard_3D_CNC_EXTRUDER_X_POS, EXTRUDER15_X_POS);
	IOWR_16DIRECT( base_addr + DevBoard_3D_CNC_EXTRUDER15, DevBoard_3D_CNC_EXTRUDER_Y_POS, EXTRUDER15_Y_POS);

	return 0;
}

static int MotorEncorderSetting( int base_addr )
{
	alt_u8 MotorEncoder = 0;

	/* Motor X Encoder Setting */
	if( MOTOR_X_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_X_OFST ;
	}
	/* Motor Y Encoder Setting */
	if( MOTOR_Y_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_Y_OFST ;
	}
	/* Motor Z Encoder Setting */
	if( MOTOR_Z_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_Z_OFST ;
	}
	IOWR_8DIRECT( base_addr, DevBoard_3D_CNC_ENCODER, MotorEncoder); /* 모터 엔코더 설정 */

	/* Extruder 0 Encoder Setting */
	IOWR_8DIRECT( base_addr, DevBoard_3D_CNC_SELECT_EXTRUDER, 0 );
	MotorEncoder = IORD_8DIRECT ( base_addr, DevBoard_3D_CNC_ENCODER );
	if( MOTOR_E0_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_E_OFST;
	}
	/* Extruder 1 Encoder Setting */
	IOWR_8DIRECT( base_addr, DevBoard_3D_CNC_SELECT_EXTRUDER, 1 );
	MotorEncoder = IORD_8DIRECT ( base_addr, DevBoard_3D_CNC_ENCODER );
	if( MOTOR_E1_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_E_OFST;
	}
	/* Extruder 2 Encoder Setting */
	IOWR_8DIRECT( base_addr, DevBoard_3D_CNC_SELECT_EXTRUDER, 2 );
	MotorEncoder = IORD_8DIRECT ( base_addr, DevBoard_3D_CNC_ENCODER );
	if( MOTOR_E2_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_E_OFST;
	}
	/* Extruder 3 Encoder Setting */
	IOWR_8DIRECT( base_addr, DevBoard_3D_CNC_SELECT_EXTRUDER, 3 );
	MotorEncoder = IORD_8DIRECT ( base_addr, DevBoard_3D_CNC_ENCODER );
	if( MOTOR_E3_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_E_OFST;
	}
	/* Extruder 4 Encoder Setting */
	IOWR_8DIRECT( base_addr, DevBoard_3D_CNC_SELECT_EXTRUDER, 4 );
	MotorEncoder = IORD_8DIRECT ( base_addr, DevBoard_3D_CNC_ENCODER );
	if( MOTOR_E4_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_E_OFST;
	}
	/* Extruder 5 Encoder Setting */
	IOWR_8DIRECT( base_addr, DevBoard_3D_CNC_SELECT_EXTRUDER, 5 );
	MotorEncoder = IORD_8DIRECT ( base_addr, DevBoard_3D_CNC_ENCODER );
	if( MOTOR_E5_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_E_OFST;
	}
	/* Extruder 6 Encoder Setting */
	IOWR_8DIRECT( base_addr, DevBoard_3D_CNC_SELECT_EXTRUDER, 6 );
	MotorEncoder = IORD_8DIRECT ( base_addr, DevBoard_3D_CNC_ENCODER );
	if( MOTOR_E6_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_E_OFST;
	}
	/* Extruder 7 Encoder Setting */
	IOWR_8DIRECT( base_addr, DevBoard_3D_CNC_SELECT_EXTRUDER, 7 );
	MotorEncoder = IORD_8DIRECT ( base_addr, DevBoard_3D_CNC_ENCODER );
	if( MOTOR_E7_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_E_OFST;
	}
	/* Extruder 8 Encoder Setting */
	IOWR_8DIRECT( base_addr, DevBoard_3D_CNC_SELECT_EXTRUDER, 8 );
	MotorEncoder = IORD_8DIRECT ( base_addr, DevBoard_3D_CNC_ENCODER );
	if( MOTOR_E8_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_E_OFST;
	}
	/* Extruder 9 Encoder Setting */
	IOWR_8DIRECT( base_addr, DevBoard_3D_CNC_SELECT_EXTRUDER, 9 );
	MotorEncoder = IORD_8DIRECT ( base_addr, DevBoard_3D_CNC_ENCODER );
	if( MOTOR_E9_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_E_OFST;
	}
	/* Extruder 10 Encoder Setting */
	IOWR_8DIRECT( base_addr, DevBoard_3D_CNC_SELECT_EXTRUDER, 10 );
	MotorEncoder = IORD_8DIRECT ( base_addr, DevBoard_3D_CNC_ENCODER );
	if( MOTOR_E10_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_E_OFST;
	}
	/* Extruder 11 Encoder Setting */
	IOWR_8DIRECT( base_addr, DevBoard_3D_CNC_SELECT_EXTRUDER, 11 );
	MotorEncoder = IORD_8DIRECT ( base_addr, DevBoard_3D_CNC_ENCODER );
	if( MOTOR_E11_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_E_OFST;
	}
	/* Extruder 12 Encoder Setting */
	IOWR_8DIRECT( base_addr, DevBoard_3D_CNC_SELECT_EXTRUDER, 12 );
	MotorEncoder = IORD_8DIRECT ( base_addr, DevBoard_3D_CNC_ENCODER );
	if( MOTOR_E12_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_E_OFST;
	}
	/* Extruder 13 Encoder Setting */
	IOWR_8DIRECT( base_addr, DevBoard_3D_CNC_SELECT_EXTRUDER, 13 );
	MotorEncoder = IORD_8DIRECT ( base_addr, DevBoard_3D_CNC_ENCODER );
	if( MOTOR_E13_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_E_OFST;
	}
	/* Extruder 14 Encoder Setting */
	IOWR_8DIRECT( base_addr, DevBoard_3D_CNC_SELECT_EXTRUDER, 14 );
	MotorEncoder = IORD_8DIRECT ( base_addr, DevBoard_3D_CNC_ENCODER );
	if( MOTOR_E14_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_E_OFST;
	}
	/* Extruder 15 Encoder Setting */
	IOWR_8DIRECT( base_addr, DevBoard_3D_CNC_SELECT_EXTRUDER, 15 );
	MotorEncoder = IORD_8DIRECT ( base_addr, DevBoard_3D_CNC_ENCODER );
	if( MOTOR_E15_ENCODER == TRUE) {
		MotorEncoder |= 1 << DevBoard_3D_CNC_ENCODER_E_OFST;
	}
	return 0;
}

static int CoolingFanSetting( int base_addr )
{
	alt_u8 FlagBit = 0;

	FlagBit = IORD_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + FAN_EXTRUDER_NUM * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG );
	FlagBit |= DevBoard_3D_CNC_EXTRUDER_CONFIG_PWM_ONLY_MSK;
	FlagBit |= DevBoard_3D_CNC_EXTRUDER_CONFIG_PWM_ENABLE_MSK;
	IOWR_8DIRECT( DEVCORE_3D_CNC_BASE + DevBoard_3D_CNC_EXTRUDER0 + FAN_EXTRUDER_NUM * 0x10, DevBoard_3D_CNC_EXTRUDER_CONFIG, FlagBit );

}
//FAN_EXTRUDER_NUM
alt_u16 GetExtruderNum ( int base_addr )
{
    return IORD_8DIRECT( base_addr, DevBoard_3D_CNC_ENCODER );
}

alt_u32 GetExtruderPos ( int base_addr )
{
	return IORD_32DIRECT( base_addr, DevBoard_3D_CNC_EXTRUDER_POS);
}

alt_16 MAX31855TemperatureToHex( int Temperature )
{
	alt_16 ReturnValue = 0;
	double CalcData = 0.0;

	CalcData = (double)Temperature / 0.25;

	ReturnValue = lround( CalcData );

	return ( ReturnValue );
}

double MAX31855HexToTemperature( alt_16 TempValue )
{
	double ReturnValue = 0.0;

	ReturnValue = (double)TempValue * 0.25;

	return ReturnValue;
}
