/*
 * i2c-lcd.h
 *
 *  Created on: Nov 11, 2024
 *      Author: LENOVO
 */

#ifndef INC_I2C_LCD_H_
#define INC_I2C_LCD_H_

#include "main.h"

void lcd_init (void);   // initialize lcd

void lcd_send_cmd (char cmd);  // send command to the lcd

void lcd_send_data (char data);  // send data to the lcd

void lcd_send_string (char *str);  // send string to the lcd

void lcd_clear_display (void);	//clear display lcd

void lcd_goto_XY (int row, int col); //set proper location on screen

#endif /* INC_I2C_LCD_H_ */
