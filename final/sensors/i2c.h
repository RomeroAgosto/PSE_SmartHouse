/**
 * @file i2c.h
 * @author Deep Impact
 * @date 15 Dez 2017
 * @brief File header of functions used by the I2C1 module, connected to SDA1 and SCL1 pins of the PIC32MX795F512L. 
 * 
 * Company  Deep Impact
 * 
 * ==============================================
 */

#ifndef I2C_H
#define	I2C_H

// General definitions
#define READ 1          // Read bit
#define WRITE 0         // Write bit
#define ACK 0           // Acknowledge bit
#define NACK 1          // Not-acknowledge bit

// HIH8120 digital temperature/humidity sensor definitions
#define SENS_ADDRESS_HIH8120  0x27      // Device ID
#define HIH8120_CLK_FREQ 100000         // Slave clock
#define ADDR_RD_HIH8120 ((SENS_ADDRESS_HIH8120 << 1) | READ) // Device ID + WRITE bit

// TC74 digital temperature sensor definitions
#define SENS_ADDRESS_TC74 0x4D      // Device ID
#define TC74_CLK_FREQ 100000        // Slave clock
#define RTR 0                       // Read temperature commando
#define ADDR_WR_TC74 ((SENS_ADDRESS_TC74 << 1) | WRITE) // Device ID + WRITE bit
#define ADDR_RD_TC74 ((SENS_ADDRESS_TC74 << 1) | READ)  // Device ID + READ bit

/** @brief i2c1_init, Initializes the I2C module.
 * ==============================================
 */ 

void i2c1_init(void);

/** @brief i2c1_set_clock, Sets up the clock signal for the SCL1 pin.
 *  
 * @param clock_freq - frequency of the slave clock.
 * @return 0
 */

int i2c1_set_clock(unsigned int clock_freq);

/** @brief i2c1_start, Starts up the I2C module.
 *       
 * 
 */

void i2c1_start(void);

/** @brief i2c1_stop, Stops the I2C module.
 * 
 */

void i2c1_stop(void);

/** @brief i2c1_send Sends data to state desired command (READ OR WRITE) or to select <br>
 *         		slave by device ID. Returns acknowledge status bit of the slave to the <br>
 *         		master device.
 *  
 * @param value - acknowledge bit of the slave device.
 * @return 0
 *  
 */

int i2c1_send(unsigned char value);

/** @brief i2c1_receiver, Receives data byte(s) from slave device and returns it. Sends <br>
 *         acknowledge status bit of the master to the slave.
 * 
 * @param ack_bit - acknowledge bit of the master device.
 */

char i2c1_receive(char ack_bit);
/** @brief i2c1_s7, Returns temperature value reading from TC74 sensor.
 *   
 * @return 0
 */

int i2c1_s7();

/** @brief i2c1_s8, Humidity and temperature value reading from HIH8120 sensor.
 *   
 * @param *humi_temp[2] - pointers to register the humidity and temperature <br>
 *                        reading from the sensor. First value is the humidity <br>
 *                        value, second value is the temperature value.
 * @return 0
 */

int i2c1_s8(int *humi_temp); 
#endif	/* I2C_H */



