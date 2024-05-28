#ifndef MCAL_TIMERX_TIMERX_INTERFACE_H_
#define MCAL_TIMERX_TIMERX_INTERFACE_H_

typedef enum
{
    RISING_EDGE = 0,
    FALLING_EDGE
}Trigger_Type;

typedef void (*timer_callback_t)(void);

#include "STD_TYPES.h"

#define TIMER2 2
#define TIMER3 3
#define TIMER4 4
#define TIMER5 5

#define CH1 1
#define CH2 2
#define CH3 3
#define CH4 4
void MTIMERx_voidInit(void);


void MTIMERx_voidPWMSetup(u8 copy_u8TimerID, u8 copy_u8ChannelID);

void MTIMERx_voidSetPWMDuty(u8 copy_u8TimerID, u8 copy_u8ChannelID, u32 copy_u32Duty);

void MTIMERx_voidInputCaptureSetup(u8 copy_u8TimerID, u8 copy_u8ChannelID);

void MTIMERx_voidStartTimer(u8 copy_u8TimerID);

void MTIMERx_voidStopTimer(u8 copy_u8TimerID);

void MTIMERx_voidGetInputCaptureCounter(u8 copy_u8TimerID, u8 copy_u8ChannelID, u32 *ptr_Counts);



void MTIMERx_voidSetInputCaptureTrigger(u8 copy_u8TimerID, u8 copy_u8ChannelID, u8 copy_u8ICTrigger);

void MTIMERx_voidInputCaptureCallback(u8 copy_u8TimerID, u8 copy_u8ChannelID, timer_callback_t ptr);


#endif /* MCAL_TIMERX_TIMERX_INTERFACE_H_ */
