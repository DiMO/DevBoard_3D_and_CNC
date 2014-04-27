/*
 * lcd.h
 *
 *  Created on: 2014. 3. 24.
 *      Author: dimo
 */

#ifndef LCD_H_
#define LCD_H_

extern int LCD_Display_Open(char *lcd_display);
extern int LCD_Display_TextOut(char *pText);
extern int LCD_Display_Clear(void);
extern void LCD_Display_Close(void);


#endif /* LCD_H_ */
