#include "PORT.h"
#include "Port_Config.h"



// configure  direction and usable pins in project
Port_ConfigType  PortCfg[]={

//lcd
		{Dio_PortA, Pin_4, PORT_PIN_OUT},
		{Dio_PortA, Pin_5, PORT_PIN_OUT},
		{Dio_PortA, Pin_6, PORT_PIN_OUT},
};
