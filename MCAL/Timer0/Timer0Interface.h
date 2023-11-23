/*
 * Timer.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef MCAL_TIMER0_TIMER0INTERFACE_H_
#define MCAL_TIMER0_TIMER0INTERFACE_H_
#include "../../STD_TYPES.h"


void  Timer0_voidInit(void);
void  Timer0_voidStart();
void Timer0_voidStop();
void Timer0_voidSetCallBack(  void (*ptr)(void));
void Timer0_setCTCValue(u8 value);
void Timer0_setDelay_ms_UsingCTC(  u16  copy_u16delay_ms);
void Timer0_voidSetDutyCycleUsingPWM(u8 copy_u8DutyCycle);


#endif /* MCAL_TIMER0_TIMER0INTERFACE_H_ */
