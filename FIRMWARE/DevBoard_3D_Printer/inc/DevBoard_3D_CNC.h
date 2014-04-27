/*
 * DevBoard_3D_CNC.h
 *
 *  Created on: 2014. 3. 31.
 *      Author: dimo
 */

#ifndef DEVBOARD_3D_CNC_H_
#define DEVBOARD_3D_CNC_H_

#define DevBoard_3D_CNC_MOTOR_CLOCK				50000000 /* ( Hz ) 입력 */
#define DevBoard_3D_CNC_PWM_CLOCK				50000000 /* ( Hz ) 입력 */

#define DevBoard_3D_CNC_RUNNING 				(0x000)
#define DevBoard_3D_CNC_RUNNING_X_MSK			(0x01)
#define DevBoard_3D_CNC_RUNNING_X_OFST			(0)
#define DevBoard_3D_CNC_RUNNING_Y_MSK			(0x04)
#define DevBoard_3D_CNC_RUNNING_Y_OFST			(2)
#define DevBoard_3D_CNC_RUNNING_Z_MSK			(0x10)
#define DevBoard_3D_CNC_RUNNING_Z_OFST			(4)
#define DevBoard_3D_CNC_RUNNING_E_MSK			(0x40)
#define DevBoard_3D_CNC_RUNNING_E_OFST			(6)

#define DevBoard_3D_CNC_STATUS					(0x001)
#define DevBoard_3D_CNC_STATUS_X_MSK			(0x01)
#define DevBoard_3D_CNC_STATUS_X_OFST			(0)
#define DevBoard_3D_CNC_STATUS_Y_MSK			(0x04)
#define DevBoard_3D_CNC_STATUS_Y_OFST			(2)
#define DevBoard_3D_CNC_STATUS_Z_MSK			(0x10)
#define DevBoard_3D_CNC_STATUS_Z_OFST			(4)
#define DevBoard_3D_CNC_STATUS_E_MSK			(0x40)
#define DevBoard_3D_CNC_STATUS_E_OFST			(6)

#define DevBoard_3D_CNC_ENCODER					(0x002)
#define DevBoard_3D_CNC_ENCODER_X_MSK			(0x01)
#define DevBoard_3D_CNC_ENCODER_X_OFST			(1)
#define DevBoard_3D_CNC_ENCODER_Y_MSK			(0x04)
#define DevBoard_3D_CNC_ENCODER_Y_OFST			(2)
#define DevBoard_3D_CNC_ENCODER_Z_MSK			(0x10)
#define DevBoard_3D_CNC_ENCODER_Z_OFST			(4)
#define DevBoard_3D_CNC_ENCODER_E_MSK			(0x40)
#define DevBoard_3D_CNC_ENCODER_E_OFST			(6)

#define DevBoard_3D_CNC_MOVE_ZERO				(0x003)
#define DevBoard_3D_CNC_MOVE_ZERO_X_MSK			(0x01)
#define DevBoard_3D_CNC_MOVE_ZERO_X_OFST		(1)
#define DevBoard_3D_CNC_MOVE_ZERO_Y_MSK			(0x04)
#define DevBoard_3D_CNC_MOVE_ZERO_Y_OFST		(2)
#define DevBoard_3D_CNC_MOVE_ZERO_Z_MSK			(0x10)
#define DevBoard_3D_CNC_MOVE_ZERO_Z_OFST		(4)
#define DevBoard_3D_CNC_MOVE_ZERO_E_MSK			(0x40)
#define DevBoard_3D_CNC_MOVE_ZERO_E_OFST		(6)

#define DevBoard_3D_CNC_MOVE_MAX				(0x004)
#define DevBoard_3D_CNC_MOVE_MAX_X_MSK			(0x01)
#define DevBoard_3D_CNC_MOVE_MAX_X_OFST			(0)
#define DevBoard_3D_CNC_MOVE_MAX_Y_MSK			(0x04)
#define DevBoard_3D_CNC_MOVE_MAX_Y_OFST			(2)
#define DevBoard_3D_CNC_MOVE_MAX_Z_MSK			(0x10)
#define DevBoard_3D_CNC_MOVE_MAX_Z_OFST			(4)
#define DevBoard_3D_CNC_MOVE_MAX_E_MSK			(0x40)
#define DevBoard_3D_CNC_MOVE_MAX_E_OFST			(6)

#define DevBoard_3D_CNC_SELECT_EXTRUDER			(0x005)
#define DevBoard_3D_CNC_SELECT_EXTRUDER_MSK		(0x0F)

#define DevBoard_3D_CNC_EXTRUDER_MOVE			(0x006) /* Write Only */
#define DevBoard_3D_CNC_EXTRUDER_POS			(0x006) /* Read Only */
#define DevBoard_3D_CNC_MOTOR_CLK_DIV_X			(0x00A)
#define DevBoard_3D_CNC_MOTOR_CLK_DIV_Y			(0x00C)
#define DevBoard_3D_CNC_MOTOR_CLK_DIV_Z			(0x00E)

#define DevBoard_3D_CNC_MOTOR_MOVE_X			(0x010)
#define DevBoard_3D_CNC_MOTOR_PREPOS_X			(0x014)
#define DevBoard_3D_CNC_MOTOR_MOVE_X_MAX		(0x018)
#define DevBoard_3D_CNC_MOTOR_CURRENT_POS_X		(0x01C)

#define DevBoard_3D_CNC_MOTOR_MOVE_Y			(0x020)
#define DevBoard_3D_CNC_MOTOR_PREPOS_Y			(0x024)
#define DevBoard_3D_CNC_MOTOR_MOVE_Y_MAX		(0x028)
#define DevBoard_3D_CNC_MOTOR_CURRENT_POS_Y		(0x02C)

#define DevBoard_3D_CNC_MOTOR_MOVE_Z			(0x030)
#define DevBoard_3D_CNC_MOTOR_PREPOS_Z			(0x034)
#define DevBoard_3D_CNC_MOTOR_MOVE_Z_MAX		(0x038)
#define DevBoard_3D_CNC_MOTOR_CURRENT_POS_Z		(0x03C)


/* Exteruder Part Configure */

#define DevBoard_3D_CNC_EXTRUDER_PWM_VALUE		(0x0)
#define DevBoard_3D_CNC_EXTRUDER_CURR_TEMP		(0x2)
#define DevBoard_3D_CNC_EXTRUDER_MOTOR_CLK_DIV	(0x4)
#define DevBoard_3D_CNC_EXTRUDER_PWM_CLK_DIV	(0x6)
#define DevBoard_3D_CNC_EXTRUDER_SET_TEMP		(0x8)

#define DevBoard_3D_CNC_EXTRUDER_CONFIG							(0xA)
#define DevBoard_3D_CNC_EXTRUDER_CONFIG_PWM_ENABLE_MSK			(0x01)
#define DevBoard_3D_CNC_EXTRUDER_CONFIG_PWM_ENABLE_OFST			(0)
#define DevBoard_3D_CNC_EXTRUDER_CONFIG_FAST_PWM_MSK			(0x02)
#define DevBoard_3D_CNC_EXTRUDER_CONFIG_FAST_PWM_OFST			(1)
#define DevBoard_3D_CNC_EXTRUDER_CONFIG_PWM_ONLY_MSK			(0x04)
#define DevBoard_3D_CNC_EXTRUDER_CONFIG_PWM_ONLY_OFST			(2)
#define DevBoard_3D_CNC_EXTRUDER_CONFIG_OUTPUT_TEMP_SEL_MSK		(0x08)
#define DevBoard_3D_CNC_EXTRUDER_CONFIG_OUTPUT_TEMP_SEL_OFST	(3)
#define DevBoard_3D_CNC_EXTRUDER_CONFIG_SENSOR_OPEN_MSK			(0x10)
#define DevBoard_3D_CNC_EXTRUDER_CONFIG_SENSOR_OPEN_OFST		(4)
#define DevBoard_3D_CNC_EXTRUDER_CONFIG_SENSOR_GND_MSK			(0x20)
#define DevBoard_3D_CNC_EXTRUDER_CONFIG_SENSOR_GND_OFST			(5)
#define DevBoard_3D_CNC_EXTRUDER_CONFIG_SENSOR_VCC_MSK			(0x40)
#define DevBoard_3D_CNC_EXTRUDER_CONFIG_SENSOR_VCC_OFST			(6)
#define DevBoard_3D_CNC_EXTRUDER_CONFIG_TEMP_FAULT_MSK			(0x80)
#define DevBoard_3D_CNC_EXTRUDER_CONFIG_TEMP_FAULT_OFST			(7)

#define DevBoard_3D_CNC_EXTRUDER_X_POS			(0xC)
#define DevBoard_3D_CNC_EXTRUDER_Y_POS			(0xE)

#define DevBoard_3D_CNC_EXTRUDER0				(0x100)
#define DevBoard_3D_CNC_EXTRUDER1				(0x110)
#define DevBoard_3D_CNC_EXTRUDER2				(0x120)
#define DevBoard_3D_CNC_EXTRUDER3				(0x130)
#define DevBoard_3D_CNC_EXTRUDER4				(0x140)
#define DevBoard_3D_CNC_EXTRUDER5				(0x150)
#define DevBoard_3D_CNC_EXTRUDER6				(0x160)
#define DevBoard_3D_CNC_EXTRUDER7				(0x170)
#define DevBoard_3D_CNC_EXTRUDER8				(0x180)
#define DevBoard_3D_CNC_EXTRUDER9				(0x190)
#define DevBoard_3D_CNC_EXTRUDER10				(0x1A0)
#define DevBoard_3D_CNC_EXTRUDER11				(0x1B0)
#define DevBoard_3D_CNC_EXTRUDER12				(0x1C0)
#define DevBoard_3D_CNC_EXTRUDER13				(0x1D0)
#define DevBoard_3D_CNC_EXTRUDER14				(0x1E0)
#define DevBoard_3D_CNC_EXTRUDER15				(0x1F0)

extern int DevBoard_3D_CNC_init ( int base_addr );
extern alt_u16 GetExtruderNum ( int base_addr );
extern alt_u32 GetExtruderPos ( int base_addr );
extern alt_16 MAX31855TemperatureToHex( int Temperature );
extern double MAX31855HexToTemperature( alt_16 TempValue );

#endif /* DEVBOARD_3D_CNC_H_ */
