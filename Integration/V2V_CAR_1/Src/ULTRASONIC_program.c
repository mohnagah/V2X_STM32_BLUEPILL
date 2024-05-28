#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"
#include "SYSTICK_interface.h"
#include "TIMERx_interface.h"

#include "ULTRASONIC_private.h"
#include "ULTRASONIC_config.h"
#include "ULTRASONIC_interface.h"


static u32 GlobalArr_u32EchoFlag[US_NUMBER] = {CLEAR};
static u32 GlobalArr_u32StartTime[US_NUMBER] = {CLEAR};
static u32 GlobalArr_u32EndTime[US_NUMBER] = {CLEAR};

static u8 GlobalArr_u8USTimer[US_NUMBER]= US_TIMERS;

static u8 GlobalArr_u8USEchoPort[US_NUMBER]= US_ECHO_PORTS;
static u8 GlobalArr_u8USChannel[US_NUMBER]= US_CHANNELS;
static u8 GlobalArr_u8USChannelPin[US_NUMBER]= US_CHANNEL_PINS;

static u8 GlobalArr_u8TriggerPort[US_NUMBER] = US_TRIGGER_PORTS;
static u8 GlobalArr_u8TriggerPin[US_NUMBER] = US_TRIGGERS_PINS;
/* counter in OVF ISR */
static u32 Global_u32Timer1OVFCounter = CLEAR;
///* Counter Flag for wave change */
//static u8 Global_u8EchoFlag = CLEAR;
///* Global Variable for record starting of wave */
//static u32 Local_u32StartTime = CLEAR;
///* Global Variable for record return of wave */
//static u32 Local_u32EndTime = CLEAR;

/* ************************************************************************** */
/* Function : HUS_voidInit							                       	  */
/* Argument : void						             						  */
/* Returns  : void		                                                      */
/* Role     : Setup timer and interrupt of ICU/OVF				        	  */
/* ************************************************************************** */
void HUS_voidInit(void)
{
	/* Initialize Timer_1 */
	MRCC_voidEnableClock(RCC_APB1,APB1_TIM2EN);

	for(u8 i = 0; i< 4;i++)
	{
		MTIMERx_voidInputCaptureSetup(GlobalArr_u8USTimer[i],GlobalArr_u8USChannel[i]);
		MTIMERx_voidSetInputCaptureTrigger(GlobalArr_u8USTimer[i],GlobalArr_u8USChannel[i],RISING_EDGE);
		MGPIO_voidSetPinMode(GlobalArr_u8USEchoPort[i],GlobalArr_u8USChannelPin[i],INPUT_PULL_UP_DOWN);
		MGPIO_voidSetPinValue(GlobalArr_u8USEchoPort[i],GlobalArr_u8USChannelPin[i],GPIO_LOW);
		/* Set Trigger Pin as Output and Echo Pin Input*/
		MGPIO_voidSetPinMode(GlobalArr_u8TriggerPort[i],GlobalArr_u8TriggerPin[i],OUTPUT_SPEED_10MHZ_PP);
	}


	MTIMERx_voidInit();


	/* Enable ICU & OVF Interrupts */
	MNVIC_voidEnableInterrupt(28);

	/* Set CallBack ICU function */
	MTIMERx_voidInputCaptureCallback(GlobalArr_u8USTimer[US_FRONT],
			GlobalArr_u8USChannel[US_FRONT], HUS_void_FRONT_ECHO_Interrupt);
	MTIMERx_voidInputCaptureCallback(GlobalArr_u8USTimer[US_F_SIDE],
			GlobalArr_u8USChannel[US_F_SIDE],HUS_void_F_SIDE_ECHO_Interrupt);
	MTIMERx_voidInputCaptureCallback(GlobalArr_u8USTimer[US_B_SIDE],
				GlobalArr_u8USChannel[US_B_SIDE],HUS_void_B_SIDE_ECHO_Interrupt);
	MTIMERx_voidInputCaptureCallback(GlobalArr_u8USTimer[US_BACK],
					GlobalArr_u8USChannel[US_BACK],HUS_void_BACK_ECHO_Interrupt);
	/* Set CallBack OVF function */
	MTIMERx_voidSetOVFCallback(TIMER2, HUS_voidOVFCounts);

	MSTK_voidInit();
}
/* -------------------------------------------------------------------------- */
/* ************************************************************************** */
/* Function : HUS_voidGetDistance					                       	  */
/* Argument : Pointer to distance variable		       						  */
/* Returns  : void		                                                      */
/* Role     : Calculate Distance of US wave						        	  */
/* ************************************************************************** */
void HUS_voidGetDistance(u8 copy_u8UltrasonicID, u16 *ptr_u16Distance)
{

	/* SET A PULSE ON TRIG PIN */
	MTIMERx_voidStartTimer(TIMER2);
//	MTIMERx_voidStartTimer(TIMER3);
	MGPIO_voidSetPinValue(GlobalArr_u8TriggerPort[copy_u8UltrasonicID],GlobalArr_u8TriggerPin[copy_u8UltrasonicID],GPIO_HIGH);
	MSTK_voidSetBusyWait(15);
	MGPIO_voidSetPinValue(GlobalArr_u8TriggerPort[copy_u8UltrasonicID],GlobalArr_u8TriggerPin[copy_u8UltrasonicID],GPIO_LOW);
//	while(Global_u8EchoFlag !=FLAG_CALCULATING);
	if(GlobalArr_u32EchoFlag[copy_u8UltrasonicID] == FLAG_CALCULATING)
	{
		*ptr_u16Distance = (u16) ((GlobalArr_u32EndTime[copy_u8UltrasonicID] - GlobalArr_u32StartTime[copy_u8UltrasonicID])
				* ((f32) TIMER_CLK / FCPU)) / ((f32) DISTANCE_FACTOR);

		GlobalArr_u32EchoFlag[copy_u8UltrasonicID] = FLAG_RISING_EDGE;
		MTIMERx_voidStopTimer(TIMER2);
	}
}
/* -------------------------------------------------------------------------- */
/* ************************************************************************** */
/* Function : HUS_voidGetAvgDistance				                       	  */
/* Argument : Pointer to Average distance variable	  						  */
/* Returns  : void		                                                      */
/* Role     : Get Average of Sensor Readings					        	  */
/* ************************************************************************** */
void HUS_voidGetAvgDistance(u16 *ptr_u16AvgDistance)
{
	u8 counter = CLEAR;
	u16 Local_u16Distance = CLEAR;
	u32 Local_u32Sum = CLEAR;
	for(counter = 0;counter<READING_NO;counter++)
	{
//		HUS_voidGetDistance(&Local_u16Distance);
		Local_u32Sum += Local_u16Distance;
		MSTK_voidSetBusyWait(5000);
	}
	*ptr_u16AvgDistance = (u16)(Local_u32Sum/READING_NO);
}
/* -------------------------------------------------------------------------- */
static void HUS_voidOVFCounts(void)
{
	Global_u32Timer1OVFCounter++;
}
/* -------------------------------------------------------------------------- */
static void HUS_void_FRONT_ECHO_Interrupt(void)
{

	/* WAVE START */
	if(GlobalArr_u32EchoFlag[US_FRONT] == FLAG_RISING_EDGE)
	{
		GlobalArr_u32EchoFlag[US_FRONT] = FLAG_FALLING_EDGE;
		MTIMERx_voidGetInputCaptureCounter(GlobalArr_u8USTimer[US_FRONT],
				GlobalArr_u8USChannel[US_FRONT],
				&GlobalArr_u32StartTime[US_FRONT]);

		Global_u32Timer1OVFCounter = CLEAR;
		MTIMERx_voidSetInputCaptureTrigger(GlobalArr_u8USTimer[US_FRONT],
				GlobalArr_u8USChannel[US_FRONT], FALLING_EDGE);

	}
	/* WAVE END */
	else if(GlobalArr_u32EchoFlag[US_FRONT] == FLAG_FALLING_EDGE)
	{
		GlobalArr_u32EchoFlag[US_FRONT] = FLAG_CALCULATING;
		MTIMERx_voidGetInputCaptureCounter(GlobalArr_u8USTimer[US_FRONT],
				GlobalArr_u8USChannel[US_FRONT],
				&GlobalArr_u32EndTime[US_FRONT]);

		GlobalArr_u32EndTime[US_FRONT] += Global_u32Timer1OVFCounter * 65535;
		MTIMERx_voidSetInputCaptureTrigger(GlobalArr_u8USTimer[US_FRONT],
				GlobalArr_u8USChannel[US_FRONT], RISING_EDGE);
	}

}
/* -------------------------------------------------------------------------- */
static void HUS_void_F_SIDE_ECHO_Interrupt(void)
{

	/* WAVE START */
	if(GlobalArr_u32EchoFlag[US_F_SIDE] == FLAG_RISING_EDGE)
	{
		GlobalArr_u32EchoFlag[US_F_SIDE] = FLAG_FALLING_EDGE;
		MTIMERx_voidGetInputCaptureCounter(GlobalArr_u8USTimer[US_F_SIDE],
				GlobalArr_u8USChannel[US_F_SIDE],
				&GlobalArr_u32StartTime[US_F_SIDE]);

		Global_u32Timer1OVFCounter = CLEAR;
		MTIMERx_voidSetInputCaptureTrigger(GlobalArr_u8USTimer[US_F_SIDE],
				GlobalArr_u8USChannel[US_F_SIDE], FALLING_EDGE);

	}
	/* WAVE END */
	else if(GlobalArr_u32EchoFlag[US_F_SIDE] == FLAG_FALLING_EDGE)
	{
		GlobalArr_u32EchoFlag[US_F_SIDE] = FLAG_CALCULATING;
		MTIMERx_voidGetInputCaptureCounter(GlobalArr_u8USTimer[US_F_SIDE],
				GlobalArr_u8USChannel[US_F_SIDE],
				&GlobalArr_u32EndTime[US_F_SIDE]);

		GlobalArr_u32EndTime[US_F_SIDE] += Global_u32Timer1OVFCounter * 65535;
		MTIMERx_voidSetInputCaptureTrigger(GlobalArr_u8USTimer[US_F_SIDE],
				GlobalArr_u8USChannel[US_F_SIDE], RISING_EDGE);
	}

}
/* -------------------------------------------------------------------------- */
static void HUS_void_B_SIDE_ECHO_Interrupt(void)
{

	/* WAVE START */
	if(GlobalArr_u32EchoFlag[US_B_SIDE] == FLAG_RISING_EDGE)
	{
		GlobalArr_u32EchoFlag[US_B_SIDE] = FLAG_FALLING_EDGE;
		MTIMERx_voidGetInputCaptureCounter(GlobalArr_u8USTimer[US_B_SIDE],
				GlobalArr_u8USChannel[US_B_SIDE],
				&GlobalArr_u32StartTime[US_B_SIDE]);

		Global_u32Timer1OVFCounter = CLEAR;
		MTIMERx_voidSetInputCaptureTrigger(GlobalArr_u8USTimer[US_B_SIDE],
				GlobalArr_u8USChannel[US_B_SIDE], FALLING_EDGE);

	}
	/* WAVE END */
	else if(GlobalArr_u32EchoFlag[US_B_SIDE] == FLAG_FALLING_EDGE)
	{
		GlobalArr_u32EchoFlag[US_B_SIDE] = FLAG_CALCULATING;
		MTIMERx_voidGetInputCaptureCounter(GlobalArr_u8USTimer[US_B_SIDE],
				GlobalArr_u8USChannel[US_B_SIDE],
				&GlobalArr_u32EndTime[US_B_SIDE]);

		GlobalArr_u32EndTime[US_B_SIDE] += Global_u32Timer1OVFCounter * 65535;
		MTIMERx_voidSetInputCaptureTrigger(GlobalArr_u8USTimer[US_B_SIDE],
				GlobalArr_u8USChannel[US_B_SIDE], RISING_EDGE);
	}

}
/* -------------------------------------------------------------------------- */
static void HUS_void_BACK_ECHO_Interrupt(void)
{

	/* WAVE START */
	if(GlobalArr_u32EchoFlag[US_BACK] == FLAG_RISING_EDGE)
	{
		GlobalArr_u32EchoFlag[US_BACK] = FLAG_FALLING_EDGE;
		MTIMERx_voidGetInputCaptureCounter(GlobalArr_u8USTimer[US_BACK],
				GlobalArr_u8USChannel[US_BACK],
				&GlobalArr_u32StartTime[US_BACK]);

		Global_u32Timer1OVFCounter = CLEAR;
		MTIMERx_voidSetInputCaptureTrigger(GlobalArr_u8USTimer[US_BACK],
				GlobalArr_u8USChannel[US_BACK], FALLING_EDGE);

	}
	/* WAVE END */
	else if(GlobalArr_u32EchoFlag[US_BACK] == FLAG_FALLING_EDGE)
	{
		GlobalArr_u32EchoFlag[US_BACK] = FLAG_CALCULATING;
		MTIMERx_voidGetInputCaptureCounter(GlobalArr_u8USTimer[US_BACK],
				GlobalArr_u8USChannel[US_BACK],
				&GlobalArr_u32EndTime[US_BACK]);

		GlobalArr_u32EndTime[US_BACK] += Global_u32Timer1OVFCounter * 65535;
		MTIMERx_voidSetInputCaptureTrigger(GlobalArr_u8USTimer[US_BACK],
				GlobalArr_u8USChannel[US_BACK], RISING_EDGE);
	}

}
/* -------------------------------------------------------------------------- */
