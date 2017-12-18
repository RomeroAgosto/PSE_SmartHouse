/* the statevariables structure is defined in the internal_state.h, some IDEs can say the include is unused but it isn't!*/

#include "statemachine_light_control.h"

static int CYCLES[4]={20};/*!< every light can have a different cycle*/
static int counter[4]; /* Counter for all timer/lights */
static int light_state[4];//={0};

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
int SetNewCycle(int room,int new_cycle){
    printf("the new cycle of room %d is %d s\n",room,new_cycle);
    CYCLES[room]=new_cycle;
}
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
int desiredLight_dummy(int light){
return 1;
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

/* dummy to get fictive sensor values*/
int GetLightControl_dummy(int light) //just for test int
{
        // light 1
        if (light==0){
            return TRUE; //movement, sensor 0
        }
        // light 2
        else if(light==1){
            return FALSE; //movement, sensor 1
        }
        else if(light==2){
        // light 3
            return FALSE; //movement, sensor 2
        }
        else if(light==3){
        // light 4
            return FALSE; //movement, sensor 3
        }
    
    return 0;
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
int SetLightState_dummy(int light, int ON )
{
    if (ON==TRUE){
        PORTAbits.RA3=1;
    }
    else if(ON==FALSE){
        PORTAbits.RA3=0;
    };
    return TRUE;
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
void Statemachine_LightControl(int light) {

#if _DEBUG == 0
    int movement= GetLightControl(light);/*!< saves the movement */
    int turned_on= desiredLight(light);/*!< saved if the light should be turned on */
#else
    int movement= GetLightControl_dummy(light);/*initialize the specific sensors, increase readability*/
    int turned_on= desiredLight_dummy(light);
#endif

    if(turned_on==TRUE){
        /* states are stored in the states variables. so higher function can easily access the current states*/
        switch (light_state[light]) {
            case TURNED_OFF:
                counter[light]=0;
                light_state[light]= TURNED_OFF;
                PORTAbits.RA3=0;
#if _DEBUG == 0
                SetLightState(light, FALSE );
#else
                SetLightState_dummy(light,FALSE );
#endif
        
                if(movement==TRUE ) {light_state[light] = TURNED_ON;}
                break;

            case TURNED_ON:
#if _DEBUG == 0
                SetLightState(light, TRUE );
#else
                SetLightState_dummy(light,TRUE );
#endif
                PORTAbits.RA3=1;
                if(counter[light]>=CYCLES[light]){
                    light_state[light] = TURNED_OFF;
                }
                break;
            default:
#if _DEBUG == 0
                SetLightState(light,FALSE );
#else
                SetLightState_dummy(light, FALSE);
#endif
                light_state[light] = TURNED_OFF; /* default state is turn off!*/
                break;
        }
    }
}