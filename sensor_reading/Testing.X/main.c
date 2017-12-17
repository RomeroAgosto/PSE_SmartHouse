/* 
 * File:   main.c
 * Author: Ricardo
 *
 * Created on 17 December 2017, 00:06
 */

#include <stdlib.h>
#include <xc.h>
//#include <sys/attribs.h>

#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>

#define SYSCLK  80000000L   // System clock frequency, in Hz
#define PBUSCLK 40000000L   // Peripheral bus clock

#include <p32xxxx.h>
#include "update.h"
/*
 * 
 */
int main() {
    valuesinti();
    updateSensors();
    
    return (EXIT_SUCCESS);
}

