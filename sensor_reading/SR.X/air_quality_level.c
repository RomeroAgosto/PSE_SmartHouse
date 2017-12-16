#include <stdio.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>

//function that returns air quality level from a room
int air_quality_level(int *a[4]){
    double a1, a2, a3, a4, am;
    double c_threshold;
    AD1CON1bits.SSRC = 7; // Internal counter ends sampling and starts conversion
    AD1CON1bits.CLRASAM = 1; //Stop conversion when 1st A/D converter interrupt is generated and clears ASAM bit automatically
    AD1CON1bits.FORM = 0; // Integer 16 bit output format
    AD1CON2bits.VCFG = 0; // VR+=AVdd; VR-=AVss
    AD1CON2bits.SMPI = 3; // Number (+1) of consecutive conversions, stored in ADC1BUF0...ADCBUF{SMPI}
    AD1CON3bits.ADRC = 1; // ADC uses internal RC clock
    AD1CON3bits.SAMC = 16; // Sample time is 16TAD ( TAD = 100ns)
    int i;
    for(i=0;i<4;i++){
        switch(i){
            case(0):
                AD1CHSbits.CH0SA = 0; // Select AN0 as input for A/D converter
                TRISBbits.TRISB0 = 1; // AN0 in input mode
                AD1PCFGbits.PCFG0 = 0; // AN0 as analog input
                c_threshold=100;
                // suppose we have a sensor that reads concentrations from 0 to 100 ug/m3, for pm10 particles
                // below 20 ug/m3 is safe (green level)
                // between 20 and 50 ug/m3 is city-level concentrations in Europe (yellow level)
                // above 65 ug/m3 has long term consequences for health (red level)
                break;
            case(1):
                AD1CHSbits.CH0SA = 1; // Select AN5 as input for A/D converter
                TRISBbits.TRISB1 = 1; // AN5 in input mode
                AD1PCFGbits.PCFG1 = 0; // AN5 as analog input
                c_threshold=10000;
                // giving that we have a sensor that can read concentrations from 0 to 10000 ppm, for CO2 particles
                // concentrations below 600 ppm are safe (green level)
                // between 600 and 5000 ppm are unconfortable concentrations for humans (yellow level)
                // above 5000 ug/m3 are dangerous concentration for humans (red level)
                break;
            case(2):
                AD1CHSbits.CH0SA = 2; // Select AN6 as input for A/D converter
                TRISBbits.TRISB2 = 1; // AN6 in input mode
                AD1PCFGbits.PCFG2 = 0; // AN6 as analog input
                c_threshold=300;
                // admitting that a sensor is used that reads concentrations from 0 to 300 ppm, for CO particles
                // below 25 ppm are safe concentrations (green level)
                // between 25 and 200 ppm are harmful concentrations for humans, for long periods of time (yellow level)
                // above 200 ug/m3 are life-threatning concentrations (red level)
                break;
            case(3):
                AD1CHSbits.CH0SA = 3; // Select AN7 as input for A/D converter
                TRISBbits.TRISB3 = 1; // AN7 in input mode
                AD1PCFGbits.PCFG3 = 0; // AN7 as analog 
                c_threshold=500;
                // using a sensor that reads concentrations from 0 to 500 ppm, for O3 particles
                // below 100 ppm are safe concentrations (green level)
                // between 100 and 200 ppm are harmful concentrations for humans, for long periods of time (yellow level)
                // above 200 ug/m3 are life-threatning concentrations (red level)
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
        a1 = (ADC1BUF0 * 3.3) / 1023;
        a2 = (ADC1BUF1 * 3.3) / 1023;
        a3 = (ADC1BUF2 * 3.3) / 1023;
        a4 = (ADC1BUF3 * 3.3) / 1023;

        am=(a1+a2+a3+a4)/4;
        
        a[i]=(int)(c_threshold/3.3*am);
        
    }
    return 0;
}
