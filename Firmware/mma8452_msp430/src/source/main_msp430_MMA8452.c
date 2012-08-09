/*
 * main_msp430_MMA8452.c
 *
 *  Created on: 9 Aug 2012
 *      Author: WIN7
 */


#include<msp430g2553.h>
#include "../header/i2c.h"
#include "../header/MMA8452.h"

void main(){
	i2c_init();
	P2SEL = 0;
	P2SEL2 = 0;
	P2DIR = 0xFF;
	i2c_WriteOneByte(0x00,0x0E);
	standby();
	while(1){
		active();
		P2OUT = ~i2c_ReadOneByte(0X03);
		_delay_cycles(500000);
	}
}
