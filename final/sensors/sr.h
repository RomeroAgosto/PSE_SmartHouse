/**
 * @file sr.h
 * @author Deep Impact
 * @date 15 Dez 2017
 * @brief File header of functions that register values from different sensors.
 * 
 * Company  Deep Impact
 * 
 * ==============================================
 */

#ifndef SR_H
#define	SR_H

/** @brief air_temp_analog, Air temperature value reading from 6 analog sensors (LM335), using the <br>
 *         ADC converter.
 *  
 * @param *t[6] - pointers to register the reading values from the sensors.
 * @return 0
 */

int air_temp_analog(int *t);

/** @brief water_temp_analog, Water temperature value reading from a potentiometer, by using the ADC <br>
 *         converter.
 *      
 * @param *t - pointer to register the reading value from the potentiometer.
 * @return 0
 */

int water_temp_analog(int *t);

/** @brief temp_digital, Air temperature value reading from 2 digital temperature sensors (TC74 <br>
 *         and HIH8120).
 *       
 * @param *t[2] - pointers to register the reading values from the sensors.
 * @return 0
 */

int temp_digital(int *t);

/** @brief temp_digital, Specific gas concentration readings, that is manipulated by 20 <br> 
 *         potentiometers, using the ADC converter.
 *     
 * @param *a[20] - pointers to register the reading values from the potentiometers.
 * @return 0
 */

int air_quality_level(int *a);

/** @brief adc_init, Initialize ADC used by the PIC32MX795F512L to read analog values <br>
 *         with the use of the ADC converter.
 *  
 */
void adc_init();

/** @brief motion_detection, Register motion detection, simulated by push-button switches.
 *        
 * @param *m[4] - pointers to register the reading values from the push-button switches.
 * @return 0
 */

int motion_detection(int *m);
#endif	/* SR_H */

