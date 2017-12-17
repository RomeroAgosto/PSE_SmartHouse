#include <stdio.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>

int motion_detection(int *m[4]){
    TRISD=(TRISD & 0x0000)|0x000f;              // define RD3-RD0 as input
    int i;
    int button_on;
    for (i=0;i<4;i++){
        switch(i){
            case(0):
                if(PORTDbits.RD0==1)
                    button_on=1;
                else
                    button_on=0;
                break;
            case(1):
                if(PORTDbits.RD1==1)
                    button_on=1;
                else
                    button_on=0;
                break;
            case(2):
                if(PORTDbits.RD2==1)
                    button_on=1;
                else
                    button_on=0;
                break;
            case(3):
                if(PORTDbits.RD3==1)
                    button_on=1;
                else
                    button_on=0;
                break;
            default:
                return -1;
                break;
        }
        m[i]=&(button_on);    
    }
    return 0;
}