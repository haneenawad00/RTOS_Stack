/*
 * PORT.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef MCAL_PORT_PORT_H_
#define MCAL_PORT_PORT_H_


#include  "../DIO/DIO.h"
#include <avr/io.h>


typedef enum {
	Pin_0,
	Pin_1,
	Pin_2,
	Pin_3,
	Pin_4,
	Pin_5,
	Pin_6,
	Pin_7
} Port_PinType;


typedef enum {

	PORT_PIN_IN,
	PORT_PIN_OUT
}Port_PinDirectionType;


typedef enum{
   Input,
   Output

} Port_PinModeType;


//For Set Direction
void Port_Init ();




#endif /* MCAL_PORT_PORT_H_ */
