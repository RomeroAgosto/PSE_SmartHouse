/* 
 * File:   sr.h
 * Author: Ganzas
 *
 * Created on 12 de Dezembro de 2017, 14:56
 */

#ifndef SR_H
#define	SR_H

<<<<<<< Updated upstream
int temp(int *t[6]);
int air_quality_level(int *a[4]);
=======
int temp_analog(int *p);
char air_quality_level(int air_sens_numb);
double temp_digital(int d_temp_sens_numb);
>>>>>>> Stashed changes
//int humidity_temperature(int h_sens_numb, double *p);
int motion_detection(int motion_sens_numb);
#endif	/* SR_H */

