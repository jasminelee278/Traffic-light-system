/*
 * scheduler.c
 *
 *  Created on: Nov 29, 2024
 *      Author: LENOVO
 */


#include "scheduler.h"
#include "main.h"

sTask SCH_tasks_G[SCH_MAX_TASKS];
int task_count = 0;

void SCH_Init(void){
    unsigned char i;
    for (i = 0; i < SCH_MAX_TASKS; i++){
        SCH_Delete_Task(i);
    }
}
unsigned char SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD){
	int prev;
	if(task_count >= SCH_MAX_TASKS){
		return 0;
	}
	for(prev = 0; prev < task_count; prev++){
		if(DELAY < SCH_tasks_G[prev].Delay)
			break;
		DELAY -= SCH_tasks_G[prev].Delay;
	}
	for (int i = task_count; i >prev; i--){
		SCH_tasks_G[i] = SCH_tasks_G[i - 1];
	}
	SCH_tasks_G[prev].pTask = pFunction;
	SCH_tasks_G[prev].Delay = DELAY;
	SCH_tasks_G[prev].Period = PERIOD;
	SCH_tasks_G[prev].RunMe = 0;
    SCH_tasks_G[prev].TaskID = prev;
	task_count++;
	if(prev + 1 < task_count + 1){
		SCH_tasks_G[prev + 1].Delay -= DELAY;
	}
	return prev;
}
void SCH_Update(void){
    if (SCH_tasks_G[0].pTask){
        if (SCH_tasks_G[0].Delay == 0){
            SCH_tasks_G[0].RunMe++;
            if (SCH_tasks_G[0].Period){
                SCH_tasks_G[0].Delay = SCH_tasks_G[0].Period;
            }
        }else{
            SCH_tasks_G[0].Delay--;
        }
    }
}
void SCH_Dispatch_Tasks(void){
    if (SCH_tasks_G[0].RunMe > 0){
    	SCH_tasks_G[0].RunMe -= 1;
        (*SCH_tasks_G[0].pTask)();
        if (SCH_tasks_G[0].Period == 0){
            SCH_Delete_Task(0);
        }else{
            sTask temp = SCH_tasks_G[0];
            SCH_Delete_Task(0);
            SCH_Add_Task(temp.pTask, temp.Delay, temp.Period);
        }
    }
}
unsigned char SCH_Delete_Task(const int TASK_INDEX){
	if (TASK_INDEX != task_count- 1){
		for (int i = TASK_INDEX; i < task_count - 1; i++){
			SCH_tasks_G[i] = SCH_tasks_G[i + 1];
			SCH_tasks_G[i].TaskID = i;
		}
	}
	SCH_tasks_G[task_count - 1].pTask = 0x0000;
	SCH_tasks_G[task_count - 1].Delay = 0;
	SCH_tasks_G[task_count - 1].Period = 0;
	SCH_tasks_G[task_count - 1].RunMe = 0;
	SCH_tasks_G[task_count - 1].TaskID = NO_TASK_ID;
	task_count--;
	return 0;
}
