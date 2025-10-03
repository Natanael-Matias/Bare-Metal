/**
* File: SysTick.c
* Author: Natanael Matias
* Date: 2025-09-16
*
* # Calculating the RELOAD value
* The RELOAD value can be any value in the range 0x00000001-0x00FFFFFF. A start value of 0 is
* possible, but has no effect because the SysTick exception request and COUNTFLAG are
* activated when counting from 1 to 0.
* The RELOAD value is calculated according to its use. For example, to generate a multi-shot
* timer with a period of N processor clock cycles, use a RELOAD value of N-1. If the SysTick
* interrupt is required every 100 clock pulses, set RELOAD to 99.
*
* When ENABLE is set to 1, the counter loads the RELOAD value from the SYST_RVR register
* and then counts down. On reaching 0, it sets the COUNTFLAG to 1 and optionally asserts the
* SysTick depending on the value of TICKINT. It then loads the RELOAD value again, and
* begins counting.
*/

#include <stdint.h>
#include "SysTick.h"

static uint32_t ticks = 0;

/**
* @brief Configure RELOAD register of SysTick Timer
* @param valueOfTime: Time in [us] for each event.
*/
void SysTickReload(uint32_t valueOfTime) {
	uint32_t valueOfCycles = (16000000U)/(valueOfTime);

	SYST_RVR &= ~(0x00FFFFFF);
	SYST_RVR |= ((valueOfCycles - 1) & 0x00FFFFFF);
}

/**
* @brief
* @param systickConfig: struct pointer containing the values of the bit fields of the SysTick Control and Status Register.
*/

void SysTickInit(SysTickConfig_t* systickConfig) {
	SysTickReload(systickConfig -> valueOfTime);
	SYST_CSR &= ~(0x07);

	systickConfig -> tickint &= SYST_CSR_TICKINT;
	systickConfig -> clksource &= SYST_CSR_CLKSOURCE;
	systickConfig -> enable &= SYST_CSR_ENABLE;

	SYST_CSR |= (systickConfig -> tickint | systickConfig -> clksource);
	SYST_CSR |= systickConfig -> enable;
}

/**
* @brief
* @param
*/
void SysTickConfig(void) {
	SysTickConfig_t systickConf;

	systickConf.clksource = SYST_CSR_CLKSOURCE;
	systickConf.tickint = SYST_CSR_TICKINT;
	systickConf.enable = SYST_CSR_ENABLE;
	systickConf.valueOfTime = 2000; // 500 us

	SysTickInit(&systickConf);
}

uint32_t GetTick(void) {
	return ticks;
}

void UpdateTick(void) {
	ticks++;
}

void SysTick_Handler(void) {
	UpdateTick();
	PENDSVPEND();
}

/**
* @brief
* @param
*/

