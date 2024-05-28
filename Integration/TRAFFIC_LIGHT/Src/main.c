

/*LIB */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/*MCAL*/
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"
#include "SYSTICK_interface.h"
#include "USART_INTERFACE.h"
/*HAL*/
#include "TL_TIMER_interface.h"
#include "DELAY.h"
#include "SSD_interface.h"


int main()
{

	/*RCC*/
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2,APB2_AFIOEN);
	MRCC_voidEnableClock(RCC_APB2,APB2_GPIOAEN);
	MRCC_voidEnableClock(RCC_APB2,APB2_GPIOBEN);
	MRCC_voidEnableClock(RCC_APB2,APB2_GPIOCEN);


	//MRCC_voidEnableClock(RCC_APB1,APB1_TIM2EN);
	MRCC_voidEnableClock(RCC_APB2, APB2_USART1EN);


	MNVIC_voidEnableInterrupt(37);
	MNVIC_voidEnableInterrupt(28);
	SSD_voidInit();


	/*USART GPIO*/
	MGPIO_voidSetPinMode(GPIO_A,PIN9,OUTPUT_SPEED_2MHZ_AFPP);//TX
		MGPIO_voidSetPinMode(GPIO_A,PIN10,INPUT_FLOATING);//RX

	/*ADC1 GPIO*/
	//MGPIO_voidSetPinMode(GPIO_A,PIN0,INPUT_ANALOG);

	/*SYSTICK*/
	MSTK_voidInit();


	/*USART*/
	MUSART_VidInit();

	/*Traffic Light*/
	TL_voidInit();


	while(1)
	{

		TL_voidTrafficLight();
		MSTK_voidSetBusyWait(4000);


	}
}
