#include <stdint.h>
#include <stdio.h>
#include "main.h"
#include "SysTick.h"
#include "led.h"
#include "task_scheduler.h"


Task_t tasks[NUM_TASKS] = {
		{T1_STACK_START, 0, running, Task1Handler},
		{T2_STACK_START, 0, running, Task2Handler},
		{T3_STACK_START, 0, running, Task3Handler},
		{IDLE_STACK_START, 0, running, IdleHandler}
};

LED_t led1;
LED_t led2;

int main(void)
{
	
	led1.config.port = PORTG;
	led1.config.pin = PIN_13;
	led1.config.state = LED_OFF;
	led1.config.connetion = CATHODE_COMMON;

	LedInit(&led1);

	led2.config.port = PORTG;
	led2.config.pin = PIN_14;
	led2.config.state = LED_OFF;
	led2.config.connetion = CATHODE_COMMON;

	LedInit(&led2);

	AppInit(tasks);
	AppStart();

    /* Loop forever */
	for(;;);
}



void Task1Handler(void){
	while(1){
		led1.On(&led1);
		TaskWait(1000);
		led1.Off(&led1);
		TaskWait(1000);
	}
}

void Task2Handler(void){
	while(1){
		led2.On(&led2);
		TaskWait(500);
		led2.Off(&led2);
		TaskWait(500);
	}
}

void Task3Handler(void){
	while(1){
		if(!led1.config.state)
			printf("Led 1 is on.\n");
		if(!led2.config.state)
			printf("Led 2 is on.\n");
		TaskWait(500);
	}
}

void Task4Handler(void){
	while(1){

	}
}

void IdleHandler(void){
	for(;;);
}

void HardFault_Handler(void){
	while(1);
}

void UsageFault_Handler(void) {
	while(1);
}

void MemManage_Handler(void) {
	while(1);
}

void BusFault_Handler(void) {
	while(1);
}

