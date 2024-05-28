
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"
#include "SSD_interface.h"

u8 ssd_arr[]={63,6,91,79,102,109,125,7,127,111};  //array in decimals from 0-9 for 7seg display.

void SSD_voidInit(void)
{

#if NUMBER_OF_SSD == TWO
	/**Activate the Enable for the two 7-segments**/
	MGPIO_voidSetPinMode(SSD_ENABLE_PORT,FIRST_SSD_ENABLE, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(SSD_ENABLE_PORT,SECOND_SSD_ENABLE, OUTPUT_SPEED_10MHZ_PP);

	/**Activate the pins for the first 7-segment**/
	MGPIO_voidSetPinMode(FIRST_SSD_PORT,PIN3,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(FIRST_SSD_PORT,PIN4,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(FIRST_SSD_PORT,PIN5,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(FIRST_SSD_PORT,PIN6,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(FIRST_SSD_PORT,PIN7,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(FIRST_SSD_PORT,PIN8,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(FIRST_SSD_PORT,PIN11,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(FIRST_SSD_PORT,PIN12,OUTPUT_SPEED_10MHZ_PP);

	/**Activate the pins for the first 7-segment**/
	MGPIO_voidSetPinMode(SECOND_SSD_PORT,PIN5 ,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(SECOND_SSD_PORT,PIN6 ,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(SECOND_SSD_PORT,PIN7 ,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(SECOND_SSD_PORT,PIN8 ,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(SECOND_SSD_PORT,PIN9 ,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(SECOND_SSD_PORT,PIN10,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(SECOND_SSD_PORT,PIN11,OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(SECOND_SSD_PORT,PIN12,OUTPUT_SPEED_10MHZ_PP);
#else
#error("Wrong Number of SSDs");
#endif
}

void SSD_voidSendNumber(SSD_t SSD_config,u8 Copy_u8num)
{
	if(SSD_config.activestate==COMMON_CATHODE)
	{
		if(SSD_config.dataport==SECOND_SSD_PORT)
		{
			MGPIO_voidSetPinValue(SECOND_SSD_PORT,PIN5 ,GET_BIT(ssd_arr[Copy_u8num],7));
			MGPIO_voidSetPinValue(SECOND_SSD_PORT,PIN6 ,GET_BIT(ssd_arr[Copy_u8num],6));
            MGPIO_voidSetPinValue(SECOND_SSD_PORT,PIN7 ,GET_BIT(ssd_arr[Copy_u8num],5));
            MGPIO_voidSetPinValue(SECOND_SSD_PORT,PIN8 ,GET_BIT(ssd_arr[Copy_u8num],4));
            MGPIO_voidSetPinValue(SECOND_SSD_PORT,PIN9 ,GET_BIT(ssd_arr[Copy_u8num],3));
            MGPIO_voidSetPinValue(SECOND_SSD_PORT,PIN10,GET_BIT(ssd_arr[Copy_u8num],2));
            MGPIO_voidSetPinValue(SECOND_SSD_PORT,PIN11,GET_BIT(ssd_arr[Copy_u8num],1));
            MGPIO_voidSetPinValue(SECOND_SSD_PORT,PIN12,GET_BIT(ssd_arr[Copy_u8num],0));
		}
		else if(SSD_config.dataport==FIRST_SSD_PORT)
		{
			MGPIO_voidSetPinValue(FIRST_SSD_PORT,PIN3,GET_BIT(ssd_arr[Copy_u8num] ,7));
			MGPIO_voidSetPinValue(FIRST_SSD_PORT,PIN4,GET_BIT(ssd_arr[Copy_u8num] ,6));
            MGPIO_voidSetPinValue(FIRST_SSD_PORT,PIN5,GET_BIT(ssd_arr[Copy_u8num] ,5));
            MGPIO_voidSetPinValue(FIRST_SSD_PORT,PIN6,GET_BIT(ssd_arr[Copy_u8num] ,4));
            MGPIO_voidSetPinValue(FIRST_SSD_PORT,PIN7,GET_BIT(ssd_arr[Copy_u8num] ,3));
            MGPIO_voidSetPinValue(FIRST_SSD_PORT,PIN8,GET_BIT(ssd_arr[Copy_u8num] ,2));
            MGPIO_voidSetPinValue(FIRST_SSD_PORT,PIN11,GET_BIT(ssd_arr[Copy_u8num],1));
            MGPIO_voidSetPinValue(FIRST_SSD_PORT,PIN12,GET_BIT(ssd_arr[Copy_u8num],0));
		}
	}
	else if(SSD_config.activestate==COMMON_ANODE)
	{
		if(SSD_config.dataport==SECOND_SSD_PORT)
		{
			MGPIO_voidSetPinValue(SECOND_SSD_PORT,PIN5 ,~GET_BIT(ssd_arr[Copy_u8num],7));
			MGPIO_voidSetPinValue(SECOND_SSD_PORT,PIN6 ,~GET_BIT(ssd_arr[Copy_u8num],6));
            MGPIO_voidSetPinValue(SECOND_SSD_PORT,PIN7 ,~GET_BIT(ssd_arr[Copy_u8num],5));
            MGPIO_voidSetPinValue(SECOND_SSD_PORT,PIN8 ,~GET_BIT(ssd_arr[Copy_u8num],4));
            MGPIO_voidSetPinValue(SECOND_SSD_PORT,PIN9 ,~GET_BIT(ssd_arr[Copy_u8num],3));
            MGPIO_voidSetPinValue(SECOND_SSD_PORT,PIN10,~GET_BIT(ssd_arr[Copy_u8num],2));
            MGPIO_voidSetPinValue(SECOND_SSD_PORT,PIN11,~GET_BIT(ssd_arr[Copy_u8num],1));
            MGPIO_voidSetPinValue(SECOND_SSD_PORT,PIN12,~GET_BIT(ssd_arr[Copy_u8num],0));
		}
		else if(SSD_config.dataport==FIRST_SSD_PORT)
		{
			MGPIO_voidSetPinValue(FIRST_SSD_PORT,PIN3 ,~GET_BIT(ssd_arr[Copy_u8num],7));
			MGPIO_voidSetPinValue(FIRST_SSD_PORT,PIN4 ,~GET_BIT(ssd_arr[Copy_u8num],6));
            MGPIO_voidSetPinValue(FIRST_SSD_PORT,PIN5 ,~GET_BIT(ssd_arr[Copy_u8num],5));
            MGPIO_voidSetPinValue(FIRST_SSD_PORT,PIN6 ,~GET_BIT(ssd_arr[Copy_u8num],4));
            MGPIO_voidSetPinValue(FIRST_SSD_PORT,PIN7 ,~GET_BIT(ssd_arr[Copy_u8num],3));
            MGPIO_voidSetPinValue(FIRST_SSD_PORT,PIN8 ,~GET_BIT(ssd_arr[Copy_u8num],2));
            MGPIO_voidSetPinValue(FIRST_SSD_PORT,PIN11,~GET_BIT(ssd_arr[Copy_u8num],1));
            MGPIO_voidSetPinValue(FIRST_SSD_PORT,PIN12,~GET_BIT(ssd_arr[Copy_u8num],0));
		}
	}
}

void SSD_voidEnable(SSD_t SSD_config)
{
	if(SSD_config.activestate==COMMON_CATHODE)
	{
		MGPIO_voidSetPinValue(SSD_config.controlport, SSD_config.controlpin, GPIO_LOW);
	}
	else if(SSD_config.activestate==COMMON_ANODE)
	{
		MGPIO_voidSetPinValue(SSD_config.controlport, SSD_config.controlpin, GPIO_HIGH);
	}
}

void SSD_voidDisable(SSD_t SSD_config)
{
	if(SSD_config.activestate==COMMON_CATHODE)
	{
		MGPIO_voidSetPinValue(SSD_config.controlport, SSD_config.controlpin, GPIO_HIGH);
	}
	else if(SSD_config.activestate==COMMON_ANODE)
	{
		MGPIO_voidSetPinValue(SSD_config.controlport, SSD_config.controlpin, GPIO_LOW);
	}
}

void SSD_voidPovSendNumber(u32 Copy_u32Number)
{
#if NUMBER_OF_SSD == TWO
	SSD_t SSD_1 = {FIRST_SSD_PORT,SSD_ENABLE_PORT,FIRST_SSD_ENABLE,FIRST_SSD_TYPE};
	SSD_t SSD_2 = {SECOND_SSD_PORT,SSD_ENABLE_PORT,SECOND_SSD_ENABLE,SECOND_SSD_TYPE};

	SSD_voidEnable(SSD_1);
	SSD_voidEnable(SSD_2);
	SSD_voidSendNumber(SSD_1, UNITS(Copy_u32Number));
	SSD_voidSendNumber(SSD_2, TENS(Copy_u32Number));
#else
#error("Wrong Number of SSDS")
#endif
}
