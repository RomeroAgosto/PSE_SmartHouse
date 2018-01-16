 
/**
 * @file actuators.h
 * @brief This file is use to turn ON/OFF ligths, heaters, ventilator and buzzer
 * 
 * This system will have:
 * 1 water heater; 
 * 4 ligth, that are using by the movement sensors; 
 * 8 air heaters; 
 * 1 ventilator; 
 * 1 buzzer.
 * Company  Deep Impact
 * @author Deep Impact
 * @date 15 Dez 2017
 * 
 * ==============================================
 */
 
#ifndef ACTUATORS_H
#define  ACTUATORS_H
 
#include <p32xxxx.h>
#include <stdio.h>
 
/**@def GREEN
*/
#define GREEN 0
/**@def YELLOW
*/
#define YELLOW 1
/**@def RED
*/
#define RED 2
 
/**
 * @brief set_ligth,this funtion will turn ON/OFF the lights
 * 
 * -> In the n_ligth, if is state=1 will turn ON the light, if state=0 will turn off the light.
 * @param n_light 0..3-> Number of the light
 * @param state ON/OFF-> Set the state
 * @return 0
 * ==============================================
 */    
int set_light(int n_light, int state);
 
/**
 * @brief set_heater,this funtion will turn ON/OFF the air heaters
 * 
 * -> Inside of room, if state=1 will turn ON the Air-Heater, if state=0 will turn off the Air-Heater.
 * @param room 0..7-> Number of room that have the heater
 * @param state ON/OFF -> Set the state
 * @return 0
 * ==============================================
 */ 
int set_heater(int room, int state);
 /**
 * @brief set_ventilator_buzzer,this funtion will turn ON/OFF the ventilator and buzzer
 * 
 * Will have just one ventilator and buzzer for all;
 * ->If the state=GREEN will turn OFF the Buzzer and the Ventilator, 
 * if state=YELLOW will turn OFF the buzzer and turn ON the Ventilator and
 * if state=RED will turn ON the Buzzer and the Ventilator
 * @param state GREEN/YELLOW/RED-> Set the state
 * @return 0
 * ==============================================
 */ 
int set_ventilator_buzzer(int state);
 
#endif  /* ACTUATORS_H */