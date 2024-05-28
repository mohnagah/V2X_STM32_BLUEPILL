#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"

/*Static global variable to hold the call back (ISR function)*/
/*static void (* EXTI0_CallBack) (void) = NULL_PTR;*/

/*I can do the global variable like (ARRAY) bacause i will do 16 interrupts better than 16 global variables*/
static void (*EXTI_CallBack[16]) (void);

/*Initialization function for the interrupt line and sense mood*/
void MEXTI_voidInit(void)
{
    #if     EXTI_LINE == EXTI_LINE0 /*If it EXTI LINE0*/
	    SET_BIT(EXTI_IMR, EXTI_LINE0); /*Then set the bit of the line in the IMR Register*/
    #elif   EXTI_LINE == EXTI_LINE1 /*If it EXTI LINE1*/
	    SET_BIT(EXTI_IMR, EXTI_LINE1); /*Then set the bit of the line in the IMR Register*/
	#elif   EXTI_LINE == EXTI_LINE2 /*If it EXTI LINE2*/
	    SET_BIT(EXTI_IMR, EXTI_LINE2); /*Then set the bit of the line in the IMR Register*/
    #elif   EXTI_LINE == EXTI_LINE3 /*If it EXTI LINE3*/
	    SET_BIT(EXTI_IMR, EXTI_LINE3); /*Then set the bit of the line in the IMR Register*/
    #elif   EXTI_LINE == EXTI_LINE4 /*If it EXTI LINE4*/
	    SET_BIT(EXTI_IMR, EXTI_LINE4); /*Then set the bit of the line in the IMR Register*/
	#elif   EXTI_LINE == EXTI_LINE5 /*If it EXTI LINE5*/
	    SET_BIT(EXTI_IMR, EXTI_LINE5); /*Then set the bit of the line in the IMR Register*/
    #elif   EXTI_LINE == EXTI_LINE6 /*If it EXTI LINE6*/
	    SET_BIT(EXTI_IMR, EXTI_LINE6); /*Then set the bit of the line in the IMR Register*/
    #elif   EXTI_LINE == EXTI_LINE7 /*If it EXTI LINE7*/
	    SET_BIT(EXTI_IMR, EXTI_LINE7); /*Then set the bit of the line in the IMR Register*/
	#elif   EXTI_LINE == EXTI_LINE8 /*If it EXTI LINE8*/
	    SET_BIT(EXTI_IMR, EXTI_LINE8); /*Then set the bit of the line in the IMR Register*/
    #elif   EXTI_LINE == EXTI_LINE9 /*If it EXTI LINE9*/
	    SET_BIT(EXTI_IMR, EXTI_LINE9); /*Then set the bit of the line in the IMR Register*/
    #elif   EXTI_LINE == EXTI_LINE10 /*If it EXTI LINE10*/
	    SET_BIT(EXTI_IMR, EXTI_LINE10); /*Then set the bit of the line in the IMR Register*/
	#elif   EXTI_LINE == EXTI_LINE11 /*If it EXTI LINE11*/
	    SET_BIT(EXTI_IMR, EXTI_LINE11); /*Then set the bit of the line in the IMR Register*/
    #elif   EXTI_LINE == EXTI_LINE12 /*If it EXTI LINE12*/
	    SET_BIT(EXTI_IMR, EXTI_LINE12); /*Then set the bit of the line in the IMR Register*/
    #elif   EXTI_LINE == EXTI_LINE13 /*If it EXTI LINE13*/
	    SET_BIT(EXTI_IMR, EXTI_LINE13); /*Then set the bit of the line in the IMR Register*/
	#elif   EXTI_LINE == EXTI_LINE14 /*If it EXTI LINE14*/
	    SET_BIT(EXTI_IMR, EXTI_LINE14); /*Then set the bit of the line in the IMR Register*/
    #elif   EXTI_LINE == EXTI_LINE15 /*If it EXTI LINE15*/
	    SET_BIT(EXTI_IMR, EXTI_LINE15); /*Then set the bit of the line in the IMR Register*/
    #else
		#error "WRONGE CHOICE"
	#endif

    #if EXTI_SENSE_MOOD == EXTI_RISING_EDGE /*if the sense mood is Rising Edge*/
        SET_BIT(EXTI_RTSR, EXTI_LINE); /*I need to set the bit of the line in the RTSR Register*/
    #elif EXTI_SENSE_MOOD == EXTI_FALLING_EDGE /*if the sense mood is Falling Edge*/
        SET_BIT(EXTI_FTSR, EXTI_LINE); /*I need to set the bit of the line in the FTSR Register*/
    #elif EXTI_SENSE_MOOD == EXTI_ON_CHANGE /*if the sense mood is On Change i will set both Rising and Falling Edges*/
        SET_BIT(EXTI_RTSR, EXTI_LINE); /*I need to set the bit of the line in the RTSR Register*/
        SET_BIT(EXTI_FTSR, EXTI_LINE); /*I need to set the bit of the line in the FTSR Register*/
    #else
        #error "WRONGE CHOICE"
    #endif
}

/*I use this function if i want to change the sense mood(Rising, Falling or On Change) in RUN_TIME*/
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8SenseMood)
{
    switch (Copy_u8SenseMood) /*switch between Moods*/
    {
    case EXTI_RISING_EDGE: /*If it Rising Edge*/
        SET_BIT(EXTI_RTSR, Copy_u8Line); /*Set the bit of the line in the RTSR Register*/
        CLR_BIT(EXTI_FTSR, Copy_u8Line); /*clear the bit of the line in the FTSR Register*/
        break;
    case EXTI_FALLING_EDGE: /*If it Falling Edge*/
        SET_BIT(EXTI_FTSR, Copy_u8Line); /*Set the bit of the line in the FTSR Register*/
        CLR_BIT(EXTI_RTSR, Copy_u8Line); /*clear the bit of the line in the RTSR Register*/
        break;
    case EXTI_ON_CHANGE: /*If it On Change*/
        SET_BIT(EXTI_RTSR, Copy_u8Line); /*Set the bit of the line in the RTSR Register*/
        SET_BIT(EXTI_FTSR, Copy_u8Line); /*Set the bit of the line in the FTSR Register*/
        break;
    default:
        /*Return Error*/
        break;
    }
}

/*Function to enable the line*/
void MEXTI_voidEnableLine(u8 Copy_u8Line)
{
    SET_BIT(EXTI_IMR, Copy_u8Line); /*Setting the bit of the line in the IMR Register will enable the line*/
}

/*Function to disable the line*/
void MEXTI_voidDisableLine(u8 Copy_u8Line)
{
    CLR_BIT(EXTI_IMR, Copy_u8Line); /*Clearing the bit of the line in the IMR Register will disable the line*/
}

/*Function to set the software interrupt trigger*/
void MEXTI_voidSoftwareTrigger(u8 Copy_u8Line)
{
    SET_BIT(EXTI_SWIER, Copy_u8Line); /*Setting the line in the SWIER Register to enable the event and it clears itself after occurrence of the event*/
}

/*Function for the call back*/
void MEXTI_voidSetCallBack(u8 Copy_u8Line,void (*ptr) (void))
{
    EXTI_CallBack[Copy_u8Line] = ptr; /*Making the global array hold the ptr value in the line i want*/
}

/*ISR Function i can say its >> (Handler Function for EXTI0 (IRQ >> means (Interrupt Request)))*/
void EXTI0_IRQHandler(void)
{
    EXTI_CallBack[0](); /*Calling the EXTI_CallBack and calling it means executing it and executing it means executing the next line*/
    SET_BIT(EXTI_PR, 0); /*Clearing the pending bit(pending flag) in ISR for EXTI0*/
}

/*ISR Function i can say its >> (Handler Function for EXTI1 (IRQ >> means (Interrupt Request)))*/
void EXTI1_IRQHandler(void)
{
    EXTI_CallBack[1](); /*Calling the EXTI_CallBack and calling it means executing it and executing it means executing the next line*/
    SET_BIT(EXTI_PR, 1); /*Clearing the pending bit(pending flag) in ISR for EXTI1*/
}

/*ISR Function i can say its >> (Handler Function for EXTI2 (IRQ >> means (Interrupt Request)))*/
void EXTI2_IRQHandler(void)
{
    EXTI_CallBack[2](); /*Calling the EXTI_CallBack and calling it means executing it and executing it means executing the next line*/
    SET_BIT(EXTI_PR, 2); /*Clearing the pending bit(pending flag) in ISR for EXTI2*/
}

/*ISR Function i can say its >> (Handler Function for EXTI3 (IRQ >> means (Interrupt Request)))*/
void EXTI3_IRQHandler(void)
{
    EXTI_CallBack[3](); /*Calling the EXTI_CallBack and calling it means executing it and executing it means executing the next line*/
    SET_BIT(EXTI_PR, 3); /*Clearing the pending bit(pending flag) in ISR for EXTI3*/
}

/*ISR Function i can say its >> (Handler Function for EXTI4 (IRQ >> means (Interrupt Request)))*/
void EXTI4_IRQHandler(void)
{
    EXTI_CallBack[4](); /*Calling the EXTI_CallBack and calling it means executing it and executing it means executing the next line*/
    SET_BIT(EXTI_PR, 4); /*Clearing the pending bit(pending flag) in ISR for EXTI4*/
}

/*ISR Function i can say its >> (Handler Function for EXTI5 (IRQ >> means (Interrupt Request)))*/
void EXTI5_IRQHandler(void)
{
    EXTI_CallBack[5](); /*Calling the EXTI_CallBack and calling it means executing it and executing it means executing the next line*/
    SET_BIT(EXTI_PR, 5); /*Clearing the pending bit(pending flag) in ISR for EXTI5*/
}

/*ISR Function i can say its >> (Handler Function for EXTI6 (IRQ >> means (Interrupt Request)))*/
void EXTI6_IRQHandler(void)
{
    EXTI_CallBack[6](); /*Calling the EXTI_CallBack and calling it means executing it and executing it means executing the next line*/
    SET_BIT(EXTI_PR, 6); /*Clearing the pending bit(pending flag) in ISR for EXTI6*/
}

/*ISR Function i can say its >> (Handler Function for EXTI7 (IRQ >> means (Interrupt Request)))*/
void EXTI7_IRQHandler(void)
{
    EXTI_CallBack[7](); /*Calling the EXTI_CallBack and calling it means executing it and executing it means executing the next line*/
    SET_BIT(EXTI_PR, 7); /*Clearing the pending bit(pending flag) in ISR for EXTI7*/
}

/*ISR Function i can say its >> (Handler Function for EXTI8 (IRQ >> means (Interrupt Request)))*/
void EXTI8_IRQHandler(void)
{
    EXTI_CallBack[8](); /*Calling the EXTI_CallBack and calling it means executing it and executing it means executing the next line*/
    SET_BIT(EXTI_PR, 8); /*Clearing the pending bit(pending flag) in ISR for EXTI8*/
}

/*ISR Function i can say its >> (Handler Function for EXTI9 (IRQ >> means (Interrupt Request)))*/
void EXTI9_IRQHandler(void)
{
    EXTI_CallBack[9](); /*Calling the EXTI_CallBack and calling it means executing it and executing it means executing the next line*/
    SET_BIT(EXTI_PR, 9); /*Clearing the pending bit(pending flag) in ISR for EXTI9*/
}

/*ISR Function i can say its >> (Handler Function for EXTI10 (IRQ >> means (Interrupt Request)))*/
void EXTI10_IRQHandler(void)
{
    EXTI_CallBack[10](); /*Calling the EXTI_CallBack and calling it means executing it and executing it means executing the next line*/
    SET_BIT(EXTI_PR, 10); /*Clearing the pending bit(pending flag) in ISR for EXTI10*/
}

/*ISR Function i can say its >> (Handler Function for EXTI11 (IRQ >> means (Interrupt Request)))*/
void EXTI11_IRQHandler(void)
{
    EXTI_CallBack[11](); /*Calling the EXTI_CallBack and calling it means executing it and executing it means executing the next line*/
    SET_BIT(EXTI_PR, 11); /*Clearing the pending bit(pending flag) in ISR for EXTI11*/
}

/*ISR Function i can say its >> (Handler Function for EXTI12 (IRQ >> means (Interrupt Request)))*/
void EXTI12_IRQHandler(void)
{
    EXTI_CallBack[12](); /*Calling the EXTI_CallBack and calling it means executing it and executing it means executing the next line*/
    SET_BIT(EXTI_PR, 12); /*Clearing the pending bit(pending flag) in ISR for EXTI12*/
}

/*ISR Function i can say its >> (Handler Function for EXTI13 (IRQ >> means (Interrupt Request)))*/
void EXTI13_IRQHandler(void)
{
    EXTI_CallBack[13](); /*Calling the EXTI_CallBack and calling it means executing it and executing it means executing the next line*/
    SET_BIT(EXTI_PR, 13); /*Clearing the pending bit(pending flag) in ISR for EXTI13*/
}

/*ISR Function i can say its >> (Handler Function for EXTI14 (IRQ >> means (Interrupt Request)))*/
void EXTI14_IRQHandler(void)
{
    EXTI_CallBack[14](); /*Calling the EXTI_CallBack and calling it means executing it and executing it means executing the next line*/
    SET_BIT(EXTI_PR, 14); /*Clearing the pending bit(pending flag) in ISR for EXTI14*/
}

/*ISR Function i can say its >> (Handler Function for EXTI15 (IRQ >> means (Interrupt Request)))*/
void EXTI15_IRQHandler(void)
{
    EXTI_CallBack[15](); /*Calling the EXTI_CallBack and calling it means executing it and executing it means executing the next line*/
    SET_BIT(EXTI_PR, 15); /*Clearing the pending bit(pending flag) in ISR for EXTI15*/
}
