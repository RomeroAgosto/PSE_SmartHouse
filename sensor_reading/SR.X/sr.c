#include <stdio.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>

// HIH8120 temp sensor specific defines
//#define SENS_ADDRESS_HIH8120  0x27      // device dependent
//#define HIH8120_CLK_FREQ 100000    // 100 KHz
//#define ADDR_RD_HIH8120 ((SENS_ADDRESS_HIH8120 << 1) | READ)

int air_temp_analog(int *t[8]);
int water_temp_analog(int *t[8], int i);
int temp_digital(int *t[8]);


/*int temp(int *t[8]){
    int i;
    for(i=0;i<8;i++){
        if(i<5)
            air_temp_analog(t); 
        if(i==5)
            water_temp_analog(t); 
        else
            temp_digital(t);
    }
    return 0;
}*/