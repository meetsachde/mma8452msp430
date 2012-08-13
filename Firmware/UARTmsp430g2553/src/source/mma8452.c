/*
 * mma8452.c
 *
 *  Created on: 13 Aug 2012
 *      Author: Cu Xuan Duc
 */
#include "msp430g2553.h"
#include "../header/i2c.h"
#include "../header/mma8452.h"

//------------------------------------------------------------------------------
// Sets the MMA8452 to standby mode.It must be in standby to change most register settings
//------------------------------------------------------------------------------
void mma8452_standby(){
  char c;
  c = i2c_ReadOneByte(0x2A);
  i2c_WriteOneByte(c & ~(0x01),0x2A);
}
//------------------------------------------------------------------------------
//Sets the MMA8452 to active mode.Needs to be in this mode to output data
//------------------------------------------------------------------------------
void mma8452_active(){
  char c;
  c = i2c_ReadOneByte(0x2A);
  i2c_WriteOneByte(c | 0x01,0x2A );
}




