#include "../sensor_struct/struct_lib.h"
#include "update.h"
static sensorvalues current_values;

ss_getAirTemperature(air_temperature *i)
{
    air_temperature ola;
    memcpy(i,ola,sizeof(ola));
    return 0;
}
/*air_quality get_air_quality()
{
   // return NULL;
}
lights get_ligthsensors()
{
  //  return NULL;
}
water get_water_temperature()
{
  //  return NULL;
}
*/
int update_data(void)
{
    ss_getAirTemperature(&current_values.air_temperature_sensor);
    //ss_getAirQuality(&actual_values.air_quality_sensor);
    //ss_getLigth(&actual_values.light_sensors);
    //ss_getWaterTemperature(&actual_values.water_temperature);
    
    //ss_getLigthSwitch(&current_values.light_sensors);
    return 0;
}


/** 
  @Function
    int GetAirQuality(int n_air,struct air_quality_data *air_quality) 

  @Summary
    Save in a given pointer the corrent values of air quality 

  @Parameters
    @param param1 Describe the first parameter to the function.
    
    @param param2 Describe the second parameter to the function.

  @Returns
    List (if feasible) and describe the return values of the function.
    <ul>
      <li>1   Indicates an error occurred
      <li>0   Indicates an error did not occur
    </ul>
 */

/*## AIR QUALITY ##*/
int GetAirQuality(int n_air,struct air_quality_data *air_quality){
    *air_quality=current_values.air_quality_sensor[n_air];
    return 0;
}

int SetVentilatorState(int n_air,int state)
{
    current_values.air_quality_sensor[n_air].ventilator=state;   
    return 0;
}
/*## AIR TEMPERATURE ##*/
int GetAirTemperature(int n_air)
{
    return current_values.air_temperature_sensor[n_air].temp;
}

int SetHeatingAirState(int n_air,int state){
    current_values.air_temperature_sensor[n_air].heater=state;
    return 0; /*we should introduce a check, if this procedure was successful */
}

/*## Ligth ##*/
int GetLigthControl(int n_ligth,int *sensor_values)
{
    sensor_values[0]= current_values.light_sensors[n_ligth].mechanical_switch;
    sensor_values[1]= current_values.light_sensors[n_ligth].movement_sensor;
   
    return 0;
}

int SetLightSate(int n_ligth,int state)
{
    current_values.light_sensors[n_ligth].ligth_state=state;
    return 0; /*we should introduce a check, if this procedure was successful */
}


/*## WATER TEMPERATURE ##*/
int GetWaterTemperature()
{
    return current_values.water_temperature.temp;
}

int SetWaterHeaterSate(int state)
{
    current_values.water_temperature.water_heater=state;
    return 0; /*we should introduce a check, if this procedure was successful */
}
/* *****************************************************************************
 End of File
 */
