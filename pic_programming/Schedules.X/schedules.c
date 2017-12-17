#include "schedules.h"
#include <stdio.h>


//static house home; /*home definition is supposed to be here!*/

int get_schedule_message(char *to_send)
{
    char message[500];
    int i,start,stop;
    char n_start[4];
    char n_stop[4];
    //strcpy(message,to_send);
    /*message[1]:numeric valor to acess array_function
    message[2]:numeric valor to acess array_room
    message[3]:numeric valor to acess array_schedule
    essage[4]:numeric valor to acess schedules
    message[5]: id valor
    message[6]:value valor
    message[7]: enable valor
    message[8--11]:star time values
    message[12-15]:stop_time values*/
    for(i=0;i<4;i++)
    {
        n_start[i]=to_send[8+i];
        n_stop[i]=to_send[12+i];
    }

    sscanf(n_start,"%4d",&start);// convert 4 chat for a int
    sscanf(n_stop,"%4d",&stop);

    home.array_function[to_send[1]-'0'].array_room[to_send[2]-'0'].array_schedule[to_send[3]-'0'].schedules[to_send[4]-'0'].id=to_send[5]-'0';
    home.array_function[to_send[1]-'0'].array_room[to_send[2]-'0'].array_schedule[to_send[3]-'0'].schedules[to_send[4]-'0'].value=to_send[6]-'0';
	home.array_function[to_send[1]-'0'].array_room[to_send[2]-'0'].array_schedule[to_send[3]-'0'].schedules[to_send[4]-'0'].enable=to_send[7]-'0';
    home.array_function[to_send[1]-'0'].array_room[to_send[2]-'0'].array_schedule[to_send[3]-'0'].schedules[to_send[4]-'0'].start_time=start;
    home.array_function[to_send[1]-'0'].array_room[to_send[2]-'0'].array_schedule[to_send[3]-'0'].schedules[to_send[4]-'0'].stop_time=stop;
}
