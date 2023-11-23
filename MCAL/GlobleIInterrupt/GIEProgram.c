

#include "GIEInterface.h"
#include "GIERegister.h"
#include "../../BIT_MATH.h"
#include "../../STD_TYPES.h"


void GI_voidEnable(void){
	SET_BIT(SREG,SREG_I);
}
void GI_voidDisable(void){
	CLR_BIT(SREG,SREG_I);
}
