/* 
 * File:   actuators.h
 * Author: Ricardo
 *
 * Created on 18 December 2017, 06:33
 */

#ifndef ACTUATORS_H
#define	ACTUATORS_H

#include <p32xxxx.h>
#include <stdio.h>

#define GREEN 0
#define YELLOW 1
#define RED 2
    
    
int set_light(int n_light, int state);
int set_heater(int room, int state);
int set_ventilator_buzzer(int room);


#ifdef	__cplusplus
}
#endif

#endif	/* ACTUATORS_H */

