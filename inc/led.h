#include <stdint.h>

#define __IO                volatile
#define NUM_GPIO            9 // A - I

typedef enum {
	PIN_0 = 0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15
} LED_Pin_t;

typedef enum {
	PORTA = 0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
	PORTG,
	PORTH,
	PORTI
}LED_Port_t;

typedef enum {
    ANODE_COMMON,
    CATHODE_COMMON
} LED_Comm_t;

typedef enum {
    LED_ON,
    LED_OFF
} LED_State_t;

typedef struct {
    LED_Port_t      port;
    LED_Pin_t       pin;
    LED_Comm_t      connetion;
    LED_State_t     state;

} LED_Config_t;

typedef struct LED_t{
    LED_Config_t config;
    void (*On)(struct LED_t*);
    void (*Off)(struct LED_t*);
} LED_t;

void LedInit(LED_t* ledConfig);
void LedOn(LED_t* led);
void LedOff(LED_t* led);
