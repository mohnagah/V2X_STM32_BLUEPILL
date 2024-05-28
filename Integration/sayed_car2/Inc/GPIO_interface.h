#ifndef _GPIO_INTERFACE_H_
#define _GPIO_INTERFACE_H_

/* Pin values */

typedef enum
{
    GPIO_LOW, 
    GPIO_HIGH
}Gpio_ValueType;

/*  ANOTHER DEFINITION FOR VALUES

#define GPIO_LOW    0
#define GPIO_HIGH   1
*/

/* PORTS */

typedef enum
{
    GPIO_A,
    GPIO_B,
    GPIO_C
}Gpio_PortType;

/*  ANOTHER DEFINITION FOR PORTS
#define GPIOA   0
#define GPIOB   1
#define GPIOC   2
*/

/* PINS */

typedef enum
{
    PIN0, 
    PIN1, 
    PIN2,
    PIN3, 
    PIN4, 
    PIN5, 
    PIN6, 
    PIN7, 
    PIN8, 
    PIN9, 
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15
}Gpio_PinType;

/*  ANOTHER DEFINITION FOR PINS
#define PIN0    0 
#define PIN1    1 
#define PIN2    2 
#define PIN3    3 
#define PIN4    4 
#define PIN5    5 
#define PIN6    6 
#define PIN7    7 
#define PIN8    8 
#define PIN9    9 
#define PIN10   10
#define PIN11   11
#define PIN12   12
#define PIN13   13
#define PIN14   14
#define PIN15   15

*/

/* Pin Modes 
PP -> (Push Pull)
OD -> (Open Drain)
AFPP -> (Alternative Function Push Pull)
AFOD -> (Alternative Function Open Drain)
*/
#define INPUT_ANALOG                0b0000
#define INPUT_FLOATING              0b0100
#define INPUT_PULL_UP_DOWN          0b1000


#define OUTPUT_SPEED_10MHZ_PP        0b0001
#define OUTPUT_SPEED_10MHZ_OD        0b0101
#define OUTPUT_SPEED_10MHZ_AFPP      0b1001
#define OUTPUT_SPEED_10MHZ_AFOD      0b1101

#define OUTPUT_SPEED_2MHZ_PP         0b0010
#define OUTPUT_SPEED_2MHZ_OD         0b0110
#define OUTPUT_SPEED_2MHZ_AFPP       0b1010
#define OUTPUT_SPEED_2MHZ_AFOD       0b1110

#define OUTPUT_SPEED_50MHZ_PP        0b0011
#define OUTPUT_SPEED_50MHZ_OD        0b0111
#define OUTPUT_SPEED_50MHZ_AFPP      0b1011
#define OUTPUT_SPEED_50MHZ_AFOD      0b1111



void MGPIO_voidSetPinMode(Gpio_PortType Copy_u8Port, Gpio_PinType Copy_u8Pin, u8 Copy_u8Mode);
void MGPIO_voidSetPinValue(Gpio_PortType Copy_u8Port, Gpio_PinType Copy_u8Pin, Gpio_ValueType Copy_u8Value);
u8 MGPIO_u8GetPinValue(Gpio_PortType Copy_u8Port, Gpio_PinType Copy_u8Pin);
Gpio_ValueType Gpio_FlipPinLevel(Gpio_PortType port, Gpio_PinType pin);
Gpio_ValueType Gpio_ReadPinLevel (Gpio_PortType port, Gpio_PinType pin);

#endif
