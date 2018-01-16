//#include "../CKCommon/ConfigBits/config_bits.h" // NOTE!! Must precede project file includes
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#include <p32xxxx.h>
//#include "../CKCommon/UART/uart.h" 

#define SYSCLK  80000000L // System clock frequency, in Hz
#define PBCLOCK 40000000L // Peripheral Bus Clock frequency, in Hz

#include <time.h>
#include "../CKCommon/ConfigBits/config_bits.h"
#include "../CKCommon/UART/uart.h"

#include "../../final/clock_hall/hallClock.h"


void counter()
{
    printf("Done!\n\r");
}

void delay(unsigned int dms){
    unsigned int t;
    t=ReadCoreTimer()+40000*dms;
    while(ReadCoreTimer() < t);
}


int main(int argc, char** argv) {
    
    // Performance optimization (flash access time, enable instruct and data cache,... and PBClock setup
    SYSTEMConfigPerformance(SYSCLK);
    mOSCSetPBDIV(OSC_PB_DIV_2); // This is necessary since SYSTEMConfigPerformance defaults FPBDIV to DIV_1

    if(UartInit(PBCLOCK, 115200) != UART_SUCCESS) {
        while(1);
    }
    __XC_UART = 1; /* Redirect stdin/stdout/stderr to UART1*/
     //init_uart();

    
    setup_clock_hall(&counter);

    
//##-------- 
    
#if 0
    struct tm str_time;
    str_time.tm_year = 2000-1900;
    str_time.tm_mon = 1;
    str_time.tm_mday = 28;
    str_time.tm_hour = 23;
    str_time.tm_min = 59;
    str_time.tm_sec = 40;
    str_time.tm_wday=1;
    str_time.tm_isdst = 0;
    update_time(str_time);
#else
    char *to_send="#@200001128235900"; /*message format #@AAAAMMWDDHHmmss */
    get_time(to_send);
#endif
    

    struct tm time;
    // Loop
    while (1) {
        delay(100);
        get_time_hall(&time);
        printf("day: %d/%d/%d;\n hour: %d:%d:%d \n\r",time.tm_mday,time.tm_mon,(time.tm_year+1900),time.tm_hour,time.tm_min,time.tm_sec);
    }
    return 0;
}
/* *****************************************************************************
 End of File
 */
