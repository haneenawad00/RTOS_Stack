/*
 * Port_Config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef MCAL_PORT_PORT_CONFIG_H_
#define MCAL_PORT_PORT_CONFIG_H_

#include "PORT.h"

#define SIZE   3

typedef struct {
	Dio_PortType Port ;
	Port_PinType  Pin;
	Port_PinDirectionType  Direction ;
}Port_ConfigType ;



#endif /* MCAL_PORT_PORT_CONFIG_H_ */
