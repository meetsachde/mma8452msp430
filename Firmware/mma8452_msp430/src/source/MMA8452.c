/*
 * MMA8452.c
 *
 *  Created on: 9 Aug 2012
 *      Author: WIN7
 */

#include "MMA8452.h"
/* Sets the MMA8452 to standby mode.
   It must be in standby to change most register settings */
void standby(){
  char c;
  c = i2c_ReadOneByte(0x2A);
  i2c_WriteOneByte(c & ~(0x01),0x2A);
}

/* Sets the MMA8452 to active mode.
   Needs to be in this mode to output data */
void active(){
  char c;
  c = i2c_ReadOneByte(0x2A);
  i2c_WriteOneByte(c | 0x01,0x2A );
}

/*read X_value*/
void Read_X_value(){
	X_value=i2c_ReadOneByte(0x01)*2/128;			//8 higher bit of X_value(12 bit) store in 0x01
}

/*read Y_value*/
void Read_Y_value(){
	Y_value=i2c_ReadOneByte(0x03)*2/128;			//8 higher bit of Y_value(12 bit) store in 0x03
}

/*read Z_value*/
void Read_Z_value(){
	Z_value=i2c_ReadOneByte(0x05)*2/128;			//8 higher bit of Z_value(12 bit) store in 0x05
}

