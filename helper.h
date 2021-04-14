/*
 * helper.h
 *
 *  Created on: Apr 14, 2021
 *      Author: Snove
 */

#ifndef HELPER_H_
#define HELPER_H_

process_t* get_last (process_t* startPt);

void enable_int(uint32_t m);

uint32_t disable_int(void);

#endif /* HELPER_H_ */
