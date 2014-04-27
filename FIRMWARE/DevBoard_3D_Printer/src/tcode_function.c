/*
 * tcode_command.c
 *
 *  Created on: 2014. 3. 31.
 *      Author: dimo
 */

/*
 * gcode_function.c
 *
 *  Created on: 2014. 3. 21.
 *      Author: dimo
 */

#include <stdio.h>
#include <string.h>
#include <alt_types.h>
#include "system.h"
#include "../inc/configure.h"
#include "../inc/DevBoard_3D_CNC.h"
#include "../inc/gcode_command.h"
#include "../inc/buffer_operation.h"

static int t0_command( char *command_string);
static int t1_command( char *command_string);
static int t2_command( char *command_string);
static int t3_command( char *command_string);
static int t4_command( char *command_string);
static int t5_command( char *command_string);
static int t6_command( char *command_string);
static int t7_command( char *command_string);
static int t8_command( char *command_string);
static int t9_command( char *command_string);
static int t10_command( char *command_string);
static int t11_command( char *command_string);
static int t12_command( char *command_string);
static int t13_command( char *command_string);
static int t14_command( char *command_string);
static int t15_command( char *command_string);


struct command_struct t_command_array [] = {
		{    0, t0_command },
		{    1, t1_command },
		{    2, t2_command },
		{    3, t3_command },
		{    4, t4_command },
		{    5, t5_command },
		{    6, t6_command },
		{    7, t7_command },
		{    8, t8_command },
		{    9, t9_command },
		{   10, t10_command },
		{   11, t11_command },
		{   12, t12_command },
		{   13, t13_command },
		{   14, t14_command },
		{   15, t15_command },
		{ NULL, NULL }
};

static int t0_command( char *command_string)
{
	return buffer_command_t(0);
}
static int t1_command( char *command_string)
{
	return buffer_command_t(1);
}
static int t2_command( char *command_string)
{
	return buffer_command_t(2);
}
static int t3_command( char *command_string)
{
	return buffer_command_t(3);
}
static int t4_command( char *command_string)
{
	return buffer_command_t(4);
}
static int t5_command( char *command_string)
{
	return buffer_command_t(5);
}
static int t6_command( char *command_string)
{
	return buffer_command_t(6);
}
static int t7_command( char *command_string)
{
	return buffer_command_t(7);
}
static int t8_command( char *command_string)
{
	return buffer_command_t(8);
}
static int t9_command( char *command_string)
{
	return buffer_command_t(9);
}
static int t10_command( char *command_string)
{
	return buffer_command_t(10);
}
static int t11_command( char *command_string)
{
	return buffer_command_t(11);
}
static int t12_command( char *command_string)
{
	return buffer_command_t(12);
}
static int t13_command( char *command_string)
{
	return buffer_command_t(13);
}
static int t14_command( char *command_string)
{
	return buffer_command_t(14);
}
static int t15_command( char *command_string)
{
	return buffer_command_t(15);
}




