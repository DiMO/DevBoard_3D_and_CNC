/*
 * gcode_command.c
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

int gcode_command_index = 0;
char gcode_command_buffer[GCODE_MAX_COMMAND_SIZE];

static int g_command_running( int command_number, char *string );
static int m_command_running( int command_number, char *string );
static int t_command_running( int command_number, char *string );
static int k_command_running( int command_number, char *string );

int init_gcode_command(void)
{
	int index = 0;
	int ReturnValue = -1;

	for( index = 0 ; index < GCODE_MAX_COMMAND_SIZE ; index = index + 1 ) {
		gcode_command_buffer[index] = 0;
	}
	ReturnValue = 0;

	return ReturnValue;
}

int write_gcode_command ( char ch )
{
	int ReturnValue = DEFAULT_ERROR;

	if( gcode_command_index < GCODE_MAX_COMMAND_SIZE ) {
		switch( ch ) {
		    case 0x08 : {
		    	gcode_command_index--;
		    	gcode_command_buffer[gcode_command_index] = NULL;
		    	break;
		    }
		    default : {
				gcode_command_buffer[gcode_command_index] = toupper(ch);
				gcode_command_index++;

				ReturnValue = NO_ERROR;
				break;
		    }
		}

	} else {
		gcode_command_buffer[gcode_command_index] = (char)NULL;

		ReturnValue = GCODE_COMMAND_BUFFER_FULL;
	}
	return ReturnValue;
}

int PressToEnter(void)
{
	int ReturnValue = -1;

	if( gcode_command_index != 0) {
		char command_type = 0;
		int command_number = 0;

	    gcode_command_buffer[gcode_command_index] = 0;

		if( strchr( (char *)&gcode_command_buffer[1], ';') != NULL ) {
			char *next_string_pos = NULL;

			next_string_pos = strchr( (char *)&gcode_command_buffer[1], ';' );
			*(next_string_pos) = NULL;
		}

	    sscanf( (char *)&gcode_command_buffer[0], "%c%d ", &command_type, &command_number);

	    switch( command_type) {
	        case 'G' : {
	        	char *next_string_pos = NULL;

	        	next_string_pos = strchr( (char *)&gcode_command_buffer[0], 'G');
	        	next_string_pos = strchr( next_string_pos, ' ');

	        	ReturnValue = g_command_running( command_number, ( next_string_pos + 1));
	        	break;
	        }
	        case 'T' : {
	        	char *next_string_pos = NULL;

	        	next_string_pos = strchr( (char *)&gcode_command_buffer[0], 'T');
	        	next_string_pos = strchr( next_string_pos, ' ');

	        	ReturnValue = t_command_running( command_number, ( next_string_pos + 1));
	        	break;
	        }
	        case 'K' : {
	        	char *next_string_pos = NULL;

	        	next_string_pos = strchr( (char *)&gcode_command_buffer[0], 'K');
	        	next_string_pos = strchr( next_string_pos, ' ');

	        	ReturnValue = k_command_running( command_number, ( next_string_pos + 1));
	        	break;
	        }
	        case 'M' : {
	        	char *next_string_pos = NULL;

	        	next_string_pos = strchr( (char *)&gcode_command_buffer[0], 'M');
	        	next_string_pos = strchr( next_string_pos, ' ');

	        	ReturnValue = m_command_running( command_number, ( next_string_pos + 1));
	        	break;
	        }
	        case ';' : {
	        	static char *OutputString = "ok\n\r";

	        	printf( OutputString );
	            write( gcode_uart, OutputString, strlen( OutputString ) );
	            ReturnValue = 0;
	        	break;
	        }
	        default : {
	        	break;
	        }
	    }
	    if( ReturnValue == -1 ) {
	    	static char *OutputString = "Unknown Command or Not Supported !!!\n\rok\n\r";

	    	printf( OutputString );
	    	write( gcode_uart, OutputString, strlen( OutputString ) );
	    }
	    memset( gcode_command_buffer, 0, GCODE_MAX_COMMAND_SIZE);
	    gcode_command_index = 0;
	}
	return ReturnValue;
}

static int g_command_running( int command_number, char *string )
{
	int ReturnValue = -1;

	if( string != NULL ) {
		int loop_index = 0;

		while ( g_command_array[loop_index].function != NULL ) {
			if( g_command_array[loop_index].command_number == command_number ) {
				ReturnValue = g_command_array[loop_index].function( string );
				break;
			} else {
				loop_index = loop_index + 1;
			}
		}
	}
	return ReturnValue;
}

static int m_command_running( int command_number, char *string )
{
	int ReturnValue = -1;

	if( string != NULL ) {
		int loop_index = 0;

		while ( m_command_array[loop_index].function != NULL ) {
			if( m_command_array[loop_index].command_number == command_number ) {
				ReturnValue = m_command_array[loop_index].function( string );
				break;
			} else {
				loop_index = loop_index + 1;
			}
		}
	}
	return ReturnValue;
}

static int t_command_running( int command_number, char *string )
{
	int ReturnValue = -1;

	if( string != NULL ) {
		int loop_index = 0;

		while ( t_command_array[loop_index].function != NULL ) {
			if( t_command_array[loop_index].command_number == command_number ) {
				ReturnValue = t_command_array[loop_index].function( string );
				break;
			} else {
				loop_index = loop_index + 1;
			}
		}
	}
	return ReturnValue;
}

static int k_command_running( int command_number, char *string )
{
	int ReturnValue = -1;

	if( string != NULL ) {
		int loop_index = 0;

		while ( k_command_array[loop_index].function != NULL ) {
			if( k_command_array[loop_index].command_number == command_number ) {
				ReturnValue = k_command_array[loop_index].function( string );
				break;
			} else {
				loop_index = loop_index + 1;
			}
		}
	}
	return ReturnValue;
}

double GetStringToValue_d( char Type, char *StringPos)
{
	double ReturnValue = 0.0;

	if( StringPos != NULL ) {
		char *ConvertPos = NULL;

		ConvertPos = strchr( StringPos, Type) + 1;
		ReturnValue = strtod( ConvertPos, NULL);
	}
	return ReturnValue;
}

int GetStringToValue( char Type, char *StringPos)
{
	int ReturnValue = 0.0;

	if( StringPos != NULL ) {
		char *ConvertPos = NULL;

		ConvertPos = strchr( StringPos, Type) + 1;
		ReturnValue = strtol( ConvertPos, (char **)NULL, 10);
	}
	return ReturnValue;
}

int EndofCommand(void)
{
	char *OutputString = "\n\rok\n\r";
	printf( OutputString );
	write( gcode_uart, OutputString, strlen( OutputString ) );
	return 0;
}
