
#include "actuators.h"
#include <p32xxxx.h>

int setLight(int n_light, int state) 
{
    if(n_light==0){  
        PORTEbits.RE4=state;
    }
    else if(n_light==1){  
        PORTEbits.RE1=state;
    }
    else if(n_light==2){  
        PORTEbits.RE2=state;
    }
    else if(n_light==3){  
        PORTEbits.RE3=state;
    }
    return 0;
}

int setVentilatorBuzzer(int state) {
    if(state==GREEN){
        PORTE=PORTE & 0xff9f;
    }
    else if(state==YELLOW) {
        PORTE=(PORTE & 0xffbf) | 0x0020;
    }
    else if(state==RED) {
        PORTE=PORTE | 96;
        
    }
}
