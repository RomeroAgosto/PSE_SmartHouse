#include "struct_lib.h"
#include "update.h"
#include <stdio.h>


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
 
int updateSensors() 
{
    static int p[20];
    static int i, j;
    air_temp_analog(p);
    
    for(i=0;i<6;i++) {
        current_values.air_temperature_sensor[i].temp=p[i];
    }
 
    water_temp_analog(p);
    
    current_values.water_temperature.temp=p[0];
 
    temp_digital(p);

    for(i=0;i<2;i++) {
        current_values.air_temperature_sensor[i+6].temp=p[i];
    }
 
    air_quality_level(p);
    
    for (i=0;i<4;i++) {
        for(j=0;j<5;j++)
            if(j==0){
                current_values.air_quality_sensor[i].p10=p[i*5+j];
            }
            if(j==1) {
                current_values.air_quality_sensor[i].co=p[i*5+j];
            }
            if(j==2) {
                current_values.air_quality_sensor[i].co2=p[i*5+j];
            }
            if(j==3) {
                current_values.air_quality_sensor[i].o3=p[i*5+j];
            }
            if(j==4) {
                current_values.air_quality_sensor[i].humity=p[i*5+j];
            }
    }
 
    motion_detection(p);
    
    for(i==0;i<4;) {
        current_values.light_sensors[i].movement_sensor=p[i];
    }
 
    return 0;
    
}
 
void print() {
    int i;
    for(i=0;i<8;i++){
        printf("%d\n",current_values.air_temperature_sensor[i].temp);
    }
}

/*## AIR QUALITY ##*/
int GetAirQuality(int n_air, double *p){
    (p[0])=current_values.air_quality_sensor[n_air].p10;
    (p[1])=current_values.air_quality_sensor[n_air].co;
    (p[2])=current_values.air_quality_sensor[n_air].co2;
    (p[3])=current_values.air_quality_sensor[n_air].o3;
    (p[4])=current_values.air_quality_sensor[n_air].humity;
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