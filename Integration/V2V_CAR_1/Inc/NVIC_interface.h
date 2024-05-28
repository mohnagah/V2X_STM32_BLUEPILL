#ifndef _NVIC_INTERFACE_H_
#define _NVIC_INTERFACE_H_

#include "STD_TYPES.h"

void MNVIC_voidInit            (      void     );
void MNVIC_voidEnableInterrupt (u8 Copy_u8IntID);
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntID);
void MNVIC_voidSetPendingFlag  (u8 Copy_u8IntID);
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntID);
void MNVIC_voidSetPriority     (u8 Copy_u8PeripheralIndex, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);
u8 NVIC_u8GetActiveFlag       (u8 Copy_u8IntID);

#endif
