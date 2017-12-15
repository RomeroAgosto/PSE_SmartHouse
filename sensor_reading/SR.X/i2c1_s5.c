#include <stdio.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#include "i2c.h"

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

int i2c1_s5(){
    int ack;
    int td1;
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
    td1=i2c1_receive(NACK); 
    i2c1_stop();    // Send Stop event
    return td1;
}
