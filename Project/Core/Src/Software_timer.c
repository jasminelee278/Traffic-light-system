/*
 * Software_timer.c
 *
 *  Created on: Nov 13, 2024
 *      Author: LENOVO
 */

#include "Software_timer.h"

int timerCounter[10];
int timer_flag[10];

void setTimer(int index, int counter){
	timerCounter[index]=counter/TICK;
	timer_flag[index]=0;
}
void clearTimer(){
	for(int i=0;i<10;i++){
	timerCounter[i]=0;
	timer_flag[i]=0;
	}
}
void timer_run(){
	for(int i=0;i<10;i++){
		if(timerCounter[i]>=0){
			timerCounter[i]--;
			if(timerCounter[i]<=0){
				timer_flag[i]=1;
			}
		}
	}
}
int isTimerExpired(int index){
	if(timer_flag[index]==1){
		timer_flag[index]=0;
		return 1;
	}
	else
	return 0;
}
