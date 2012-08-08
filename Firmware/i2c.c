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
  UCB0I2CSA = 0x1D;                         // MMA address
  UCB0CTL1 &= ~UCSWRST;                     // Clear SW reset, resume operation
}

char read_i2c(char reg_addr){
	while(UCB0CTL1 & UCTXSTP);				// Ensure stop condition got sent
	UCB0CTL1 |= UCTXSTT + UCTR;				// Send start condition
	while(UCB0CTL1 & UCTXSTT)				// Ensure start condition got sent
	UCB0TXBUF = reg_addr;					// Send register address
	UCB0CTL1 &= ~UCTR;						// Receive mode
	UCB0CTL1 |= UCTXSTT;					// Repeat start condition
	while(UCB0CTL1 & UCTXSTT);
	UCB0CTL1 |= UCTXSTP;					// Send stop condition
	while(UCB0CTL1 & UCTXSTP);
	return UCB0RXBUF;
}

