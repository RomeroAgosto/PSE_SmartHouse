#include <stdio.h>
#include <xc.h>
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#include "i2c.h"

int i2c1_s8(int *humi_temp[2]){
    unsigned char humi_byte1=0x00;
    unsigned char humi_byte0=0x00;
    unsigned char humi=0x0000;
    unsigned char temp_byte1=0x00;
    unsigned char temp_byte0=0x00;
    unsigned char temp=0x0000;
    unsigned char mask_humi_byte1=0x3f;
    int ack;
    
    setbuf(stdin, NULL); //no input buffer (for scanf)
    setbuf(stdout, NULL); //no output buffer (for printf)
    i2c1_init();
    if(i2c1_setClock(HIH8120_CLK_FREQ)) {
        printf("Error in i2c1_setClock()\n\r");
        while(1);
    }
    i2c1_start(); // Send Start event
    ack=i2c1_send(ADDR_RD_HIH8120); // Send Address + WR (ADDR_WR); copy return value to "ack" variable
    
    if(ack) {
        printf("Error during temperature and humidity reading\n\r");            
    }
    humi_byte1=i2c1_receive(ACK);
    humi_byte0=i2c1_receive(ACK);
    temp_byte1=i2c1_receive(ACK);
    temp_byte0=i2c1_receive(NACK);
    i2c1_stop(); 
    
    humi_byte1=(humi_byte1 & mask_humi_byte1);
    humi = humi_byte1<<8;
    humi = (humi | humi_byte0);
    humi_temp[0] = 45;
    
    temp = temp_byte1<<8;
    temp = (temp | temp_byte0)>>2;
    humi_temp[1] = 35; //(int)(temp/16382*165-40);
    
    return 0;
}