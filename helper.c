/*
 * helper.c
 *
 *  Created on: Apr 15, 2021
 *      Author: JohnO
 */
#include <MKL25Z4.h>
#include "shared_structs.h"
#include "3140_concur.h"
#include "helper.h"

// Helper Functions
process_t* get_last (process_t* startPt) {
	//Given a start pointer, finds the last pointer of the linked list
	while (startPt->next != NULL) {
		startPt = startPt->next;
	}
	return startPt;
}

void enable_int(uint32_t m) {
	__set_PRIMASK(m);
	//OR NVIC_EnableIRQ(PIT_IRQn)
};

uint32_t disable_int(void){
	uint32_t m;
	m = __get_PRIMASK();
	__disable_irq();
	//OR NVIC_DisableIRQ(PIT_IRQn)
	return m;
};
