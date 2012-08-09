/*
 * i2c.h
 *
 *  Created on: 9 Aug 2012
 *      Author: WIN7
 */

#ifndef I2C_H_
#define I2C_H_

void i2c_start();
void i2c_stop();
void i2c_init();
char i2c_ReadOneByte(char address);
				//address:register address
void i2c_WriteOneByte(char data,char address);
				//data, address:register address

#endif /* I2C_H_ */
