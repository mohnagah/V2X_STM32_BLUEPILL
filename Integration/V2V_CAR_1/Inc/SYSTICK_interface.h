#ifndef MCAL_SYSTICK_SYSTICK_INTERFACE_H_
#define MCAL_SYSTICK_SYSTICK_INTERFACE_H_

/* ************************************************************************** */
/* Function : MSTK_voidInit                                                   */
/* Argument : Void                                                            */
/* Returns  : Void                                                            */
/* Role     : Stop the timer, Disable interrupt,and Set tick equals AHB/8     */
/* ************************************************************************** */
void MSTK_voidInit(void);

/* ************************************************************************** */
/* Function : MSTK_voidSetBusyWait                                            */
/* Argument : Number of ticks                                                 */
/* Returns  : Void                                                            */
/* Role     : Stay in the function for (number of tick x 1 Ms)                */
/* ************************************************************************** */
void MSTK_voidSetBusyWait(u32 A_u32Ticks);

/* ************************************************************************** */
/* Function : MSTK_voidSetIntervalSingle                                      */
/* Argument : Number of ticks and Address of a function                       */
/* Returns  : Void                                                            */
/* Role     : Call a function once after time interval                        */
/* ************************************************************************** */
void MSTK_voidSetIntervalSingle(u32 A_u32Ticks, void (*A_FuncPtr)(void));

/* ************************************************************************** */
/* Function : MSTK_voidSetIntervalPeriodic                                    */
/* Argument : Number of ticks and Address of a function                       */
/* Returns  : Void                                                            */
/* Role     : Call a function always after time interval                      */
/* ************************************************************************** */
void MSTK_voidSetIntervalPeriodic(u32 A_u32Ticks, void (*A_FuncPtr)(void));

/* ************************************************************************** */
/* Function : MSTK_voidStopInterval                                           */
/* Argument : Void                                                            */
/* Returns  : Void                                                            */
/* Role     : Stop Calling a function that have been calling periodic         */
/* ************************************************************************** */
void MSTK_voidStopInterval(void);

/* ************************************************************************** */
/* Function : MSTK_u32GetElapsedTime                                          */
/* Argument : Void                                                            */
/* Returns  : Time in micro seconds                                           */
/* Role     : measure the time passed during the interval                     */
/* ************************************************************************** */
u32 MSTK_u32GetElapsedTime(void);

/* ************************************************************************** */
/* Function : MSTK_u32GetRemainingTime                                        */
/* Argument : Void                                                            */
/* Returns  : Time in micro seconds                                           */
/* Role     : measure the time remaining during the interval                  */
/* ************************************************************************** */
u32 MSTK_u32GetRemainingTime(void);

#endif /* MCAL_SYSTICK_SYSTICK_INTERFACE_H_ */
