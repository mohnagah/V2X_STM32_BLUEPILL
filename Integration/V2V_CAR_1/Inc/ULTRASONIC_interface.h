#ifndef HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_
#define HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_

#define US_FRONT 0
#define US_F_SIDE 1
#define US_B_SIDE 2
#define US_BACK 3



/* ************************************************************************** */
/* Function : HUS_voidInit							                       	  */
/* Argument : void						             						  */
/* Returns  : void		                                                      */
/* Role     : Setup timer and interrupt of ICU/OVF				        	  */
/* ************************************************************************** */
void HUS_voidInit(void);

/* ************************************************************************** */
/* Function : HUS_voidGetDistance					                       	  */
/* Argument : Pointer to distance variable		       						  */
/* Returns  : void		                                                      */
/* Role     : Calculate Distance of US wave						        	  */
/* ************************************************************************** */
void HUS_voidGetDistance(u8 copy_u8UltrasonicID, u16 *ptr_u16Distance);

/* ************************************************************************** */
/* Function : HUS_voidGetAvgDistance				                       	  */
/* Argument : Pointer to Average distance variable	  						  */
/* Returns  : void		                                                      */
/* Role     : Get Average of Sensor Readings					        	  */
/* ************************************************************************** */
void HUS_voidGetAvgDistance(u16 *ptr_u16AvgDistance);


void MTIMERx_voidSetOVFCallback(u8 copy_u8TimerID, timer_callback_t ptr);

#endif /* HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_ */
