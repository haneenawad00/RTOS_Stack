/*
 * DIO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_


typedef enum {
	PinA_0,
	PinA_1,
	PinA_2,
	PinA_3,
	PinA_4,
	PinA_5,
	PinA_6,
	PinA_7,
	PinB_0,
	PinB_1,
	PinB_2,
	PinB_3,
	PinB_4,
	PinB_5,
	PinB_6,
	PinB_7,
	PinC_0,
	PinC_1,
	PinC_2,
	PinC_3,
	PinC_4,
	PinC_5,
	PinC_6,
	PinC_7,
	PinD_0,
	PinD_1,
	PinD_2,
	PinD_3,
	PinD_4,
	PinD_5,
	PinD_6,
	PinD_7
} Dio_ChannelType;

typedef enum {
	Dio_PortA, Dio_PortB, Dio_PortC, Dio_PortD
} Dio_PortType;

typedef enum {
	STD_LOW, STD_HIGH
} Dio_LevelType;


void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void    Dio_FlipChannel( Dio_ChannelType ChannelId) ;
#endif /* MCAL_DIO_DIO_H_ */
