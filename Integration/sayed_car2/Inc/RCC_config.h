#ifndef _RCC_CONFIG_H_
#define _RCC_CONFIG_H_

#define RCC_HSI_FREQ    16000000
#define RCC_HSE_FREQ    16000000

//#define RCC_CLOCK_TYPE          RCC_HSE_CRYSTAL
#define RCC_AHB_PRESCALER       RCC_SYSCLK_DIVIDED_1
#define RCC_APB1_PRESCALER      RCC_HCLK_DIVIDED_1
#define RCC_APB2_PRESCALER      RCC_HCLK_DIVIDED_1

#if RCC_CLOCK_TYPE == RCC_PLL
    #define RCC_PLL_INPUT       RCC_PLL_IN_HSE_DIV_2
    #define RCC_PLL_MUL_VAL     4
#endif

/* options for clock source :    
    1- RCC_HSE_CRYSTAL  
    2- RCC_HSE_RC
    3- RCC_HSI  
    4- RCC_PLL             */

#define RCC_CLOCK_TYPE  RCC_HSI


/* options for clock source :    
    1- RCC_PLL_INPUT_HSI_DIV_2  
    2- RCC_PLL_INPUT_HSE_DIV_2
    3- RCC_PLL_INPUT_HSE       */

/* Note: Select Value only if you have PLL as input clock source */
//#if RCC_CLOCK_TYPE == RCC_PLL
//#define RCC_PLL_INPUT   RCC_PLL_INPUT_HSE_DIV_2
//#endif

/* Note: Select Value only if you have PLL as input clock source */
/* Options 2 to 16 */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL 4
#endif

#endif
