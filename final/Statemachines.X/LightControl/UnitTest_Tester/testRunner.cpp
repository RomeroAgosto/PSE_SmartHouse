#include <CppUTest/TestHarness.h>
#include <CppUTest/TestHarness.h>
#include <stdio.h>
extern "C" {

#include "../StatemachineLightControl/statemachine_light_control.h"


/*--------------------------   Single Light-------------------------------------------------*/
TEST_GROUP(TEST_LIGHT_CONTROL_SINGLE) {
    void setup() // setup
    {

    }

    void teardown() {

    }
};

/* Simple turn on*/
TEST(TEST_LIGHT_CONTROL_SINGLE, TEST_LIGHT_CONTROL_TURN_ON) {
    reset_light_states();
    int length = 8;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[8] = {1, 0, 0, 1, 1, 1, 1, 1};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    set_desired_light(0, TRUE);
    set_light_sensor_values(0, TRUE);
    int i;
    for (i = 0; i < 2; i++) {
        statemachine_light_control(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    for (i = 0; i < length; i++) {
        //printf("I compare [%d] the expected result %d with current result %d\n",i,ResultExpected[i],Result_complete[i]);
        CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
    }
}
/* Turn on and turn off after 20 Cycles*/
TEST(TEST_LIGHT_CONTROL_SINGLE, TEST_LIGHT_CONTROL_TURN_ON_AND_OFF) {
    reset_light_states();
    int length = 12;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[12] = {1, 0, 0, 1,  1, 1, 1, 1,  1,1,1,0};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    set_desired_light(0, TRUE);
    set_light_sensor_values(0, TRUE);
    /*Cycle standard of 20*/
    set_light_cycles(0,20); /*important because another test would overwrite the static int -> test fails */
    int i;
    for (i = 0; i < 2; i++) {
        statemachine_light_control(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    set_light_sensor_values(0, FALSE);
    int j;
    for (j = 0; j<20 ; j++) {
        set_timer(0);
    }

    statemachine_light_control(0, Result);
    Result_complete[i * 4 + 0] = Result[0];
    Result_complete[i * 4 + 1] = Result[1];
    Result_complete[i * 4 + 2] = Result[2];
    Result_complete[i * 4 + 3] = Result[3];

    for (i = 0; i < length; i++) {
        //printf("I compare [%d] the expected result %d with current result %d\n",i,ResultExpected[i],Result_complete[i]);
        CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
    }
}
/* Change Cycle Time and Turn off after X Cycles*/
TEST(TEST_LIGHT_CONTROL_SINGLE, TEST_LIGHT_CONTROL_TURN_ON_AND_OFF_CHANGED_CYCLES) {
    reset_light_states();
    int length = 16;
    /* light general turned on, state before, setLight, state after*/
    int ResultExpected[16] = {1, 0, 0, 1,  1, 1, 1, 1,  1,1,1,1, 1,1,1,0};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    set_desired_light(0, TRUE);
    set_light_sensor_values(0, TRUE);

    /*Change Cycle time */
    set_light_cycles(0,50);
    int i;
    for (i = 0; i < 2; i++) {
        statemachine_light_control(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    set_light_sensor_values(0, FALSE);
    int j;
    /*go to one before timer limit exceeds */
    for (j = 0; j<49 ; j++) {
        set_timer(0);
    }

    statemachine_light_control(0, Result);
    Result_complete[i * 4 + 0] = Result[0];
    Result_complete[i * 4 + 1] = Result[1];
    Result_complete[i * 4 + 2] = Result[2];
    Result_complete[i * 4 + 3] = Result[3];
    i++;

    /*exceed timer limit */
    set_timer(0);
    set_timer(0);

    statemachine_light_control(0, Result);
    Result_complete[i * 4 + 0] = Result[0];
    Result_complete[i * 4 + 1] = Result[1];
    Result_complete[i * 4 + 2] = Result[2];
    Result_complete[i * 4 + 3] = Result[3];
    for (i = 0; i < length; i++) {
       // printf("I compare [%d] the expected result %d with current result %d\n",i,ResultExpected[i],Result_complete[i]);
        CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
    }
}
/* After turning on set schedule off*/
TEST(TEST_LIGHT_CONTROL_SINGLE, TEST_LIGHT_CONTROL_TURN_ON_AND_OFF_SETTING_DESIRED_VALUE_FALSE) {
    reset_light_states();
    int length = 16;
    /* light general turned on, state before, setLight, state after*/
    int ResultExpected[16] = {1, 0, 0, 1,  1, 1, 1, 1,  0,1,0,0,  0,0,0,0};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    set_desired_light(0, TRUE);
    set_light_sensor_values(0, TRUE);

    int i;
    for (i = 0; i < 2; i++) {
        statemachine_light_control(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /*set desired value to false -> sensor still active -> should turn off*/
    set_desired_light(0, FALSE);
    for (i;  i<4 ; i++) {
        statemachine_light_control(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
    }
    for (i = 0; i < length; i++) {
       // printf("I compare [%d] the expected result %d with current result %d\n",i,ResultExpected[i],Result_complete[i]);
        CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
    }
}

/*--------------------------   All Lights-------------------------------------------------*/
TEST_GROUP(TEST_LIGHT_CONTROL_ALL_LIGHTS) {
    void setup() // setup
    {

    }

    void teardown() {

    }
};


/* Simple turn on*/
TEST(TEST_LIGHT_CONTROL_ALL_LIGHTS, TEST_LIGHT_CONTROL_TURN_ON_ALL_LIGHTS) {
    reset_light_states();
    int length = 8;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[8] = {1, 0, 0, 1, 1, 1, 1, 1};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    int k;
    for (k = 0; k < 4; k++) {

        set_desired_light(k, TRUE);
        set_light_sensor_values(k, TRUE);
        int i;
        for (i = 0; i < 2; i++) {
            statemachine_light_control(k, Result);
            Result_complete[i * 4 + 0] = Result[0];
            Result_complete[i * 4 + 1] = Result[1];
            Result_complete[i * 4 + 2] = Result[2];
            Result_complete[i * 4 + 3] = Result[3];
        }
        for (i = 0; i < length; i++) {
           // printf("I compare light %d, i = %d, the expected result %d with current result %d\n",k,i,ResultExpected[i],Result_complete[i]);
            CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
        }
    }
}
/* Turn on and turn off after 20 Cycles*/
TEST(TEST_LIGHT_CONTROL_ALL_LIGHTS, TEST_LIGHT_CONTROL_TURN_ON_AND_OFF_ALL_LIGHTS) {
    reset_light_states();
    int length = 12;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[12] = {1, 0, 0, 1,  1, 1, 1, 1,  1,1,1,0};
    int Result[4], Result_complete[length];
    int k;
    for(k=0;k++;k<4) {
        /* set sensor values for test*/
        set_desired_light(k, TRUE);
        set_light_sensor_values(k, TRUE);
        /*Cycle standard of 20*/
        set_light_cycles(k, 20); /*important because another test would overwrite the static int -> test fails */
        int i;
        for (i = 0; i < 2; i++) {
            statemachine_light_control(k, Result);
            Result_complete[i * 4 + 0] = Result[0];
            Result_complete[i * 4 + 1] = Result[1];
            Result_complete[i * 4 + 2] = Result[2];
            Result_complete[i * 4 + 3] = Result[3];
            //printf("result[]= %d\n",Result_complete[i*3]);
        }
        /*turn off, because otherwise the the state turns to on again*/
        set_light_sensor_values(k, FALSE);
        int j;
        for (j = 0; j < 20; j++) {
            set_timer(0);
        }

        statemachine_light_control(k, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];

        for (i = 0; i < length; i++) {
            //printf("I compare [%d] the expected result %d with current result %d\n",i,ResultExpected[i],Result_complete[i]);
            CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
        }
    }
}
/* Change Cycle Time and Turn off after X Cycles*/
TEST(TEST_LIGHT_CONTROL_ALL_LIGHTS, TEST_LIGHT_CONTROL_TURN_ON_AND_OFF_CHANGED_CYCLES_ALL_LIGHTS) {
    reset_light_states();
    int length = 16;
    /* light general turned on, state before, setLight, state after*/
    int ResultExpected[16] = {1, 0, 0, 1,  1, 1, 1, 1,  1,1,1,1, 1,1,1,0};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    int k;
    for(k=0;k<4;k++){
        set_desired_light(k, TRUE);
        set_light_sensor_values(k, TRUE);

        /*Change Cycle time */
        set_light_cycles(k,50);
        int i;
        for (i = 0; i < 2; i++) {
            statemachine_light_control(k, Result);
            Result_complete[i * 4 + 0] = Result[0];
            Result_complete[i * 4 + 1] = Result[1];
            Result_complete[i * 4 + 2] = Result[2];
            Result_complete[i * 4 + 3] = Result[3];
            //printf("result[]= %d\n",Result_complete[i*3]);
        }
        set_light_sensor_values(k, FALSE);
        int j;
        /*go to one before timer limit exceeds */
        for (j = 0; j<49 ; j++) {
            set_timer(k);
        }

        statemachine_light_control(k, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        i++;

        /*exceed timer limit */
        set_timer(k);
        set_timer(k);

        statemachine_light_control(k, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        for (i = 0; i < length; i++) {
            // printf("I compare [%d] the expected result %d with current result %d\n",i,ResultExpected[i],Result_complete[i]);
            CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
        }
    }
}
/* After turning on set schedule off*/
TEST(TEST_LIGHT_CONTROL_ALL_LIGHTS, TEST_LIGHT_CONTROL_TURN_ON_AND_OFF_SETTING_DESIRED_VALUE_FALSE) {
    reset_light_states();
    int length = 16;
    /* light general turned on, state before, setLight, state after*/
    int ResultExpected[16] = {1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    int k;
    for (k = 0; k < 4; k++) {
        set_desired_light(k, TRUE);
        set_light_sensor_values(k, TRUE);

        int i;
        for (i = 0; i < 2; i++) {
            statemachine_light_control(k, Result);
            Result_complete[i * 4 + 0] = Result[0];
            Result_complete[i * 4 + 1] = Result[1];
            Result_complete[i * 4 + 2] = Result[2];
            Result_complete[i * 4 + 3] = Result[3];
            //printf("result[]= %d\n",Result_complete[i*3]);
        }
        /*set desired value to false -> sensor still active -> should turn off*/
        set_desired_light(k, FALSE);
        for (i; i < 4; i++) {
            statemachine_light_control(k, Result);
            Result_complete[i * 4 + 0] = Result[0];
            Result_complete[i * 4 + 1] = Result[1];
            Result_complete[i * 4 + 2] = Result[2];
            Result_complete[i * 4 + 3] = Result[3];
        }
        for (i = 0; i < length; i++) {
            // printf("I compare [%d] the expected result %d with current result %d\n",i,ResultExpected[i],Result_complete[i]);
            CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
        }
    }
}

}
