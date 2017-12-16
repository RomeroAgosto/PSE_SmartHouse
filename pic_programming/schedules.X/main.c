#include "send_messages.h"
#include "message.h"
#include "schedules.h"
#include "../clock_hall/hallClock.h"
#include <time.h>


int main() {
    int message_flag = 3;
    char send[5000];
    char msg[]="#11112322002305";
    message_handle(message_flag, msg);
    printf("id: %d \n",home.array_function[1].array_room[1].array_schedule[1].schedules[1].id);
    printf("val:%d \n",home.array_function[1].array_room[1].array_schedule[1].schedules[1].value);
    printf("start:%d \n",home.array_function[1].array_room[1].array_schedule[1].schedules[1].start_time);
    printf("stop:%d \n",home.array_function[1].array_room[1].array_schedule[1].schedules[1].stop_time);

    //check_schedule();
    //send_message(send);
    return 0;
}