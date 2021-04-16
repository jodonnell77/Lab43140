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
	unsigned int is_blocked; //0: not blocked, 1: is blocked
	unsigned int* sp;
	unsigned int* orig_sp;
	struct process_state* next;
};

/**
 * This defines the lock structure
 */
typedef struct lock_state {
	struct process_state* blocked_queue_start;
	unsigned int is_taken; //0: available, 1: taken
} lock_t;

/**
 * This defines the conditional variable structure
 */
typedef struct cond_var {

} cond_t;

#endif
