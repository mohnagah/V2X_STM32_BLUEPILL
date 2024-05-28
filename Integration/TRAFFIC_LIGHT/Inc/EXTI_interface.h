#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_



void MEXTI_voidInit(void);
void MTIMERx_voidUpdatePSC(u8 copy_u8TimerID, u32 copy_u32Psc, u32 copy_u32MaxValue);
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8SenseMood);
void MEXTI_voidEnableLine(u8 Copy_u8Line);
void MEXTI_voidDisableLine(u8 Copy_u8Line);
void MEXTI_voidSoftwareTrigger(u8 Copy_u8Line);
void MEXTI_voidSetCallBack (u8 copy_u8Line, void (*ptr) (void));


/*Define EXTI_SENSE_MOOD*/
typedef enum{
    EXTI_RISING_EDGE  ,
    EXTI_FALLING_EDGE ,
    EXTI_ON_CHANGE
}EXTI_Type;

/*Define EXTI_LINE_TYPE*/
typedef enum{
    EXTI_LINE0 ,
    EXTI_LINE1 ,
    EXTI_LINE2 ,
    EXTI_LINE3 ,
    EXTI_LINE4 ,
    EXTI_LINE5 ,
    EXTI_LINE6 ,
    EXTI_LINE7 ,
    EXTI_LINE8 ,
    EXTI_LINE9 ,
    EXTI_LINE10,
    EXTI_LINE11,
    EXTI_LINE12,
    EXTI_LINE13,
    EXTI_LINE14,
    EXTI_LINE15
}EXTI_LineType;

/*Another way to define EXTI_SENSE_MOOD
#define EXTI_RISING_EDGE    0
#define EXTI_FALLING_EDGE   1
#define EXTI_ON_CHANGE      2
*/

/*Another way to define EXTI_LINE_TYPE
#define EXTI_LINE0     0
#define EXTI_LINE1     1
#define EXTI_LINE2     2
#define EXTI_LINE3     3
#define EXTI_LINE4     4
#define EXTI_LINE5     5
#define EXTI_LINE6     6
#define EXTI_LINE7     7
#define EXTI_LINE8     8
#define EXTI_LINE9     9
#define EXTI_LINE10    10
#define EXTI_LINE11    11
#define EXTI_LINE12    12
#define EXTI_LINE13    13
#define EXTI_LINE14    14
#define EXTI_LINE15    15
*/




#endif
