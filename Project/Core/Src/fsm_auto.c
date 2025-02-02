/*
 * fsm_auto.c
 *
 *  Created on: Nov 13, 2024
 *      Author: LENOVO
 */

/*
 * fsm_auto.c
 *
 *  Created on: Oct 24, 2024
 *      Author: LENOVO
 */
#include "fsm_auto.h"
void counter_1s(){
	time_counter_1--;
	time_counter_2--;
}
void fsm_auto_run(){
	isButtonPressed(1);
	switch(status){
		case INIT:
			if(1){
				mode=0;
				status = GREEN_RED;
				time_counter_1=duration_green/1000;
				time_counter_2=duration_red/1000;
				setting_time = duration_red/1000;
				lcd_clear_display();
			}
			break;
		case GREEN_RED:
			mode=0;
			updateBufferLcd_run();
			led_green_red();
			if(time_counter_1==0){
				time_counter_1=duration_yellow/1000;
				time_counter_2=duration_yellow/1000;
				status = YELLOW_RED;
			}
			if(isButtonLongPressed(0)){
				mode=1;
				init_trafficlight();
				status = WAIT;
				modee = MODIFY_RED;
				lcd_clear_display();
				time_counter_1=1;
				time_counter_2=1;
			}
			if(isButtonPressed(0)){
				mode=4;
				laststatus=status;
				status = WAIT;
				time_counter_1=0;
				time_counter_2=0;
				lcd_clear_display();
			}
			break;
		case YELLOW_RED:
			mode=0;
			updateBufferLcd_run();
			led_yellow_red();
			if(time_counter_1==0){
				time_counter_1=duration_red/1000;
				time_counter_2=duration_green/1000;
				status = RED_GREEN;
			}
			if(isButtonLongPressed(0)==1){
				mode=1;
				init_trafficlight();
				status=WAIT;
				modee = MODIFY_RED;
				lcd_clear_display();
				time_counter_1=1;
				time_counter_2=1;
			}
			if(isButtonPressed(0)==1){
				mode=4;
				laststatus=status;
				status = WAIT;
				time_counter_1=2;
				time_counter_2=0;
				lcd_clear_display();
			}
			break;
		case RED_GREEN:
			mode=0;
			updateBufferLcd_run();
			led_red_green();
			if(time_counter_2==0){
				time_counter_2=duration_yellow/1000;
				time_counter_1=duration_yellow/1000;
				status = RED_YELLOW;
			}
			if(isButtonLongPressed(0)==1){
				mode=1;
				init_trafficlight();
				status=WAIT;
				modee = MODIFY_RED;
				lcd_clear_display();
				time_counter_1=1;
								time_counter_2=1;
			}
			if(isButtonPressed(0)==1){
				mode=4;
				laststatus=status;
				status = WAIT;
				time_counter_1=0;
				time_counter_2=0;
				lcd_clear_display();
			}
			break;
		case RED_YELLOW:
			mode=0;
			updateBufferLcd_run();
			led_red_yellow();
			if(time_counter_2==0){
				status = GREEN_RED;
				time_counter_1= duration_green/1000;
				time_counter_2=duration_red/1000;
			}
			if(isButtonLongPressed(0)==1){
				mode=1;
				init_trafficlight();
				status=WAIT;
				lcd_clear_display();
				time_counter_1=1;
								time_counter_2=1;
			}
			if(isButtonPressed(0)==1){
				mode=4;
				laststatus=status;
				status = WAIT;
				time_counter_1=0;
				time_counter_2=2;
				lcd_clear_display();
			}
			break;
		case WAIT:

			break;

	}
}
