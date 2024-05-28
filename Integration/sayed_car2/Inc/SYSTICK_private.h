#ifndef MCAL_SYSTICK_SYSTICK_PRIVATE_H_
#define MCAL_SYSTICK_SYSTICK_PRIVATE_H_

/* --------------------------------- Global --------------------------------- */
u8 STK_u8IntervalMode;
void (*CallBack)(void);
/* -------------------------------------------------------------------------- */
#define Null 0
/* -------------------------------------------------------------------------- */
/* ----------------------------- Interval Modes ----------------------------- */
#define STK_SINGLE_MODE 1
#define STK_PERIODIC_MODE 2
/* -------------------------------------------------------------------------- */
/* ------------------------------- Flag Values ------------------------------ */
/* ------------------------------- Tick Source ------------------------------ */
#define AHB_TICK_BY_8 0
#define AHB_TICK 1
/* -------------------------------------------------------------------------- */
/* ------------------------------- Flag Values ------------------------------ */
#define FLAG_DOWN 0
#define FLAG_UP 1
/* -------------------------------------------------------------------------- */
/* ------------------------------ CTRL Register ----------------------------- */
#define CTRL_ENABLE 0
#define CTRL_TICK_INT 1
#define CTRL_CLKSOURCE 2
#define CTRL_COUNT_FLAG 16
/* -------------------------------------------------------------------------- */
/* ---------------------------- Systick Register ---------------------------- */
#define SYSTICK_BASE_ADDRESS 0xE000E010
typedef struct
{
    u32 CTRL;
    u32 LOAD;
    u32 VAL;
    u32 CALIB;

} SYSTICK_MemMap_t;

#define STK ((volatile SYSTICK_MemMap_t *)(SYSTICK_BASE_ADDRESS))
/* -------------------------------------------------------------------------- */

#endif /* MCAL_SYSTICK_SYSTICK_PRIVATE_H_ */
