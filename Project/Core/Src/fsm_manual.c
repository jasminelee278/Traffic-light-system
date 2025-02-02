/*
 * fsm_manual.c
 *
 *  Created on: Nov 13, 2024
 *      Author: LENOVO
 */

/*
 * fsm_manual.c
 *
 *  Created on: Nov 1, 2024
 *      Author: LENOVO
 */


#include "fsm_manual.h"

void fsm_manual_run(){
	switch(laststatus){
		case GREEN_RED:
			updateBufferLcd_run();
			led_green_red();
			if(isButtonPressed(1)==1){
				status=laststatus;
				laststatus=WAIT;
				mode=0;
				setTimer(0, duration_green);
				setTimer(2, 1000);
				time_counter_1=duration_green/1000;
				time_counter_2=duration_red/1000;
				setting_time = duration_red/1000;
			}
			if(isButtonPressed(0)){
				setTimer(0, duration_yellow);
				setTimer(2, 1000);
				time_counter_1=duration_yellow/1000;
				laststatus = YELLOW_RED;
				time_counter_1=duration_yellow/1000;
				time_counter_2=0;
			}
			break;
		case YELLOW_RED:
			updateBufferLcd_run();
			led_yellow_red();
			if(isTimerExpired(0)==1){
				clearTimer();
				laststatus = RED_GREEN;
				time_counter_1=0;
				time_counter_2=0;
			}
			if(isTimerExpired(2)){
				setTimer(2, 1000);
				time_counter_1--;
			}
			if(isButtonPressed(1)){
				status=laststatus;
				laststatus=WAIT;
				mode=0;
				setTimer(0, duration_yellow);
				setTimer(2, 1000);
				time_counter_1=duration_yellow/1000;
				time_counter_2=duration_yellow/1000;
				setting_time = duration_red/1000;
			}
			break;
		case RED_GREEN:
			updateBufferLcd_run();
			led_red_green();
			if(isButtonPressed(0)){
				setTimer(0, duration_yellow);
				setTimer(2, 1000);
				time_counter_2=duration_yellow/1000;
				laststatus = RED_YELLOW;
				time_counter_1=0;
				time_counter_2=duration_yellow/1000;
			}
			if(isButtonPressed(1)==1){
				status=laststatus;
				laststatus=WAIT;
				mode=0;
				setTimer(0, duration_green);
				setTimer(2, 1000);
				time_counter_1=duration_red/1000;
				time_counter_2=duration_green/1000;
				setting_time = duration_red/1000;
			}
			break;
		case RED_YELLOW:
			updateBufferLcd_run();
			led_red_yellow();
			if(isTimerExpired(0)){
				clearTimer();
				laststatus = GREEN_RED;
				time_counter_1=0;
				time_counter_2=0;
			}
			if(isTimerExpired(2)){
				setTimer(2, 1000);
				time_counter_2--;
			}
			if(isButtonPressed(1)){
				status=laststatus;
				laststatus=WAIT;
				mode=0;
				setTimer(0, duration_yellow);
				setTimer(2, 1000);
				time_counter_1=duration_yellow/1000;
				time_counter_2=duration_yellow/1000;
				setting_time = duration_red/1000;
			}
			break;
		case WAIT:
			break;
	}
}



