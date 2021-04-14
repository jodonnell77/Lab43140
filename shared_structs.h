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
	unsigned int* curr_sp;
	unsigned int* init_sp;
	struct process_state* nextProcess;
};

/**
 * This defines the lock structure
 */
typedef struct lock_state {
	struct process_state* currently_running; //NULL if lock_taken is 0
	struct process_state* blocked_queue_start;
	unsigned int is_taken; //0: available, 1: taken
} lock_t;

/**
 * This defines the conditional variable structure
 */
typedef struct cond_var {

} cond_t;

#endif
