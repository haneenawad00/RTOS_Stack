
#include "DIO.h"
#include "avr/io.h"
#include  "../../BIT_MATH.h"


void Dio_WriteChannel( Dio_ChannelType   ChannelId   ,   Dio_LevelType Level ){
//using if statment
/*  if ((ChannelId  >=  0) && (ChannelId < 8 )){
     if (Level == 1 ){

    	 SET_BIT(PORTA  , ChannelId);
     }else {

    	 CLR_BIT(PORTA , ChannelId );
     }

                                                                    }
  else if ( (ChannelId  >=8 ) && (ChannelId<16)){
	   if (Level == 1 ){

	    	 SET_BIT(PORTB  , ChannelId %8);
	     }else {

	    	 CLR_BIT(PORTB , ChannelId %8  );
	     }                                                                  }
	   else if ( (ChannelId  >=16 ) && (ChannelId< 24)){
	  	   if (Level == 1 ){

	  	    	 SET_BIT(PORTC , ChannelId %8);
	  	     }else {

	  	    	 CLR_BIT(PORTC , ChannelId %8  );
	  	     }                                                                   }
	   else if ( (ChannelId  >=24 ) && (ChannelId< 32)){
	  	  	   if (Level == 1 ){

	  	  	    	 SET_BIT(PORTD  , ChannelId %8);
	  	  	     }else {

	  	  	    	 CLR_BIT(PORTD , ChannelId %8  );
	  	  	     }                                                                   }*/


//using switch

	   Dio_PortType   port = ChannelId / 8 ;

		switch(port ){

		case Dio_PortA  :
			 if (Level == 1 ){

			    	 SET_BIT(PORTA  , ChannelId);
			     }else {

			    	 CLR_BIT(PORTA , ChannelId );
			     }

			  break;
		case Dio_PortB :
			   if (Level == 1 ){

			    	 SET_BIT(PORTB  , ChannelId %8);
			     }else {

			    	 CLR_BIT(PORTB , ChannelId %8  );
			     }
					  break;
		case Dio_PortC :
			  if (Level == 1 ){

						  	    	 SET_BIT(PORTC , ChannelId %8);
						  	     }else {

						  	    	 CLR_BIT(PORTC , ChannelId %8  );
						  	     }
					  break;
		case Dio_PortD :

		  	   if (Level == 1 ){

			  	  	    	 SET_BIT(PORTD  , ChannelId %8);
			  	  	     }else {

			  	  	    	 CLR_BIT(PORTD , ChannelId %8  );
			  	  	     }
					  break;

	}

}

Dio_LevelType  Dio_ReadChannel  ( Dio_ChannelType  ChannelId)
{

	     Dio_PortType   port = ChannelId / 8 ;

	switch(port ){

	case Dio_PortA  :
		 return GET_BIT(PINA , ChannelId%8);   //misra rules (one place on return ) then put it i local variable
		  break;
	case Dio_PortB :
		 return GET_BIT(PINB , ChannelId %8);
		 break;
	case Dio_PortC :
		 return GET_BIT(PINC , ChannelId %8);
		  break;
	case Dio_PortD :
		 return GET_BIT(PIND , ChannelId %8);
		  break;
	default : return 0;

}
}
void   Dio_FlipChannel( Dio_ChannelType ChannelId) {

	     Dio_PortType   port = ChannelId / 8 ;

	switch(port ){

	case Dio_PortA  :
		    TOG_BIT(PORTA ,ChannelId %8 );
			 break;
	case Dio_PortB :
		 TOG_BIT(PORTB ,ChannelId %8 );
		 break;
	case Dio_PortC :
		 TOG_BIT(PORTC ,ChannelId %8 );
		  break;
	case Dio_PortD :
		 TOG_BIT(PORTD ,ChannelId %8 );
		  break;


	}


}

