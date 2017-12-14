#include <stdio.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#include "i2c1.h"

// Generic defines
#define READ 1
#define WRITE 0
#define ACK 0
#define NACK 1

// TC74 temp sensor specific defines
#define SENS_ADDRESS_TC74 0x4D      // device dependent
#define TC74_CLK_FREQ 100000    // 100 KHz
#define RTR 0
#define ADDR_WR_TC74 ((SENS_ADDRESS_TC74 << 1) | WRITE)
#define ADDR_RD_TC74 ((SENS_ADDRESS_TC74 << 1) | READ)

// HIH8120 temp sensor specific defines
#define SENS_ADDRESS_HIH8120  0x27      // device dependent
#define HIH8120_CLK_FREQ 100000    // 100 KHz
#define ADDR_RD_HIH8120 ((SENS_ADDRESS_HIH8120 << 1) | READ)

//function that returns (analog) temperature value from a room
double temp_analog(int a_temp_sens_numb){
    double t1, t2, t3, t4, tm, temperature;
    double calibration_value;
    AD1CON1bits.SSRC = 7; // Internal counter ends sampling and starts conversion
    AD1CON1bits.CLRASAM = 1; //Stop conversion when 1st A/D converter interrupt is generated and clears ASAM bit automatically
    AD1CON1bits.FORM = 0; // Integer 16 bit output format
    AD1CON2bits.VCFG = 0; // VR+=AVdd; VR-=AVss
    AD1CON2bits.SMPI = 3; // Number (+1) of consecutive conversions, stored in ADC1BUF0...ADCBUF{SMPI}
    AD1CON3bits.ADRC = 1; // ADC uses internal RC clock
    AD1CON3bits.SAMC = 16; // Sample time is 16TAD ( TAD = 100ns)
    switch(a_temp_sens_numb){
        case(1):
            AD1CHSbits.CH0SA = 4; // Select AN4 as input for A/D converter
            TRISBbits.TRISB4 = 1; // AN4 in input mode
            AD1PCFGbits.PCFG4 = 0; // AN4 as analog input
            calibration_value=2.67;
            break;
        case(2):
            AD1CHSbits.CH0SA = 5; // Select AN5 as input for A/D converter
            TRISBbits.TRISB5 = 1; // AN5 in input mode
            AD1PCFGbits.PCFG5 = 0; // AN5 as analog input
            calibration_value=2.67;
            break;
        case(3):
            AD1CHSbits.CH0SA = 6; // Select AN6 as input for A/D converter
            TRISBbits.TRISB6 = 1; // AN6 in input mode
            AD1PCFGbits.PCFG6 = 0; // AN6 as analog input
            calibration_value=2.55;
            break;
        case(4):
            AD1CHSbits.CH0SA = 7; // Select AN7 as input for A/D converter
            TRISBbits.TRISB7 = 1; // AN7 in input mode
            AD1PCFGbits.PCFG7 = 0; // AN7 as analog input
            calibration_value=2.57;
            break;
        default:
            return -1;
            break;
    }
    AD1CON1bits.ON = 1;
    IFS1bits.AD1IF = 0; // Reset interrupt flag
    AD1CON1bits.ASAM = 1; // Start conversion
    while (IFS1bits.AD1IF == 0); // Wait fo EOC

    t1 = (ADC1BUF0 * 3.3) / 1023;
    t2 = (ADC1BUF1 * 3.3) / 1023;
    t3 = (ADC1BUF2 * 3.3) / 1023;
    t4 = (ADC1BUF3 * 3.3) / 1023;
    
    tm= (t1+t2+t3+t4)/4;

    temperature= 22+(tm-calibration_value)*100;
        
    return temperature;
}
//function that returns air quality level from a room
char air_quality_level(int air_sens_numb){
    double a1, a2, a3, a4, am;
    int level;
    AD1CON1bits.SSRC = 7; // Internal counter ends sampling and starts conversion
    AD1CON1bits.CLRASAM = 1; //Stop conversion when 1st A/D converter interrupt is generated and clears ASAM bit automatically
    AD1CON1bits.FORM = 0; // Integer 16 bit output format
    AD1CON2bits.VCFG = 0; // VR+=AVdd; VR-=AVss
    AD1CON2bits.SMPI = 3; // Number (+1) of consecutive conversions, stored in ADC1BUF0...ADCBUF{SMPI}
    AD1CON3bits.ADRC = 1; // ADC uses internal RC clock
    AD1CON3bits.SAMC = 16; // Sample time is 16TAD ( TAD = 100ns)
    switch(air_sens_numb){
        case(1):
            AD1CHSbits.CH0SA = 0; // Select AN0 as input for A/D converter
            TRISBbits.TRISB0 = 1; // AN0 in input mode
            AD1PCFGbits.PCFG0 = 0; // AN0 as analog input
            break;
        case(2):
            AD1CHSbits.CH0SA = 1; // Select AN5 as input for A/D converter
            TRISBbits.TRISB1 = 1; // AN5 in input mode
            AD1PCFGbits.PCFG1 = 0; // AN5 as analog input
            break;
        case(3):
            AD1CHSbits.CH0SA = 2; // Select AN6 as input for A/D converter
            TRISBbits.TRISB2 = 1; // AN6 in input mode
            AD1PCFGbits.PCFG2 = 0; // AN6 as analog input
            break;
        case(4):
            AD1CHSbits.CH0SA = 3; // Select AN7 as input for A/D converter
            TRISBbits.TRISB3 = 1; // AN7 in input mode
            AD1PCFGbits.PCFG3 = 0; // AN7 as analog input
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
    
    if(am<1.1){
        return 'G';
    }
    if(am>=1.1 & am<2.2){
        return 'Y';
    }
    if(am>=2.2){
        return 'R';
    }
}
//function that returns (digital) temperature value from a room
double temp_digital(int d_temp_sens_numb){
    
    int ack;
    double temp_digital;
    TRISBbits.TRISB8=0;
    TRISBbits.TRISB9=0;
    TRISBbits.TRISB10=0;
    TRISBbits.TRISB11=0;
    LATBbits.LATB8=1;
    LATBbits.LATB9=1;
    LATBbits.LATB10=1;
    LATBbits.LATB11=1;
    switch(d_temp_sens_numb){
        case(5):
            LATBbits.LATB8=0;
        case(6):
            LATBbits.LATB9=0;
        default:
            return -1;
            break;
    }
    setbuf(stdin, NULL); //no input buffer (for scanf)
    setbuf(stdout, NULL); //no output buffer (for printf)
    i2c1_init();
    if(i2c1_setClock(TC74_CLK_FREQ)) {
        printf("Error in i2c1_setClock()\n\r");
        while(1);
    }
    i2c1_start(); // Send Start event
    ack=i2c1_send(ADDR_WR_TC74); // Send Address + WR (ADDR_WR); copy return value to "ack" variable
    ack+=i2c1_send(RTR); // Send Command (RTR); add return value to "ack" variable
    i2c1_start(); // Send Start event (again)
    ack+=i2c1_send(ADDR_RD_TC74);    // Send Address + RD (ADDR_RD); add return value to "ack" variable
    // Test "ack" variable; if "ack" != 0 then an error has occurred
    if(ack) {
        printf("Error during temperature reading\n\r");            
    }
    // Receive a value from slave ? send NACK; copy received value to
    // "temperature" variable
    temp_digital=i2c1_receive(NACK); 
    i2c1_stop();    // Send Stop event
    return temp_digital;
}
//function that returns (digital) temperature and humidity value from a room
double* humidity_temperature(int h_dt_sens_numb){
    
    int ack;
    int th=0x00;
    int t=0x0000;
    int h=0x0000;
    int status=0x0;
    
    static double humi_temp [2];
    
    // define ports connected to mosfet 1,2,3,4 as deactivated
    switch(h_dt_sens_numb){
        case(7):
            //port connected to mosfet 3 activated
        case(8):
            //port connected to mosfet 4 activated
        default:
            exit(-1);
            break;
    }
    setbuf(stdin, NULL); //no input buffer (for scanf)
    setbuf(stdout, NULL); //no output buffer (for printf)
    i2c1_init();
    if(i2c1_setClock(HIH8120_CLK_FREQ)) {
        printf("Error in i2c1_setClock()\n\r");
        while(1);
    }
    
    i2c1_start(); // Send Start event (again)
    ack=i2c1_send(ADDR_RD_HIH8120);    // Send Address + RD (ADDR_RD); add return value to "ack" variable
    // Test "ack" variable; if "ack" != 0 then an error has occurred
    if(ack) {
        printf("Error during temperature and humidity reading\n\r");            
    }
    // Receive a value from slave ? send NACK; copy received value to
    // "temperature" variable
    th=i2c1_receive(ACK); 
    status=th>>6;
    if (status == 0x0){
        h=(th | 0x0000)<<8;
        th=i2c1_receive(ACK); 
        h=(th | 0x0000);
        
        th=i2c1_receive(ACK);
        t=(th | 0x0000)<<8;
        th=i2c1_receive(NACK);
        t=(th | 0x0000)>>2;
    }
    i2c1_stop();    // Send Stop event
    humi_temp[0]=h/16382.0*100.0;
    humi_temp[1]=t/16382.0*165.0-40.0;
    return humi_temp;
    if (status != 0x0)
        return humidity_temperature(h_dt_sens_numb);
}
//function that determine if motion was detected or not from a room
char motion_detection(int motion_sens_numb){
    double m1,m2,mm;
    
    AD1CON1bits.SSRC = 7; // Internal counter ends sampling and starts conversion
    AD1CON1bits.CLRASAM = 1; //Stop conversion when 1st A/D converter interrupt is generated and clears ASAM bit automatically
    AD1CON1bits.FORM = 0; // Integer 16 bit output format
    AD1CON2bits.VCFG = 0; // VR+=AVdd; VR-=AVss
    AD1CON2bits.SMPI = 1; // Number (+1) of consecutive conversions, stored in ADC1BUF0...ADCBUF{SMPI}
    AD1CON3bits.ADRC = 1; // ADC uses internal RC clock
    AD1CON3bits.SAMC = 16; // Sample time is 16TAD ( TAD = 100ns)
    switch(motion_sens_numb){
        case(1):
            AD1CHSbits.CH0SA = 8; // Select AN8 as input for A/D converter
            TRISBbits.TRISB8 = 1; // AN8 in input mode
            AD1PCFGbits.PCFG8 = 0; // AN8 as analog input
            break;
        case(2):
            AD1CHSbits.CH0SA = 9; // Select AN9 as input for A/D converter
            TRISBbits.TRISB9 = 1; // AN9 in input mode
            AD1PCFGbits.PCFG9 = 0; // AN9 as analog input
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
    
    mm=(m1+m2)/2;
    
    if(mm<1.65){
        return 'D';
    }
    if(mm>=1.65){
        return 'N';
    }
}
