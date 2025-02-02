/*
 * fsm_setting.c
 *
 *  Created on: Nov 13, 2024
 *      Author: LENOVO
 */


/*
 * fsm_manual.c
 *
 *  Created on: Oct 28, 2024
 *      Author: LENOVO
 */

#include <fsm_setting.h>
void fsm_setting_run(){
	switch(modee){
	case MODIFY_RED:
		updateBufferLcd_run();
		if(time_counter_1==0){
			time_counter_1=1;
			TogglePinRED();
		}
		if(isButtonPressed(0)){
			mode=2;
			modee = MODIFY_YELLOW;
			init_trafficlight();
			setting_time = duration_yellow/1000;
			lcd_clear_display();
		}
		if(isButtonPressed(1)){
			setting_time = (setting_time+1)%100;
			if(setting_time==0){
				setting_time=1;
			}
		}
		if(isButtonLongPressed(0)){
			init_trafficlight();
			duration_green = setting_time*1000 - duration_yellow;
			duration_red = setting_time*1000;
			status = INIT;
			modee=WAIT;
		}
		break;
	case MODIFY_YELLOW:
		updateBufferLcd_run();
		if(time_counter_1==0){
			time_counter_1=1;
			TogglePinYELLOW();
		}
		if(isButtonPressed(0)){
			mode=3;
			modee = MODIFY_GREEN;
			init_trafficlight();
			setting_time = duration_green/1000;
			lcd_clear_display();
		}
		if(isButtonPressed(1)){
			setting_time = (setting_time+1)%100;
			if(setting_time==0){
				setting_time=1;
			}
		}
		if(isButtonLongPressed(0)){
			init_trafficlight();
			duration_yellow = setting_time*1000;
			duration_red = setting_time*1000 + duration_green;
			status = INIT;
			modee=WAIT;
		}
		break;
	case MODIFY_GREEN:
		updateBufferLcd_run();
		if(time_counter_1==0){
			time_counter_1=1;
			TogglePinGREEN();
		}
		if(isButtonPressed(0)){
			mode=1;
			modee = MODIFY_RED;
			init_trafficlight();
			setting_time = duration_red/1000;
			lcd_clear_display();
		}
		if(isButtonPressed(1)){
			setting_time = (setting_time+1)%100;
			if(setting_time==0){
				setting_time=1;
			}
		}
		if(isButtonLongPressed(0)){
			init_trafficlight();
			duration_red = setting_time*1000 + duration_yellow;
			duration_green = setting_time*1000;
			status = INIT;
			modee=WAIT;
		}
		break;
	case WAIT:
		break;
	}
}

