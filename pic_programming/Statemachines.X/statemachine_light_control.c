/* the statevariables structure is defined in the internal_state.h, some IDEs can say the include is unused but it isn't!*/
#include "statemachine_light_control.h"


static int counter[4]; /* Counter for all timer/lights */
static int light_state[4];//={0};
int sensor_value;
/* dummy to get fictive sensor values*/
int update_sensorvalues(int light) //just for test int
{

        // light 1
        if (light==0){
        sensor_value=TRUE; //movement, sensor 0
        }
        // light 2
        else if(light==1){
        sensor_value=FALSE; //movement, sensor 1
        }
        else if(light==2){
        // light 3
        sensor_value=FALSE; //movement, sensor 2
        }
        else if(light==3){
        // light 4
        sensor_value=FALSE; //movement, sensor 3
        }
    
    return 0;
}

int SetLight(int light, int ON )
{
    if (ON==TRUE){//PORTAbits.RA3=1;
    } /*for debugging, just light 0 should be turned on*/
    else if(ON==FALSE){
        //PORTAbits.RA3=0;
    };
    return TRUE;
}
int SetTimer(int light)
{
    counter[light]++;/*increase counter by a timer overrun -> counter[] just local known -> setter function*/
    return 1;
}

void Statemachine_LightControl(int light) {
    int movement;/*initialize the specific sensors, increase readability*/
    int sensor_value[2];/* initialize the sensor array -> contains Values of the switch and the movement detection*/
    
    int turned_on=ds_DesiredLigth(light);
    if(turned_on==TRUE){
        //update_sensorvalues(light,sensor_value); /*expects as return value a pointer to the sensor values*/


        /*update sensor values*/
        movement; /*obtain movement sensor*/


        /* states are stored in the states variables. so higher function can easily access the current states*/
        switch (light_state[light]) {
            case TURNED_OFF:
                counter[light]=0;
                SetLight(light,FALSE);
                if(movement==TRUE ) {
                    light_state[light] = TURNED_ON;
                }
                break;

            case TURNED_ON:
                SetLight(light, TRUE);
                if(counter[light]>=CYCLES){
                    light_state[light] = TURNED_OFF;
                }
                break;
            default:
                //printf("i couldn't go into one state!\n");
                light_state[light] = TURNED_OFF; /* default state is turn off!*/
                break;
        }
    }
}