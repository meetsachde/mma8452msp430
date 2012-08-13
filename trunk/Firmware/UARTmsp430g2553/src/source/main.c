/****************************************************************
*
* www.payitforward.edu.vn
*
****************************************************************/
/****************************************************************
*
* MSP430 Training Course
*
****************************************************************/
/****************************************************************
*
*    Module        : main.c
*    Description  : Read sensor mma 8452 data and transmit data to computer using uart
*
*    Tool            : Launchpad
*    Chip            : MSP430G2553
*     History       : 13/08/2012
*
*    Author        : Cu Xuan Duc
*    Notes          :
*
*
****************************************************************/
/****************************************************************
* IMPORT
****************************************************************/
#include "msp430g2553.h"
#include "../header/i2c.h"
#include "../header/uart.h"
#include "../header/mma8452.h"
/****************************************************************
* EXTERN
****************************************************************/

/*none...*/

/*****************************************************************/

/*****************************************************************
GLOBAL VARIABLE
******************************************************************/

int X_read_sensor,Y_read_sensor,Z_read_sensor;

/*****************************************************************
* ROUTINES
******************************************************************/
//------------------------------------------------------------------------------
// convert value to number to display on computer using uart
//------------------------------------------------------------------------------
void xuliso(char so)
{
	unsigned char i=0,j;
	unsigned int kq[10];
	while (so!=0)
	{
		i++;
		kq[i]=so%10;
		so=so/10;
	}
	for (j=1;j<i+1;j++)
		TimerA_UART_tx(kq[i-j+1]+0x30);
}
//------------------------------------------------------------------------------
// convert value read from sensor to real value
//------------------------------------------------------------------------------
void chuyengiatri(char data_in){
	float data_out;
	if(data_in==0xFF)	TimerA_UART_tx(0x30);
	if ((data_in & 0x80)==0){
		data_out= data_in*2*10/128;
	    xuliso(data_out);
	}
	else
	{
	    data_out=(256-data_in)*2/128;
	    TimerA_UART_print("-");
	    xuliso(data_out);
	}
}

//------------------------------------------------------------------------------
// delay 1s
//------------------------------------------------------------------------------
void delay1s(){
	char m;
	for(m=0;m<5;m++)
	    _delay_cycles(200000);
}
/****************************************************************
* MAIN
****************************************************************/
/* -- void main (void)    -----------------------------------------
*
* Description    : Configure port,read data from 3 register 0x01:OUT_X_MSB
					,0x03:OUT_Y_MSB,0x05:OUT_Z_MSB of MMA8452
*
* Parameters    : none
* Return        : don't care
* Notes        :
*/
void main(void)
{
	i2c_init();
	uart_init();
	i2c_WriteOneByte(0x00,0x0E);
	mma8452_standby();
	TimerA_UART_print("msp430g2553 UART+mma8452\r\n");
	TimerA_UART_print("hello.\r\n");
	for(;;)
    {
    	mma8452_active();
    	X_read_sensor=i2c_ReadOneByte(0x01);
    	Y_read_sensor=i2c_ReadOneByte(0x03);
    	Z_read_sensor=i2c_ReadOneByte(0x05);

    	TimerA_UART_print("X:");
    	chuyengiatri(X_read_sensor);
    	TimerA_UART_print("m/s2 ");
    	TimerA_UART_print("\n");

    	TimerA_UART_print("Y:");
    	chuyengiatri(Y_read_sensor);
    	TimerA_UART_print("m/s2 ");
    	TimerA_UART_print("\n");

    	TimerA_UART_print("Z:");
    	chuyengiatri(Z_read_sensor);
    	TimerA_UART_print("m/s2 ");
    	TimerA_UART_print("\n");
    	delay1s();
    }
}

/****************************************************************
 * END OF main.c
 ****************************************************************/












