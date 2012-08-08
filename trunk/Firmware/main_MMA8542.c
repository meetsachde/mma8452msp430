//TODO: Write your info

#include <msp430.h>
//TODO: Add your header files here

//global variables 
//YOUR_TYPE_VAR X_value;
//YOUR_TYPE_VAR Y_value;
//YOUR_TYPE_VAR Z_value;


void main(void)
{
	init();
	
	for (;;)
	{
		X_value = Read_X_Value();
		Y_value = Read_Y_Value();
		Z_value = Read_Z_Value();
	}
}