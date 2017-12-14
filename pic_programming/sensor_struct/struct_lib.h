
#ifndef SENSOR_STRUCT_STRUCT_LIB_H
#define SENSOR_STRUCT_STRUCT_LIB_H

/*
 declare a sensor values structure inside of your function -> inside of that structure u can 
 * find all structures defined
 * 
 * use: 
 * 
 *  sensorvalues sensor_values;
 *  sensor_values.air_temperature_sensor[2].temp=20; -> setting values
 *  int temp =sensor_values.air_temperature_sensor[2].temp -> reading values
 * 
 * 
 * The structure should be defined locally as static -> access for other functions just 
 * with getter and setter functions
 */

struct water_data
{
    double temp;
    int water_heater; /*its turned on/off*/
};

struct light_data
{
    int movement_sensor;
    int mechanical_switch;
};

struct air_quality_data
{
    double p10;
    double co;
    double co2;
    double o3;
    double humity;
    int state;
};

struct air_temperature_data
{
    double temp;
    int state;
};

typedef struct water_data water;
typedef struct light_data lights[8];
typedef struct air_quality_data air_quality[4];
typedef struct air_temperature_data air_temperature[8];

typedef struct {
    water water_temperature;
    lights light_sensors;
    air_quality air_quality_sensor;
    air_temperature air_temperature_sensor;
}sensorvalues;

/* *****************************************************************************
 End of File
 */

#endif //SENSOR_STRUCT_STRUCT_LIB_H
