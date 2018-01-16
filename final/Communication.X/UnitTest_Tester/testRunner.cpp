#include <CppUTest/TestHarness.h>
#include <CppUTest/TestHarness.h>
#include <stdio.h>
extern "C" {

#include "../StatemachineCommunication/send_receive_messages.h"


/*--------------------------   Single Light-------------------------------------------------*/
TEST_GROUP(TEST_COMMUNICATION) {
    void setup() // setup
    {

    }

    void teardown() {

    }
};
/* Receive new shedule */
TEST(TEST_COMMUNICATION, SIMPLEMESSAGE_RECEIVE_SCHEDULE) {
    reset_messages();
    int length = 3;
    /* state, message created -> 1= create normal message*/
    int ResultExpected[3] = {2,2,0};
    int Result[3], Result_complete[length];
    /* set sensor values for test*/
    int i;
        char message[]="#+fghjk*";
        set_message(message);
        set_message_flag(1);
        statemachine_communication(Result);
        for (i=0;i<length;i++) {
            //printf("I compare in receive schedule[%d] the expected result %d with current result %d\n",i,ResultExpected[i],Result[i]);
            CHECK_EQUAL(ResultExpected[i], Result[i]);
        }
}
    //CHECK_EQUAL(ResultExpected[i], Result_complete[i])
/* Send update to the pc*/
TEST(TEST_COMMUNICATION, SIMPLEMESSAGE_SEND_NORMAL) {
    reset_messages();

    int length = 3;
    /* state, message created -> 1= create normal message*/
    int ResultExpected[3] = {1,1,0};
    int Result[3], Result_complete[length];
    /* set sensor values for test*/
    int i;
    char message[]="#?*";
    set_message(message);
    set_message_flag(1);
    int result= statemachine_communication(Result);
    for (i = 0; i < length; i++) {
        //printf("simple message\n");
        CHECK_EQUAL(Result[i],ResultExpected[i]);
        //CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
    }
}

TEST(TEST_COMMUNICATION, SIMPLEMESSAGE_RECEIVE_SCHEDULE_AND_SEND_MESSAGE) {
    reset_messages();
    int length = 6;
    /* state, message created -> 1= create normal message*/
    int ResultExpected[6] = {2,2,0,1,1,0};
    int Result[length/2], Result_complete[length];
    /* set sensor values for test*/
    int i;
    char message[]="#+fghjk*";
    set_message_flag(1);
    set_message(message);
    statemachine_communication(Result);
    for(i=0;i<3;i++){
        Result_complete[i] = Result[i];
    }
    char message_1[]="#?*";
    reset_messages();
    set_message_flag(1);
    set_message(message_1);
    statemachine_communication(Result);
    for(i=3;i<6;i++){
        Result_complete[i] = Result[i-3];
    }
    for (i=0;i<length;i++) {
        // printf("I compare  in receive and send [%d] the expected result %d with current result %d\n",i,ResultExpected[i],Result_complete[i]);
        CHECK_EQUAL(Result_complete[i], ResultExpected[i]);
    }

    //CHECK_EQUAL(ResultExpected[i], Result_complete[i])
}

TEST(TEST_COMMUNICATION, SIMPLEMESSAGE_RECEIVE_SCHEDULE_AND_SEND_MESSAGE_MESSAGE_DELAY) {
    reset_messages();
    int length = 6;
    /* state, message created -> 1= create normal message*/
    int ResultExpected[6] = {2,2,5,1,1,10};
    int Result[3], Result_complete[length];
    /* set sensor values for test*/
    int i;
    char message[]="trash#+fghjk*";
    set_message_flag(1);
    set_message(message);
    statemachine_communication(Result);
    for(i=0;i<3;i++){

        Result_complete[i] = Result[i];
    }
    char message_1[]="trashtrash#?*";
    set_message_flag(1);
    set_message(message_1);
    statemachine_communication(Result);
    for(i;i<6;i++){
        Result_complete[i] = Result[i-3];
    }
    for (i=0;i<length;i++) {
        //printf("I compare int send message with delay[%d] the expected result %d with current result %d\n",i,ResultExpected[i],Result_complete[i]);
        CHECK_EQUAL(ResultExpected[i],Result_complete[i]);
    }

    //CHECK_EQUAL(ResultExpected[i], Result_complete[i])
}

TEST(TEST_COMMUNICATION, SIMPLEMESSAGE_SEND_MESSAGE_MESSAGEFLAG_OFF_FIRST) {
    reset_messages();
    int length = 6;
    /* state, message created -> 1= create normal message*/
    int ResultExpected[6] = {0,0,0,1,1,0};
    int Result[length/2], Result_complete[length];
    /* set sensor values for test*/
    int k;
    char message[]="#?*";
    set_message_flag(0);
    set_message(message);
    statemachine_communication(Result);
    for(k=0;k<3;k++){
        Result_complete[k] = Result[k];
    }
    set_message_flag(1);
    set_message(message);
    statemachine_communication(Result);
    for(k=3;k<6;k++){
        Result_complete[k] = Result[k-3];
    }
    for (k=0;k<length;k++) {
        //  printf("I compare [%d] the expected result %d with current result %d\n",k,ResultExpected[k],Result[k]);
        CHECK_EQUAL(Result_complete[k], ResultExpected[k]);
    }

    //CHECK_EQUAL(ResultExpected[i], Result_complete[i])
}

TEST(TEST_COMMUNICATION, SIMPLEMESSAGE_GET_LOG_AFTER_FLAG){
    reset_messages();
    int length = 6;
    /* state, message created -> 1= create normal message*/
    int ResultExpected[6] = {0,0,0,3,3,0};
    int Result[length/2], Result_complete[length];
    /* set sensor values for test*/
    int k;
    char message[]="#?*";
    set_message_flag(0);
    set_message(message);
    statemachine_communication(Result);
    for(k=0;k<3;k++){
        Result_complete[k] = Result[k];
    }
    set_message_flag(1);
    char message_1[]="#!*";
    set_message(message_1);
    statemachine_communication(Result);
    for(k=3;k<6;k++){
        Result_complete[k] = Result[k-3];
    }
    for (k=0;k<length;k++) {
        //printf("I compare [%d] the expected result %d with current result %d\n",k,ResultExpected[k],Result[k]);
        CHECK_EQUAL(Result_complete[k], ResultExpected[k]);
    }


}

TEST(TEST_COMMUNICATION, SIMPLEMESSAGE_SEND_TECHNICIAN) {
    reset_messages();

    int length = 3;
    /* state, message created -> 1= create normal message*/
    int ResultExpected[3] = {5,5,0};
    int Result[3], Result_complete[length];
    /* set sensor values for test*/
    int i;
    char message[]="#~12345678912345678912345678901234567891234567890*";
    set_message(message);
    set_message_flag(1);
    statemachine_communication(Result);
    for (i = 0; i < length; i++) {
        printf("compare [Result[%d] = %d  with ResultExpected[%d]= %d\n",i,Result[i],i,ResultExpected[i]);
        CHECK_EQUAL(Result[i],ResultExpected[i]);
        //CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
    }
}

}