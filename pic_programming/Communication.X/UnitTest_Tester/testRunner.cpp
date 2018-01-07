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

/* Simple turn on*/
TEST(TEST_COMMUNICATION, SIMPLEMESSAGE) {
    int length = 8;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[8] = {1, 0, 0, 1, 1, 1, 1, 1};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    int i;
    for (i = 0; i < length; i++) {
        //printf("I compare [%d] the expected result %d with current result %d\n",i,ResultExpected[i],Result_complete[i]);
        CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
    }
}

}