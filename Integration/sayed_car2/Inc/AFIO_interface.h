#ifndef _AFIO_INTERFACE_H_
#define _AFIO_INTERFACE_H_

void AFIO_voidRemap(u8 copy_u8Peripheral, u8 copy_u8Value);
void AFIO_voidSetSourceEXTI(u8 copy_u8Line, u8 copy_u8Port);
void AFIO_voidEnableEventOutput(u8 copy_u8Port, u8 copy_u8Pin);

/*
--> Options for copy_u8Port
    AFIO_PORTA
    AFIO_PORTB
    AFIO_PORTC
------------------------------------------------
--> Options for copy_u8Pin
    0
    1
    2
    ....
    15
------------------------------------------------
--> Options for copy_u8Peripheral
    AFIO_FSMC_NADV         
    AFIO_TIM14_REMAP       
    AFIO_TIM13_REMAP       
    AFIO_TIM11_REMAP       
    AFIO_TIM10_REMAP       
    AFIO_TIM9_REMAP        
    AFIO_SWJ_CFG           
    AFIO_ADC2_ETRGREG_REMAP
    ADC2_ETRGINJ_REMAP     
    ADC1_ETRGREG_REMAP     
    AFIO_ADC1_ETRGINJ_REMAP
    AFIO_TIM5CH4_IREMAP    
    AFIO_PD01_REMAP        
    AFIO_CAN_REMAP         
    AFIO_TIM4_REMAP        
    AFIO_TIM3_REMAP        
    AFIO_TIM2_REMAP        
    AFIO_TIM1_REMAP        
    AFIO_USART3_REMAP      
    AFIO_USART2_REMAP      
    AFIO_USART1_REMAP      
    AFIO_I2C1_REMAP        
    AFIO_SPI1_REMAP        
------------------------------------------------
--> Options for copy_u8Line:
    AFIO_EXTI_LINE0
    AFIO_EXTI_LINE1
    AFIO_EXTI_LINE2
    AFIO_EXTI_LINE3
    AFIO_EXTI_LINE4
    AFIO_EXTI_LINE5
    AFIO_EXTI_LINE6
    AFIO_EXTI_LINE7
    AFIO_EXTI_LINE8
    AFIO_EXTI_LINE9
    AFIO_EXTI_LINE10
    AFIO_EXTI_LINE11
    AFIO_EXTI_LINE12
    AFIO_EXTI_LINE13
    AFIO_EXTI_LINE14
    AFIO_EXTI_LINE15
*/

#define AFIO_PORTA                  0
#define AFIO_PORTB                  1
#define AFIO_PORTC                  2

#define AFIO_EXTI_LINE0             0
#define AFIO_EXTI_LINE1             1
#define AFIO_EXTI_LINE2             2
#define AFIO_EXTI_LINE3             3
#define AFIO_EXTI_LINE4             4
#define AFIO_EXTI_LINE5             5
#define AFIO_EXTI_LINE6             6
#define AFIO_EXTI_LINE7             7
#define AFIO_EXTI_LINE8             8
#define AFIO_EXTI_LINE9             9
#define AFIO_EXTI_LINE10            10
#define AFIO_EXTI_LINE11            11
#define AFIO_EXTI_LINE12            12
#define AFIO_EXTI_LINE13            13
#define AFIO_EXTI_LINE14            14
#define AFIO_EXTI_LINE15            15

#define AFIO_FSMC_NADV              30
#define AFIO_TIM14_REMAP            29
#define AFIO_TIM13_REMAP            28
#define AFIO_TIM11_REMAP            27
#define AFIO_TIM10_REMAP            26
#define AFIO_TIM9_REMAP             25
#define AFIO_SWJ_CFG                24
#define AFIO_ADC2_ETRGREG_REMAP     20
#define ADC2_ETRGINJ_REMAP          19
#define ADC1_ETRGREG_REMAP          18
#define AFIO_ADC1_ETRGINJ_REMAP     17
#define AFIO_TIM5CH4_IREMAP         16
#define AFIO_PD01_REMAP             15
#define AFIO_CAN_REMAP              13
#define AFIO_TIM4_REMAP             12
#define AFIO_TIM3_REMAP             10
#define AFIO_TIM2_REMAP             8
#define AFIO_TIM1_REMAP             6
#define AFIO_USART3_REMAP           4
#define AFIO_USART2_REMAP           3
#define AFIO_USART1_REMAP           2
#define AFIO_I2C1_REMAP             1
#define AFIO_SPI1_REMAP             0


#endif
