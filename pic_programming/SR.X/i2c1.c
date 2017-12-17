#include <xc.h>

void i2c1_init(void){
    // Enable I2C1 module
    I2C1CONbits.ON=1;
    return;
}
int i2c1_setClock(unsigned int clock_freq){
    // Write I2C1BRG
    // Assumed a 40MHz PBCLOCK, value from Tab 24-1 of PIC32MXfamily ref manual
    if(clock_freq == 100000) {
        I2C1BRG=0x0C6;
        return 0;
    }
    return -1;
}
void i2c1_start(void){
    // Activate Start event (I2C1CON, bit SEN)
    // Wait for completion of the Start event. The I2C1CON bit SEN is automtic.
    //   reset and thus can be used for polling the end of the start command
    I2C1CONbits.SEN=1;
    while(I2C1CONbits.SEN==1);
    return;

}
void i2c1_stop(void){
    // Wait util the lower 5 bits of I2CxCON are all 0 (the lower 5 bits
    //       of I2CxCON must be 0 before attempting to set the PEN bit)
    // Activate Stop event (I2C1CON, bit PEN)
    // Wait for completion of the Stop event (I2C1CON, bit PEN)
    while( (I2C1CON & 0x1F) != 0);
    I2C1CONbits.PEN=1;
    while(I2C1CONbits.PEN==1);
    return;


}
int i2c1_send(unsigned char value){
    // Copy "value" to I2C1TRN register
    // Wait while master transmission is in progress (8 bits + ACK\)
    //     (I2C1STAT, bit TRSTAT ? transmit status bit)
    // Return acknowledge status bit (I2C1STAT, bit ACKSTAT)
    I2C1TRN=value;
    while(I2C1STATbits.TRSTAT);
    return I2C1STATbits.ACKSTAT;

}
char i2c1_receive(char ack_bit){
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
    while( (I2C1CON & 0x1F) != 0);
    I2C1CONbits.RCEN=1;
    while(I2C1STATbits.RBF == 0);
    I2C1CONbits.ACKDT=ack_bit;
    I2C1CONbits.ACKEN = 1;
    while(I2C1CONbits.ACKEN == 1);
    return(I2C1RCV);
}


