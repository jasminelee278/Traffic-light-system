/*
 * global.h
 *
 *  Created on: Nov 13, 2024
 *      Author: LENOVO
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "Software_timer.h"
#include "Button.h"
#include "scheduler.h"

#define INIT 0
#define GREEN_RED 1
#define YELLOW_RED 2
#define RED_GREEN 3
#define RED_YELLOW 4
#define WAIT 5

#define MODIFY_RED 6
#define MODIFY_YELLOW 7
#define MODIFY_GREEN 8

#define MODE 0
#define MODIFY 1
#define SET 2

extern int mode;
extern int modee;

extern int status;
extern int laststatus;

extern int time_counter_1;
extern int time_counter_2;
extern int setting_time;

extern int duration_red;
extern int duration_yellow;
extern int duration_green;

#endif /* INC_GLOBAL_H_ */
