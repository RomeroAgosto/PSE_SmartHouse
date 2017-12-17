#include "message.h"
#include "schedules.h"
int message_handle(int message_flag, char *message) {


    if (message_flag == SEND_NO_MESSAGE) {
        message = "#*";
    } else if (message_flag == SEND_NEW_STATUS) {
        message[0]='#';
        //create_normal_message(message);
    } else if (message_flag == SEND_SCHEDULES) {
    } else if (message_flag == RECEIVE_SCHEDULES) {
        get_schedule_message(message);
    } else if (message_flag == SEND_DATALOG) {

    }
    return 1;
}


