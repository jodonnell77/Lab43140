/*
 * helper.c
 *
 *  Created on: Apr 14, 2021
 *      Author: Snove
 */

#include "shared_structs.h"
#include <stdlib.h>
#include <MKL25Z4.h>
#include "3140_concur.h"

process_t* get_last (process_t* startPt) {
	//Given a start pointer, finds the last pointer of the linked list
	while (startPt->nextProcess != NULL) {
		startPt = startPt->nextProcess;
	}
	return startPt;
}

void enable_int(uint32_t m) {
	__set_PRIMASK(m);
};

uint32_t disable_int(void){
	uint32_t m;
	m = __get_PRIMASK();
	__disable_irq();
	return m;
};
