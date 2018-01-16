//#include "../CKCommon/ConfigBits/config_bits.h" // NOTE!! Must precede project file includes
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#include <p32xxxx.h>
#include <time.h>
#include "../CKCommon/ConfigBits/config_bits.h"
#include "../CKCommon/UART/uart.h"
#include "../clock_hall/hallClock.h"

#include "../Communication.X/StatemachineCommunication/send_receive_messages.h"
#include "../sensors/sr.h"
#include "../update/update.h"
#include "../log/log_functions.h"


#define SYSCLK  80000000L // System clock frequency, in Hz
#define PBCLOCK 40000000L // Peripheral Bus Clock frequency, in Hz

void run_alonsideWClock(void){
    SetTimer(0);
    SetTimer(1);
    SetTimer(2);
    SetTimer(3);
}

#if 0
void delay(unsigned int dms){
    unsigned int t;
    t=ReadCoreTimer()+40000*dms;
    while(ReadCoreTimer() < t);
}
#endif

int main(int argc, char** argv) {
    // Performance optimization (flash access time, enable instruct and data cache,... and PBClock setup
    SYSTEMConfigPerformance(SYSCLK);
    mOSCSetPBDIV(OSC_PB_DIV_2); // This is necessary since SYSTEMConfigPerformance defaults FPBDIV to DIV_1

    setup_clock_hall(&run_alonsideWClock);
    setup_half_a_hour(&setLogFlag);
    // Init UART and redirect tdin/stdot/stderr to UART
   
    int i;
    
    adc_init();
    if(UartInit(PBCLOCK, 115200) != UART_SUCCESS) {
        while(1);
    }
    __XC_UART = 1; /* Redirect stdin/stdout/stderr to UART1*/
     init_uart();
//##-------- 
    struct tm str_time;
    str_time.tm_year = 2000-1900;
    str_time.tm_mon = 0;
    str_time.tm_mday = 0;
    str_time.tm_hour = 0;
    str_time.tm_min = 59;
    str_time.tm_sec = 0;
    str_time.tm_wday = 0;
    
    update_time(str_time);

    
    TRISE=TRISE && 0xf000;
    PORTE=PORTE && 0xf000;
    TRISG=TRISG && 0xfff0;
    TRISGbits.TRISG2=0;
    PORTG=PORTG || 0x000f;
    TRISA=0x0000;
    PORTA=0x0000;
    // Loop
    while (1) {
        updateSensors();
        Statemachine_AirQuality(0);
        for(i=0;i<4;i++){
            Statemachine_LightControl(i);
        }
        Statemachine_WaterControl();
        for(i=0;i<8;i++){
            Statemachine_AirControl(i);
        }       
        Statemachine_Communication();  
        log_data_saving();
    }
    return 0;
}
/* *****************************************************************************
 End of File
 */
