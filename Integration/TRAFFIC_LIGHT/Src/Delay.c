#include	"Std_Types.h"
#include "DELAY.h"




void _delay_ms(u32 ticks)
{
	for(u32 i =0; i<(500)*ticks; i++)
			{
				asm("NOP");
			}
}

void _delay_us(u32 ticks)
{
	for(u32 i =0; i<ticks; i++)
			{
				asm("NOP");
			}
}
