
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SSD_interface.h"
#include "TL_TIMER_private.h"
#include "TL_TIMER_config.h"
#include "TL_TIMER_interface.h"
#include "USART_INTERFACE.h"
u8 Global_u8TrafficLightState;

void TL_voidInit(void)
{
	SSD_voidInit();
	MUSART_VidInit();
	MGPIO_voidSetPinMode(LED_PORT, RED_PIN, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(LED_PORT, YELLOW_PIN, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinMode(LED_PORT, GREEN_PIN, OUTPUT_SPEED_10MHZ_PP);

}

void TL_voidTrafficLight(void)
{
static u8 state = 0;
	static u8 Local_u8TimeInSeconds=0;
	static u16 Local_s8CountDown=RED_TIME+YELLOW_TIME+GREEN_TIME;
	Local_u8TimeInSeconds++;
	if(RED)
	{
		Global_u8TrafficLightState = RED_LIGHT_STATE;
		SSD_voidPovSendNumber(Local_s8CountDown-YELLOW_TIME-GREEN_TIME);
		MGPIO_voidSetPinValue(LED_PORT, GREEN_PIN, GPIO_LOW);
		MGPIO_voidSetPinValue(LED_PORT, RED_PIN, GPIO_HIGH);
		Local_s8CountDown--;
		if(state == 0){
		MUSART1_VidSendCharSync('R');
		state = 1;

		}
	}
	else if (YELLOW)
	{
		Global_u8TrafficLightState = YELLOW_LIGHT_STATE;
		SSD_voidPovSendNumber(Local_s8CountDown-GREEN_TIME);
		MGPIO_voidSetPinValue(LED_PORT, RED_PIN, GPIO_LOW);
		MGPIO_voidSetPinValue(LED_PORT, YELLOW_PIN, GPIO_HIGH);
		Local_s8CountDown--;
		if(state == 1){
		MUSART1_VidSendCharSync('Y');
		state = 2;

		}

	}
	else if (GREEN)
	{
		Global_u8TrafficLightState = GREEN_LIGHT_STATE;
		SSD_voidPovSendNumber(Local_s8CountDown);
		MGPIO_voidSetPinValue(LED_PORT, YELLOW_PIN, GPIO_LOW);
		MGPIO_voidSetPinValue(LED_PORT, GREEN_PIN, GPIO_HIGH);
		Local_s8CountDown--;
		if(state == 2){
		MUSART1_VidSendCharSync('G');
		state = 0;

		}
	}
	else
	{
		Local_u8TimeInSeconds=0;
		Local_s8CountDown=RED_TIME+YELLOW_TIME+GREEN_TIME;
	}
}
