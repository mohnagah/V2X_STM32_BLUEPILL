#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_



/*To get the base address you need to go to Memory and bus architecture then Memory map                */
/*To get the address of the Registers you need to go to Interrupts and events then to EXTI register map*/
/*External Interrupts Registers and they must be in the order as shown in the datasheet                */
#define EXTI_BASE_ADDRESS   0x40010400 /*This is the base address of External Interrupts               */

#define EXTI_IMR      *((volatile u32*)(0x40010400)) /*Interrupt mask register (EXTI_IMR)            */
#define EXTI_EMR      *((volatile u32*)(0x40010404)) /*Event mask register (EXTI_EMR)                */
#define EXTI_RTSR     *((volatile u32*)(0x40010408)) /*Rising trigger selection register (EXTI_RTSR) */
#define EXTI_FTSR     *((volatile u32*)(0x4001040C)) /*Falling trigger selection register (EXTI_FTSR)*/
#define EXTI_SWIER    *((volatile u32*)(0x40010410)) /*Software interrupt event register (EXTI_SWIER)*/
#define EXTI_PR       *((volatile u32*)(0x40010414)) /*Pending register (EXTI_PR)                    */

/*Another way to define addresses for External Interrupts*/

/*
typedef struct
{
    volatile u32 IMR  ;
    volatile u32 EMR  ;
    volatile u32 RTSR ;
    volatile u32 FTSR ;
    volatile u32 SWIER;
    volatile u32 PR   ;
}EXTI_Type;

#define EXTI ((volatile EXTI_Type *)0x40010400) 
(Pointer to struct) If you accessed any Register that will jump to it in the struct directly       */

#endif
