//TODO: Write your info

#include <msp430g2553.h>
#include "i2c.h"
#include "MMA8452.h"

//global variables 
int X_value,Y_value,Z_value;


void main(void)
{
	P2SEL=0;
	P2SELH=0;
	P2DIR=0xFF;
	i2c_init();
	i2c_WriteOneByte(0x00,0x0E);
	standby();
	for (;;)
	{
		active();
		Read_X_Value();
		Read_Y_Value();
		Read_Z_Value();
		_delay_cycles(500000);
	}
}