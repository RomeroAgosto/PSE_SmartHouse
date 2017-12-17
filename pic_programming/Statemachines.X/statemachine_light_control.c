/* the statevariables structure is defined in the internal_state.h, some IDEs can say the include is unused but it isn't!*/
#include "statemachine_light_control.h"


static int counter[4]; /* Counter for all timer/lights */
static int light_state[4];//={0};
/* dummy to get fictive sensor values*/
int update_sensorvalues(int light, int *sensor_values) //just for test int
{
    // light 1
    if (light==0){
    sensor_values[0]=TRUE; //movement, sensor 0
    sensor_values[1]=TRUE;//switch 0
    }
    // light 2
    else if(light==1){
    sensor_values[0]=FALSE; //movement, sensor 1
    sensor_values[1]=FALSE;//switch 1
    }
    else if(light==2){
    // light 3
    sensor_values[0]=FALSE; //movement, sensor 2
    sensor_values[1]=FALSE;//switch 2
    }
    else if(light==3){
    // light 4
    sensor_values[0]=FALSE; //movement, sensor 3
    sensor_values[1]=FALSE; // switch 3
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
    int movement, mechanical_switch;/*initialize the specific sensors, increase readability*/
    int sensor_value[2];/* initialize the sensor array -> contains Values of the switch and the movement detection*/
    
    
    update_sensorvalues(light,sensor_value); /*expects as return value a pointer to the sensor values*/
   
    
    /*update sensor values*/
    movement=sensor_value[0]; /*obtain movement sensor*/
    mechanical_switch= sensor_value[1];/*mechanical switch -> manually pressed*/
    
    
    /* states are stored in the states variables. so higher function can easily access the current states*/
    switch (light_state[light]) {
        case TURNED_OFF:
            counter[light]=0;
            SetLight(light,FALSE);
            if(movement==TRUE || mechanical_switch==TRUE) {
                light_state[light] = TURNED_ON;
            }
            break;

        case TURNED_ON:
            SetLight(light, TRUE);
            if(counter[light]>=CYCLES && mechanical_switch==FALSE){
                light_state[light] = TURNED_OFF;
            }
            break;
        default:
            printf("i couldn't go into one state!\n");
            light_state[light] = TURNED_OFF; /* default state is turn off!*/
            break;
    }
}