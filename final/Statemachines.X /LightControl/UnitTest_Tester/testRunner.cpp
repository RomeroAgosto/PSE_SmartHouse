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
    ResetLightStates();
    int length = 8;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[8] = {1, 0, 0, 1, 1, 1, 1, 1};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    SetDesiredLight(0, TRUE);
    SetLightSensorValues(0, TRUE);
    int i;
    for (i = 0; i < 2; i++) {
        Statemachine_LightControl(0, Result);
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
    ResetLightStates();
    int length = 12;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[12] = {1, 0, 0, 1,  1, 1, 1, 1,  1,1,1,0};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    SetDesiredLight(0, TRUE);
    SetLightSensorValues(0, TRUE);
    /*Cycle standard of 20*/
    SetNewCycle(0,20); /*important because another test would overwrite the static int -> test fails */
    int i;
    for (i = 0; i < 2; i++) {
        Statemachine_LightControl(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    SetLightSensorValues(0, FALSE);
    int j;
    for (j = 0; j<20 ; j++) {
        SetTimer(0);
    }

    Statemachine_LightControl(0, Result);
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
    ResetLightStates();
    int length = 16;
    /* light general turned on, state before, setLight, state after*/
    int ResultExpected[16] = {1, 0, 0, 1,  1, 1, 1, 1,  1,1,1,1, 1,1,1,0};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    SetDesiredLight(0, TRUE);
    SetLightSensorValues(0, TRUE);

    /*Change Cycle time */
    SetNewCycle(0,50);
    int i;
    for (i = 0; i < 2; i++) {
        Statemachine_LightControl(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    SetLightSensorValues(0, FALSE);
    int j;
    /*go to one before timer limit exceeds */
    for (j = 0; j<49 ; j++) {
        SetTimer(0);
    }

    Statemachine_LightControl(0, Result);
    Result_complete[i * 4 + 0] = Result[0];
    Result_complete[i * 4 + 1] = Result[1];
    Result_complete[i * 4 + 2] = Result[2];
    Result_complete[i * 4 + 3] = Result[3];
    i++;

    /*exceed timer limit */
    SetTimer(0);
    SetTimer(0);

    Statemachine_LightControl(0, Result);
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
    ResetLightStates();
    int length = 16;
    /* light general turned on, state before, setLight, state after*/
    int ResultExpected[16] = {1, 0, 0, 1,  1, 1, 1, 1,  0,1,0,0,  0,0,0,0};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    SetDesiredLight(0, TRUE);
    SetLightSensorValues(0, TRUE);

    int i;
    for (i = 0; i < 2; i++) {
        Statemachine_LightControl(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /*set desired value to false -> sensor still active -> should turn off*/
    SetDesiredLight(0, FALSE);
    for (i;  i<4 ; i++) {
        Statemachine_LightControl(0, Result);
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
    ResetLightStates();
    int length = 8;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[8] = {1, 0, 0, 1, 1, 1, 1, 1};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    int k;
    for (k = 0; k < 4; k++) {

        SetDesiredLight(k, TRUE);
        SetLightSensorValues(k, TRUE);
        int i;
        for (i = 0; i < 2; i++) {
            Statemachine_LightControl(k, Result);
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
    ResetLightStates();
    int length = 12;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[12] = {1, 0, 0, 1,  1, 1, 1, 1,  1,1,1,0};
    int Result[4], Result_complete[length];
    int k;
    for(k=0;k++;k<4) {
        /* set sensor values for test*/
        SetDesiredLight(k, TRUE);
        SetLightSensorValues(k, TRUE);
        /*Cycle standard of 20*/
        SetNewCycle(k, 20); /*important because another test would overwrite the static int -> test fails */
        int i;
        for (i = 0; i < 2; i++) {
            Statemachine_LightControl(k, Result);
            Result_complete[i * 4 + 0] = Result[0];
            Result_complete[i * 4 + 1] = Result[1];
            Result_complete[i * 4 + 2] = Result[2];
            Result_complete[i * 4 + 3] = Result[3];
            //printf("result[]= %d\n",Result_complete[i*3]);
        }
        /*turn off, because otherwise the the state turns to on again*/
        SetLightSensorValues(k, FALSE);
        int j;
        for (j = 0; j < 20; j++) {
            SetTimer(0);
        }

        Statemachine_LightControl(k, Result);
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
    ResetLightStates();
    int length = 16;
    /* light general turned on, state before, setLight, state after*/
    int ResultExpected[16] = {1, 0, 0, 1,  1, 1, 1, 1,  1,1,1,1, 1,1,1,0};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    int k;
    for(k=0;k<4;k++){
        SetDesiredLight(k, TRUE);
        SetLightSensorValues(k, TRUE);

        /*Change Cycle time */
        SetNewCycle(k,50);
        int i;
        for (i = 0; i < 2; i++) {
            Statemachine_LightControl(k, Result);
            Result_complete[i * 4 + 0] = Result[0];
            Result_complete[i * 4 + 1] = Result[1];
            Result_complete[i * 4 + 2] = Result[2];
            Result_complete[i * 4 + 3] = Result[3];
            //printf("result[]= %d\n",Result_complete[i*3]);
        }
        SetLightSensorValues(k, FALSE);
        int j;
        /*go to one before timer limit exceeds */
        for (j = 0; j<49 ; j++) {
            SetTimer(k);
        }

        Statemachine_LightControl(k, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        i++;

        /*exceed timer limit */
        SetTimer(k);
        SetTimer(k);

        Statemachine_LightControl(k, Result);
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
    ResetLightStates();
    int length = 16;
    /* light general turned on, state before, setLight, state after*/
    int ResultExpected[16] = {1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    int k;
    for (k = 0; k < 4; k++) {
        SetDesiredLight(k, TRUE);
        SetLightSensorValues(k, TRUE);

        int i;
        for (i = 0; i < 2; i++) {
            Statemachine_LightControl(k, Result);
            Result_complete[i * 4 + 0] = Result[0];
            Result_complete[i * 4 + 1] = Result[1];
            Result_complete[i * 4 + 2] = Result[2];
            Result_complete[i * 4 + 3] = Result[3];
            //printf("result[]= %d\n",Result_complete[i*3]);
        }
        /*set desired value to false -> sensor still active -> should turn off*/
        SetDesiredLight(k, FALSE);
        for (i; i < 4; i++) {
            Statemachine_LightControl(k, Result);
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
