#include <stdio.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#include "i2c.h"

int i2c1_s7(){
    int ack;
    int temp_d1;
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
    temp_d1=i2c1_receive(NACK); 
    i2c1_stop();    // Send Stop event
    return temp_d1;
}
