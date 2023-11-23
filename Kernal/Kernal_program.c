/*
 * Kernal_program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */
#include "../STD_TYPES.h"
#include "../BIT_MATH.h"
#include "../MCAL/Timer0/Timer0Interface.h"
#include "../MCAL/GlobleIInterrupt/GIEInterface.h"

#include "Kernal_interface.h"
#include "Kernal_private.h"
#include "Kernal_config.h"

typedef struct {
	u16 Periodicity;
	void (*TaskFunc)(void);
}Task_type;

Task_type SystemTasks[TASK_NUM] = {{NULL}};

void RTOS_voidStart(void){

Timer0_voidSetCallBack(Scheduler);
GI_voidEnable();
Timer0_voidInit();
Timer0_voidStart();

}
void RTOS_voidCreateTask(u8 Copu_u8Priority , void (*Copy_TaskFunc)(void) , u16 Copy_u16Periodicity){

	if (Copy_TaskFunc != NULL){
		    SystemTasks[Copu_u8Priority].Periodicity = Copy_u16Periodicity;
		    SystemTasks[Copu_u8Priority].TaskFunc = Copy_TaskFunc;
	}

}
static void Scheduler(void){
     volatile static  u16  Local_u16SysTickCounter=0;
     Local_u16SysTickCounter++;
     u8 Local_TaskCounter;
     for (Local_TaskCounter=0; Local_TaskCounter<TASK_NUM ; Local_TaskCounter++){
    	 if (Local_u16SysTickCounter % SystemTasks[Local_TaskCounter].Periodicity ==0){
    		   if (SystemTasks[Local_TaskCounter].TaskFunc != NULL){
    			   SystemTasks[Local_TaskCounter].TaskFunc();
    		   }
    	 }else {

    	 //nothing
     }}}
