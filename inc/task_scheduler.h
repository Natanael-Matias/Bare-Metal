/*
 * task_scheduler.h
 *
 *  Created on: Sep 26, 2025
 *      Author: Natanael.matias
 */

#ifndef TASK_SCHEDULER_H_
#define TASK_SCHEDULER_H_

#include <stdint.h>

#define INTERUPT_DISABLE()		do{ __asm volatile("CPSID I");	}while(0)
#define INTERRUPT_ENABLE()		do{ __asm volatile("CPSIE I");	}while(0)

#define		SHCSR			*((volatile uint32_t*) 0xE000ED24) //System Handler Control and State Register
#define		MEMFAULTENA		(1 << 16)	// MemManage enable bit
#define 	BUSFAULTENA		(1 << 17)	// BusFault enable bit
#define 	USGFAULTENA		(1 << 18)	// UsageFault enable bit

#define NUM_TASKS			4//5

// stack memory calculations
#define SIZE_TASK_STACK			1024U
#define SIZE_SCHED_STACK		SIZE_TASK_STACK

#define SRAM_START				0x20000000UL
#define SIZE_SRAM				(128 * 1024)
#define SRAM_END				((SRAM_START) + (SIZE_SRAM))

#define T1_STACK_START			SRAM_END
#define T2_STACK_START			((T1_STACK_START) - (SIZE_TASK_STACK))
#define T3_STACK_START			((T2_STACK_START) - (SIZE_TASK_STACK))
#define T4_STACK_START			((T3_STACK_START) - (SIZE_TASK_STACK))
#define IDLE_STACK_START		((T4_STACK_START) - (SIZE_TASK_STACK))
#define SCHED_STACK_START		((IDLE_STACK_START) - (SIZE_TASK_STACK))

typedef enum{
	running,
	blocked
} taskStatus_t;

typedef struct {
	uint32_t taskStackAddr;
	uint32_t tickCount;
	taskStatus_t taskStatus;
	void (*TaskHandler)(void);
}Task_t;

void TaskWait(uint32_t time_ms);
void InitTasksStack(void);
uint32_t GetPSPValue(void);
void UpdateNextTask(void);
void SavePSP(uint32_t pspCurrentValue);
void AppInit(Task_t* tasksArray);
void AppStart(void);
__attribute__((naked)) void InitSchedulerStack(uint32_t schedStackAddr);
__attribute__((naked)) void SwitchToPSP(void);
__attribute__ ((naked)) void PendSV_Handler(void);

#endif /* TASK_SCHEDULER_H_ */
