#include "schedules.h"
#include "desiredValues.h"
#include <stdio.h>

 
int  get_schedule_message(char *to_send)
{
    int i,start,stop,value;
    char n_start[4];
    char n_stop[4];
    char n_value[2];
    //strcpy(message,to_send);
    /*message[2]:numeric valor to acess array_type
    message[3]:numeric valor to acess array_room
    message[4]:numeric valor to acess array_wday
    message[5]:numeric valor to acess schedules
    message[6]: id valor
    message[7-8]:value valor
    message[9]: enable valor
    message[10--13]:star time values
    message[14-17]:stop_time values*/
    for(i=0;i<4;i++)
    {
        n_start[i]=to_send[10+i];
        n_stop[i]=to_send[14+i];
 
    }
    for(i=0;i<2;i++){
        n_value[i]=to_send[7+i];
    }
 
    sscanf(n_start,"%4d",&start);// convert 4 char's to a int
    sscanf(n_stop,"%4d",&stop);// convert 4 char's to a int
    sscanf(n_value,"%2d",&value);// convert 2 char's to a int
 
    setId(to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',to_send[6]-'0');
    setValue(to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',value);
    setEnable(to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',to_send[9]-'0');
    setStartTime(to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',start);
    setStopTime(to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',stop);
    printf("start day %d\n",getStartTime(0,0,0,i));
    printf("#function[%d], room[%d],day[%d],schedules[%d], id = %d \n",to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',to_send[6]-'0'); 
    printf("#function[%d], room[%d],day[%d],schedules[%d], vale = %d\n",to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',value); 
    printf("#function[%d], room[%d],day[%d],schedules[%d], enable = %d\n",to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',to_send[9]-'0'); 
    printf("#function[%d], room[%d],day[%d],schedules[%d], start = %d\n",to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',start); 
    printf("#function[%d], room[%d],day[%d],schedules[%d], stop = %d\n",to_send[2]-'0',to_send[3]-'0',to_send[4]-'0',to_send[5]-'0',stop); 
 
 
}

 
