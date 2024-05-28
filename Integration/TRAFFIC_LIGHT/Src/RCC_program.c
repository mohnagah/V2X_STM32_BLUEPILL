#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_config.h"
#include "RCC_interface.h"
#include "RCC_private.h"

void MRCC_voidInitSysClock(void)
{
    #if     RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
        RCC_CR   = 0x00010000; /* Enable HSE with no bypass "CRYSTAL": HSEON = 1, HSEBYP = 0 */
        RCC_CFGR = 0x00000001; /* HSE selected as system clock : SW = 01 */
        /*Wait until HSE ready*/
		while (!GET_BIT(RCC_CR, HSERDY));

    #elif   RCC_CLOCK_TYPE == RCC_HSE_RC
        RCC_CR   = 0x00050000;    /* Enable HSE with bypass "RC": HSEON = 1, HSEBYP = 0 */
        RCC_CFGR = 0x00000001;    /* HSE selected as system clock : SW = 01 */
        /*Wait until HSE ready*/
		while (!GET_BIT(RCC_CR, HSERDY));

    #elif   RCC_CLOCK_TYPE == RCC_HSI
        RCC_CR   = 0x00000081; /* Enable HSI + Trimming = 0 : HSION = 1, HSITRIM = 10000*/
        RCC_CFGR = 0x00000000;/* HSI selected as system clock : SW = 00 */
        /* Wait until HSI ready */
		while (!GET_BIT(RCC_CR, HSIRDY));

    #elif   RCC_CLOCK_TYPE == RCC_PLL
		RCC_CR   = 0x00000000;
		RCC_CFGR = 0x00000002; /* PLL selected as system clock : SW = 11 				 */
		RCC_CFGR |= (RCC_PLL_MUL_VAL-2)<<18; /* PLL multiplication factor 				 */
		#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			CLR_BIT(RCC_CFGR, PLLSRC);
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
			SET_BIT(RCC_CFGR, PLLSRC);
			SET_BIT(RCC_CFGR, PLLXTPRE);
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
			SET_BIT(RCC_CFGR, PLLSRC);
			CLR_BIT(RCC_CFGR, PLLXTPRE);
		#else
			#error("WRONG PLL INPUT")
		#endif
		RCC_CR   = 0x01000000; /* Enable PLL : PLLON = 1*/

	
	#else
		#error("WRONG CLOCK TYPE")
	#endif

	/* Configure AHB presaler */
	RCC_CFGR |= (RCC_AHB_PRESCALER << 4);

	/* Configure APB1 presaler */
	RCC_CFGR |= (RCC_APB1_PRESCALER << 8);

	/* Configure APB2 presaler */
	RCC_CFGR |= (RCC_APB2_PRESCALER << 11);
}

void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    if (Copy_u8PerId <= 31)
    {
        switch (Copy_u8BusId)
        {
        case RCC_AHB :
            SET_BIT(RCC_AHBENR, Copy_u8PerId);
            break;
        case RCC_APB1 :
            SET_BIT(RCC_APB1ENR, Copy_u8PerId);
            break;
        case RCC_APB2 :
            SET_BIT(RCC_APB2ENR, Copy_u8PerId);
            break;
        default:
        /* Return Error */
            break;
        }
    }
    else{
        /* Return Error */
    }
}

void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    if (Copy_u8PerId <= 31)
    {
        switch (Copy_u8BusId)
        {
        case RCC_AHB :
            CLR_BIT(RCC_AHBENR, Copy_u8PerId);
            break;
        case RCC_APB1 :
            CLR_BIT(RCC_APB1ENR, Copy_u8PerId);
            break;
        case RCC_APB2 :
            CLR_BIT(RCC_APB2ENR, Copy_u8PerId);
            break;
        default:
        /* Return Error */
            break;
        }
    }
    else{
        /* Return Error */
    }
}

u32  MRCC_u32GetClockFrequency (u8 copy_u8BusSource)
{
	u32 local_u32SysClk, local_u32Result;
	u8  local_u8Prescaler = 0;
	
	#if   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL || RCC_HSE_RC
		local_u32SysClk  =  RCC_HSE_FREQ;

	#elif RCC_CLOCK_TYPE == RCC_HSI
		local_u32SysClk  =  RCC_HSI_FREQ;

	#elif RCC_CLOCK_TYPE == RCC_PLL

		#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			local_u32SysClk =  RCC_HSI_FREQ >> 1; /* Divide by 2 */

		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
			local_u32SysClk =  RCC_HSE_FREQ >> 1; /* Divide by 2 */

		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
			local_u32SysClk =  RCC_HSE_FREQ;

		#endif

		local_u32SysClk *= RCC_PLL_MUL_VAL;

	#endif
	switch (copy_u8BusSource)
	{
	case RCC_AHB:
		/*
			(RCC_AHB_PRESCALER value , division factor) are
			(7,1), (8,2), (9,4), (10,8), (11,16)
			so substract 7 from RCC_AHB_PRESCALER we get (prescaler , division factor) are
			(0,1), (1,2), (2,4), (3,8), (4,16)
			shifting right the SYSCLK value with the prescaler will divide it with the required value
			the rest values are 
			(12,64), (13,128), (14,256)
			so we should substract 6 to get
			(6,64), (7,128), (8,256)
		*/
		if (local_u8Prescaler<12)
		{
		local_u8Prescaler = RCC_AHB_PRESCALER  - 7; 
		}
		else {
		local_u8Prescaler = RCC_AHB_PRESCALER  - 6; 
		}
		
		break;
	case RCC_APB1:
		/*
			(RCC_APB1_PRESCALER value , division factor) are
			(3,1), (4,2), (5,4), (6,8), (7,16)
			so substract 3 from RCC_APB1_PRESCALER we get (prescaler , division factor) are
			(0,1), (1,2), (2,4), (3,8), (4,16)
			shifting right the SYSCLK value with the prescaler will divide it with the required value
		*/
		local_u8Prescaler = RCC_APB1_PRESCALER - 3;
		break;
	case RCC_APB2:
		/* Same as RCC_APB1 */
		local_u8Prescaler = RCC_APB2_PRESCALER - 3;
		break;
	default:
		/* no divisions, return SYSCLK */
		local_u8Prescaler = 0; 
		break;
	}
	local_u32Result = local_u32SysClk >> local_u8Prescaler;
	return local_u32Result;
}
