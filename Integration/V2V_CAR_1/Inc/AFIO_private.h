#ifndef _AFIO_PRIVATE_H_
#define _AFIO_PRIVATE_H_

#define AFIO_EVCR       *((volatile u32*)(0x40010000))
#define AFIO_MAPR       *((volatile u32*)(0x40010004))
#define AFIO_EXTICR1    *((volatile u32*)(0x40010008))
#define AFIO_EXTICR2    *((volatile u32*)(0x4001000C))
#define AFIO_EXTICR3    *((volatile u32*)(0x40010010))
#define AFIO_EXTICR4    *((volatile u32*)(0x40010014))
#define AFIO_MAPR2      *((volatile u32*)(0x4001001C))


#endif
