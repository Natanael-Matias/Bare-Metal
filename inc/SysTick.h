/*
 * SysTick.h
 *
 *  Created on: Sep 16, 2025
 *  Author: Natanael.matias
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#define SYST_CSR		*((volatile uint32_t*) 0xE000E010UL)
#define SYST_RVR		*((volatile uint32_t*) 0xE000E014UL)


#define SYST_CSR_ENABLE		0x01 // 0 = counter disabled 1 = counter enabled.
#define SYST_CSR_TICKINT	0x02 // 0 = counting down to zero does not assert the SysTick exception request 1 = counting down to zero asserts the SysTick exception request.
#define SYST_CSR_CLKSOURCE 	0x04 // 0 = external clock 1 = processor clock.

#define ICSR					*((volatile uint32_t*) 0xE000ED04UL)
#define PENDSVSET				(0x01 << 28) // changes PendSV exception state to pending.

#define PENDSVPEND()			(ICSR |= PENDSVSET)

/**
 * @brief This struct configures the bit fields of the SysTick Control and Status Register. Each value must be loaded with
 * 			the corresponding macro value. For 0 value, use the 1's complement (~) of the macro.
 */
typedef struct{
	uint8_t 	enable;
	uint8_t 	tickint;
	uint8_t		clksource;
	uint32_t	valueOfTime;
} SysTickConfig_t;

void SysTickReload(uint32_t valueOfTime);
void SysTickInit(SysTickConfig_t* systickConfig);
void SysTick_Handler(void);
void SysTickConfig(void);
void UpdateTick(void);
uint32_t GetTick(void);


#endif /* SYSTICK_H_ */
