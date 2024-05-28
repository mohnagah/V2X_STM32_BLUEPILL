#ifndef HAL_ULTRASONIC_ULTRASONIC_PRIVATE_H_
#define HAL_ULTRASONIC_ULTRASONIC_PRIVATE_H_

static void HUS_voidOVFCounts(void);
static void HUS_void_FRONT_ECHO_Interrupt(void);
static void HUS_void_F_SIDE_ECHO_Interrupt(void);
static void HUS_void_B_SIDE_ECHO_Interrupt(void);
static void HUS_void_BACK_ECHO_Interrupt(void);
#define CLEAR 0

#define PORT_A 0
#define PORT_B 1

#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7
#define PIN_8 8
#define FLAG_RISING_EDGE 0
#define FLAG_FALLING_EDGE 1
#define FLAG_CALCULATING 2

#define DISTANCE_FACTOR 58.3090379

//58.3090379


#endif /* HAL_ULTRASONIC_ULTRASONIC_PRIVATE_H_ */
