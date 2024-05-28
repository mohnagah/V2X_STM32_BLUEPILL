#ifndef _NVIC_PRIVATE_H_
#define _NVIC_PRIVATE_H_



#define NVIC_BASE_ADDRESS   0xE000E100 /*This is the BASE ADDRESS of NVIC(Nested Vectored Interrupt Controller)*/
#define SCB_BASE_ADDRESS    0xE000ED00 /*This is the BASE ADDRESS of SCB(System Control Block)*/

#define NVIC_ISER0 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x000)) /*Enable External interrupts from 0 to 31 (Register)*/
#define NVIC_ISER1 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x004)) /*Enable External interrupts from 32 to 63 (Register)*/

#define NVIC_ICER0 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x080)) /*Disable External interrupts from 0 to 31 (Register)*/
#define NVIC_ICER1 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x084)) /*Disable External interrupts from 32 to 63 (Register)*/

#define NVIC_ISPR0 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x100)) /*Interrupt SET Pending Flag from 0 to 31 (Register)*/
#define NVIC_ISPR1 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x104)) /*Interrupt SET Pending Flag from 32 to 63(Register)*/

#define NVIC_ICPR0 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x180)) /*Interrupt CLEAR Pending Flag from 0 to 31 (Register)*/
#define NVIC_ICPR1 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x184)) /*Interrupt CLEAR Pending Flag from 32 to 63 (Register)*/

#define NVIC_IABR0 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x200)) /*Read only Register to get the Value fo Active Flag from 0 to 31 i used volatile here because its only read only register */
#define NVIC_IABR1 *((volatile u32 *)(NVIC_BASE_ADDRESS + 0x204)) /*Read only Register to get the Value fo Active Flag from 32 to 63 i used volatile here because its only read only register*/
#define NVIC_IPR    ((volatile u8  *)(NVIC_BASE_ADDRESS + 0x300)) /* Interrupt Priority Register and (u8) because we access it by BYTE*/
/*To access (NVIC_IPR) I can do it (NVIC_IPR[0]-> and this means first Register-> Interrupt0) or (*(NVIC_IPR+0)-> and this means first Register-> Interrupt0)*/

#define SCB_AIRCR  *((volatile u32 *)(SCB_BASE_ADDRESS + 0x0C  )) /*this is the adress of AIRCR(Application interrupt and reset control register)*/


/*(0x05FA) is the VECTKEY to be able to write to the Register*/
#define NVIC_GROUP_4_SUB_0   0x05FA0300 /*This means i have 4 groupes priority and 0 sub-groupes priority*/ 
#define NVIC_GROUP_3_SUB_1   0x05FA0400 /*This means i have 3 groupes priority and 1 sub-groupes priority*/ 
#define NVIC_GROUP_2_SUB_2   0x05FA0500 /*This means i have 2 groupes priority and 2 sub-groupes priority*/ 
#define NVIC_GROUP_1_SUB_3   0x05FA0600 /*This means i have 1 groupes priority and 3 sub-groupes priority*/ 
#define NVIC_GROUP_0_SUB_4   0x05FA0700 /*This means i have 0 groupes priority and 4 sub-groupes priority*/ 

#endif
