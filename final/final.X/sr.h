/** @file  sr.h
 * @author Deep Impact
 * @date 15 Dez 2017
 *  @brief File header of functions that register values from different sensors. 
 * 
 */

#ifndef SR_H
#define	SR_H

/** @brief Air temperature value reading from 6 analog sensors (LM335), using the <br>
 *         ADC converter.
 *         
 *  @param *t[6] - pointers to register the reading values from the sensors.
 */
int air_temp_analog(int *t);

/** @brief Water temperature value reading from a potentiometer, by using the ADC <br>
 *         converter.
 *         
 *  @param *t - pointer to register the reading value from the potentiometer.
 *  
 */
int water_temp_analog(int *t);

/** @brief Air temperature value reading from 2 digital temperature sensors (TC74 <br>
 *         and HIH8120).
 *            
 * @param *t[2] - pointers to register the reading values from the sensors.
 */
int temp_digital(int *t);

/** @brief Specific gas concentration readings, that is manipulated by 20 <br> 
 *         potentiometers, using the ADC converter.
 * 
 * @param *a[20] - pointers to register the reading values from the potentiometers.
 */
int air_quality_level(int *a);

/** @brief Initialize ADC used by the PIC32MX795F512L to read analog values <br>
 *         with the use of the ADC converter.
 */
void adc_init();

/** @brief Register motion detection, simulated by push-button switches.
 *            
 * @param *m[4] - pointers to register the reading values from the push-button switches.
 */
int motion_detection(int *m);
#endif	/* SR_H */

