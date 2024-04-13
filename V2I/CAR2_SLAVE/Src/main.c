/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

//#include "EXTI_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"
#include "SYSTICK_interface.h"
#include "LCD_int.h"
#include "USART_INTERFACE.h"
#include "MotorDriver_interface.h"
#include "TIMERx_interface.h"

int main(void)
{


	    MRCC_voidInitSysClock();
		MRCC_voidEnableClock(RCC_APB2,APB2_AFIOEN);
		MRCC_voidEnableClock(RCC_APB2,APB2_GPIOAEN);
		MRCC_voidEnableClock(RCC_APB2,APB2_GPIOBEN);
		MRCC_voidEnableClock(RCC_APB2,APB2_GPIOCEN);
		MRCC_voidEnableClock(RCC_APB1,APB1_TIM2EN);
		MRCC_voidEnableClock(RCC_APB2, APB2_USART1EN);


		MNVIC_voidEnableInterrupt(37); // Enable UART
		MNVIC_voidEnableInterrupt(28); //Enable Timer


		MGPIO_voidSetPinMode(GPIO_A,PIN9,OUTPUT_SPEED_2MHZ_AFPP);//TX
		MGPIO_voidSetPinMode(GPIO_A,PIN10,INPUT_FLOATING);//RX


		HLCD_voidInit();
		MUSART_VidInit();
		MSTK_voidInit();
		H_MotorDriver_voidInit();
		u8 read_data = 0;  // variable to store data received
		volatile u8 forward_state = 0; // Flag for forward motors
		volatile u8 stop_state = 0; // Flag for stop motors

		H_MotorDriver_voidForward();


   while(1){

	    read_data =  MUSART1_u8RecCharSynch();

	     HLCD_voidDispIntNum(read_data);

	     HLCD_voidClrScreen();

	     if(read_data == 65 && stop_state == 0){ //car crash happen
              forward_state = 0;
             //MGPIO_voidSetPinValue(GPIO_A,PIN8,GPIO_HIGH);
	    	 H_MotorDriver_voidStop();
	    	 stop_state = 1;
	     }
	     else if ((read_data == 83) && (forward_state == 0)) { //safe mode

             stop_state = 0;

	    	 H_MotorDriver_voidForward();
             forward_state = 1;


	     }
	     else if (read_data == 66 && stop_state == 0){
	    	 forward_state = 0;

	    	 H_MotorDriver_voidStop();
	    	 stop_state = 1;
	     }
	     else if (read_data == 67 && stop_state == 0){
	    	 forward_state = 0;

	    	 H_MotorDriver_voidStop();
	    	 stop_state = 1;
	     }
	     else if(read_data == 0 || read_data == ' '){

	    	 H_MotorDriver_voidForward();
	     }

   }
}
