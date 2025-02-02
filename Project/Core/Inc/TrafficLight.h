/*
 * TrafficLight.h
 *
 *  Created on: Nov 13, 2024
 *      Author: LENOVO
 */

#ifndef INC_TRAFFICLIGHT_H_
#define INC_TRAFFICLIGHT_H_

#include "main.h"
#include "global.h"

void init_trafficlight();
void led_green_red();
void led_yellow_red();
void led_red_yellow();
void led_red_green();

void TogglePinRED();
void TogglePinYELLOW();
void TogglePinGREEN();

#endif /* INC_TRAFFICLIGHT_H_ */
