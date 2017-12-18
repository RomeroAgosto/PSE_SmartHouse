/* 
 * File:   statemachines.h
 * Author: sascha
 *
 * Created on December 17, 2017, 3:02 AM
 */

#ifndef STATEMACHINES_H
#define	STATEMACHINES_H

#include "statemachine_airtemp_control.h" 
#include "statemachine_airquality_control.h"
#include "statemachine_watertemp_control.h"
#include "statemachine_light_control.h"

#include "stdio.h"
#include <stdlib.h>
#include <string.h>

#define _DEBUG 1 /*!< DEBUG 1  hides the PIC implementation and introduces an artificial register to use for testing*/

#if _DEBUG ==0

#include <proc/p32mx795f512l.h>
#include "../Schedules.X/desiredValues.h"

#else

#define TRUE 1
#define FALSE 0


typedef struct{
    int RA1;
    int RA2;
    int RA3;
    int RA4;
    int RA5;
    int RA6;
}PORT_SIM;

PORT_SIM PORTAbits;

#endif

#endif	/* STATEMACHINES_H */

