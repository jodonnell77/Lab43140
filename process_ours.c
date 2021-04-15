///*
// * process.c
// *
// *  Created on: Apr 14, 2021
// *      Author: JohnO
// *
// *      COPIED FROM LAB 3
// */
//
//#include <stdlib.h>
//#include <MKL25Z4.h>
//#include "3140_concur.h"
//#include "shared_structs.h"
//#include "helper.h"
//
//
//process_t* process_queue = NULL;
//process_t* current_process = NULL;
//
//int process_create (void (*f)(void), int n) {
//	// Disable Global interrupts
//	uint32_t m = disable_int();
//
//
//	unsigned int * procPointer =  process_stack_init(*f, n);
//
//	if(procPointer == NULL) {
//		return -1;
//	} else {
//		//Initializes the process to be added onto the linked list
//		process_t* elementPt;
//		elementPt = malloc(sizeof(process_t));
//		elementPt->curr_sp = procPointer;
//		elementPt->init_sp = procPointer;
//		elementPt->nextProcess = NULL;
//		elementPt->size = n;
//		elementPt->is_blocked = 0; //ADDED
//
//		//Make this the only element of the list if the list is empty
//		if(process_queue == NULL) {
//			process_queue = elementPt;
//		} else {
//			//Create a temporary process state, and keep updating it until it is the last element
//			process_t* tempProcessPt = get_last(process_queue);
//			tempProcessPt->nextProcess = elementPt;
//		}
//
//		// Re-enable global interrupts
//		enable_int(m);
//
//		return 0;
//	}
//
//}
//
//void process_start(void) {
//	NVIC_EnableIRQ(PIT_IRQn);
//	SIM->SCGC6 = SIM_SCGC6_PIT_MASK; // Enable clock to PIT module
//	PIT->MCR = (0 << 1); // Enable clock for MCR
//	PIT->CHANNEL[0].LDVAL = 0x0FF00; // Set load value of zeroth PIT
//	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TIE_MASK; // Enable timer for interrupts
//	process_begin();
//}
//
//extern unsigned int * process_select (unsigned int * cursp) {
//
//	if (current_process != NULL) {
//		//Shifts the beginning of the linked list to one forward
//		process_queue = current_process->nextProcess;
//		//If a current stack pointer exists, change linked list
//		if (cursp != NULL) {
//
//			//If there was one element left in the linked list (current_process->nextProcess->nextProcess doesn't exist)
//			if (process_queue == NULL) { process_queue = current_process; }
//			else {
//				//Similar to process_create, reach end of linked list and append to it
//				process_t* tempProcessPt = get_last(process_queue);
//				tempProcessPt->nextProcess = current_process;
//			}
//			//Updating fields for current process
//			current_process->curr_sp = cursp;
//			current_process->nextProcess = NULL;
//
//		} else {
//			//Free up memory for the stack, then for the current process
//			process_stack_free(current_process->init_sp, current_process->size);
//			free(current_process);
//		}
//	}
//	//If there is a beginning to the linked list, update current and return its stack pointer
//	if(process_queue != NULL) {
//		current_process = process_queue;
//		return  process_queue->curr_sp; }
//	//If there is no beginning to the linked list, then there is no current pointer.
//	return NULL;
//}
//
//
//
//
//
//
