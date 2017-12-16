/*
 * 
 * Program source that stores to an array, the temperature value (in integer format)
 * from one of the 2 digital sensors (TC74). This function works by using two of the 
 * I2C modules available on the PIC32MX795F512L microchip.
 * 
 */

#include <stdio.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>

//next two lines are two functions used to calculate temperatures from the 2 I2C 
//modules, that are connected to their respective digital sensor

int i2c1_s5();      
int i2c2_s6();

int temp_digital(int *t[6]){
    int i; //variable to control selection of the sensors
    int temp_d;  //variable to save value from one of the digital sensors
    for(i=4;i<6;i++){
        switch(i-4){    //select one of the 2 digital sensors
            case(0):
                temp_d=i2c1_s5();  //get and save value from I2C1 module
                break;
            case(1):
                temp_d=i2c2_s6(); //get and save value from I2C2 module
                break;
            default:
                return -1;
                break;
        }
        t[i]=temp_d; //storing temperature value to a variable
    }
    return 0;
}
