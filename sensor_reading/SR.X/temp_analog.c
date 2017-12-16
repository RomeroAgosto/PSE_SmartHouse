/*
 * 
 * Program source that returns the temperature value (in integer format) from 
 * one of the 4 analog sensors (LM335). This function works by using the ADC 
 * converter available on the PIC32MX795F512L microchip.
 * 
 */

#include <stdio.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>

int temp_analog(int *t[6]){
    double t1, t2, t3, t4, tm, temperature; //variables of voltages read from ADC converter 
    double calibration_value; //variable of voltage reading from a certain temperature
    AD1CON1bits.SSRC = 7; // Internal counter ends sampling and starts conversion
    AD1CON1bits.CLRASAM = 1; //Stop conversion when 1st A/D converter interrupt is generated and clears ASAM bit automatically
    AD1CON1bits.FORM = 0; // Integer 16 bit output format
    AD1CON2bits.VCFG = 0; // VR+=AVdd; VR-=AVss
    AD1CON2bits.SMPI = 3; // Number (+1) of consecutive conversions, stored in ADC1BUF0...ADCBUF{SMPI}
    AD1CON3bits.ADRC = 1; // ADC uses internal RC clock
    AD1CON3bits.SAMC = 16; // Sample time is 16TAD ( TAD = 100ns)
    int i;                  //variable to control selection of the sensors and storage of values
    for(i=0;i<4;i++) {
        switch(i){              //select the analog sensor to read its temperature
            case(0):
                AD1CHSbits.CH0SA = 4; // Select AN4 as input for A/D converter
                TRISBbits.TRISB4 = 1; // AN4 in input mode
                AD1PCFGbits.PCFG4 = 0; // AN4 as analog input
                calibration_value=2.71;  //voltage value at the temperature of 21ºC
                break;
            case(1):
                AD1CHSbits.CH0SA = 5; // Select AN5 as input for A/D converter
                TRISBbits.TRISB5 = 1; // AN5 in input mode
                AD1PCFGbits.PCFG5 = 0; // AN5 as analog input
                calibration_value=2.67; //voltage value at the temperature of 21ºC
                break;
            case(2):
                AD1CHSbits.CH0SA = 6; // Select AN6 as input for A/D converter
                TRISBbits.TRISB6 = 1; // AN6 in input mode
                AD1PCFGbits.PCFG6 = 0; // AN6 as analog input
                calibration_value=2.56; //voltage value at the temperature of 21ºC
                break;
            case(3):
                AD1CHSbits.CH0SA = 7; // Select AN7 as input for A/D converter
                TRISBbits.TRISB7 = 1; // AN7 in input mode
                AD1PCFGbits.PCFG7 = 0; // AN7 as analog input
                calibration_value=2.55; //voltage value at the temperature of 21ºC
                break;
            default:
                return -1;
                break;
        }
        AD1CON1bits.ON = 1; //Turn on ADC converter
        IFS1bits.AD1IF = 0; // Reset interrupt flag
        AD1CON1bits.ASAM = 1; // Start conversion
        while (IFS1bits.AD1IF == 0); // Wait fo EOC

        //next 4 lines represent calculation of voltages from 4 consecutive ADC readings
        t1 = (ADC1BUF0 * 3.3) / 1023; 
        t2 = (ADC1BUF1 * 3.3) / 1023;
        t3 = (ADC1BUF2 * 3.3) / 1023;
        t4 = (ADC1BUF3 * 3.3) / 1023;

        tm= (t1+t2+t3+t4)/4;  //average value of voltage read from ADC

        t[i]= (int)(21+(tm-calibration_value)*100); //calculate respective voltage and storing to a variable

    }
    return 0;
}

