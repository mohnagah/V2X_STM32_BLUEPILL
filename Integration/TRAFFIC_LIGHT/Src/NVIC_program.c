#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "NVIC_config.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"

/*Function for NVIC_GROUP_SUB_DISTRIBUTION*/
void MNVIC_voidInit(void)
{
    SCB_AIRCR = NVIC_GROUP_SUB_DISTRIBUTION;
}

/*Function to enable Interrupts in ISER0 & ISER1 Registers*/
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntID)
{
    if(Copy_u8IntID <= 31) /*Check form 0 to 31 because the ISER0 Register from 0 to 31 BITS*/
    {
        NVIC_ISER0 = (1 << Copy_u8IntID); /*Setting the bit in ISER0 Register like this to be faster because SET_BIT takes a lot of Instructions*/
    }
    else if(Copy_u8IntID <= 59) /*Check form 32 to 59 because the ISER1 Register from 32 to 63 BITS but i want just to 59*/
    {
        Copy_u8IntID -= 32; /*Copy_u8IntID - 32 (to start from BIT 0 in the Register ISER1)*/
        NVIC_ISER1 = (1 << Copy_u8IntID); /*Setting the bit in ISER1 Register like this to be faster because SET_BIT takes a lot of Instructions*/
    }
    else
    {
        /* Return Error */
    }
}

/*Function to disable Interrupts in ICER0 & ICER1 Registers and to disable the interrupts you need to put 1 in the Registers in the BIT you want (to CLEAR)*/
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntID)
{
    if(Copy_u8IntID <= 31) /*Check form 0 to 31 because the ICER0 Register from 0 to 31 BITS*/
    {
        NVIC_ICER0 = (1 << Copy_u8IntID); /*Clearing the bit in ICER0 Register like this to be faster because CLR_BIT takes a lot of Instructions*/
    }
    else if(Copy_u8IntID <= 59) /*Check form 32 to 59 because the ICER1 Register from 32 to 63 BITS but i want just to 59*/
    {
        Copy_u8IntID -= 32; /*Copy_u8IntID - 32 (to start from BIT 0 in the Register ICER1)*/
        NVIC_ICER1 = (1 << Copy_u8IntID); /*Clearing the bit in ICER1 Register like this to be faster because CLR_BIT takes a lot of Instructions*/
    }
    else
    {
        /* Return Error */
    }
}

/*Function to SET the Pending FLAG in ISPR0 & ISPR1 Registers*/
/*NOTE: I SET Pending flag for Testing or Debugging*/
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntID)
{
    if(Copy_u8IntID <= 31) /*Check form 0 to 31 because the ISPR0 Register from 0 to 31 BITS*/
    {
        NVIC_ISPR0 = (1 << Copy_u8IntID); /*Clearing the bit in ISPR0 Register like this to be faster because CLR_BIT takes a lot of Instructions*/
    }
    else if(Copy_u8IntID <= 59) /*Check form 32 to 59 because the ISPR1 Register from 32 to 63 BITS but i want just to 59*/
    {
        Copy_u8IntID -= 32; /*Copy_u8IntID - 32 (to start from BIT 0 in the Register ISPR1)*/
        NVIC_ISPR1 = (1 << Copy_u8IntID); /*Clearing the bit in ISPR1 Register like this to be faster because CLR_BIT takes a lot of Instructions*/
    }
    else
    {
        /* Return Error */
    }
}

/*Function to SET the Pending FLAG in ICPR0 & ICPR1 Registers and to disable the Pending flag you need to put 1 in the Registers in the BIT you want (to CLEAR)*/
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntID)
{
    if(Copy_u8IntID <= 31) /*Check form 0 to 31 because the ICPR0 Register from 0 to 31 BITS*/
    {
        NVIC_ICPR0 = (1 << Copy_u8IntID); /*Clearing the bit in ICPR0 Register like this to be faster because CLR_BIT takes a lot of Instructions*/
    }
    else if(Copy_u8IntID <= 59) /*Check form 32 to 59 because the ICPR1 Register from 32 to 63 BITS but i want just to 59*/
    {
        Copy_u8IntID -= 32; /*Copy_u8IntID - 32 (to start from BIT 0 in the Register ICPR1)*/
        NVIC_ICPR1 = (1 << Copy_u8IntID); /*Clearing the bit in ICPR1 Register like this to be faster because CLR_BIT takes a lot of Instructions*/
    }
    else
    {
        /* Return Error */
    }
}

/*Function to GET the ACTIVE FLAG*/
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntID)
{
    u8 Local_u8Result = 0; /*Local variable to receive the value in it */
    if(Copy_u8IntID <= 31) /*Check form 0 to 31 because the IABR0 Register from 0 to 31 BITS*/
	{
		Local_u8Result = GET_BIT(NVIC_IABR0, Copy_u8IntID); /*Getting the value of the Active flag in register IABR0 and receive it in the local variable*/
	}
	else if(Copy_u8IntID <= 59)
	{
		Copy_u8IntID -= 32; /*Copy_u8IntID - 32 (to start from BIT 0 in the Register IABR1)*/
		Local_u8Result = GET_BIT(NVIC_IABR1, Copy_u8IntID); /*Getting the value of the Active flag in register IABR1 and receive it in the local variable*/
	}
	else
	{
		/* Return Error */ 
	}
    return Local_u8Result;
}

/*Function to SET the PRIORITY of the GROUPS and the SUB-GROUPS*/
void MNVIC_voidSetPriority(u8 Copy_u8PeripheralIndex, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority)
{
    u8 local_u8Priority = 0;
    if(Copy_u8PeripheralIndex < 60)
    {
        if(NVIC_GROUP_SUB_DISTRIBUTION == NVIC_GROUP_4_SUB_0) /*If i used 4 groups and 0 sub-groups*/
        {
            local_u8Priority = Copy_u8GroupPriority << 4; /*I shifted left by 4 because first 4 BITS are reserved and i want to write in next 4 BITS*/
        }
        else if(NVIC_GROUP_SUB_DISTRIBUTION == NVIC_GROUP_0_SUB_4) /*If i used 0 groups and 4 sub-groups*/
        {
            local_u8Priority = Copy_u8SubPriority << 4; /*I shifted left by 4 because first 4 BITS are reserved and i want to write in next 4 BITS*/
        }
        else if(NVIC_GROUP_SUB_DISTRIBUTION == NVIC_GROUP_3_SUB_1) /*If i used 3 groups and 1 sub-groups*/
        {
            local_u8Priority = (Copy_u8GroupPriority << 5) | (Copy_u8SubPriority << 4); /*I shifted left the (Copy_u8GroupPriority by 5) because the 4th BIT for the sub group and, then i shifted (Copy_u8SubPriority by 4) to write in it*/
        }
        else if(NVIC_GROUP_SUB_DISTRIBUTION == NVIC_GROUP_2_SUB_2) /*If i used 2 groups and 2 sub-groups*/
        {
            local_u8Priority = (Copy_u8GroupPriority << 6) | (Copy_u8SubPriority << 4); /*I shifted left the (Copy_u8GroupPriority by 6) because the 4th and the 5th BITS for the sub group and, then i shifted (Copy_u8SubPriority by 4) to write in 4 and 5 BITS*/
        }
        else if(NVIC_GROUP_SUB_DISTRIBUTION == NVIC_GROUP_1_SUB_3) /*If i used 1 group and 3 sub-groups*/
        {
            local_u8Priority = (Copy_u8GroupPriority << 7) | (Copy_u8SubPriority << 4); /*I shifted left the (Copy_u8GroupPriority by 7) because the 4th, the 5th and the 6th BITS for the sub group and, then i shifted (Copy_u8SubPriority by 4) to write in 4, 5 and 6 BITS*/
        }
        NVIC_IPR[Copy_u8PeripheralIndex] = local_u8Priority; /*Here i received the result of (local_u8Priority) in array*/
    }
    else
    {
        /* Return Error*/
    }
}
