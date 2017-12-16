/** \file  i2c1.h
 *  \brief File header of functions used by the 2 digital sensors - TC74 <br>
 *         and HIH8120 - using I2C communication.
 * 
 *  \author Bruno Barbosa NMEC 68150
 * 
 *  \date 18/12/2017
 */

#ifndef I2C1_H
#define	I2C1_H

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
int i2c1_s8(int *humi_temp[2]); 

#endif	/* I2C1_H */

