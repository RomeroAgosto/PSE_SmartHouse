#include <stdio.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>

// HIH8120 temp sensor specific defines
//#define SENS_ADDRESS_HIH8120  0x27      // device dependent
//#define HIH8120_CLK_FREQ 100000    // 100 KHz
//#define ADDR_RD_HIH8120 ((SENS_ADDRESS_HIH8120 << 1) | READ)

int temp_analog(int *t[6]);
int temp_digital(int *t[6]);

int temp(int *t[6]){
    int i;
    for(i=0;i<6;i++){
        if(i<4)
            temp_analog(t); 
        else
            temp_digital(t);
    }
    return 0;
}
//function that returns (digital) temperature and humidity value from a room
/*int humidity_temperature(int h_dt_sens_numb){
     
    switch(h_dt_sens_numb){
        case(7):
            return 0;
            break;
        default:
            return -1;
            break;
    }
}*/

