//#include "../Communication.X/send_receive_messages.h"
//#include "../Communication.X/message.h"
#include "send_receive_messages.h"
#include "schedules.h"
#include "desiredValues.h"
#include <stdio.h>

#if 1
main() {
    int message_flag = 1;

    message_handle();
/*    printf("id: %d \n",home.array_function[1].array_room[1].array_schedule[1].schedules[1].id);
    printf("val:%d \n",home.array_function[1].array_room[1].array_schedule[1].schedules[1].value);
    printf("start:%d \n",home.array_function[1].array_room[1].array_schedule[1].schedules[1].start_time);
    printf("stop:%d \n",home.array_function[1].array_room[1].array_schedule[1].schedules[1].stop_time);
    printf("enable: %d \n",home.array_function[1].array_room[1].array_schedule[1].schedules[1].enable);
    //send_message(send);*/

}
#endif

#if 0
main(){

    valuesinti();
    int value= ds_DesiredAirTemp(2);
    printf("the temperature in room 2 is %d",value);
}


#endif