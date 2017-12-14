

/** \file timer_libs.h
* \brief This library include some functions that handle the PIC32 timer in a "user-friendly" way. Allow some other programmer, less knowledgeable of the PIC32 intricacies.
*  
*
* 
*
* \author Rafael Almeida & Samuel Simoes
*
* \date 03-11-2017
*/

/** 
\mainpage <br> This library include some functions that handle the PIC32 timer in a "user-friendly" way. Allow some other programmer, less knowledgeable of the PIC32 intricacies.
<B> This library was design to PIC32MX795F512H!
 * \author <br> Rafael Almeida & Samuel Simoes
\date 03-11-2017


*/

#define t_on 1  /*!<  default value to turn on the timer*/
#define t_off 0  /*!< default value to turn off the timer */

/** 
* \brief This functions configs the timer's 
* \param  timerx  a value form 1 to 5, select the timer from 1 to 5
* \param frequency  the frequency disired, the frequency need to be bigger than 1.2Hz
* 
* \return EXIT_FAILURE in case of the argument's conditions are not respected
 * \author Rafael Almeida & Samuel Simoes
* \date 03-11-2017  
*/
void tmr_config(int timerx ,double frequency );

/** 
* \brief This functions wait the ativation of the flag 
*  \param  timerx a value form 1 to 5, select the timer from 1 to 5
* 
*  \return EXIT_FAILURE in case of the argument's conditions are not respected
 * \author Rafael Almeida & Samuel Simoes
 * \date 03-11-2017  
*/
void tmr_wait(int timerx);

/** 
* \brief This functions configs the timer's interrups
* \param  timerx a value form 1 to 5, select the timer from 1 to 5
* \param priority define the priority of the interrupt, should chose a value between 1 and 6, be 1 the lower priority and 6 the higher
* \param *tmr_function the function that will execute when the interrupt handler is called
* \return EXIT_FAILURE in case of the argument's conditions are not respected
 * \author Rafael Almeida & Samuel Simoes
 * \date 03-11-2017  
*/
void tmr_intrpt_config(int timerx , int priority, void (*tmr_function)(void));

/** 
* \brief This functions reset the interrupt flag
*  \param timerx a value form 1 to 5, select the timer from 1 to 5
* \return EXIT_FAILURE in case of the argument's conditions are not respected
 * \author Rafael Almeida & Samuel Simoes
 * \date 03-11-2017  
* 
*/
void tmr_reset_flag(int timerx );

/**
 * \brief This functions activates or disable the timer
 * \param timerx a value form 1 to 5, to select the timer from 1 to 5 
 * \param signal should be t_on or t_off, respectively turn on/off the timer
 * \return EXIT_FAILURE in case of the argument's conditions are not respected
 * \author Rafael Almeida & Samuel Simoes
 * \date 03-11-2017  
 */
void tmr_OnOff(int timerx, int signal);

