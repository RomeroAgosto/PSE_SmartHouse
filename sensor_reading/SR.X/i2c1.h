/* 
 * File:   i2c1.h
 * Author: Ganzas
 *
 * Created on 12 de Dezembro de 2017, 14:57
 */

#ifndef I2C1_H
#define	I2C1_H

void i2c1_init(void);
int i2c1_setClock(unsigned int clock_freq);
void i2c1_start(void);
void i2c1_stop(void);
int i2c1_send(unsigned char value);
char i2c1_receive(char ack_bit);

#endif	/* I2C1_H */

