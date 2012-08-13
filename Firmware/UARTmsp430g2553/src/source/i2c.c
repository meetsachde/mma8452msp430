/*
 * i2c.c
 *
 *  Created on: 13 Aug 2012
 *      Author: Cu Xuan Duc
 */

#include <msp430g2553.h>
#include "../header/i2c.h"


#define SDA     BIT7 //P1.7
#define SCL     BIT6 //P1.6

//------------------------------------------------------------------------------
// I2C initialization
//------------------------------------------------------------------------------
void i2c_init(){
  WDTCTL = WDTPW + WDTHOLD;               // Stop watchdog timer
  P1DIR |= BIT0;                            // P1.0 output
  P1SEL |= BIT6 + BIT7;                     // Assign I2C pins to USCI_B0
  P1SEL2|= BIT6 + BIT7;                     // Assign I2C pins to USCI_B0
  UCB0CTL1 |= UCSWRST;                      // Enable SW reset
  UCB0CTL0 = UCMST + UCMODE_3 + UCSYNC;     // I2C Master, synchronous mode
  UCB0CTL1 = UCSSEL_2 + UCSWRST;            // Use SMCLK, keep SW reset
  UCB0BR0 = 12;                             // fSCL = SMCLK/12 = ~100kHz
  UCB0BR1 = 0;
  UCB0I2CSA = 0x1D;                         // MMA8452 address=0x1d
  UCB0CTL1 &= ~UCSWRST;                     // Clear SW reset, resume operation
}

//------------------------------------------------------------------------------
// I2C start
//------------------------------------------------------------------------------
void i2c_start(void){
	UCB0CTL1 |= UCTXSTT;                    // I2C start condition
	while (UCB0CTL1 & UCTXSTT);             // Start condition sent?
}

//------------------------------------------------------------------------------
// I2C stop
//------------------------------------------------------------------------------
void i2c_stop(void){
	UCB0CTL1 |= UCTXSTP;                    // I2C stop condition
	while(UCB0CTL1 & UCTXSTP);
}

//------------------------------------------------------------------------------
// read 1 byte data from a register
//------------------------------------------------------------------------------
char i2c_ReadOneByte(char address){
	while(UCB0CTL1 & UCTXSTP);				// Ensure stop condition got sent
	UCB0CTL1 |= UCTXSTT + UCTR;				// Send start condition
	while(UCB0CTL1 & UCTXSTT)				// Ensure start condition got sent
	UCB0TXBUF = address;					// Send register address
	UCB0CTL1 &= ~UCTR;						// Receive mode
	UCB0CTL1 |= UCTXSTT;					// Repeat start condition
	while(UCB0CTL1 & UCTXSTT);
	UCB0CTL1 |= UCTXSTP;					// Send stop condition
	while(UCB0CTL1 & UCTXSTP);
	return UCB0RXBUF;
}

//------------------------------------------------------------------------------
// write 1 byte data to a register
//------------------------------------------------------------------------------
void i2c_WriteOneByte(char data,char address){
	while(UCB0CTL1 & UCTXSTP);				// Loop until I2C STT is sent
	UCB0CTL1 |= UCTXSTT + UCTR;				// I2C TX, start condition
	while(!(IFG2 & UCB0TXIFG));
	IFG2&=~UCB0TXIFG;
	UCB0TXBUF = address;
	while(!(IFG2 & UCB0TXIFG));
	IFG2&=~UCB0TXIFG;
	UCB0TXBUF = data;
	while(!(IFG2 & UCB0TXIFG));
	UCB0CTL1 |= UCTXSTP;					//I2C stop condition after 1st TX
	IFG2 &= ~UCB0TXIFG;                     // Clear USCI_B0 TX interrupt flag
}

