/*
 * DIO_MemMap.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef MCAL_DIO_DIO_MEMMAP_H_
#define MCAL_DIO_DIO_MEMMAP_H_


//Group A Registers
#define DDRA            *((volatile u8*)0X3A)
#define PORTA			*((volatile u8*)0X3B)
#define PINA            	*((volatile u8*)0X39)
//Group B Registers
#define DDRB     	*((volatile u8*)0X37)
#define PORTB   	*((volatile u8*)0X38)
#define PINB   	    *((volatile u8*)0X36)
//Group C Registers
#define DDRC 	*((volatile u8*)0X34)
#define PORTC  	*((volatile u8*)0X35)
#define PINC   	*((volatile u8*)0X33)
//Group D Registers
#define DDRD    	*((volatile u8*)0X31)
#define PORTD      *((volatile u8*)0X32)
#define PIND       	*((volatile u8*)0X30)



#endif /* MCAL_DIO_DIO_MEMMAP_H_ */
