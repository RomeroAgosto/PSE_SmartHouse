/* 
 * File:   i2c.h
 * Author: Ganzas
 *
 * Created on 14 de Dezembro de 2017, 16:53
 */

#ifndef I2C_H
#define	I2C_H

void i2c1_init(void);
int i2c1_setClock(unsigned int clock_freq);
void i2c1_start(void);
void i2c1_stop(void);
int i2c1_send(unsigned char value);
char i2c1_receive(char ack_bit);
void i2c2_init(void);
int i2c2_setClock(unsigned int clock_freq);
void i2c2_start(void);
void i2c2_stop(void);
int i2c2_send(unsigned char value);
char i2c2_receive(char ack_bit);

#endif	/* I2C_H */



