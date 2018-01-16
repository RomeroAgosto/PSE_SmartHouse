/* 
 * File:   actuators.h
 * Author: Ricardo
 *
 * Created on 18 December 2017, 06:33
 */

#ifndef ACTUATORS_H
#define	ACTUATORS_H

#ifdef	__cplusplus
extern "C" {
#endif

#define GREEN 0
#define YELLOW 1
#define RED 2
    
    
int setLight(int n_light, int state);
int SetHeater(int room, int state);



#ifdef	__cplusplus
}
#endif

#endif	/* ACTUATORS_H */

