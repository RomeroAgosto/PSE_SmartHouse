 
/**
 * @file actuators.h
 * @author Deep Impact
 * @date 15 Dez 2017
 * @brief This file is use to turn ON/OFF ligths, heaters, ventilator and buzzer
 * 
 * This system will have:
 * 1 water heater; 
 * 4 ligth, that are using by the movement sensors; 
 * 8 air heaters; 
 * 1 ventilator; 
 * 1 buzzer.
 * 
 * Company  Deep Impact
 * 
 * ==============================================
 */
 
#ifndef ACTUATORS_H
#define  ACTUATORS_H
 
#include <p32xxxx.h>
#include <stdio.h>
 
/**@def GREEN
* State GREEN=0
*/
#define GREEN 0
/**@def YELLOW
* State YELLOW=1
*/
#define YELLOW 1
/**@def RED
* State RED=2
*/
#define RED 2
 
/**
 * @brief set_ligth,this funtion will turn ON/OFF the lights
 * 
commit:b8e4bf
WIP on master