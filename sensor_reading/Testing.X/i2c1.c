#include <xc.h>

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


