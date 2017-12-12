#include "../CKCommon/ConfigBits/config_bits.h" // NOTE!! Must precede project file includes

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#include "../CKCommon/UART/uart.h" 

#define SYSCLK  80000000L // System clock frequency, in Hz
#define PBCLOCK 40000000L // Peripheral Bus Clock frequency, in Hz

#include <time.h>
#include "hallClock.h"
#include "timer_libs.h"
void inc_clock(void)
{
    static count=0;
    if(count++%2)
    {
        incremente_time();
    }

}

int main(int argc, char** argv) {
    // Performance optimization (flash access time, enable instruct and data cache,... and PBClock setup
    SYSTEMConfigPerformance(SYSCLK);
    mOSCSetPBDIV(OSC_PB_DIV_2); // This is necessary since SYSTEMConfigPerformance defaults FPBDIV to DIV_1

    // Set RA3 and D5 ports
    TRISAbits.TRISA3 = 0;  // A3 as output
    TRISDbits.TRISD5 = 0; // D5 a output
    ODCDbits.ODCD5 = 1; // D5 as open-drain

    // Init UART and redirect tdin/stdot/stderr to UART
    if(UartInit(PBCLOCK, 115200) != UART_SUCCESS) {
        PORTAbits.RA3 = 1;
        while(1);
    }
    __XC_UART = 1; /* Redirect stdin/stdout/stderr to UART1*/
//#   
       // Set timer
    T2CONbits.ON = 0; // Stop timer
    T2CONbits.TCS = 0; // Internal clock
    T2CONbits.TCKPS = 0b111; //Select 256 pre-scaler: fclk = 40000000/256= 156250Hz
    T2CONbits.T32 = 0; // 16 bit timer operation
    PR2= 65000;   // Timer event around 0.4s (1/156250*65535)
    TMR2=0;
    T2CONbits.TON=1; // Start the timer    
    
//##-------- 
    struct tm str_time;
    str_time.tm_year = 2000-1900;
    str_time.tm_mon = 1;
    str_time.tm_mday = 28;
    str_time.tm_hour = 23;
    str_time.tm_min = 59;
    str_time.tm_sec = 40;
    str_time.tm_isdst = 0;
    
    update_time(str_time);
    struct tm time;
    
    tmr_config(3,2);
    tmr_intrpt_config(3,2,&inc_clock);
    tmr_OnOff(3,1);

    
    // Loop
    while (1) {
        //Busywait for timer
        while(IFS0bits.T2IF==0);  
        // Reset int flag
        IFS0bits.T2IF=0;
        get_timeHall(&time);
        printf("day: %d/%d/%d;\n hour: %d:%d:%d \n\r",time.tm_mday,time.tm_mon,(time.tm_year+1900),time.tm_hour,time.tm_min,time.tm_sec);
    }
    return 0;
}
/* *****************************************************************************
 End of File
 */
