/*
 * TimerProgram.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */


#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"

#include "Timer0Interface.h"
#include "Timer0Register.h"
#include "Timer0Config.h"
#include "Timer0Private.h"


static void (*PtrCallBackOVF0)(void)= NULL;
 volatile static  u32  CTC_Counter =0;

void  Timer0_voidInit(void){

 #if   TMR0_MODE == TMR0_NORMAIL_MODE

	CLR_BIT(TCCR0 , TCCR0_WGM00) ;
	CLR_BIT(TCCR0 , TCCR0_WGM01) ;
		//set Preload Value
	TCNT0 = PreLoadValue ;


  #elif  TMR0_MODE == TMR0_CTC_MODE
	//set Compare Match Mode
			CLR_BIT(TCCR0 , TCCR0_WGM00) ;
			SET_BIT(TCCR0 , TCCR0_WGM01) ;
	//enable Timer0 interrupt (ctc)
	SET_BIT(TIMSK , TIMSK_OCIE0) ;

#elif TMR0_MODE == TMR0_PWM_MODE
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);

	#if TMR0_PWM_INMODE	 == TMR0_PWM_INVERTING
	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

	#elif TMR0_PWM_INMODE	 == TMR0_PWM_NONINVERTING
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);

#elif   TMR0_MODE == TMR0_PHASECOREECT_MODE
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0, TCCR0_WGM01);


		#if TMR0_PHASECOREECT_MODE == TMR0_PHASECORRECT_NONINVERTING
				CLR_BIT(TCCR0 , TCCR0_COM00) ;
				SET_BIT(TCCR0 , TCCR0_COM01) ;
		#elif TMR0_PHASECOREECT_MODE == TMR0_PHASECORRECT_INVERTING
				SET_BIT(TCCR0 , TCCR0_COM00) ;
				SET_BIT(TCCR0 , TCCR0_COM01) ;
	#endif
#endif

	//enable Timer0 interrupt (normal )
	SET_BIT(TIMSK , TIMSK_TOIE0);
#endif

}




void  Timer0_voidStart(){

#if  TMR0_PRESCALLER == TMR0_PRESCALLER_1
	   SET_BIT(TCCR0 , TCCR0_CS00);
      CLR_BIT(TCCR0 , TCCR0_CS01);
	   CLR_BIT(TCCR0 , TCCR0_CS02);


#elif  TMR0_PRESCALLER == TMR0_PRESCALLER_8
	    CLR_BIT(TCCR0 , TCCR0_CS00);
	   SET_BIT(TCCR0 , TCCR0_CS01);
	   CLR_BIT(TCCR0 , TCCR0_CS02);


#elif  TMR0_PRESCALLER == TMR0_PRESCALLER_64

   SET_BIT(TCCR0 , TCCR0_CS00);
   SET_BIT(TCCR0 , TCCR0_CS01);
   CLR_BIT(TCCR0 , TCCR0_CS02);

#elif  TMR0_PRESCALLER == TMR0_PRESCALLER_256

   CLR_BIT(TCCR0 , TCCR0_CS00);
   CLR_BIT(TCCR0 , TCCR0_CS01);
     SET_BIT(TCCR0 , TCCR0_CS02);


#elif  TMR0_PRESCALLER == TMR0_PRESCALLER_1024

      SET_BIT(TCCR0 , TCCR0_CS00);
       CLR_BIT(TCCR0 , TCCR0_CS01);
         SET_BIT(TCCR0 , TCCR0_CS02);

#endif

}

void Timer0_voidStop(){
   //Stop Timer
	CLR_BIT(TCCR0 ,TCCR0_CS00);
	CLR_BIT(TCCR0 , TCCR0_CS01);
	CLR_BIT(TCCR0 , TCCR0_CS02);
}

void Timer0_setCTCValue(u8 value){
	OCR0 = value;

}


void Timer0_voidSetDutyCycleUsingPWM(u8 copy_u8DutyCycle){
	 if(copy_u8DutyCycle){

#if TMR0_PWM_INMODE	 == TMR0_PWM_NONINVERTING
      OCR0 = (((u16)copy_u8DutyCycle *256)/100)-1;

#elif TMR0_PWM_INMODE	 == TMR0_PWM_INVERTING

      copy_u8DutyCycle = 100- copy_u8DutyCycle;
      OCR0 = (((u16)copy_u8DutyCycle *256)/100)-1;


#elif TMR0_PHASECOREECT_MODE == TMR0_PHASECORRECT_NONINVERTING
      OCR0 = (((u16)copy_u8DutyCycle *256)/100)-1;
#elif TMR0_PHASECOREECT_MODE == TMR0_PHASECORRECT_INVERTING
      copy_u8DutyCycle = 100- copy_u8DutyCycle;
            OCR0 = (((u16)copy_u8DutyCycle *256)/100)-1;

#endif

	 }
}

void Timer0_voidSetCallBack(  void (*ptr)(void)){
	  if(ptr != NULL){

		  PtrCallBackOVF0 = ptr ;
	  }
	  }
void Timer0_setDelay_ms_UsingCTC(  u16  copy_u16delay_ms){



#if  TMR0_PRESCALLER == TMR0_PRESCALLER_64
	//under condition : tick time = 4 Ms .
	OCR0= 249;
	CTC_Counter = copy_u16delay_ms;
#endif




}

//ISR Timer0 Overflow
void  __vector_11(void) __attribute__  ((signal));
void __vector_11(void){
	static u16   Local_u16OVFCounter =0;
	Local_u16OVFCounter++;

	if(Timer0_overFlow_Counter == Local_u16OVFCounter ){
		//clear counter
		Local_u16OVFCounter=0;
		 TCNT0= PreLoadValue;
	  	 if ( PtrCallBackOVF0 != NULL){
	  		  PtrCallBackOVF0();
	  	 }

	}
}


void  __vector_10(void) __attribute__  ((signal));
void __vector_10(void){
	static u16   Local_u16OVFCounter =0;
	Local_u16OVFCounter++;

	if(CTC_Counter== Local_u16OVFCounter ){
		//clear counter
		Local_u16OVFCounter =0;

	  	 if ( PtrCallBackOVF0 != NULL){
	  		  PtrCallBackOVF0();
	  	 }

	}
}
