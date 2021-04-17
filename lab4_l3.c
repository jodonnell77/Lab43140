///*
// * lab4_l3.c
// *
// *  Created on: Apr 16, 2021
// *      Author: JohnO
// */
//
//#include "3140_concur.h"
//#include "utils.h"
//#include "lock.h"
//
//
//lock_t l;
//void p1(void){
//	int i= 0;
//	while(i < 2) {
//		/*NCS*/
//		delay();
//		i++;
//		/*CS*/
//		l_lock(&l);
//		LEDRed_Toggle();
//		delay();
//		LEDRed_Toggle();
//		delay();
//		LEDBlue_Toggle();
//		delay();
//		LEDBlue_Toggle();
//		delay();
//		l_unlock(&l);
//	}
//}
//
//void p2(void){
//	int i= 0;
//	while(i < 4){
//		/*NCS*/
//		delay();
//		i++;
//		LEDGreen_Toggle();
//		delay();
//		LEDGreen_Toggle();
//	}
//}
//
//
//int main(void){
//	LED_Initialize();           /* Initialize the LEDs           */
//
//	l_init (&l);
//
//	if (process_create (p1,20) < 0) {
//	 	return -1;
//	}
//	if (process_create (p2,20) < 0) {
//	 	return -1;
//	}
//
//	process_start();
//	LEDGreen_On();
//
//	while(1);
//	return 0;
//}
