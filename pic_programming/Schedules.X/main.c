#include "../Communication.X/send_receive_messages.h"
#include "../Communication.X/message.h"
#include "schedules.h"
#include <stdio.h>

main() {
    int message_flag = 3;
    char msg[]="#111112322002305";
    message_handle(message_flag, msg);
    printf("id: %d \n",home.array_function[1].array_room[1].array_schedule[1].schedules[1].id);
    printf("val:%d \n",home.array_function[1].array_room[1].array_schedule[1].schedules[1].value);
    printf("start:%d \n",home.array_function[1].array_room[1].array_schedule[1].schedules[1].start_time);
    printf("stop:%d \n",home.array_function[1].array_room[1].array_schedule[1].schedules[1].stop_time);
    printf("enable: %d \n",home.array_function[1].array_room[1].array_schedule[1].schedules[1].enable);
    //send_message(send);

}