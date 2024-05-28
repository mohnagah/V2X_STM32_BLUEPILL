/* -------------------------------------------------------------------------- */
/*                                   Include                                  */
/* -------------------------------------------------------------------------- */
/* --------------------------------- STD LIB -------------------------------- */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "SYSTICK_configuration.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/*                                   Program                                  */
/* -------------------------------------------------------------------------- */
/* ************************************************************************** */
/* Function : MSTK_voidInit                                                   */
/* Argument : Void                                                            */
/* Returns  : Void                                                            */
/* Role     : Stop the timer, Disable interrupt,and Set tick equals AHB/8     */
/* ************************************************************************** */
void MSTK_voidInit(void)
{
	/* Stop Timer */
	CLR_BIT(STK->CTRL, CTRL_ENABLE);
	STK->LOAD = Null;
	STK->VAL = Null;
	/* Disable Interrupt */
	CLR_BIT(STK->CTRL, CTRL_TICK_INT);
	/* Set the source AHB/8 or AHB */
#if SOURCE == AHB_TICK_BY_8
	CLR_BIT(STK->CTRL, CTRL_CLKSOURCE);
#elif SOURCE == AHB_TICK
    SET_BIT(STK->CTRL, CTRL_CLKSOURCE);
#endif
}

/* ************************************************************************** */
/* Function : MSTK_voidSetBusyWait                                            */
/* Argument : Number of ticks                                                 */
/* Returns  : Void                                                            */
/* Role     : Stay in the function for (number of tick x 1 Ms)                */
/* ************************************************************************** */
void MSTK_voidSetBusyWait(u32 A_u32Ticks)
{
	/* Reset timer value and clear flag */
	STK->VAL = 0;
	/* Save the value of time */
	STK->LOAD = A_u32Ticks*1000;
	/* Start Timer */
	SET_BIT(STK->CTRL, CTRL_ENABLE);
	/* Start Delay */
	while (GET_BIT(STK->CTRL, CTRL_COUNT_FLAG) == FLAG_DOWN)
		;
	/* Stop Timer */
	CLR_BIT(STK->CTRL, CTRL_ENABLE);
	STK->LOAD = Null;
	STK->VAL = Null;
}

/* ************************************************************************** */
/* Function : MSTK_voidSetIntervalSingle                                      */
/* Argument : Number of ticks and Address of a function                       */
/* Returns  : Void                                                            */
/* Role     : Call a function once after time interval                        */
/* ************************************************************************** */
void MSTK_voidSetIntervalSingle(u32 A_u32Ticks, void (*A_FuncPtr)(void))
{
	/* Save the value of time */
	STK->LOAD = A_u32Ticks;
	/* Start Timer */
	SET_BIT(STK->CTRL, CTRL_ENABLE);
	/* Save the function address */
	CallBack = A_FuncPtr;
	/* Set Interval mode single */
	STK_u8IntervalMode = STK_SINGLE_MODE;
	/* Enable Interrupt */
	SET_BIT(STK->CTRL, CTRL_TICK_INT);
}

/* ************************************************************************** */
/* Function : MSTK_voidSetIntervalPeriodic                                    */
/* Argument : Number of ticks and Address of a function                       */
/* Returns  : Void                                                            */
/* Role     : Call a function always after time interval                      */
/* ************************************************************************** */
void MSTK_voidSetIntervalPeriodic(u32 A_u32Ticks, void (*A_FuncPtr)(void))
{
	/* Save the value of time */
	STK->LOAD = A_u32Ticks;
	/* Start Timer */
	SET_BIT(STK->CTRL, CTRL_ENABLE);
	/* Save the function address */
	CallBack = A_FuncPtr;
	/* Set Interval mode periodic */
	STK_u8IntervalMode = STK_PERIODIC_MODE;
	/* Enable Interrupt */
	SET_BIT(STK->CTRL, CTRL_TICK_INT);
}

/* ************************************************************************** */
/* Function : MSTK_voidStopInterval                                           */
/* Argument : Void                                                            */
/* Returns  : Void                                                            */
/* Role     : Stop Calling a function that have been calling periodic         */
/* ************************************************************************** */
void MSTK_voidStopInterval(void)
{
}

/* ************************************************************************** */
/* Function : MSTK_u32GetElapsedTime                                          */
/* Argument : Void                                                            */
/* Returns  : Time in micro seconds                                           */
/* Role     : measure the time passed during the interval                     */
/* ************************************************************************** */
u32 MSTK_u32GetElapsedTime(void)
{
	return ((STK->LOAD) - (STK->VAL));
}

/* ************************************************************************** */
/* Function : MSTK_u32GetRemainingTime                                        */
/* Argument : Void                                                            */
/* Returns  : Time in micro seconds                                           */
/* Role     : measure the time remaining during the interval                  */
/* ************************************************************************** */
u32 MSTK_u32GetRemainingTime(void)
{
	return (STK->VAL);
}

//vpid Systick_Handler(void)
//{
//	if(CallBack != NULL)
//	{
//		CallBack();
//	}
//}
