#include "schedules.h"
#include "desiredValues.h"
#include <stdio.h>

 
int  get_schedule_message(char *to_send){  
    int i,start,stop,value;
    char n_start[4];
    char n_stop[4];
    char n_value[2];
    //strcpy(message,to_send);
    /*message[2]:numeric valor to acess array_type 0
    message[3]:numeric valor to acess array_room 0
    message[4]:numeric valor to acess array_wday 6
    message[5]:numeric valor to acess schedules 0
    message[6]: id valor 0
    message[7-8]:value valor 88
    message[9]: enable valor 1
    message[10--13]:star time values 0000
    message[14-17]:stop_time values*/ //0100
    for(i=0;i<4;i++)    {
        n_start[i]=to_send[10+i];
        n_stop[i]=to_send[14+i];
 
    }
    for(i=0;i<2;i++){
        n_value[i]=to_send[7+i];
    }
 
    sscanf(n_start,"%4d",&start);// convert 4 char's to a int
    sscanf(n_stop,"%4d",&stop);// convert 4 char's to a int
    sscanf(n_value,"%2d",&value);// convert 2 char's to a int
 
    set_id(to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',to_send[6]-'0');
    set_value(to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',value);
    set_enable(to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',to_send[9]-'0');
    set_start_time(to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',start);
    set_stop_time(to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',stop);
    
    /*
    printf("start day %d\n",get_start_time(0,0,0,i));
    printf("#function[%d], room[%d],day[%d],schedules[%d], id = %d \n",to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',to_send[6]-'0'); 
    printf("#function[%d], room[%d],day[%d],schedules[%d], vale = %d\n",to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',value); 
    printf("#function[%d], room[%d],day[%d],schedules[%d], enable = %d\n",to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',to_send[9]-'0'); 
    printf("#function[%d], room[%d],day[%d],schedules[%d], start = %d\n",to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',start); 
    printf("#function[%d], room[%d],day[%d],schedules[%d], stop = %d\n",to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',stop); 
    */
 
}

 
