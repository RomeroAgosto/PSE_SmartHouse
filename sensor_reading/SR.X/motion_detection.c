#include <stdio.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>

//function that determine if motion was detected or not from a room
int motion_detection(int motion_sens_numb){
    double m1,m2,mm;
    
    AD1CON1bits.SSRC = 7; // Internal counter ends sampling and starts conversion
    AD1CON1bits.CLRASAM = 1; //Stop conversion when 1st A/D converter interrupt is generated and clears ASAM bit automatically
    AD1CON1bits.FORM = 0; // Integer 16 bit output format
    AD1CON2bits.VCFG = 0; // VR+=AVdd; VR-=AVss
    AD1CON2bits.SMPI = 1; // Number (+1) of consecutive conversions, stored in ADC1BUF0...ADCBUF{SMPI}
    AD1CON3bits.ADRC = 1; // ADC uses internal RC clock
    AD1CON3bits.SAMC = 16; // Sample time is 16TAD ( TAD = 100ns)
    switch(motion_sens_numb){
        case(0):
            AD1CHSbits.CH0SA = 9; // Select AN9 as input for A/D converter
            TRISBbits.TRISB9 = 1; // AN9 in input mode
            AD1PCFGbits.PCFG9 = 0; // AN9 as analog input
            break;
        case(1):
            AD1CHSbits.CH0SA = 10; // Select AN10 as input for A/D converter
            TRISBbits.TRISB10 = 1; // AN10 in input mode
            AD1PCFGbits.PCFG10 = 0; // AN10 as analog input
            break;
        default:
            return -1;
            break;
    }
    AD1CON1bits.ON = 1;
    
    IFS1bits.AD1IF = 0; // Reset interrupt flag
    AD1CON1bits.ASAM = 1; // Start conversion
    while (IFS1bits.AD1IF == 0); // Wait fo EOC

    // Convert to 0..3.3V 
    m1 = (ADC1BUF0 * 3.3) / 1023;
    m2 = (ADC1BUF1 * 3.3) / 1023;
    
    mm=(int)((m1+m2)/2);
    
    return mm;
}
