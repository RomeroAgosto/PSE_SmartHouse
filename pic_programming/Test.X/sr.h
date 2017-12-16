/* 
 * File:   sr.h
 * Author: Ganzas
 *
 * Created on 12 de Dezembro de 2017, 14:56
 */

#ifndef SR_H
#define	SR_H

int temp_analog(int *p);
char air_quality_level(int air_sens_numb);
double temp_digital(int d_temp_sens_numb);
//int humidity_temperature(int h_sens_numb, double *p);
char motion_detection(int motion_sens_numb);
#endif	/* SR_H */

