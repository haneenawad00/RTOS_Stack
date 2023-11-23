/*
 * Timer0Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef MCAL_TIMER0_TIMER0CONFIG_H_
#define MCAL_TIMER0_TIMER0CONFIG_H_

#define   PreLoadValue  113
#define Timer0_overFlow_Counter  976
#define   TIMER0_CTC_VAL      249


#define   TMR0_MODE               TMR0_CTC_MODE
#define TMR0_PRESCALLER    TMR0_PRESCALLER_64
/*
TMR0_PWM_MODE options:

1. TMR0_PWM_INVERTING
2. TMR0_PWM_NONINVERTING
*/
#define TMR0_PWM_INMODE				TMR0_PWM_NONINVERTING
/*
 * option for TMR0 MODES :
 * 1-TMR0_NORMAL_MODE
 * 2-TMR0_CTC_MODE
 */

#endif /* MCAL_TIMER0_TIMER0CONFIG_H_ */
