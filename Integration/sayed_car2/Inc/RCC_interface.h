#ifndef _RCC_INTERFACE_H_
#define _RCC_INTERFACE_H_
#include "STD_TYPES.h"
void MRCC_voidInitSysClock(void);
void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
u32  MRCC_u32GetClockFrequency   ( u8 copy_u8BusSource );

/*
-----------------------------------------------------------------------
--> copy_u8BusId Options:
    RCC_AHB
    RCC_APB1
    RCC_APB2
-----------------------------------------------------------------------
--> copy_u8BusSource Options:
    RCC_AHB
    RCC_APB1
    RCC_APB2
    RCC_SYSCLK
-----------------------------------------------------------------------
--> copy_u8PeriheralId options for RCC_AHB
        SDIOEN:     SDIO clock enable
        FSMCEN:     FSMC clock enable
        CRCEN:      CRC clock enable
        FLITFEN:    FLITF clock enable
        SRAMEN:     SRAM interface clock enable
        DMA2EN:     DMA2 clock enable
        DMA1EN:     DMA1 clock enable
-----------------------------------------------------------------------
--> copy_u8PeriheralId options for RCC_APB1
        DACEN:      DAC interface clock enable
        PWREN:      Power interface clock enable
        BKPEN:      Backup interface clock enable
        CANEN:      CAN clock enable
        USBEN:      USB clock enable
        I2C2EN:     I2C 2 clock enable
        I2C1EN:     I2C 1 clock enable
        UART5EN:    USART 5 clock enable
        UART4EN:    USART 4 clock enable
        USART3EN:   USART 3 clock enable
        USART2EN:   USART 2 clock enable
        SPI3EN:     SPI 3 clock enable
        SPI2EN:     SPI 2 clock enable
        WWDGEN:     Window watchdog clock enable
        TIM14EN:    Timer 14 clock enable
        TIM13EN:    Timer 13 clock enable
        TIM12EN:    Timer 12 clock enable
        TIM7EN:     Timer 7 clock enable
        TIM6EN:     Timer 6 clock enable
        TIM5EN:     Timer 5 clock enable
        TIM4EN:     Timer 4 clock enable
        TIM3EN:     Timer 3 clock enable
        TIM2EN:     Timer 2 clock enable
-----------------------------------------------------------------------
--> copy_u8PeriheralId options for RCC_APB2
        TIM11EN:    TIM11 timer clock enable
        TIM10EN:    TIM10 timer clock enable
        TIM9EN:     TIM9 timer clock enable
        ADC3EN:     ADC3 interface clock enable
        USART1EN:   USART1 clock enable
        TIM8EN:     TIM8 Timer clock enable
        SPI1EN:     SPI 1 clock enable
        TIM1EN:     TIM1 Timer clock enable
        ADC2EN:     ADC 2 interface clock enable
        ADC1EN:     ADC 1 interface clock enable
        IOPCEN:     I/O port C clock enable
        IOPBEN:     I/O port B clock enable
        IOPAEN:     I/O port A clock enable
        AFIOEN:     Alternate function I/O clock enable
-----------------------------------------------------------------------
*/

/*         Bus          */
#define RCC_AHB         0 
#define RCC_APB1        1
#define RCC_APB2        2
#define RCC_SYSCLK      3

/*         AHB          */
#define AHB_SDIOEN          10
#define AHB_FSMCEN          8
#define AHB_CRCEN           6
#define AHB_FLITFEN         4
#define AHB_SRAMEN          2
#define AHB_DMA2EN          1
#define AHB_DMA1EN          0


/*         APB1         */
#define APB1_DACEN           29
#define APB1_PWREN           28
#define APB1_BKPEN           27
#define APB1_CANEN           25
#define APB1_USBEN           23
#define APB1_I2C2EN          22
#define APB1_I2C1EN          21
#define APB1_UART5EN         20
#define APB1_UART4EN         19
#define APB1_USART3EN        18
#define APB1_USART2EN        17
#define APB1_SPI3EN          15
#define APB1_SPI2EN          14
#define APB1_WWDGEN          11
#define APB1_TIM14EN         8
#define APB1_TIM13EN         7
#define APB1_TIM12EN         6
#define APB1_TIM7EN          5
#define APB1_TIM6EN          4
#define APB1_TIM5EN          3
#define APB1_TIM4EN          2
#define APB1_TIM3EN          1
#define APB1_TIM2EN          0

/*         APB2         */
#define APB2_TIM11EN         21
#define APB2_TIM10EN         20
#define APB2_TIM9EN          19
#define APB2_ADC3EN          15
#define APB2_USART1EN        14
#define APB2_TIM8EN          13
#define APB2_SPI1EN          12
#define APB2_TIM1EN          11
#define APB2_ADC2EN          10
#define APB2_ADC1EN          9
#define APB2_GPIOCEN          4
#define APB2_GPIOBEN          3
#define APB2_GPIOAEN          2
#define APB2_AFIOEN          0



#endif
