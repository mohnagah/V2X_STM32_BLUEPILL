#ifndef STD_TYPES_H_
#define STD_TYPES_H_

//#define NULL_PTR	(void *)0
#define NULL ((void *)0)
typedef unsigned char				u8;
typedef signed char					s8;
typedef unsigned short int			u16;
typedef signed short int			s16;
typedef unsigned long			u32;
typedef signed long int				s32;
typedef unsigned long long int		u64;
typedef signed long long int		s64;
typedef float						f32;
typedef double						f64;
typedef long double					f128;
typedef enum
{
	R_NOK        ,
	R_OK         ,
	TIMER0_OK    ,
	TIMER0_NOK   ,
	TIMER2_OK    ,
	TIMER2_NOK   ,
	NULL_POINTER ,
	BUSY_FUNC	 ,
	DCMOTOR_OK	,
	DCMOTOR_NOK	,
	TIMER1_OK,
	TIMER1_NOK
}error_state_t;
typedef enum {
	FALSE,
	TRUE
} BooleanType;

//typedef enum{
//
//	OK=0,
//	NOK,
//	OUT_OF_RANGE,
//	NULL_PTR
//
//}Error_t;
#endif /* STD_TYPES_H_ */
