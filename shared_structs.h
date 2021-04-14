#ifndef __SHARED_STRUCTS_H__
#define __SHARED_STRUCTS_H__

/** Implement your structs here */

/**
 * This structure holds the process structure information
 *
 * COPIED FROM LAB 3
 */
struct process_state {
	unsigned int size;
	unsigned int* curr_sp;
	unsigned int* init_sp;
	struct process_state* nextProcess;
};

/**
 * This defines the lock structure
 */
typedef struct lock_state {
	
} lock_t;

/**
 * This defines the conditional variable structure
 */
typedef struct cond_var {

} cond_t;

#endif
