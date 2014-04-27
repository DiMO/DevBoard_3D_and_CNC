/*
 * configure.h
 *
 *  Created on: 2014. 3. 21.
 *      Author: dimo
 */

#ifndef CONFIGURE_H_
#define CONFIGURE_H_

#define GCODE_BAUD_RATE				GCODE_UART_BAUD
#define GCODE_IRQ					GCODE_UART_IRQ
#define GCODE_BASE					GCODE_UART_BASE

#define GCODE_RX_BUFFER_SIZE 		256
#define GCODE_TX_BUFFER_SIZE 		256

#define GCODE_MAX_COMMAND_SIZE		512

//#if !defined(NULL)
#define NULL						((void*)0)
//#endif

#define TRUE						1
#define FALSE						0

/* Error Code */
#define DEFAULT_ERROR				-1
#define NO_ERROR					0

#define GCODE_COMMAND_BUFFER_FULL	101

#define MOTOR_X_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */
#define MOTOR_Y_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */
#define MOTOR_Z_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */
#define MOTOR_E0_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */
#define MOTOR_E1_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */
#define MOTOR_E2_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */
#define MOTOR_E3_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */
#define MOTOR_E4_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */
#define MOTOR_E5_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */
#define MOTOR_E6_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */
#define MOTOR_E7_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */
#define MOTOR_E8_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */
#define MOTOR_E9_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */
#define MOTOR_E10_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */
#define MOTOR_E11_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */
#define MOTOR_E12_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */
#define MOTOR_E13_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */
#define MOTOR_E14_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */
#define MOTOR_E15_UNIT				(10.0) /* 1mm를 가는 데 필요한 텝수 */

#define MOTOR_X_FEEDRATE			(500.0) /* 최대 이송 속도 */
#define MOTOR_Y_FEEDRATE			(500.0) /* 최대 이송 속도 */
#define MOTOR_Z_FEEDRATE			(5.0)   /* 최대 이송 속도 */
#define MOTOR_E0_FEEDRATE			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E1_FEEDRATE			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E2_FEEDRATE			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E3_FEEDRATE			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E4_FEEDRATE			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E5_FEEDRATE			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E6_FEEDRATE			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E7_FEEDRATE			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E8_FEEDRATE			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E9_FEEDRATE			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E10_FEEDRATE			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E11_FEEDRATE			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E12_FEEDRATE			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E13_FEEDRATE			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E14_FEEDRATE			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E15_FEEDRATE			(25.0)  /* 최대 이송 속도 */

#define MOTOR_X_FEEDRATE_HOME			(500.0) /* 최대 이송 속도 */
#define MOTOR_Y_FEEDRATE_HOME			(500.0) /* 최대 이송 속도 */
#define MOTOR_Z_FEEDRATE_HOME			(5.0)   /* 최대 이송 속도 */
#define MOTOR_E0_FEEDRATE_HOME			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E1_FEEDRATE_HOME			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E2_FEEDRATE_HOME			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E3_FEEDRATE_HOME			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E4_FEEDRATE_HOME			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E5_FEEDRATE_HOME			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E6_FEEDRATE_HOME			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E7_FEEDRATE_HOME			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E8_FEEDRATE_HOME			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E9_FEEDRATE_HOME			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E10_FEEDRATE_HOME			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E11_FEEDRATE_HOME			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E12_FEEDRATE_HOME			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E13_FEEDRATE_HOME			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E14_FEEDRATE_HOME			(25.0)  /* 최대 이송 속도 */
#define MOTOR_E15_FEEDRATE_HOME			(25.0)  /* 최대 이송 속도 */

#define MOTOR_X_ENCODER				(FALSE) /* False = 엔코어 없음 */
#define MOTOR_Y_ENCODER				(FALSE)
#define MOTOR_Z_ENCODER				(FALSE)
#define MOTOR_E0_ENCODER			(FALSE)
#define MOTOR_E1_ENCODER			(FALSE)
#define MOTOR_E2_ENCODER			(FALSE)
#define MOTOR_E3_ENCODER			(FALSE)
#define MOTOR_E4_ENCODER			(FALSE)
#define MOTOR_E5_ENCODER			(FALSE)
#define MOTOR_E6_ENCODER			(FALSE)
#define MOTOR_E7_ENCODER			(FALSE)
#define MOTOR_E8_ENCODER			(FALSE)
#define MOTOR_E9_ENCODER			(FALSE)
#define MOTOR_E10_ENCODER			(FALSE)
#define MOTOR_E11_ENCODER			(FALSE)
#define MOTOR_E12_ENCODER			(FALSE)
#define MOTOR_E13_ENCODER			(FALSE)
#define MOTOR_E14_ENCODER			(FALSE)
#define MOTOR_E15_ENCODER			(FALSE)

#define EXTRUDER0_X_POS				((0) * MOTOR_X_UNIT ) /* Write to mm */
#define EXTRUDER0_Y_POS				((0) * MOTOR_Y_UNIT ) /* Write to mm */

#define EXTRUDER1_X_POS				((0) * MOTOR_X_UNIT ) /* Write to mm */
#define EXTRUDER1_Y_POS				((0) * MOTOR_Y_UNIT ) /* Write to mm */

#define EXTRUDER2_X_POS				((0) * MOTOR_X_UNIT ) /* Write to mm */
#define EXTRUDER2_Y_POS				((0) * MOTOR_Y_UNIT ) /* Write to mm */

#define EXTRUDER3_X_POS				((0) * MOTOR_X_UNIT ) /* Write to mm */
#define EXTRUDER3_Y_POS				((0) * MOTOR_Y_UNIT ) /* Write to mm */

#define EXTRUDER4_X_POS				((0) * MOTOR_X_UNIT ) /* Write to mm */
#define EXTRUDER4_Y_POS				((0) * MOTOR_Y_UNIT ) /* Write to mm */

#define EXTRUDER5_X_POS				((0) * MOTOR_X_UNIT ) /* Write to mm */
#define EXTRUDER5_Y_POS				((0) * MOTOR_Y_UNIT ) /* Write to mm */

#define EXTRUDER6_X_POS				((0) * MOTOR_X_UNIT ) /* Write to mm */
#define EXTRUDER6_Y_POS				((0) * MOTOR_Y_UNIT ) /* Write to mm */

#define EXTRUDER7_X_POS				((0) * MOTOR_X_UNIT ) /* Write to mm */
#define EXTRUDER7_Y_POS				((0) * MOTOR_Y_UNIT ) /* Write to mm */

#define EXTRUDER8_X_POS				((0) * MOTOR_X_UNIT ) /* Write to mm */
#define EXTRUDER8_Y_POS				((0) * MOTOR_Y_UNIT ) /* Write to mm */

#define EXTRUDER9_X_POS				((0) * MOTOR_X_UNIT ) /* Write to mm */
#define EXTRUDER9_Y_POS				((0) * MOTOR_Y_UNIT ) /* Write to mm */

#define EXTRUDER10_X_POS			((0) * MOTOR_X_UNIT ) /* Write to mm */
#define EXTRUDER10_Y_POS			((0) * MOTOR_Y_UNIT ) /* Write to mm */

#define EXTRUDER11_X_POS			((0) * MOTOR_X_UNIT ) /* Write to mm */
#define EXTRUDER11_Y_POS			((0) * MOTOR_Y_UNIT ) /* Write to mm */

#define EXTRUDER12_X_POS			((0) * MOTOR_X_UNIT ) /* Write to mm */
#define EXTRUDER12_Y_POS			((0) * MOTOR_Y_UNIT ) /* Write to mm */

#define EXTRUDER13_X_POS			((0) * MOTOR_X_UNIT ) /* Write to mm */
#define EXTRUDER13_Y_POS			((0) * MOTOR_Y_UNIT ) /* Write to mm */

#define EXTRUDER14_X_POS			((0) * MOTOR_X_UNIT ) /* Write to mm */
#define EXTRUDER14_Y_POS			((0) * MOTOR_Y_UNIT ) /* Write to mm */

#define EXTRUDER15_X_POS			((0) * MOTOR_X_UNIT ) /* Write to mm */
#define EXTRUDER15_Y_POS			((0) * MOTOR_Y_UNIT ) /* Write to mm */

#define EXTRUDER0_PWM_DIV			( 10 )
#define EXTRUDER1_PWM_DIV			( 10 )
#define EXTRUDER2_PWM_DIV			( 10 )
#define EXTRUDER3_PWM_DIV			( 10 )
#define EXTRUDER4_PWM_DIV			( 10 )
#define EXTRUDER5_PWM_DIV			( 10 )
#define EXTRUDER6_PWM_DIV			( 10 )
#define EXTRUDER7_PWM_DIV			( 10 )
#define EXTRUDER8_PWM_DIV			( 10 )
#define EXTRUDER9_PWM_DIV			( 10 )
#define EXTRUDER10_PWM_DIV			( 10 )
#define EXTRUDER11_PWM_DIV			( 10 )
#define EXTRUDER12_PWM_DIV			( 10 )
#define EXTRUDER13_PWM_DIV			( 10 )
#define EXTRUDER14_PWM_DIV			( 10 )
#define EXTRUDER15_PWM_DIV			( 10 )

#define BED_EXTRUDER_NUM			15
#define CHAMBER_EXTERUDER_NUM		14
#define FAN_EXTRUDER_NUM 			13

extern int	gcode_uart;

extern double HomeFeedRate_X;
extern double HomeFeedRate_Y;
extern double HomeFeedRate_Z;
extern double HomeFeedRate_E[16];

extern double MaxFeedRate_X;
extern double MaxFeedRate_Y;
extern double MaxFeedRate_Z;
extern double MaxFeedRate_E[16];

extern double MotorUnit_X;
extern double MotorUnit_Y;
extern double MotorUnit_Z;
extern double MotorUnit_E[16];

#endif /* CONFIGURE_H_ */
