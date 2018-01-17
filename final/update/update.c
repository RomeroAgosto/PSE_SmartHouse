#include "struct_lib.h"
#include "update.h"
#include <stdio.h>
#include "../sensors/sr.h"
#include <p32xxxx.h>

static sensorvalues current_values;
 
int update_sensors(){
    static int p[20];
    static int i, j;
    air_temp_analog(p);
    for(i=0;i<6;i++) {
        current_values.air_temperature_sensor[i].temp=p[i];
    }
 
    water_temp_analog(p);
    current_values.water_temperature.temp=p[0];
    //temp_digital(p);

    for(i=0;i<2;i++) {
        current_values.air_temperature_sensor[i+6].temp=p[i];
    }
    
    air_quality_level(p);
    for (i=0;i<4;i++) {
        for(j=0;j<5;j++) {
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
    }
    motion_detection(p);
    
    for(i=0;i<4;i++) {
        current_values.light_sensors[i].movement_sensor=p[i];
    }
    return 0;
    
}

int get_heating_air_state(int n_air){
    return current_values.air_temperature_sensor[n_air].heater;
}
/*## AIR QUALITY ##*/
int get_air_quality(int n_air, int *p){
    (p[0])=current_values.air_quality_sensor[n_air].p10;
    (p[1])=current_values.air_quality_sensor[n_air].co;
    (p[2])=current_values.air_quality_sensor[n_air].co2;
    (p[3])=current_values.air_quality_sensor[n_air].o3;
    (p[4])=current_values.air_quality_sensor[n_air].humity;
    return 0;
}


int set_ventilator_state(int room_id, int state){
    current_values.air_quality_sensor[room_id].ventilator=state;   
    return 0;
}
/*## AIR TEMPERATURE ##*/
int get_air_temperature(int n_air){
    return current_values.air_temperature_sensor[n_air].temp;
}
 
int set_air_heater(int n_air,int state){
    current_values.air_temperature_sensor[n_air].heater=state;
    return 0; /*we should introduce a check, if this procedure was successful */
}
int get_ventilator_state() {
    return current_values.air_quality_sensor[0].ventilator;
}
/*## Ligth ##*/
int get_light_control(int n_ligth){
    return current_values.light_sensors[n_ligth].movement_sensor;
   
}
 
int set_light_state(int n_ligth,int state){
    current_values.light_sensors[n_ligth].ligth_state=state;
    return 0; /*we should introduce a check, if this procedure was successful */
}
 
int get_light_state(int n_ligth) {
    return current_values.light_sensors[n_ligth].ligth_state;
}
 
/*## WATER TEMPERATURE ##*/
int get_water_temperature(){
    return current_values.water_temperature.temp;
}

int set_water_heater_state(int state){
    current_values.water_temperature.water_heater=state;
    return 0; /*we should introduce a check, if this procedure was successful */
}

int get_water_heater() {
    return current_values.water_temperature.water_heater;
}
 
/* *****************************************************************************
 End of File
 */