/*
 * lock.c
 *
 *  Created on: Apr 14, 2021
 *      Author: JohnO
 */

#include "3140_concur.h"
#include "shared_structs.h"
#include "lock.h"
#include "helper.c"

/**
 * Initialises the lock structure
 *
 * @param l pointer to lock to be initialised
 */
void l_init(lock_t* l) {
	// Disable Global interrupts
	uint32_t m = disable_int();

	//l = malloc(sizeof(lock_t));
	l->currently_running = NULL;
	l->blocked_queue_start = NULL;
	l->is_taken = 0;

	// Re-enable global interrupts
	enable_int(m);
};

/**
 * Grab the lock or block the process until lock is available
 *
 * @param l pointer to lock to be grabbed
 */
void l_lock(lock_t* l) {
	// Precondition: current_process != NULL
	//If lock is 0, set currently_running to the process that called it, is_taken to 1, and continue
	//If lock is 1, add process to the end of blocked_queue_start.

	// Disable Global interrupts
	uint32_t m = disable_int();

	if(l->is_taken == 0) {
		l->currently_running = current_process;
		l->is_taken = 1;
	} else {
		// If blocked_queue_start is empty, make this the only element
		if(l->blocked_queue_start == NULL) {
			l->blocked_queue_start = current_process;
		} else {
			// Add process to end of blocked_queue_start
			process_t* tempProcessPt = get_last(l->blocked_queue_start);
			tempProcessPt->nextProcess = current_process;
		}

	}

	//Re-enable global interrupts
	enable_int(m);
};

/**
 * Release the lock along with the first process that may be waiting on
 * the lock. This ensures fairness wrt lock acquisition.
 *
 * @param l pointer to lock to be unlocked
 */
void l_unlock(lock_t* l) {
	//If lock is 0, throw error
	//If start_of_queue is NULL, set is_taken to 0, else set currently_running to blocked_queue_start, change blocked_queue_start to blocked_queue_start->next, and keep is_taken as 1.
};




