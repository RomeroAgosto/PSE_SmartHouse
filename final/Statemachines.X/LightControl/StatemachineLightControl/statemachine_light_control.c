#include "statemachine_light_control.h"

static int counter[4]={0,0,0,0}; /* Counter for all timer/lights */
static int light_state[4]={0,0,0,0};//={0};

/**
 *      @brief  set_timer, Counts the seconds till the Cycles [ in seconds ] is reached 1 Cycle <-> 1s, This function is called from the Clock interrupt
 *      @param  light
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  DeepImpact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
int set_timer(int light)
{
    counter[light]++;/*increase counter by a timer overrun -> counter[] just local known -> setter function*/
    return 1;
}

#if UNITTEST==1
int reset_light_states(){
    light_state[0]=0;
    light_state[1]=0;
    light_state[2]=0;
    light_state[3]=0;
}

int set_light(int light,int a){
    return 0;
};
/**
 *      @brief  returns the desired light temperature -> _debug
 *      @param  light room number
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  DeepImpact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
static int DesiredLightValue[4];
void set_desired_light(int light, int value){
    DesiredLightValue[light]=value;
}
int desired_light(int light){
return DesiredLightValue[light];
    }
/**
 *      @brief  Set the movement sensors
 *      @param  light number [in which aresa]
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  DeepImpact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
static int light_sensor_value[4];
int set_light_sensor_values(int light, int value){
    light_sensor_value[light]=value;
}
/* dummy to get fictive sensor values*/
int get_light_control(int light) //just for test int
{
    return light_sensor_value[light];
}
/**
 *      @brief  Set the light state during _Debugging
 *      @param  light number [in which room]
 *      @param  Choose if on = TRUE or off = FALSE
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  DeepImpact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
static int ActivatedLights[4];
int set_light_state(int light, int ON )
{
        ActivatedLights[light]=ON;
    return 0;
}
/**
 *      @brief  This state machine implements the light control, inside of this function, the decisions are made
 *      @param  light number [in which room]
 *      @states turned on == TRUE and turned_off == FALSE
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  DeepImpact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
void statemachine_light_control(int light,int *test) {
    int turned_on= desired_light(light);/*!< saved if the light should be turned on */
    test[0]=turned_on;
    test[1]=light_state[light];
#else
void statemachine_light_control(int light) {
    int turned_on= desired_light(light);/*!< saved if the light should be turned on */
#endif
    int movement= get_light_control(light);/*!< saves the movement */
            
    if(turned_on==TRUE){
        /* states are stored in the states variables. so higher function can easily access the current states*/
        switch (light_state[light]) {
            case TURNED_OFF:
                counter[light]=0;
                light_state[light]= TURNED_OFF;
                set_light_state(light, FALSE );
                set_light(light,FALSE);
                if(movement==TRUE ) {light_state[light] = TURNED_ON;}
                break;

            case TURNED_ON:
                set_light_state(light, TRUE );
                set_light(light,TRUE);
                if (movement==TRUE)counter[light]=0;
                if(counter[light]>=get_light_cycles(light)){
                    light_state[light] = TURNED_OFF;
                    
                }
                break;
            default:
                set_light_state(light,FALSE );
                light_state[light] = TURNED_OFF; /* default state is turn off!*/
                break;
        }
    }
    else{
        set_light_state(light,FALSE );
        light_state[light] = TURNED_OFF; /* default state is turn off!*/
        set_light(light,FALSE);
    }
#if UNITTEST ==1
    test[2]=ActivatedLights[light];
    test[3]=light_state[light];
#endif
}