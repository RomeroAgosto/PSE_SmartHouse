/* 
 * File:   sr.h
 * Author: Ganzas
 *
 * Created on 12 de Dezembro de 2017, 14:56
 */

#ifndef SR_H
#define	SR_H

double temp_analog(int a_temp_sens_numb);
char air_quality_level(int air_sens_numb);
double temp_digital(int d_temp_sens_numb);
double humidity(int h_sens_numb);
char motion_detection(int motion_sens_numb);
#endif	/* SR_H */

