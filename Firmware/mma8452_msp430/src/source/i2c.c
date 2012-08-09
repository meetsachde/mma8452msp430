/*
 * i2c.c
 *
 *  Created on: 9 Aug 2012
 *      Author: WIN7
 */

#include <msp430g2553.h>
#include "../header/i2c.h"

#define SDA     BIT7 //P1.7
#define SCL     BIT6 //P1.6

/*i2c initialization*/
void i2c_init(){
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
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

/*i2c start*/
void i2c_start(void){
	// Send i2c START condition
    USISRL = 0x00; 							// Load USISRL Lower Byte Shift Register MSB with 0 for i2c START
    USICTL0 |= USIGE | USIOE; 				// Force Output Latch, And Enable Data Output Bit (High to Low SDA while SCL is High)
    USICTL0 &= ~USIGE; 						// Clear Output Latch (Return to Clock Control)
}

/*i2c stop*/
void i2c_stop(void){
	// Prepare i2c STOP condition
    USICTL0 |= USIOE; 						// Enable Data Output Bit (Turn SDA into Output)
    USISRL = 0x00;							// Load USISRL Lower Byte Shift Register MSB with 0 for i2c STOP
    USICNT = 1; 							// Load USICNT Counter with number of Bits to Send. USIIFG Auto-Cleared
    // Data TXed by USI I2C
    while((USICTL1 & USIIFG) != 0x01); 		// Delay, Wait for USIIFG, Counter down to 0


	// Send i2c STOP condition
    USISRL = 0xFF; 							// Load USISRL Lower Byte Shift Register MSB with 1 for i2c STOP
    USICTL0 |= USIGE; 						// Force Output Latch (Low to High SDA while SCL is High)
    USICTL0 &= ~USIOE & ~USIGE ; 			// Clear Data Output Enable Bit and Output Latch (Release SCL)
}

/*read 1 byte data from a register*/
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

/*write 1 byte data to a register*/
void i2c_WriteOneByte(char data,char address){
	while(UCB0CTL1 & UCTXSTP);
	UCB0CTL1 |= UCTXSTT + UCTR;
	while(!(IFG2 & UCB0TXIFG));
	UCB0TXBUF = address;
	while(!(IFG2 & UCB0TXIFG));
	UCB0TXBUF = data;
	while(!(IFG2 & UCB0TXIFG));
	UCB0CTL1 |= UCTXSTP;
	IFG2 &= ~UCB0TXIFG;                     // Clear USCI_B0 TX int flag
}
