/* the statevariables structure is defined in the internal_state.h, some IDEs can say the include is unused but it isn't!*/
#include "statemachine_light_control.h"
#



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
    if (ON==TRUE){PORTAbits.RA3=1;
    /*printf("turn_on light %d\n",light);*/
    } /*for debugging, just light 0 should be turned on*/
    else if(ON==FALSE){
        PORTAbits.RA3=0;
       // printf("turn_off light %d\n",light);
    };
    return TRUE;
}
int SetTimer(int light)
{
    counter[light]++;/*increase counter by a timer overrun -> counter[] just local known -> setter function*/
   // printf("im increasing, the new counter is counter[%d]=%d\n",light,counter[light]);
    return 1;
}

void Statemachine_LightControl(int light, char* to_send) {
    int movement, mechanical_switch;/*initialize the specific sensors, increase readability*/
    int sensor_value[2];/* initialize the sensor array -> contains Values of the switch and the movement detection*/
    /* initialize pointer to the sensor values*/
  /*pointer should point to the defined array*/
    update_sensorvalues(light,sensor_value); /*expects as return value a pointer to the sensor values*/

    /*update sensor values*/
    movement=sensor_value[0]; /*obtain movement sensor*/
    mechanical_switch= sensor_value[1];
    printf("counter[0]=%d\n",counter[0]);
    /* states are stored in the states variables. so higher function can easily access the current states*/
    switch (light_state[light]) {
        case TURNED_OFF:
            counter[light]=0;
            SetLight(light,FALSE);
            if   (movement==TRUE || mechanical_switch==TRUE) {
                light_state[light] = TURNED_ON;
            }
            break;

        case TURNED_ON:
            SetLight(light, TRUE);
            //SetTimer(light);
            if (counter[light]>=CYCLES && mechanical_switch==FALSE){
                light_state[light] = TURNED_OFF;
                //printf("turning_off");
            }
            break;
       // default:
            //printf("i couldn't go into one state!\n");
       //     light_state[light] = TURNED_OFF; /* default state is turn off!*/
     //       break;
    }
    //printf("the next state of light %d is: %d\n",light/2,light_state[light]);
 //   char add_to_message[30];
//    sprintf(add_to_message,""
 //           "      \"Light_%d\":%d,\n",light,light_state[light]);
//    strcat(to_send,add_to_message); /*append the string*/
}