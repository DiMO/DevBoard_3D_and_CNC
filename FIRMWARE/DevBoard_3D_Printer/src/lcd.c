/*
 * lcd.c
 *
 *  Created on: 2014. 3. 24.
 *      Author: dimo
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <alt_types.h>
#include <io.h>
#include "system.h"
#include "../inc/configure.h"
#include "../inc/lcd.h"

// (\b): Move the cursor to the left by one character
// (\r): Move the cursor to the start of the current line
// (\n): Move the cursor to the start of the line and move it donw one line

static FILE *lcd_fp=0;

int LCD_Display_Open(char *lcd_display){
	lcd_fp = fopen(lcd_display, "w");
    if (lcd_fp)
        return TRUE;
    return FALSE;
}
int LCD_Display_TextOut(char *pText){
    if (!lcd_fp)
        return FALSE;
    fwrite(pText, strlen(pText), 1, lcd_fp);
    return TRUE;
}

int LCD_Display_Clear(void){
    char szText[32]="\n\n";
    if (!lcd_fp)
        return FALSE;
    fwrite(szText, strlen(szText), 1, lcd_fp);
    return TRUE;
}


void LCD_Display_Close(void){
    if (lcd_fp)
        fclose(lcd_fp);
    lcd_fp = NULL;
}
