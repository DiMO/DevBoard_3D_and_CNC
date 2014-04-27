/*
 * buffer_operation.h
 *
 *  Created on: 2014. 4. 8.
 *      Author: dimo
 */

#ifndef BUFFER_OPERATION_H_
#define BUFFER_OPERATION_H_

extern int buffer_init( char *DeviceName );
extern int buffer_command_g1( alt_u8 AxisType, double DataX, double DataY, double DataZ, double DataE, double FeedRate, alt_8 SelectTool );
extern int buffer_command_g2( alt_u8 AxisType, double DataX, double DataY, double DataZ, double DataI, double DataJ, double DataE, double FeedRate, alt_8 SelectTool );
extern int buffer_command_g3( alt_u8 AxisType, double DataX, double DataY, double DataZ, double DataI, double DataJ, double DataE, double FeedRate, alt_8 SelectTool );
extern int buffer_command_g28( alt_u8 AxisType, double PreX, double PreY, double PreZ, double FeedRate );
extern int buffer_command_t( alt_u8 ToolNum );

#endif /* BUFFER_OPERATION_H_ */
