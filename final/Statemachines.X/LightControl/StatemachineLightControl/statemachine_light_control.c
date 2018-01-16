#include "statemachine_light_control.h"

static int CYCLES[4]={20,20,20,20};/*!< every light can have a different cycle*/
static int counter[4]={0,0,0,0}; /* Counter for all timer/lights */
static int light_state[4]={0,0,0,0};//={0};
int GetCycle(int room){
    return CYCLES[room];
}
/**
 *      @brief  enforces the user to set a new cycle time
 *      @param  new_cycle is expected in seconds
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  DeepImpact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
int set_light_cycles(int light_number, int cycle_time){
    CYCLES[light_number]=cycle_time;
}
int get_light_cycles(int light_number){
    return CYCLES[light_number];

}

/**
 *      @brief  SetTimer, Counts the seconds till the Cycles [ in seconds ] is reached 1 Cycle <-> 1s, This function is called from the Clock interrupt
 *      @param  light
 *     @author  Sascha Marquardt, sascha.marquardt@ua.pt
 *     Created  20-Set-2017
 *     Company  DeepImpact
 *   Copyright  Copyright (c) 2017, Sascha Marquardt
 *
 * ==============================================
 */
int SetTimer(int light)
{
    counter[light]++;/*increase counter by a timer overrun -> counter[] just local known -> setter function*/
    return 1;
}

#if UNITTEST==1
int ResetLightStates(){
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
void SetDesiredLight(int light, int value){
    DesiredLightValue[light]=value;
}
int desiredLight(int light){
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
int SetLightSensorValues(int light, int value){
    light_sensor_value[light]=value;
}
/* dummy to get fictive sensor values*/
int GetLightControl(int light) //just for test int
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
int SetLightState(int light, int ON )
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
void Statemachine_LightControl(int light,int *test) {
    int turned_on= desiredLight(light);/*!< saved if the light should be turned on */
    test[0]=turned_on;
    test[1]=light_state[light];
#else
void Statemachine_LightControl(int light) {
    int turned_on= desiredLight(light);/*!< saved if the light should be turned on */
#endif
    int movement= GetLightControl(light);/*!< saves the movement */
            
    if(turned_on==TRUE){
        /* states are stored in the states variables. so higher function can easily access the current states*/
        switch (light_state[light]) {
            case TURNED_OFF:
                counter[light]=0;
                light_state[light]= TURNED_OFF;
                SetLightState(light, FALSE );
                set_light(light,FALSE);
                if(movement==TRUE ) {light_state[light] = TURNED_ON;}
                break;

            case TURNED_ON:
                SetLightState(light, TRUE );
                set_light(light,TRUE);
                if (movement==TRUE)counter[light]=0;
                if(counter[light]>=CYCLES[light]){
                    light_state[light] = TURNED_OFF;
                    
                }
                break;
            default:
                SetLightState(light,FALSE );
                light_state[light] = TURNED_OFF; /* default state is turn off!*/
                break;
        }
    }
    else{
        SetLightState(light,FALSE );
        light_state[light] = TURNED_OFF; /* default state is turn off!*/
        set_light(light,FALSE);
    }
#if UNITTEST ==1
    test[2]=ActivatedLights[light];
    test[3]=light_state[light];
#endif
}