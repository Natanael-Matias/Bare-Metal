/*
 * main.h
 *
 *  Created on: Sep 17, 2025
 *      Author: Natanael.matias
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>

//semihosting init function
extern void initialise_monitor_handles(void);

void IdleHandler(void);
void Task1Handler(void);
void Task2Handler(void);
void Task3Handler(void);
void Task4Handler(void);


#endif /* MAIN_H_ */
