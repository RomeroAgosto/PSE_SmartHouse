/**
 * @file update.h
 * @author Deep Impact (c)
 * @date 10 Jan 2018
 * @brief File contains the update of the sensor value structure
 * In the beginning of the program, the update sensor function is called. Then, 
 * new sensor data will be written into the sensor structure. Since the structure
 * is privat, getter and setter methods have been written to obtain/write values
 * from/into the structure.
 */

#ifndef UPDATE_H
#define UPDATE_H

#include "struct_lib.h"

/**
 *     @brief  Update sensors, gains current sensor values in the beginning of each cycle
 *     @author Deep Impact
 *     @date 03.12.208
 * ==============================================
 */


int update_sensors();


/**
 *     @brief  Update sensors, gains current sensor values in the beginning of each cycle
 *     @input room for 
 *     @author Deep Impact
 *     @date 03.12.2017
 * ==============================================
 */

int get_air_quality(int n_air, int* p);


/**
 *     @brief  Update sensors, gains current sensor values in the beginning of each cycle
 *     @author Deep Impact
 *     @date 03.12.208
 * ==============================================
 */

int set_ventilator_state(int room_id, int state);

int get_ventilator_state();

int get_air_temperature(int n_air);

int state_air_quality(int n_air,int state);

int get_heating_air_state(int n_air);

int get_light_control(int n_ligth);

int set_light_state(int n_ligth,int state);

int get_light_state(int n_ligth);

int get_water_temperature();

int set_water_heater_state(int state);

int get_water_heater();


#endif