/** \file hallClock.c
* \brief This library include The Clock All of the System
*  
*
* 
*
* \author Samuel Simoes
*
* \date 03-11-2017
*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <p32xxxx.h>


#define TPS_256 7 // TCKPS code for xx pre-scaler
#define PBUSCLK 40000000L // Peripheral bus clock

static int dayMonMax[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; /*!<Array with last day of each month */
static struct tm time_hall; /*!<Clock all variable*/

static void (*longside_func)()=NULL; /*!<Buffur for function that will work alongside with clock all*/
static void (*halfan_hour)()=NULL;
// Stetup Hall clock and can put a func run alonside clock
void setup_clock_hall(void (*func)(void))
{
    T2CONbits.TON=0; // Start the timer
    T3CONbits.TON=0; // Start the timer
    longside_func=func;
    // Interrupt-related stuff
    void __attribute__( (interrupt(IPL2AUTO), vector(_TIMER_3_VECTOR))) tmr3_isr(void);
    IFS0bits.T3IF=0; // Reset interrupt flag
    IPC3bits.T3IP=2; //set interrupt priority (1..7) *** Make sure it matches iplx in isr declaration above ***
    //IPC3bits.IC3IS
    
    IEC0bits.T3IE = 1; // Enable T2 interrupts
   
    // Timer period configuration
    T2CONbits.TCKPS = TPS_256; //Select pre-scaler
    T2CONbits.T32 = 1; // 16 bit timer operation
    
    PR2=(float)(PBUSCLK/(1*256))-1; // Compute PR value  ;
    TMR2=0;
    TMR3=0;
    T2CONbits.TON=1; // Start the timer
    T3CONbits.TON=1; // Start the timer
  // Setup to use the external interrupt controller
    INTEnableSystemMultiVectoredInt();
}
// copy the time_hall to time
void get_time_hall(struct tm *time)
{
    *time=time_hall;
}
// save new time in time_hall
int update_time(struct tm time_temp)
{
    time_hall=time_temp;
    if(time_hall.tm_year%4==0 && (time_hall.tm_year%100!=0 || (time_hall.tm_year+1900)%400==0))
    {
        dayMonMax[1]=29;
    }
    else
    {
        dayMonMax[1]=28;
    }
    return 0;
}


void setup_half_a_hour(void (*func)(void))
{
    T4CONbits.TON=0; // Start the timer
    T5CONbits.TON=0; // Start the timer
    halfan_hour=func;
    // Interrupt-related stuff
    void __attribute__( (interrupt(IPL1AUTO), vector(_TIMER_5_VECTOR))) tmr5_isr(void);
    IFS0bits.T5IF=0; // Reset interrupt flag
    IPC5bits.T5IP=1; //set interrupt priority (1..7) *** Make sure it matches iplx in isr declaration above ***
    //IPC3bits.IC3IS
    
    IEC0bits.T5IE = 1; // Enable T2 interrupts
   
    // Timer period configuration
    T4CONbits.TCKPS = TPS_256; //Select pre-scaler
    T4CONbits.T32 = 1; // 16 bit timer operation
    PR4=(float)(PBUSCLK*20/256)-1; /*Set clock with 20sec*/
    //PR4=(float)(PBUSCLK/256*1800)-1; /*Set clock with 30min*/
    TMR4=0;
    TMR5=0;
    T4CONbits.TON=1; // Start the timer
    T5CONbits.TON=1; // Start the timer
}

/*PRIVATE FUNCTION*/
// will runs every second
void increment_time()
{
    
    time_hall.tm_sec=(time_hall.tm_sec+1)%60;   // increment sec
    
    if(time_hall.tm_sec==0)
    {    
        time_hall.tm_min=(time_hall.tm_min+1)%60;      // increment min
        
        if(time_hall.tm_min==0)   
        {
            time_hall.tm_hour=(time_hall.tm_hour+1)%24;  //increment hour     
            
            if(time_hall.tm_hour==0) 
            {   
                time_hall.tm_mday=(time_hall.tm_mday+1)%(dayMonMax[time_hall.tm_mon]+1);  // increment month-day
                time_hall.tm_wday=(time_hall.tm_wday+1)%7;                                // increment week-day
                time_hall.tm_yday++;                                                      // increment year-day
                
                if(time_hall.tm_mday==0)
                {
                    time_hall.tm_mday=1;                            // if day is 0 change to 1
                    time_hall.tm_mon=(time_hall.tm_mon+1)%12;       // increment month
        
                    if(time_hall.tm_mon==0)
                    {
                        time_hall.tm_yday=0;    // reset year-day
                        time_hall.tm_year++;    // increment year
                    
                    // -» In beging off a leap year, set dayMonMax[1]=29
                    if(time_hall.tm_mon==1)    
                    {
                        if(time_hall.tm_year%4==0 && (time_hall.tm_year%100!=0 || (time_hall.tm_year+1900)%400==0))
                        {
                            dayMonMax[1]=29;
                        }
                        else
                        {
                            dayMonMax[1]=28;
                        }
                    }
                    }
                }
            }
        }
    }
}


// timer for clock runs every secnd
void tmr3_isr(void)
{
    increment_time();
    longside_func();
    
    IFS0bits.T3IF=0; // Reset interrupt flag
}

void tmr5_isr(void)
{
    halfan_hour();
    IFS0bits.T5IF=0; // Reset interrupt flag
}
/* *****************************************************************************
 End of File
 */