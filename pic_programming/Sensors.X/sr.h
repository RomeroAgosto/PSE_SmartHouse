/** \file  sr.h
 *  \brief File header of functions that register values from different sensors. 
 * 
 *  \author Bruno Barbosa NMEC 68150
 * 
 *  \date 18/12/2017
 */

#ifndef SR_H
#define	SR_H

/** \brief Air temperature value reading from 6 analog sensors (LM335), using the <br>
 *         ADC converter.
 *         
 * \author Bruno Barbosa NMEC 68150 
 * 
 * @param *t[6] - pointers to register the reading values from the sensors.
 *  
 * \date 18/12/2017
 */
int air_temp_analog(int *t);

/** \brief Water temperature value reading from a potentiometer, by using the ADC <br>
 *         converter.
 *         
 * \author Bruno Barbosa NMEC 68150 
 * 
 * @param *t - pointer to register the reading value from the potentiometer.
 *  
 * \date 18/12/2017
 */
int water_temp_analog(int *t);

/** \brief Air temperature value reading from 2 digital temperature sensors (TC74 <br>
 *         and HIH8120).
 *            
 * \author Bruno Barbosa NMEC 68150 
 * 
 * @param *t[2] - pointers to register the reading values from the sensors.
 *  
 * \date 18/12/2017
 */
int temp_digital(int *t);

/** \brief Specific gas concentration readings, that is manipulated by 20 <br> 
 *         potentiometers, using the ADC converter.
 *            
 * \author Bruno Barbosa NMEC 68150 
 * 
 * @param *a[20] - pointers to register the reading values from the potentiometers.
 *  
 * \date 18/12/2017
 */
int air_quality_level(int *a);

/** \brief Initialize ADC used by the PIC32MX795F512L to read analog values <br>
 *         with the use of the ADC converter.
 *            
 * \author Bruno Barbosa NMEC 68150 
 * 
 * \date 18/12/2017
 */
void adc_init();

/** \brief Register motion detection, simulated by push-button switches.
 *            
 * \author Bruno Barbosa NMEC 68150 
 * 
 * @param *m[4] - pointers to register the reading values from the push-button switches.
 * 
 * \date 18/12/2017
 */
int motion_detection(int *m);
#endif	/* SR_H */

