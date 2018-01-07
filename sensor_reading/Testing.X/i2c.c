#include <xc.h>
#include <stdio.h>
#include "i2c.h"

void i2c1_init(void){
    I2C1CONbits.ON=1; // Enable I2C1 module.
    return;
}
int i2c1_setClock(unsigned int clock_freq){

    if(clock_freq == 100000) { // Condition to verify if slave clock is defined as 100 KHz.
        I2C1BRG=0x0C6;         // Baudrate generator for I2C1 (assuming PBCLOCK=40 MHz).
        return 0;
    }
    return -1;
}
void i2c1_start(void){
    I2C1CONbits.SEN=1;         // Activate start event.
    while(I2C1CONbits.SEN==1); // Wait for activation of the Start event.
    return;

}
void i2c1_stop(void){
    while( (I2C1CON & 0x1F) != 0); // Wait until the lower 5 bits of register I2C1CON are all 0.
    I2C1CONbits.PEN=1;             // Activate Stop event.
    while(I2C1CONbits.PEN==1);     // Wait for the completion of the Stop event.
    return;


}
int i2c1_send(unsigned char value){
    
    I2C1TRN=value;               // Transmit value register (I2C1TRN) with the "value".
    while(I2C1STATbits.TRSTAT);  // Wait for master to transmit data to slave device.
    return I2C1STATbits.ACKSTAT; // Return acknowledge status bit of the slave device.

}
char i2c1_receive(char ack_bit){
    while( (I2C1CON & 0x1F) != 0);// Wait until the lower 5 bits of register I2C1CON are all 0.
    I2C1CONbits.RCEN=1;           // Enable Receive Mode for the I2C1 module.
    while(I2C1STATbits.RBF == 0); // Wait while received data byte is not written
                                  // in I2C1RCV register.
    I2C1CONbits.ACKDT=ack_bit;    // Set acknowledge bit to send to slave device.
    I2C1CONbits.ACKEN = 1;        // Send ACKDT bit to slave device.
    while(I2C1CONbits.ACKEN == 1);// Wait for acknowledge bit to be transmitted to slave device.
    return(I2C1RCV);              // Return value from register I2C1RCV.
}

int i2c1_s7(){
    int ack;
    int temp_d1;
    setbuf(stdin, NULL); //no input buffer (for scanf)
    setbuf(stdout, NULL); //no output buffer (for printf)
    i2c1_init();
    if(i2c1_setClock(TC74_CLK_FREQ)) {
        //printf("Error in i2c1_setClock()\n\r");
        while(1);
    }
    i2c1_start(); // Send Start event
    ack=i2c1_send(ADDR_WR_TC74); // Send Address + WR (ADDR_WR); copy return value to "ack" variable
    ack+=i2c1_send(RTR); // Send Command (RTR); add return value to "ack" variable
    i2c1_start(); // Send Start event (again)
    ack+=i2c1_send(ADDR_RD_TC74);    // Send Address + RD (ADDR_RD); add return value to "ack" variable
    // Test "ack" variable; if "ack" != 0 then an error has occurred
    if(ack) {
        //printf("Error during temperature reading\n\r");            
    }
    // Receive a value from slave ? send NACK; copy received value to
    // "temperature" variable
    temp_d1=i2c1_receive(NACK); 
    i2c1_stop();    // Send Stop event
    return temp_d1;
}

int i2c1_s8(int *humi_temp){
    unsigned char humi_byte1=0x00;
    unsigned char humi_byte0=0x00;
    unsigned char humi=0x0000;
    unsigned char temp_byte1=0x00;
    unsigned char temp_byte0=0x00;
    unsigned char temp=0x0000;
    unsigned char mask_humi_byte1=0x3f;
    char flag;
    int ack;
    
    setbuf(stdin, NULL); //no input buffer (for scanf)
    setbuf(stdout, NULL); //no output buffer (for printf)
    i2c1_init();
    if(i2c1_setClock(HIH8120_CLK_FREQ)) {
        //printf("Error in i2c1_setClock()\n\r");
        while(1);
    }
    i2c1_start(); // Send Start event
    ack=i2c1_send(ADDR_RD_HIH8120); // Send Address + WR (ADDR_WR); copy return value to "ack" variable
    flag=1;
    if(ack) {
        //printf("Error during temperature and humidity reading\n\r");      
        flag=0;
        
    }
    if(flag==1) {
        humi_byte1=i2c1_receive(ACK);
        humi_byte0=i2c1_receive(ACK);
        temp_byte1=i2c1_receive(ACK);
        temp_byte0=i2c1_receive(NACK);
        i2c1_stop(); 

        humi_byte1=(humi_byte1 & mask_humi_byte1);
        humi = humi_byte1<<8;
        humi = (humi | humi_byte0);
        humi_temp[0] = (int)(humi/16382*100);

        temp = temp_byte1<<8;
        temp = (temp | temp_byte0)>>2;
        humi_temp[1] = (int)(temp/16382*165-40);
    }
    else {
        humi_temp[0]=-77;
        humi_temp[1]=-77;
    }
    
    
    return 0;
}

void i2c2_init(void){
    // Enable I2C1 module
    I2C2CONbits.ON=1;
    return;
}
int i2c2_setClock(unsigned int clock_freq){
    // Write I2C1BRG
    // Assumed a 40MHz PBCLOCK, value from Tab 24-1 of PIC32MXfamily ref manual
    if(clock_freq == 100000) {
        I2C2BRG=0x0C6;
        return 0;
    }
    return -1;
}
void i2c2_start(void){
    // Activate Start event (I2C1CON, bit SEN)
    // Wait for completion of the Start event. The I2C1CON bit SEN is automtic.
    //   reset and thus can be used for polling the end of the start command
    I2C2CONbits.SEN=1;
    while(I2C2CONbits.SEN==1);
    return;

}
void i2c2_stop(void){
    // Wait util the lower 5 bits of I2CxCON are all 0 (the lower 5 bits
    //       of I2CxCON must be 0 before attempting to set the PEN bit)
    // Activate Stop event (I2C1CON, bit PEN)
    // Wait for completion of the Stop event (I2C1CON, bit PEN)
    while( (I2C2CON & 0x1F) != 0);
    I2C2CONbits.PEN=1;
    while(I2C2CONbits.PEN==1);
    return;


}
int i2c2_send(unsigned char value){
    // Copy "value" to I2C1TRN register
    // Wait while master transmission is in progress (8 bits + ACK\)
    //     (I2C1STAT, bit TRSTAT ? transmit status bit)
    // Return acknowledge status bit (I2C1STAT, bit ACKSTAT)
    I2C2TRN=value;
    while(I2C2STATbits.TRSTAT);
    return I2C2STATbits.ACKSTAT;

}
char i2c2_receive(char ack_bit){
    // Wait util the lower 5 bits of I2C1CON are all 0 (the lower 5 bits
    //      of I2C1CON must be 0 before attempting to set the RCEN bit)
    // Activate RCEN bit (receive enable bit, I2C1CON)
    // Wait while byte not received (I2C1STAT, bit RBF ? receive buffer
    //      full status bit)
    // Send ACK / NACK bit. For that:
    //   1. Copy "ack_bit" to I2C1CON, bit ACKDT (be sure "ack_bit" value
    //       is only 0 or 1)
    //   2. Start Acknowledge sequence (I2C1CON, bit ACKEN)
    // Wait for completion of Acknowledge sequence (I2C1CON, bit ACKEN)
    // Return received value (I2C1RCV)
    while( (I2C2CON & 0x1F) != 0);
    I2C2CONbits.RCEN=1;
    while(I2C2STATbits.RBF == 0);
    I2C2CONbits.ACKDT=ack_bit;
    I2C2CONbits.ACKEN = 1;
    while(I2C2CONbits.ACKEN == 1);
    return(I2C2RCV);
}

