// co nhung ham dai loai nhu sau: 

//I2C_Init();
//I2C_ReadOneByte(char Address);
//I2C_ReadSequenceByte(char Address);
//I2C_WriteOneByte(char Address);
//I2C_WriteSequenceByte(char Address);

#ifndef	_I2C_H_
#define	_I2C_H_

void i2c_start();
void i2c_stop();
void i2c_init();
char i2c_ReadOneByte(char address);
				//address:register address
void i2c_WriteOneByte(char data,char address);
				//data, address:register address
#endif