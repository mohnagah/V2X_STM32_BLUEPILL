#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "AFIO_config.h"
#include "AFIO_interface.h"
#include "AFIO_private.h"

void AFIO_voidRemap(u8 Copy_u8Peripheral, u8 Copy_u8Value)
{
    if (Copy_u8Peripheral < 25)
    {
        switch (Copy_u8Peripheral)
        {
        case AFIO_SWJ_CFG:
            Copy_u8Value &= 0b00000111;
            AFIO_MAPR |= (Copy_u8Value << AFIO_SWJ_CFG);
            break;
        case AFIO_CAN_REMAP:
        case AFIO_TIM3_REMAP:
        case AFIO_TIM2_REMAP:
        case AFIO_TIM1_REMAP:
        case AFIO_USART3_REMAP:
            Copy_u8Value &= 0b00000011;
            AFIO_MAPR |= (Copy_u8Value << Copy_u8Peripheral);
            break;
        default:
            if (Copy_u8Value)
            {
                SET_BIT(AFIO_MAPR, Copy_u8Value);
            }
            else
            {
                CLR_BIT(AFIO_MAPR, Copy_u8Value);
            }

            break;
        }
    }
    else
    {
        Copy_u8Peripheral -= 20;
        if (Copy_u8Value)
        {
            SET_BIT(AFIO_MAPR2, Copy_u8Value);
        }
        else
        {
            CLR_BIT(AFIO_MAPR2, Copy_u8Value);
        }
    }
}

/*Function to set the LINE in the PORT and the Registers(EXTICR1, EXTICR2, EXTICR3, EXTICR4) every Register have 4 LINES*/
void AFIO_voidSetSourceEXTI(u8 Copy_u8Line, u8 Copy_u8Port)
{
    switch (Copy_u8Line) /*switch to find the LINE i want*/
    {
    case AFIO_EXTI_LINE0: /*If its LINE0*/
        AFIO_EXTICR1 &= 0xFFF0; /*so, i need to write 0xFFF0 in the Register EXTICR1 to access the LINE0 and its the first in the EXTICR1 Register*/
        AFIO_EXTICR1 |= (Copy_u8Port << 0); /*then i OR it with the port i want and shifted by 0 because its LINE0*/
        break;
    case AFIO_EXTI_LINE1: /*If its LINE1*/
        AFIO_EXTICR1 &= 0xFF0F; /*so, i need to write 0xFF0F in the Register EXTICR1 to access the LINE1*/
        AFIO_EXTICR1 |= (Copy_u8Port << 4); /*then i OR it with the port i want and shifted by 4 because its LINE1 and every LINE have 4 BITS*/
        break;
    case AFIO_EXTI_LINE2: /*If its LINE2*/
        AFIO_EXTICR1 &= 0xF0FF; /*so, i need to write 0xF0FF in the Register EXTICR1 to access the LINE2*/
        AFIO_EXTICR1 |= (Copy_u8Port << 8); /*then i OR it with the port i want and shifted by 8 because its LINE2 and every LINE have 4 BITS*/
        break;
    case AFIO_EXTI_LINE3: /*If its LINE3*/
        AFIO_EXTICR1 &= 0x0FFF; /*so, i need to write 0x0FFF in the Register EXTICR1 to access the LINE3*/
        AFIO_EXTICR1 |= (Copy_u8Port << 12); /*then i OR it with the port i want and shifted by 12 because its LINE3 and every LINE have 4 BITS*/
        break;
    case AFIO_EXTI_LINE4: /*If its LINE4*/
        AFIO_EXTICR2 &= 0xFFF0; /*so, i need to write 0xFFF0 in the Register EXTICR2 to access the LINE4*/
        AFIO_EXTICR2 |= (Copy_u8Port << 0); /*then i OR it with the port i want and shifted by 0 because because its LINE4 and its the first in the EXTICR2 Register*/
        break;
    case AFIO_EXTI_LINE5: /*If its LINE5*/
        AFIO_EXTICR2 &= 0xFF0F; /*so, i need to write 0xFF0F in the Register EXTICR2 to access the LINE5*/
        AFIO_EXTICR2 |= (Copy_u8Port << 4); /*then i OR it with the port i want and shifted by 4 because its LINE5 and every LINE have 4 BITS*/
        break;
    case AFIO_EXTI_LINE6: /*If its LINE6*/
        AFIO_EXTICR2 &= 0xF0FF; /*so, i need to write 0xF0FF in the Register EXTICR2 to access the LINE6*/
        AFIO_EXTICR2 |= (Copy_u8Port << 8); /*then i OR it with the port i want and shifted by 8 because its LINE6 and every LINE have 4 BITS*/
        break;
    case AFIO_EXTI_LINE7: /*If its LINE6*/
        AFIO_EXTICR2 &= 0x0FFF; /*so, i need to write 0x0FFF in the Register EXTICR2 to access the LINE7*/
        AFIO_EXTICR2 |= (Copy_u8Port << 12); /*then i OR it with the port i want and shifted by 12 because its LINE7 and every LINE have 4 BITS*/
        break;
    case AFIO_EXTI_LINE8: /*If its LINE8*/
        AFIO_EXTICR3 &= 0xFFF0; /*so, i need to write 0xFFF0 in the Register EXTICR3 to access the LINE8*/
        AFIO_EXTICR3 |= (Copy_u8Port << 0); /*then i OR it with the port i want and shifted by 0 because because its LINE8 and its the first in the EXTICR3 Register*/
        break;
    case AFIO_EXTI_LINE9: /*If its LINE9*/
        AFIO_EXTICR3 &= 0xFF0F; /*so, i need to write 0xFF0F in the Register EXTICR3 to access the LINE9*/
        AFIO_EXTICR3 |= (Copy_u8Port << 4); /*then i OR it with the port i want and shifted by 4 because its LINE9 and every LINE have 4 BITS*/
        break;
    case AFIO_EXTI_LINE10: /*If its LINE10*/
        AFIO_EXTICR3 &= 0xF0FF; /*so, i need to write 0xF0FF in the Register EXTICR3 to access the LINE10*/
        AFIO_EXTICR3 |= (Copy_u8Port << 8); /*then i OR it with the port i want and shifted by 8 because its LINE10 and every LINE have 4 BITS*/
        break;
    case AFIO_EXTI_LINE11: /*If its LINE11*/
        AFIO_EXTICR3 &= 0x0FFF; /*so, i need to write 0x0FFF in the Register EXTICR3 to access the LINE11*/
        AFIO_EXTICR3 |= (Copy_u8Port << 12); /*then i OR it with the port i want and shifted by 12 because its LINE11 and every LINE have 4 BITS*/
        break;
    case AFIO_EXTI_LINE12: /*If its LINE12*/
        AFIO_EXTICR4 &= 0xFFF0;  /*so, i need to write 0xFFF0 in the Register EXTICR4 to access the LINE8*/
        AFIO_EXTICR4 |= (Copy_u8Port << 0); /*then i OR it with the port i want and shifted by 0 because because its LINE12 and its the first in the EXTICR4 Register*/
        break;
    case AFIO_EXTI_LINE13: /*If its LINE13*/
        AFIO_EXTICR4 &= 0xFF0F; /*so, i need to write 0xFF0F in the Register EXTICR4 to access the LINE13*/
        AFIO_EXTICR4 |= (Copy_u8Port << 4); /*then i OR it with the port i want and shifted by 4 because its LINE13 and every LINE have 4 BITS*/
        break;
    case AFIO_EXTI_LINE14: /*If its LINE14*/
        AFIO_EXTICR4 &= 0xF0FF; /*so, i need to write 0xF0FF in the Register EXTICR4 to access the LINE14*/
        AFIO_EXTICR4 |= (Copy_u8Port << 8); /*then i OR it with the port i want and shifted by 8 because its LINE14 and every LINE have 4 BITS*/
        break;
    case AFIO_EXTI_LINE15: /*If its LINE15*/
        AFIO_EXTICR4 &= 0x0FFF; /*so, i need to write 0x0FFF in the Register EXTICR4 to access the LINE15*/
        AFIO_EXTICR4 |= (Copy_u8Port << 12); /*then i OR it with the port i want and shifted by 12 because its LINE15 and every LINE have 4 BITS*/
        break;
    default:
        break;
    }
}

void AFIO_voidEnableEventOutput(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    AFIO_EVCR = 0;
    AFIO_EVCR = (1 << 7) | (Copy_u8Port << 4) | (Copy_u8Pin);
}
