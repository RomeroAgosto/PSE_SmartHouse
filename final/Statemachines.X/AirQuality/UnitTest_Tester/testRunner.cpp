#include <CppUTest/TestHarness.h>
#include <CppUTest/TestHarness.h>
#include <stdio.h>
extern "C" {

#include "../Statemachine_AirQuality/statemachine_airquality_control.h"
/*
void statemachine_air_quality(int room,int *test);
void set_air_quality(int room, int *input_values);
void GetAirQuality(int room, int *sensor_values);
void SetLightQuality(int room, int color);
void SetVentilatorState(int room, int on);
void reset_air_quality_state();
/*--------------------------    TEST THE GREEN-------------------------------------------------*/

TEST_GROUP(AirQuality_GREEN) {
    void setup() // setup
    {

    }

    void teardown() {

    }
};

/* Stay in green Threshold change -> stuck on bound */
TEST(AirQuality_GREEN, TEST_AIR_QUALITY_GREEN_THRESHOLD_BOUND_LOW) {
    reset_air_quality_state();
    /*first set temperature to 60 degree*/
    int length =16;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 0,     0, 0,0,0,  0,0,0,0,  0,0,0,0};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    int sensor_values[5]={21,610,26,103,2};
    set_air_quality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    set_air_quality_threshold(0,0,20);
    set_air_quality_threshold(0,1,600);
    set_air_quality_threshold(0,2,25);
    set_air_quality_threshold(0,3,100);
    set_air_quality_threshold(0,4,2);
    /* set red thresholds*/
    set_air_quality_threshold(1,0,65);
    set_air_quality_threshold(1,1,5000);
    set_air_quality_threshold(1,2,200);
    set_air_quality_threshold(1,3,200);
    set_air_quality_threshold(1,4,2);
    int i;
    for (i = 0; i < 2; i++) {
        statemachine_air_quality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /* 0.01 would be in the bound!*/
    set_air_quality_threshold(0,0,19);
    set_air_quality_threshold(0,1,590);
    set_air_quality_threshold(0,2,24);
    set_air_quality_threshold(0,3,98);
    set_air_quality_threshold(0,4,1);
    for (i ; i < 4; i++) {
        statemachine_air_quality(0, Result);
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

/* Jump from GREEN TO RED through sensor change  */
TEST(AirQuality_GREEN, TEST_AIR_QUALITY_GREEN_RED_HIGH_VALUE) {
    reset_air_quality_state();
    /*first set temperature to 60 degree*/
    int length = 8;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[8] = {0, 0, 0, 2,     2, 1,2, 2};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    int sensor_values[5]={68,5021,203,203,10};
    set_air_quality(0,sensor_values);
    /*set thresholds*/
    set_air_quality_threshold(0,0,20);
    set_air_quality_threshold(0,1,600);
    set_air_quality_threshold(0,2,25);
    set_air_quality_threshold(0,3,100);
    set_air_quality_threshold(0,4,2);
    /* set red thresholds*/
    set_air_quality_threshold(1,0,65);
    set_air_quality_threshold(1,1,5000);
    set_air_quality_threshold(1,2,200);
    set_air_quality_threshold(1,3,200);
    set_air_quality_threshold(1,4,2);
    int i;
    for (i = 0; i < 2; i++) {
        statemachine_air_quality(0, Result);
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
/* Jump from GREEN TO RED through threshold change */
TEST(AirQuality_GREEN, TEST_AIR_QUALITY_GREEN_RED_THRESHOLD) {
    reset_air_quality_state();
    /*first set temperature to 60 degree*/
    int length =16;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 0,     0, 0,0,0,  0,0,0,2,  2,1,2,2};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    int sensor_values[5]={21,610,26,103,2};
    set_air_quality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    /*set thresholds*/
    set_air_quality_threshold(0,0,20);
    set_air_quality_threshold(0,1,600);
    set_air_quality_threshold(0,2,25);
    set_air_quality_threshold(0,3,100);
    set_air_quality_threshold(0,4,2);
    /* set red thresholds*/
    set_air_quality_threshold(1,0,65);
    set_air_quality_threshold(1,1,5000);
    set_air_quality_threshold(1,2,200);
    set_air_quality_threshold(1,3,200);
    set_air_quality_threshold(1,4,2);
    int i;
    for (i = 0; i < 2; i++) {
        statemachine_air_quality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /* 0.01 would be in the bound!*/
    /* set red thresholds*/
    set_air_quality_threshold(1,0,15);
    set_air_quality_threshold(1,1,500);
    set_air_quality_threshold(1,2,15);
    set_air_quality_threshold(1,3,50);
    set_air_quality_threshold(1,4,0);
    for (i ; i < 4; i++) {
        statemachine_air_quality(0, Result);
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
/* Jump from GREEN TO YELLOW through sensor change */
TEST(AirQuality_GREEN, TEST_AIR_QUALITY_GREEN_YELLOW_HIGH_VALUE) {
    reset_air_quality_state();
    /*first set temperature to 60 degree*/
    int length = 8;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[8] = {0, 0, 0, 2,     2, 1,2, 2};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    int sensor_values[5]={21,610,26,203,2};
    set_air_quality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    /* set yellow thresholds */
    /*set thresholds*/
    set_air_quality_threshold(0,0,20);
    set_air_quality_threshold(0,1,600);
    set_air_quality_threshold(0,2,25);
    set_air_quality_threshold(0,3,100);
    set_air_quality_threshold(0,4,2);
    /* set red thresholds*/
    set_air_quality_threshold(1,0,65);
    set_air_quality_threshold(1,1,5000);
    set_air_quality_threshold(1,2,200);
    set_air_quality_threshold(1,3,200);
    set_air_quality_threshold(1,4,2);
    int i;
    for (i = 0; i < 2; i++) {
        statemachine_air_quality(0, Result);
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
/* Jump from GREEN TO YELLOW thorugh theshold channge */
TEST(AirQuality_GREEN, TEST_AIR_QUALITY_GREEN_YELLOW_THRESHOLD) {
    reset_air_quality_state();
    /*first set temperature to 60 degree*/
    int length =16;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 0,     0, 0,0,0,  0,0,0,1,  1,1,1,1};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    int sensor_values[5]={21,610,26,103,3};
    set_air_quality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    set_air_quality_threshold(0,0,20);
    set_air_quality_threshold(0,1,600);
    set_air_quality_threshold(0,2,25);
    set_air_quality_threshold(0,3,100);
    set_air_quality_threshold(0,4,2);
    /* set red thresholds*/
    set_air_quality_threshold(1,0,65);
    set_air_quality_threshold(1,1,5000);
    set_air_quality_threshold(1,2,200);
    set_air_quality_threshold(1,3,200);
    set_air_quality_threshold(1,4,2);
    int i;
    for (i = 0; i < 2; i++) {
        statemachine_air_quality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /* 0.01 would be in the bound!*/
    set_air_quality_threshold(0,0,19);
    set_air_quality_threshold(0,1,570);
    set_air_quality_threshold(0,2,20);
    set_air_quality_threshold(0,3,90);
    set_air_quality_threshold(0,4,0);
    for (i ; i < 4; i++) {
        statemachine_air_quality(0, Result);
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


/*----------------------------- TEST THE YELLOW-----------------------------------------------*/
TEST_GROUP(AirQuality_YELLOW) {
    void setup() // setup
    {

    }

    void teardown() {

    }
};

/* Stay YELLOW Sensor value change to the lower bound (limit) */
TEST(AirQuality_YELLOW, TEST_AIR_QUALITY_YELLOW_SENSOR_CHANGE_CHECK_LOW) {
    reset_air_quality_state();
    /*first set temperature to 60 degree*/
    int length = 16;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 1,     1, 1,1, 1,   1,1,1,1, 1,1,1,1};
    int Result[4], Result_complete[length];
    /* set sensor values for test, stuck between thresholds*/
    int sensor_values[5]={24,622,29,107,5};
    set_air_quality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    set_air_quality_threshold(0,0,20);
    set_air_quality_threshold(0,1,600);
    set_air_quality_threshold(0,2,25);
    set_air_quality_threshold(0,3,100);
    set_air_quality_threshold(0,4,2);
    /* set red thresholds*/
    set_air_quality_threshold(1,0,65);
    set_air_quality_threshold(1,1,5000);
    set_air_quality_threshold(1,2,200);
    set_air_quality_threshold(1,3,200);
    set_air_quality_threshold(1,4,10);
    int i;
    for (i = 0; i < 2; i++) {
        statemachine_air_quality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /** Change the sensor value for all sensors */
    int j;
    for(j=0;j<5;j++) {
        sensor_values[j] =sensor_values[j]-1;
    }
    for (i ; i < 4; i++) {
        statemachine_air_quality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    for (i = 0; i < length; i++) {
        // printf("I compare [%d] the expected result %d with current result %d\n",i,ResultExpected[i],Result_complete[i]);
        CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
    }
}
/* Switch from YELLOW to GREEN , theshold limit bi 0.1 undercutted (limit) */
TEST(AirQuality_YELLOW, TEST_AIR_QUALITY_YELLOW_TO_GREEN_SENSOR_CHANGE_CHECK_LOW) {
    reset_air_quality_state();
    /*first set temperature to 60 degree*/
    int length = 12;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 1,     1, 1,1, 1,   1,1,1,0, 0,0,0,0};
    int Result[4], Result_complete[length];
    /* set sensor values for test, stuck between thresholds*/
    int sensor_values[5]={24,622,29,107,5};
    set_air_quality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    set_air_quality_threshold(0,0,20);
    set_air_quality_threshold(0,1,600);
    set_air_quality_threshold(0,2,25);
    set_air_quality_threshold(0,3,100);
    set_air_quality_threshold(0,4,2);
    /* set red thresholds*/
    set_air_quality_threshold(1,0,65);
    set_air_quality_threshold(1,1,5000);
    set_air_quality_threshold(1,2,200);
    set_air_quality_threshold(1,3,200);
    set_air_quality_threshold(1,4,10);
    int i;
    for (i = 0; i < 2; i++) {
        statemachine_air_quality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /** Change the sensor value, bound is in the tests 0.05 for all sensors */
    int j;
    for(j=0;j<5;j++) {
        sensor_values[j] =sensor_values[j]-43;
    }
    set_air_quality(0,sensor_values);
    for (i ; i < 4; i++) {
        statemachine_air_quality(0, Result);
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


/* Stay YELLOW Sensor value change to the upper bound (limit) */
TEST(AirQuality_YELLOW, TEST_AIR_QUALITY_THROUGH_SENSOR_CHANGE_WITH_YELLOW_THRESHOLD_CHECK_UP) {
    reset_air_quality_state();
    /*first set temperature to 60 degree*/
    int length = 16;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 1,     1, 1,1, 1,   1,1,1,1, 1,1,1,1};
    int Result[4], Result_complete[length];
    /* set sensor values for test, stuck between thresholds*/
    int sensor_values[5]={62,4879,197,197,7};
    set_air_quality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    set_air_quality_threshold(0,0,20);
    set_air_quality_threshold(0,1,600);
    set_air_quality_threshold(0,2,25);
    set_air_quality_threshold(0,3,100);
    set_air_quality_threshold(0,4,2);
    /* set red thresholds*/
    set_air_quality_threshold(1,0,65);
    set_air_quality_threshold(1,1,5000);
    set_air_quality_threshold(1,2,200);
    set_air_quality_threshold(1,3,200);
    set_air_quality_threshold(1,4,10);

    int i;
    for (i = 0; i < 2; i++) {
        statemachine_air_quality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /** Change the sensor value, bound is in the tests 0.05 for all sensors */
    int j;
    for(j=0;j<5;j++) {
        sensor_values[j] =sensor_values[j]+1;
    }
    for (i ; i < 4; i++) {
        statemachine_air_quality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    for (i = 0; i < length; i++) {
        // printf("I compare [%d] the expected result %d with current result %d\n",i,ResultExpected[i],Result_complete[i]);
        CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
    }
}

/* Switch from YELLOW to RED exceed slightly the bound */
TEST(AirQuality_YELLOW, TEST_AIR_QUALITY_YELLOW_TO_RED_THROUGH_SENSOR_CHANGE_WITH_THRESHOLD_CHECK_UP) {
    reset_air_quality_state();
    /*first set temperature to 60 degree*/
    int length = 16;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 1,     1, 1,1, 1,   1,1,1,2,   2,1,2,2};
    int Result[4], Result_complete[length];
    /* set sensor values for test, stuck between thresholds*/
    int sensor_values[5]={67,5020,202,202,12};
    set_air_quality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    set_air_quality_threshold(0,0,20);
    set_air_quality_threshold(0,1,600);
    set_air_quality_threshold(0,2,25);
    set_air_quality_threshold(0,3,100);
    set_air_quality_threshold(0,4,2);
    /* set red thresholds*/
    set_air_quality_threshold(1,0,65);
    set_air_quality_threshold(1,1,5000);
    set_air_quality_threshold(1,2,200);
    set_air_quality_threshold(1,3,200);
    set_air_quality_threshold(1,4,10);
    int i;
    for (i = 0; i < 2; i++) {
        statemachine_air_quality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /** Change the sensor value for all sensors */
    int j;
    for(j=0;j<5;j++) {
        sensor_values[j] = sensor_values[j]+1;
    }
    set_air_quality(0,sensor_values);
    for (i ; i < 4; i++) {
        statemachine_air_quality(0, Result);
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


/*----------------------------TEST THE RED STAGE ------------------------------------------------*/
TEST_GROUP(AirQuality_RED) {
    void setup() // setup
    {

    }

    void teardown() {

    }
};

/* Switch from GREEN to RED exceed slightly the bound, then change values and switch from RED to YELLOW slightly underneath the limit */
TEST(AirQuality_YELLOW, TEST_AIR_QUALITY_GREEN_TO_RED_TO_YELLOW_THROUGH_SENSOR_CHANGE_WITH_THRESHOLD_CHECK) {
    reset_air_quality_state();
    /*first set temperature to 60 degree*/
    int length = 16;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 2,     2, 1,2, 2,   2,1,2,1,   1,1,1,1};
    int Result[4], Result_complete[length];
    /* set sensor values for test, stuck between thresholds*/
    int sensor_values_change[5]={68,5021,203,203,13};
    set_air_quality(0,sensor_values_change);
    /*set thresholds*/
    set_air_quality_hysteresis(1,0,2);
    set_air_quality_hysteresis(1,1,20);
    set_air_quality_hysteresis(1,2,2);
    set_air_quality_hysteresis(1,3,2);
    set_air_quality_hysteresis(1,4,2);
    set_air_quality_hysteresis(0,0,2);
    set_air_quality_hysteresis(0,1,20);
    set_air_quality_hysteresis(0,2,2);
    set_air_quality_hysteresis(0,3,5);
    set_air_quality_hysteresis(0,4,1);

    /* set yellow thresholds */
    set_air_quality_threshold(0,0,20);
    set_air_quality_threshold(0,1,600);
    set_air_quality_threshold(0,2,25);
    set_air_quality_threshold(0,3,100);
    set_air_quality_threshold(0,4,5);
    /* set red thresholds*/
    set_air_quality_threshold(1,0,65);
    set_air_quality_threshold(1,1,5000);
    set_air_quality_threshold(1,2,200);
    set_air_quality_threshold(1,3,200);
    set_air_quality_threshold(1,4,10);
    int i;
    for (i = 0; i < 2; i++) {
        statemachine_air_quality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /** Change the sensor value, bound is in the tests 0.05 for all sensors */
    int sensor_values[5]={62,4979,197,197,5};
    set_air_quality(0,sensor_values);
    for (i ; i < 4; i++) {
        statemachine_air_quality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    for (i = 0; i < length; i++) {
        printf("I compare [%d] the expected result %d with current result %d\n",i,ResultExpected[i],Result_complete[i]);
        CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
    }
}

TEST(AirQuality_YELLOW, TEST_AIR_QUALITY_GREEN_TO_RED_TO_GREEN_THROUGH_SENSOR_CHANGE_WITH_THRESHOLD_CHECK) {
    reset_air_quality_state();
/*first set temperature to 60 degree*/
    int length = 16;
/* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 2,     2, 1,2, 2,   2,1,2,0,   0,0,0,0};
    int Result[4], Result_complete[length];
/* set sensor values for test, stuck between thresholds*/
    int sensor_values_change[5]={68,5021,203,203,13};
    set_air_quality(0,sensor_values_change);
/*set thresholds*/
/* set yellow thresholds */
    set_air_quality_threshold(0,0,20);
    set_air_quality_threshold(0,1,600);
    set_air_quality_threshold(0,2,25);
    set_air_quality_threshold(0,3,100);
    set_air_quality_threshold(0,4,5);
/* set red thresholds*/
    set_air_quality_threshold(1,0,65);
    set_air_quality_threshold(1,1,5000);
    set_air_quality_threshold(1,2,200);
    set_air_quality_threshold(1,3,200);
    set_air_quality_threshold(1,4,10);
    int i;
    for (i = 0; i < 2; i++) {
        statemachine_air_quality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
//printf("result[]= %d\n",Result_complete[i*3]);
    }
/** Change the sensor value, bound is in the tests 0.05 for all sensors */
    int sensor_values[5]={17,579,22,94,1};
    set_air_quality(0,sensor_values);
    for (i ; i < 4; i++) {
        statemachine_air_quality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
//printf("result[]= %d\n",Result_complete[i*3]);
    }
    for (i = 0; i < length; i++) {
        // printf("I compare [%d] the expected result %d with current result %d\n",i,ResultExpected[i],Result_complete[i]);
        CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
    }
}

/* TEST THE RED STAGE */
TEST_GROUP(CHECK_CHANGE_BOUND) {
    void setup() // setup
    {

    }

    void teardown() {

    }
};

TEST(CHECK_CHANGE_BOUND, CHANGE_FROM_GREEN_TO_RED_THROUGH_BOUND_CHANGE) {
    reset_air_quality_state();
    /*first set temperature to 60 degree*/
    int length = 16;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 1,     1,1,1,1,   1,1,1,2,   2,1,2,2};
    int Result[4], Result_complete[length];
    /* set sensor values for test, stuck between thresholds*/
    int sensor_values[5]={67,5020,202,202,12};
    set_air_quality(0,sensor_values);
    /*set thresholds*/
/* set yellow thresholds */
    set_air_quality_threshold(0,0,20);
    set_air_quality_threshold(0,1,600);
    set_air_quality_threshold(0,2,25);
    set_air_quality_threshold(0,3,100);
    set_air_quality_threshold(0,4,5);
/* set red thresholds*/
    set_air_quality_threshold(1,0,65);
    set_air_quality_threshold(1,1,5000);
    set_air_quality_threshold(1,2,200);
    set_air_quality_threshold(1,3,200);
    set_air_quality_threshold(1,4,10);
    int i=0;
    for (i = 0; i < 2; i++) {
        statemachine_air_quality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /** Change the sensor value, bound is in the tests 0.05 for all sensors */
    printf("2 rounds\n");

    printf("set hysteresis\n");
    set_air_quality_hysteresis(1,0,1);
    set_air_quality_hysteresis(1,1,19);
    set_air_quality_hysteresis(1,2,1);
    set_air_quality_hysteresis(1,3,1);
    set_air_quality_hysteresis(1,4,1);
    for (i ; i < 4; i++) {
        statemachine_air_quality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    set_air_quality_hysteresis(1,0,2);
    set_air_quality_hysteresis(1,1,20);
    set_air_quality_hysteresis(1,2,2);
    set_air_quality_hysteresis(1,3,2);
    set_air_quality_hysteresis(1,4,2);
    for (i = 0; i < length; i++) {
        // printf("I compare [%d] the expected result %d with current result %d\n",i,ResultExpected[i],Result_complete[i]);
        CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
    }
}







}