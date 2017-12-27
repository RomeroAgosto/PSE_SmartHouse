#include <stdio.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#include "i2c1.h"

int air_quality_level(int *a){
    int flag;                       // Flag variable to check for activated pins on PIC32MX795F512L.
    double a1, a2, a3, a4, am;      // Variables to calculate voltage reading from ADC converter.
    double c_threshold;             // Variable of upper threshold of the gas concentration reading.
    int humi_temp[2];               // Array of variables of humidity and temperature.
    int i;                          // Variable to select each of the 20 potentiometers.
    for(i=0;i<20;i++){
        switch(i){
            case(0):
                AD1CHSbits.CH0SA = 0; // Select AN0 as input for A/D converter.
                TRISBbits.TRISB0 = 1; // AN0 in input mode.
                AD1PCFGbits.PCFG0 = 0; // AN0 as analog input.
                
                // Supposing we have a sensor that reads concentrations from 0 to 100 ug/m3, for pm10 particles:
                // below 20 ug/m3 is safe (green level);
                // between 20 and 50 ug/m3 is city-level concentrations in Europe (yellow level);
                // above 65 ug/m3 has long term consequences for health (red level).
                
                c_threshold=100;       // Upper threshold of stipulated pm10 sensor. 
                flag=1;                // Pin RB0 is connected? Check.
                break;
            case(1):
                AD1CHSbits.CH0SA = 1; // Select AN5 as input for A/D converter.
                TRISBbits.TRISB1 = 1; // AN5 in input mode.
                AD1PCFGbits.PCFG1 = 0; // AN5 as analog input.
                
                // Giving that we have a sensor that can read concentrations from 0 to 10000 ppm, for CO2 particles:
                // concentrations below 600 ppm are safe (green level);
                // between 600 and 5000 ppm are unconfortable concentrations for humans (yellow level);
                // above 5000 ug/m3 are dangerous concentration for humans (red level).
                
                c_threshold=10000;   // Upper threshold of stipulated CO2 sensor. 
                flag=1;              // Pin RB1 is connected? Check.
                break;
            case(2):
                AD1CHSbits.CH0SA = 2; // Select AN6 as input for A/D converter.
                TRISBbits.TRISB2 = 1; // AN6 in input mode.
                AD1PCFGbits.PCFG2 = 0; // AN6 as analog input.
                
                // Admitting that a sensor is used that reads concentrations from 0 to 300 ppm, for CO particles:
                // below 25 ppm are safe concentrations (green level);
                // between 25 and 200 ppm are harmful concentrations for humans, for long periods of time (yellow level);
                // above 200 ug/m3 are life-threatning concentrations (red level).
                
                c_threshold=300;        // Upper threshold of stipulated CO sensor. 
                flag=1;                 // Pin RB2 is connected? Check.
                break;
            case(3):
                AD1CHSbits.CH0SA = 3; // Select AN7 as input for A/D converter.
                TRISBbits.TRISB3 = 1; // AN7 in input mode.
                AD1PCFGbits.PCFG3 = 0; // AN7 as analog.
                
                // Using a sensor that reads concentrations from 0 to 500 ppm, for O3 particles:
                // below 100 ppm are safe concentrations (green level);
                // between 100 and 200 ppm are harmful concentrations for humans, for long periods of time (yellow level);
                // above 200 ug/m3 are life-threatning concentrations (red level).
                
                c_threshold=500;        // Upper threshold of stipulated O3 sensor.
                flag=1;                 // Pin RB3 is connected? Check.
                break;
            case(4):
                i2c1_s8(humi_temp);
                flag=1;
                break;
            default:
                flag=0;
                break;
        }         
        if(flag==1){
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

            if(i<4)
                a[i]=(int)(c_threshold/3.3*am);
            else
                a[i]=(int)(humi_temp[0]);
        }
        else{
            a[i]=-77;
        }
    }
    return 0;
}
