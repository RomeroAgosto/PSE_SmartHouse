

/* the statevariables structure is defined in the internal_state.h, some IDEs can say the include is unused but it isn't!*/
#include "statemachine_light_control.h"
#include <string.h>

/* dummy to get fictive sensor values*/
int *update_sensorvalues(int *sensor_values) //just for test int
{
    // light 1
    sensor_values[0]=TRUE; //movement, sensor 0
    sensor_values[1]=TRUE;//switch 0
    // light 2
    sensor_values[2]=TRUE; //movement, sensor 1
    sensor_values[3]=TRUE;//switch 1
    // light 3
    sensor_values[4]=FALSE; //movement, sensor 2
    sensor_values[5]=FALSE;//switch 2
    // light 4
    sensor_values[6]=FALSE; //movement, sensor 3
    sensor_values[7]=FALSE; // switch 3

    return sensor_values;
}

int SetLight(int light, int ON )
{
    return TRUE;
}
int SetTimer(int light)
{
    if (counter[light]==0){/*printf("the timer has to be started here\n");*/}
    counter[light]++;/*increase counter by 1 to simulate a timer overrun*/
    //printf("the counter is now: %d\n",counter[light]);

    return 1;
}

void Statemachine_LightControl(int light, char* to_send) {
    light=light*2;/*in order to obtain the right values for from the sensors since the values are in the 2*light and 2*light +1 entry*/

    int movement, mechanical_switch;/*initialize the specific sensors, increase readability*/
    int sensor_value[7],*pointer_to_sensor_values;/* initialize the sensor array -> contains Values of the switch and the movement detection*/
    /* initialize pointer to the sensor values*/
    pointer_to_sensor_values=sensor_value; /*pointer should point to the defined array*/
    pointer_to_sensor_values=update_sensorvalues(pointer_to_sensor_values); /*expects as return value a pointer to the sensor values*/

    /*update sensor values*/
    movement=*(pointer_to_sensor_values+light);
    mechanical_switch= *(pointer_to_sensor_values+light+1);

    /* states are stored in the states variables. so higher function can easily access the current states*/
    switch (light_state[light]) {
        case TURNED_OFF:
            counter[light]=0;
            SetLight(light,FALSE);
            if   (movement==TRUE || mechanical_switch==TRUE) {light_state[light] = TURNED_ON;}
            break;

        case TURNED_ON:
            SetLight(light, TRUE);
            SetTimer(light);
            if (counter[light]>=CYCLES && mechanical_switch==FALSE){ light_state[light] = TURNED_OFF;}
            break;
        default:
            //printf("i couldn't go into one state!\n");
            light_state[light] = TURNED_OFF; /* default state is turn off!*/
            break;
    }
    //printf("the next state of light %d is: %d\n",light/2,light_state[light]);
    char add_to_message[30];
    sprintf(add_to_message,""
            "      \"Light_%d\":%d,\n",light/2,light_state[light]);
    strcat(to_send,add_to_message); /*append the string*/
}