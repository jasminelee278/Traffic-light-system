/*
 * Software_timer.h
 *
 *  Created on: Nov 13, 2024
 *      Author: LENOVO
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

#define TICK 10
extern int timer_flag[10];

void setTimer(int index, int counter);

void timer_run();

int isTimerExpired(int index);

void clearTimer();

#endif /* INC_SOFTWARE_TIMER_H_ */
