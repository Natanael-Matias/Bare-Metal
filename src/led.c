#include "led.h"

#define AHB1_ADDR_BASE      0x40020000UL
#define GPIOA_OFFSET        0x0000U
#define GPIOB_OFFSET        0x0400U
#define GPIOC_OFFSET        0x0800U
#define GPIOD_OFFSET        0x0C00U
#define GPIOE_OFFSET        0x1000U
#define GPIOF_OFFSET        0x1400U
#define GPIOG_OFFSET        0x1800U
#define GPIOH_OFFSET        0x1C00U
#define GPIOI_OFFSET        0x2000U

#define RCC_OFFSET          0x3800U
#define AHB1ENR_OFFSET      0x0030U
#define RCC_BASE_ADDR		((AHB1_ADDR_BASE) + (RCC_OFFSET))
#define AHB1ENR_ADDR        ((RCC_BASE_ADDR) + (AHB1ENR_OFFSET))
#define AHB1ENR             *((volatile uint32_t*) (AHB1ENR_ADDR))

typedef struct {
	__IO uint32_t MODER;
	__IO uint32_t OTYPER;
	__IO uint32_t OSPEEDR;
	__IO uint32_t PUPDR;
	__IO uint32_t IDR;
	__IO uint32_t ODR;
	__IO uint32_t BSRR;
	__IO uint32_t LCKR;
	__IO uint32_t AFR[2];
}GPIO_Reg_t;

#define GPIO_PARTA      ((GPIO_Reg_t*) ((AHB1_ADDR_BASE) + (GPIOA_OFFSET)))
#define GPIO_PARTB      ((GPIO_Reg_t*) ((AHB1_ADDR_BASE) + (GPIOB_OFFSET)))
#define GPIO_PARTC      ((GPIO_Reg_t*) ((AHB1_ADDR_BASE) + (GPIOC_OFFSET)))
#define GPIO_PARTD      ((GPIO_Reg_t*) ((AHB1_ADDR_BASE) + (GPIOD_OFFSET)))
#define GPIO_PARTE      ((GPIO_Reg_t*) ((AHB1_ADDR_BASE) + (GPIOE_OFFSET)))
#define GPIO_PARTF      ((GPIO_Reg_t*) ((AHB1_ADDR_BASE) + (GPIOF_OFFSET)))
#define GPIO_PARTG      ((GPIO_Reg_t*) ((AHB1_ADDR_BASE) + (GPIOG_OFFSET)))
#define GPIO_PARTH      ((GPIO_Reg_t*) ((AHB1_ADDR_BASE) + (GPIOH_OFFSET)))
#define GPIO_PARTI      ((GPIO_Reg_t*) ((AHB1_ADDR_BASE) + (GPIOI_OFFSET)))

static GPIO_Reg_t* port[NUM_GPIO] = {
                                GPIO_PARTA,
                                GPIO_PARTB,
                                GPIO_PARTC,
                                GPIO_PARTD,
                                GPIO_PARTE,
                                GPIO_PARTF,
                                GPIO_PARTG,
                                GPIO_PARTH,
                                GPIO_PARTI
                            };

void LedInit(LED_t* ledConfig) {
    AHB1ENR |= (0x01 << ledConfig->config.port);

    // MODER
    port[ledConfig->config.port]->MODER &= ~((0x03U) << (ledConfig->config.pin * 2));
    port[ledConfig->config.port]->MODER |=  ( 0x01U  << (ledConfig->config.pin * 2)); // output mode

    // OTYPER
    port[ledConfig->config.port]->OTYPER &= ~((0x01U) << ledConfig->config.pin);
    port[ledConfig->config.port]->OTYPER |=  ((0x00U) << ledConfig->config.pin); // output push-pull

    // OSPEEDR
    port[ledConfig->config.port]->OSPEEDR &= ~((0x03U) << (ledConfig->config.pin * 2));
    port[ledConfig->config.port]->OSPEEDR |=  ((0x00U) << (ledConfig->config.pin * 2)); // Low speed

    // PUPDR
    port[ledConfig->config.port]->PUPDR &= ~((0x03U) << (ledConfig->config.pin * 2));
    port[ledConfig->config.port]->PUPDR |=  ((0x00U) << (ledConfig->config.pin * 2)); // No pull-ip, pull-down

    ledConfig->On = LedOn;
    ledConfig->Off = LedOff;  
}

void LedOn(LED_t* led){
    led->config.state = LED_ON;
    if(led->config.connetion == ANODE_COMMON){
        port[led->config.port]->ODR &= ~((0x01) << led->config.pin);
        return;
    }
    port[led->config.port]->ODR |=  ((0x01) << led->config.pin);
}

void LedOff(LED_t* led){
    led->config.state = LED_OFF;
    if(led->config.connetion == ANODE_COMMON){
        port[led->config.port]->ODR |=  ((0x01) << led->config.pin);
        return;
    }
    port[led->config.port]->ODR &= ~((0x01) << led->config.pin);
}
