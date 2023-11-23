/*
 * PORT.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#include "PORT.h"
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "Port_Config.h"
#include <avr/io.h>

extern Port_ConfigType  PortCfg[];

void Port_Init (){

int i =0;
for ( i = 0 ; i < SIZE  ;  i++ ){
	switch (PortCfg[i] .Port){
	case Dio_PortA:
		 if( PortCfg[i].Direction ==  PORT_PIN_OUT){
			 SET_BIT(DDRA , PortCfg[i].Pin);}
		 else {
			 CLR_BIT(DDRA , PortCfg[i].Pin) ;
		 }
        break;
	case Dio_PortB:
			 if( PortCfg[i].Direction ==  PORT_PIN_OUT){
				 SET_BIT(DDRB , PortCfg[i].Pin);}
			 else {
				 CLR_BIT(DDRB, PortCfg[i].Pin) ;
			 }
	        break;
	case Dio_PortC:
			 if( PortCfg[i].Direction ==  PORT_PIN_OUT){
				 SET_BIT(DDRC , PortCfg[i].Pin);}
			 else {
				 CLR_BIT(DDRC , PortCfg[i].Pin) ;
			 }
	        break;
	case Dio_PortD:
			 if( PortCfg[i].Direction ==  PORT_PIN_OUT){
				 SET_BIT(DDRD , PortCfg[i].Pin);}
			 else {
				 CLR_BIT(DDRD , PortCfg[i].Pin) ;
			 }
	        break;
	}
}


}
