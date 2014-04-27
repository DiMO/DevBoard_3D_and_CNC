/*
 * main.c
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
#include "system.h"
#include "../inc/configure.h"
#include "../inc/gcode_command.h"
#include "../inc/buffer_operation.h"
#include "../inc/lcd.h"
#include "../inc/DevBoard_3D_CNC.h"

int	gcode_uart = (int)NULL;

double HomeFeedRate_X = MOTOR_X_FEEDRATE_HOME;
double HomeFeedRate_Y = MOTOR_Y_FEEDRATE_HOME;
double HomeFeedRate_Z = MOTOR_Z_FEEDRATE_HOME;
double HomeFeedRate_E[16] = {
		MOTOR_E0_FEEDRATE_HOME, MOTOR_E1_FEEDRATE_HOME, MOTOR_E2_FEEDRATE_HOME, MOTOR_E3_FEEDRATE_HOME,
		MOTOR_E4_FEEDRATE_HOME, MOTOR_E5_FEEDRATE_HOME, MOTOR_E6_FEEDRATE_HOME, MOTOR_E7_FEEDRATE_HOME,
		MOTOR_E8_FEEDRATE_HOME, MOTOR_E9_FEEDRATE_HOME, MOTOR_E10_FEEDRATE_HOME, MOTOR_E11_FEEDRATE_HOME,
		MOTOR_E12_FEEDRATE_HOME, MOTOR_E13_FEEDRATE_HOME, MOTOR_E14_FEEDRATE_HOME, MOTOR_E15_FEEDRATE_HOME,
};

double MaxFeedRate_X = MOTOR_X_FEEDRATE;
double MaxFeedRate_Y = MOTOR_Y_FEEDRATE;
double MaxFeedRate_Z = MOTOR_Z_FEEDRATE;
double MaxFeedRate_E[16] = {
		MOTOR_E0_FEEDRATE, MOTOR_E1_FEEDRATE, MOTOR_E2_FEEDRATE, MOTOR_E3_FEEDRATE,
		MOTOR_E4_FEEDRATE, MOTOR_E5_FEEDRATE, MOTOR_E6_FEEDRATE, MOTOR_E7_FEEDRATE,
		MOTOR_E8_FEEDRATE, MOTOR_E9_FEEDRATE, MOTOR_E10_FEEDRATE, MOTOR_E11_FEEDRATE,
		MOTOR_E12_FEEDRATE, MOTOR_E13_FEEDRATE, MOTOR_E14_FEEDRATE, MOTOR_E15_FEEDRATE,
};

double MotorUnit_X = MOTOR_X_UNIT;
double MotorUnit_Y = MOTOR_Y_UNIT;
double MotorUnit_Z = MOTOR_Z_UNIT;
double MotorUnit_E[16] = {
		MOTOR_E0_UNIT, MOTOR_E1_UNIT, MOTOR_E2_UNIT, MOTOR_E3_UNIT,
		MOTOR_E4_UNIT, MOTOR_E5_UNIT, MOTOR_E6_UNIT, MOTOR_E7_UNIT,
		MOTOR_E8_UNIT, MOTOR_E9_UNIT, MOTOR_E10_UNIT, MOTOR_E11_UNIT,
		MOTOR_E12_UNIT, MOTOR_E13_UNIT, MOTOR_E14_UNIT, MOTOR_E15_UNIT,
};



int main()
{
    //RegGcodeUart(); /* RS232C 포트를 등록하고 해당 정보를 받을 수 있는 설정을 한다. */
    DevBoard_3D_CNC_init( DEVCORE_3D_CNC_BASE ); /* DevBoard IP Init */
    buffer_init( BUFFER_CONTROL_NAME ); /* DevBoard Buffer Init */
	init_gcode_command();

    LCD_Display_Open( LCD_DISPLAY_NAME);
    /*                    123456789012345  12345678901234   */
    LCD_Display_TextOut( "Open 3D Printer\nDimoCore Corp.\n");

    gcode_uart = open( GCODE_UART_NAME, O_RDWR | O_NOCTTY );

    if( gcode_uart != -1 ) {
		while(1) {
			alt_u8 ch = 0;
			read( gcode_uart, &ch, 1);
			//write( gcode_uart, &ch, 1);
			//printf("%c, %d, ", ch, ch);
			switch( ch ) {
				case '\r' :
				case '\n' : {
					write( gcode_uart, "\r\n", 2);
					printf("\n");
					PressToEnter();
					break;
				}
				default : {
					write( gcode_uart, &ch, 1 );
					printf("%c", ch);
					write_gcode_command( ch );
					break;
				}
			}
		}
    } else {
    	printf( "Gcode UART Open Error !!!\n");
    }

    return 0;
}




