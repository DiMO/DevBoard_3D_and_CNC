/*
 * gcode_command.h
 *
 *  Created on: 2014. 3. 21.
 *      Author: dimo
 */

#ifndef GCODE_COMMAND_H_
#define GCODE_COMMAND_H_

extern int init_gcode_command(void);
extern int write_gcode_command ( char ch );
extern int PressToEnter(void);

typedef int (*command_function)( char *command_string);

struct command_struct {
	int command_number;
	command_function function;
};

extern struct command_struct g_command_array [];
extern struct command_struct m_command_array [];
extern struct command_struct t_command_array [];
extern struct command_struct k_command_array [];

extern double GetStringToValue_d( char Type, char *StringPos);
extern int GetStringToValue( char Type, char *StringPos);
extern int EndofCommand(void);

extern int ExtruderAbsolute;

#endif /* GCODE_COMMAND_H_ */
