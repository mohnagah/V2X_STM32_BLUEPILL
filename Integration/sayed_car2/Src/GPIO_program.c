#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"

/*Function to set the direction*/
void MGPIO_voidSetPinMode(Gpio_PortType Copy_u8Port, Gpio_PinType Copy_u8Pin, u8 Copy_u8Mode)
{
    if(Copy_u8Pin <= 15)  /* Check if the pin from 0 to 15 (all pins at the register) */
    {
        switch (Copy_u8Port)  /* Switch to find the port i want */
        {
        case GPIO_A: /* Writing on the Port A*/
            if(Copy_u8Pin <= 7) /* Check if the pin from 0 to 7 (Because it's the CRL (low)) */
            {
                GPIOA_CRL &= ~((0b1111) << (Copy_u8Pin * 4)); /* RESET the 4 BITS of the pin before using to make sure there is nothing on it*/
                GPIOA_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4)); /* Writing on the register the mode i want */
            }
            else if(Copy_u8Pin <= 15) /* Check if the pin from 8 to 15 (Because it's the CRH (High)) */
            {
                Copy_u8Pin -= 8; /* to make sure it will write at the right pin because if i say (15*4 = 60) so i did that to make sure it's right */
                GPIOA_CRH &= ~((0b1111) << (Copy_u8Pin * 4)); /* RESET the 4 BITS of the pin before using to make sure there is nothing on it*/
                GPIOA_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4)); /* Writing on the register the mode i want */
            }
            break;
        case GPIO_B: /* Writing on the Port B*/
            if(Copy_u8Pin <= 7) /* Check if the pin from 0 to 7 (Because it's the CRL (low)) */
            {
                GPIOB_CRL &= ~((0b1111) << (Copy_u8Pin * 4)); /* RESET the 4 BITS of the pin before using to make sure there is nothing on it*/
                GPIOB_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4)); /* Writing on the register the mode i want */
            }
            else if(Copy_u8Pin <= 15) /* Check if the pin from 8 to 15 (Because it's the CRH (High)) */
            {
                Copy_u8Pin -= 8; /* to make sure it will write at the right pin because if i say (15*4 = 60) so i did that to make sure it's right */
                GPIOB_CRH &= ~((0b1111) << (Copy_u8Pin * 4)); /* RESET the 4 BITS of the pin before using to make sure there is nothing on it*/
                GPIOB_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4)); /* Writing on the register the mode i want */
            }
            break;
        case GPIO_C: /* Writing on the Port C*/
            if(Copy_u8Pin <= 7) /* Check if the pin from 0 to 7 (Because it's the CRL (low)) */
            {
                GPIOC_CRL &= ~((0b1111) << (Copy_u8Pin * 4)); /* RESET the 4 BITS of the pin before using to make sure there is nothing on it*/
                GPIOC_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4)); /* Writing on the register the mode i want */
            }
            else if(Copy_u8Pin <= 15) /* Check if the pin from 8 to 15 (Because it's the CRH (High)) */
            {
                Copy_u8Pin -= 8; /* to make sure it will write at the right pin because if i say (15*4 = 60) so i did that to make sure it's right */
                GPIOC_CRH &= ~((0b1111) << (Copy_u8Pin * 4)); /* RESET the 4 BITS of the pin before using to make sure there is nothing on it*/
                GPIOC_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4)); /* Writing on the register the mode i want */
            }
            break;
        
        default:
            break;
        }
    }
    else
    {
        /* Invalid pin number error */
    }
}

void MGPIO_voidSetPinValue(Gpio_PortType Copy_u8Port, Gpio_PinType Copy_u8Pin, Gpio_ValueType Copy_u8Value)
{
    if(Copy_u8Pin <= 15)  /* Check if the pin from 0 to 15 (all pins at the register) */
    {
        switch (Copy_u8Port)  /* Switch to find the port i want */
        {
        case GPIO_A: /* Writing on the Port A*/
            if(Copy_u8Value == GPIO_HIGH) /* Check if the pin value HIGI */
            {
                SET_BIT(GPIOA_ODR, Copy_u8Pin); /* Setting the pin */
            }
            else if(Copy_u8Value == GPIO_LOW) /* Check if the pin value LOW */
            {
                CLR_BIT(GPIOA_ODR, Copy_u8Pin); /* Clearing the pin */
            }
            break;
        case GPIO_B: /* Writing on the Port B*/
            if(Copy_u8Value == GPIO_HIGH) /* Check if the pin value HIGI */
            {
                SET_BIT(GPIOB_ODR, Copy_u8Pin); /* Setting the pin */
            }
            else if(Copy_u8Value == GPIO_LOW) /* Check if the pin value LOW */
            {
                CLR_BIT(GPIOB_ODR, Copy_u8Pin); /* Clearing the pin */
            }
            break;
        case GPIO_C: /* Writing on the Port C*/
            if(Copy_u8Value == GPIO_HIGH) /* Check if the pin value HIGI */
            {
                SET_BIT(GPIOC_ODR, Copy_u8Pin); /* Setting the pin */
            }
            else if(Copy_u8Value == GPIO_LOW) /* Check if the pin value LOW */
            {
                CLR_BIT(GPIOC_ODR, Copy_u8Pin); /* Clearing the pin */
            }
            break;
        
        default:
            break;
        }
    }
    else
    {
        /* Invalid pin number error */
    }
}

u8 MGPIO_u8GetPinValue(Gpio_PortType Copy_u8Port, Gpio_PinType Copy_u8Pin)
{
    u8 u8Result = 0; /* Local variable to but the value on it to be able to return it */
    switch (Copy_u8Port)  /* Switch to find the port i want */
        {
        case GPIO_A: /* Writing on the Port A*/
            u8Result = GET_BIT(GPIOA_IDR, Copy_u8Pin);  /* getting the value on the local variable */
            break;
        case GPIO_B: /* Writing on the Port B*/
            u8Result = GET_BIT(GPIOB_IDR, Copy_u8Pin);  /* getting the value on the local variable */
            break;
        case GPIO_C: /* Writing on the Port C*/
            u8Result = GET_BIT(GPIOC_IDR, Copy_u8Pin);  /* getting the value on the local variable */
            break;
        
        default:
            break;
        }
    return u8Result;
}

