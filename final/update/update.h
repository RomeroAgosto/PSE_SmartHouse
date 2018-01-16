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
 *     @brief  update_sensors, gains current sensor values in the beginning of each cycle
 *     @author Deep Impact
 *     @date 03.12.208
 * ==============================================
 */


int update_sensors();


/**
 *     @brief  get_air_quality, gets from the structure the current values of chemicals in the air
 *     @param n_air -> number of the room
 *     @param *p -> pointer where the values will be saved
 *     @return 0

 * ==============================================
 */

int get_air_quality(int n_air, int* p);

/**
 *     @brief  set_ventilator_state, sets in the structure the current value for the ventilator state
 *     @param room_id -> id of the room
 *     @param state -> state to be set
 *     @return 0

 * ==============================================
 */

int set_ventilator_state(int room_id, int state);

/**
 *     @brief  get_ventilator_state, gets from the structure the current value of the state of the ventilator
 *     @return state of the ventilator

 * ==============================================
 */

int get_ventilator_state();

/**
 *     @brief  get_air_temperature, gets from the structure the current value of the air temperature of the room n_air
 *     @param n_air -> number of the room
 *     @return value of the air temperature

 * ==============================================
 */

int get_air_temperature(int n_air);


/**
 *     @brief  set_air_heater, sets in the structure the current value for the air temperature
 *     @param n_air -> id of the room
 *     @param state -> state to be set
 *     @return 0

 * ==============================================
 */

int set_air_heater(int n_air,int state);

/**
 *     @brief  get_heating_air_state, gets from the structure the current value of the heater for the room n_air
 *     @param n_air -> number of the room
 *     @return value of the state of the heater

 * ==============================================
 */

int get_heating_air_state(int n_air);

/**
 *     @brief  get_light_control, gets from the structure the current value of the light control for the room n_light
 *     @param n_light -> number of the room
 *     @return value of the light control

 * ==============================================
 */

int get_light_control(int n_ligth);

/**
 *     @brief  set_light_state, sets in the structure the current value for the light state
 *     @param n_light -> id of the room
 *     @param state -> state to be set
 *     @return 0

 * ==============================================
 */

int set_light_state(int n_ligth,int state);

/**
 *     @brief  get_light_state, gets from the structure the current value of the state of the light for room n_light
 *     @param n_light -> number of the room
 *     @return value of the light state

 * ==============================================
 */

int get_light_state(int n_ligth);

/**
 *     @brief  get_water_temperature, gets from the structure the current value of the water temperature
 *     @return value of water temperature

 * ==============================================
 */

int get_water_temperature();

/**
 *     @brief  set_water_heater_state, sets in the structure the current value for the water heater state
 *     @param state -> state to be set
 *     @return 0

 * ==============================================
 */

int set_water_heater_state(int state);

/**
 *     @brief  get_water_heater, gets from the structure the current value of the water heater state
 *     @return value of the water heater state

 * ==============================================
 */

int get_water_heater();


#endif