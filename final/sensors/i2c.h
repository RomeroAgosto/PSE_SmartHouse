/** \file  i2c.h
 *  \brief File header of functions used by the I2C1 module, connected to SDA1 <br>
 *         and SCL1 pins of the PIC32MX795F512L. 
 * 
 *  \author Bruno Barbosa NMEC 68150
 * 
 *  \date 18/12/2017
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

/** \brief Initializes the I2C module.
 *         
 * \author Bruno Barbosa NMEC 68150 
 *  
 * \date 18/12/2017
 */
void i2c1_init(void);

/** \brief Sets up the clock signal for the SCL1 pin.
 *         
 * \author Bruno Barbosa NMEC 68150 
 * 
 * @param clock_freq - frequency of the slave clock.
 *  
 * \date 18/12/2017
 */
int i2c1_set_clock(unsigned int clock_freq);

/** \brief Starts up the I2C module.
 *         
 * \author Bruno Barbosa NMEC 68150 
 *  
 * \date 18/12/2017
 * 
 */
void i2c1_start(void);

/** \brief Stops the I2C module.
 *         
 * \author Bruno Barbosa NMEC 68150 
 *  
 * \date 18/12/2017
 */
void i2c1_stop(void);

/** \brief Sends data to state desired command (READ OR WRITE) or to select <br>
 *         slave by device ID. Returns acknowledge status bit of the slave to the <br>
 *         master device.
 *         
 * \author Bruno Barbosa NMEC 68150 
 * 
 * @param value - acknowledge bit of the slave device.
 *  
 * \date 18/12/2017
 */
int i2c1_send(unsigned char value);

/** \brief Receives data byte(s) from slave device and returns it. Sends <br>
 *         acknowledge status bit of the master to the slave.
 *         
 * \author Bruno Barbosa NMEC 68150 
 * 
 * @param ack_bit - acknowledge bit of the master device.
 *  
 * \date 18/12/2017
 */
char i2c1_receive(char ack_bit);
/** \brief Returns temperature value reading from TC74 sensor.
 *         
 * \author Bruno Barbosa NMEC 68150 
 *  
 * \date 18/12/2017
 */
int i2c1_s7();

/** \brief Humidity and temperature value reading from HIH8120 sensor.
 *         
 * \author Bruno Barbosa NMEC 68150 
 * 
 * @param *humi_temp[2] - pointers to register the humidity and temperature <br>
 *                        reading from the sensor. First value is the humidity <br>
 *                        value, second value is the temperature value.
 *  
 * \date 18/12/2017
 */
int i2c1_s8(int *humi_temp); 
#endif	/* I2C_H */



