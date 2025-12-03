/*
 * task_scheduler.c
 *
 *  Created on: Sep 26, 2025
 *      Author: Natanael.matias
 */
#include <stdint.h>
#include <stdio.h>
#include "task_scheduler.h"
#include "SysTick.h"

static uint8_t currentTask = 0;
static Task_t* tasks;

void AppInit(Task_t* tasksArray) {
	initialise_monitor_handles();

	tasks = tasksArray;
	// Enable processor faults
	SHCSR |= (USGFAULTENA | BUSFAULTENA | MEMFAULTENA);

	InitSchedulerStack(SCHED_STACK_START);
	InitTasksStack();
	SysTickConfig();

	// Switch SP to PSP before call the first task
	SwitchToPSP();
	printf("Start program...\n");
}

void AppStart(void){
	(*tasks).TaskHandler();
}

void TaskWait(uint32_t time_ms) {
	INTERUPT_DISABLE();
	tasks[currentTask].tickCount = GetTick() + (time_ms * 2);
	PENDSVPEND();
	INTERRUPT_ENABLE();
}

void InitTasksStack(void){
	uint32_t* pPSP;
	for(int i = 0; i < NUM_TASKS; i++){
		pPSP = (uint32_t*) tasks[i].taskStackAddr;
		*(--pPSP) = 0x01000000; // xPSR
		*(--pPSP) = (uint32_t) tasks[i].TaskHandler; //PC
		*(--pPSP) = 0xFFFFFFFD; //LR
		for(int j = 0; j < 13; j++){
			*(--pPSP) = 0x00; // R0 - R12 = 0
		}
		tasks[i].taskStackAddr = (uint32_t) pPSP;
	}
}

__attribute__((naked)) void InitSchedulerStack(uint32_t schedStackAddr){
	__asm volatile("MSR MSP,R0");
	__asm volatile("BX LR");
}

uint32_t GetPSPValue(void){
	for(int i = 0; i < NUM_TASKS-1; i++)
		if (tasks[i].taskStatus == running){
			currentTask = i;
			return tasks[currentTask].taskStackAddr;
		}
	currentTask = NUM_TASKS-1;
	return tasks[currentTask].taskStackAddr;
}

__attribute__((naked)) void SwitchToPSP(void){
	//1. Initialize the PSP with TASK1 stack start
	__asm volatile("PUSH {LR}"); //Preserve LR which connects back to main()
	__asm volatile("BL GetPSPValue");
	__asm volatile("MSR PSP,R0"); //Initialize PSP
	__asm volatile("POP {LR}"); //Pops back LR value

	//2. Change SP to PSP using control register
	__asm volatile("MOV R0, #0x02");
	__asm volatile("MSR CONTROL, R0");

	__asm volatile("BX LR");
}

void SavePSP(uint32_t pspCurrentValue){
	tasks[currentTask].taskStackAddr = pspCurrentValue;
}

void UpdateNextTask(void){
	uint32_t tick = GetTick();
	for(int i = 0; i < NUM_TASKS-1; i++){
		tasks[i].taskStatus = tick < tasks[i].tickCount ? blocked : running;
		if(!tasks[i].taskStatus)
			tasks[i].tickCount = 0;
	}
}

__attribute__ ((naked)) void PendSV_Handler(void) {
	__asm volatile("MRS R0, PSP");
	__asm volatile("STMDB R0!, {R4-R11}");
	__asm volatile("PUSH {LR}");
	__asm volatile("BL SavePSP");

	__asm volatile("BL UpdateNextTask");
	__asm volatile("BL GetPSPValue");
	__asm volatile("LDMIA R0!, {R4-R11}");
	__asm volatile("MSR PSP, R0");
	__asm volatile("POP {LR}");
	__asm volatile("BX LR");
}
