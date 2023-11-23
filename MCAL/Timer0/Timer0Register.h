/*
 * Timer0Register.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef MCAL_TIMER0_TIMER0REGISTER_H_
#define MCAL_TIMER0_TIMER0REGISTER_H_




#define TIMSK			*((volatile u8*)0X59)
#define TIFR		     	*((volatile u8*)0X58)

	/*Timer0*/
#define TCCR0			*((volatile u8*)0X53)
#define TCNT0			*((volatile u8*)0X52)
#define OCR0			    *((volatile u8*)0X5C)


	#define TCCR0_FOC0      7
	#define TCCR0_WGM00		6
	#define TCCR0_COM01		5
	#define TCCR0_COM00		4
	#define TCCR0_WGM01		3
	#define TCCR0_CS02      2
	#define TCCR0_CS01		1
	#define TCCR0_CS00		0


#define TIMSK_TOIE0		0
#define TIMSK_OCIE0		1


#define TIFR_TOV0		0
#define TIFR_OCF0		1




#endif /* MCAL_TIMER0_TIMER0REGISTER_H_ */
