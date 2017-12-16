#include "struct_lib.h"
#include "sr.h"

static sensorvalues sensor_values;

void delay(unsigned int dms){
    unsigned int t;
    t=ReadCoreTimer()+40000*dms;
    while(ReadCoreTimer() < t);
}

int updateSensors() {
    int i;
    static int p[4];
    i=temp_analog(&p);
    printf("%d \n",p[0]);
    delay(500);
    printf("%d \n",p[1]);
    delay(500);
    printf("%d \n",p[2]);
    delay(500);
    printf("%d \n",p[3]);
    delay(500);
    
}
