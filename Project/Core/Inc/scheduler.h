/*
 * scheduler.h
 *
 *  Created on: Nov 29, 2024
 *      Author: LENOVO
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "stdint.h"
# define SCH_MAX_TASKS 40
# define NO_TASK_ID 0
typedef struct {
	void(*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskID;
}sTask;

void SCH_Init(void);
void SCH_Update(void);
unsigned char SCH_Add_Task(void(*pFunction)(), unsigned int DELAY, unsigned int PERIOD);
void SCH_Dispatch_Tasks(void);
unsigned char SCH_Delete_Task(const int TASK_INDEX);

#endif /* INC_SCHEDULER_H_ */
