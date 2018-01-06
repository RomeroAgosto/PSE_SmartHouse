#include <CppUTest/TestHarness.h>
#include <CppUTest/TestHarness.h>
#include <stdio.h>
extern "C" {

#include "../Statemachine_AirQuality/statemachine_airquality_control.h"

void Statemachine_AirQuality(int room,int *test);
void SetAirQuality(int room, double *input_values);
void GetAirQuality(int room, double *sensor_values);
void SetLightQuality(int room, int color);
void SetVentilationState(int room, int on);
void ResetAirQualityState();

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
    ResetAirQualityState();
    /*first set temperature to 60 degree*/
    int length =16;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 0,     0, 0,0,0,  0,0,0,0,  0,0,0,0};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    double sensor_values[5]={0.1,.1,.1,.1,.1};
    SetAirQuality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    SetAirThreshold(0,0,0,0.2);
    SetAirThreshold(0,0,1,0.2);
    SetAirThreshold(0,0,2,0.2);
    SetAirThreshold(0,0,3,0.2);
    SetAirThreshold(0,0,4,0.2);
    /* set red thresholds*/
    SetAirThreshold(0,1,0,0.6);
    SetAirThreshold(0,1,1,0.7);
    SetAirThreshold(0,1,2,0.8);
    SetAirThreshold(0,1,3,0.9);
    SetAirThreshold(0,1,4,0.2);
    int i;
    for (i = 0; i < 2; i++) {
        Statemachine_AirQuality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /* 0.01 would be in the bound!*/
    SetAirThreshold(0,0,0,0.05);
    SetAirThreshold(0,0,1,0.05);
    SetAirThreshold(0,0,2,0.05);
    SetAirThreshold(0,0,3,0.05);
    SetAirThreshold(0,0,4,0.05);
    for (i ; i < 4; i++) {
        Statemachine_AirQuality(0, Result);
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
    ResetAirQualityState();
    /*first set temperature to 60 degree*/
    int length = 8;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[8] = {0, 0, 0, 2,     2, 1,2, 2};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    double sensor_values[5]={0.5,.6,.8,1,.1};
    SetAirQuality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    SetAirThreshold(0,0,0,0.2);
    SetAirThreshold(0,0,1,0.2);
    SetAirThreshold(0,0,2,0.2);
    SetAirThreshold(0,0,3,0.2);
    SetAirThreshold(0,0,4,0.2);
    /* set red thresholds*/
    SetAirThreshold(0,1,0,0.6);
    SetAirThreshold(0,1,1,0.7);
    SetAirThreshold(0,1,2,0.8);
    SetAirThreshold(0,1,3,0.9);
    SetAirThreshold(0,1,4,0.2);
    int i;
    for (i = 0; i < 2; i++) {
        Statemachine_AirQuality(0, Result);
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
    ResetAirQualityState();
    /*first set temperature to 60 degree*/
    int length =16;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 0,     0, 0,0,0,  0,0,0,2,  2,1,2,2};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    double sensor_values[5]={0.1,.1,.1,.1,.1};
    SetAirQuality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    SetAirThreshold(0,0,0,0.2);
    SetAirThreshold(0,0,1,0.2);
    SetAirThreshold(0,0,2,0.2);
    SetAirThreshold(0,0,3,0.2);
    SetAirThreshold(0,0,4,0.2);
    /* set red thresholds*/
    SetAirThreshold(0,1,0,0.6);
    SetAirThreshold(0,1,1,0.7);
    SetAirThreshold(0,1,2,0.8);
    SetAirThreshold(0,1,3,0.9);
    SetAirThreshold(0,1,4,0.2);
    int i;
    for (i = 0; i < 2; i++) {
        Statemachine_AirQuality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /* 0.01 would be in the bound!*/
    /* set red thresholds*/
    SetAirThreshold(0,1,0,0.049);
    SetAirThreshold(0,1,1,0.049);
    SetAirThreshold(0,1,2,0.049);
    SetAirThreshold(0,1,3,0.049);
    SetAirThreshold(0,1,4,0.049);
    for (i ; i < 4; i++) {
        Statemachine_AirQuality(0, Result);
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
    ResetAirQualityState();
    /*first set temperature to 60 degree*/
    int length = 8;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[8] = {0, 0, 0, 2,     2, 1,2, 2};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    double sensor_values[5]={0.5,.6,.8,1,.1};
    SetAirQuality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    SetAirThreshold(0,0,0,0.2);
    SetAirThreshold(0,0,1,0.2);
    SetAirThreshold(0,0,2,0.2);
    SetAirThreshold(0,0,3,0.2);
    SetAirThreshold(0,0,4,0.2);
    /* set red thresholds*/
    SetAirThreshold(0,1,0,0.6);
    SetAirThreshold(0,1,1,0.7);
    SetAirThreshold(0,1,2,0.8);
    SetAirThreshold(0,1,3,0.9);
    SetAirThreshold(0,1,4,0.2);
    int i;
    for (i = 0; i < 2; i++) {
        Statemachine_AirQuality(0, Result);
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
    ResetAirQualityState();
    /*first set temperature to 60 degree*/
    int length =16;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 0,     0, 0,0,0,  0,0,0,1,  1,1,1,1};
    int Result[4], Result_complete[length];
    /* set sensor values for test*/
    double sensor_values[5]={0.1,.1,.1,.1,.1};
    SetAirQuality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    SetAirThreshold(0,0,0,0.2);
    SetAirThreshold(0,0,1,0.2);
    SetAirThreshold(0,0,2,0.2);
    SetAirThreshold(0,0,3,0.2);
    SetAirThreshold(0,0,4,0.2);
    /* set red thresholds*/
    SetAirThreshold(0,1,0,0.6);
    SetAirThreshold(0,1,1,0.7);
    SetAirThreshold(0,1,2,0.8);
    SetAirThreshold(0,1,3,0.9);
    SetAirThreshold(0,1,4,0.2);
    int i;
    for (i = 0; i < 2; i++) {
        Statemachine_AirQuality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /* 0.01 would be in the bound!*/
    SetAirThreshold(0,0,0,0.049);
    SetAirThreshold(0,0,1,0.049);
    SetAirThreshold(0,0,2,0.049);
    SetAirThreshold(0,0,3,0.049);
    SetAirThreshold(0,0,4,0.049);
    for (i ; i < 4; i++) {
        Statemachine_AirQuality(0, Result);
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
    ResetAirQualityState();
    /*first set temperature to 60 degree*/
    int length = 16;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 1,     1, 1,1, 1,   1,1,1,1, 1,1,1,1};
    int Result[4], Result_complete[length];
    /* set sensor values for test, stuck between thresholds*/
    double sensor_values[5]={0.4,.4,.4,.4,.4};
    SetAirQuality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    SetAirThreshold(0,0,0,0.2);
    SetAirThreshold(0,0,1,0.2);
    SetAirThreshold(0,0,2,0.2);
    SetAirThreshold(0,0,3,0.2);
    SetAirThreshold(0,0,4,0.2);
    /* set red thresholds*/
    SetAirThreshold(0,1,0,0.6);
    SetAirThreshold(0,1,1,0.7);
    SetAirThreshold(0,1,2,0.8);
    SetAirThreshold(0,1,3,0.9);
    SetAirThreshold(0,1,4,0.5);
    int i;
    for (i = 0; i < 2; i++) {
        Statemachine_AirQuality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /** Change the sensor value, bound is in the tests 0.05 for all sensors */
    int j;
    for(j=0;j<5;j++) {
        sensor_values[j] =0.15;
    }
    for (i ; i < 4; i++) {
        Statemachine_AirQuality(0, Result);
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
    ResetAirQualityState();
    /*first set temperature to 60 degree*/
    int length = 16;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 1,     1, 1,1, 1,   1,1,1,1, 1,1,1,1};
    int Result[4], Result_complete[length];
    /* set sensor values for test, stuck between thresholds*/
    double sensor_values[5]={0.4,.4,.4,.4,.4};
    SetAirQuality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    SetAirThreshold(0,0,0,0.2);
    SetAirThreshold(0,0,1,0.2);
    SetAirThreshold(0,0,2,0.2);
    SetAirThreshold(0,0,3,0.2);
    SetAirThreshold(0,0,4,0.2);
    /* set red thresholds*/
    SetAirThreshold(0,1,0,0.6);
    SetAirThreshold(0,1,1,0.7);
    SetAirThreshold(0,1,2,0.8);
    SetAirThreshold(0,1,3,0.9);
    SetAirThreshold(0,1,4,0.5);
    int i;
    for (i = 0; i < 2; i++) {
        Statemachine_AirQuality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /** Change the sensor value, bound is in the tests 0.05 for all sensors */
    int j;
    for(j=0;j<5;j++) {
        sensor_values[j] =0.149;
    }
    for (i ; i < 4; i++) {
        Statemachine_AirQuality(0, Result);
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
/* Stay YELLOW Sensor value change to the upper bound (limit) */
TEST(AirQuality_YELLOW, TEST_AIR_QUALITY_THROUGH_SENSOR_CHANGE_WITH_YELLOW_THRESHOLD_CHECK_UP) {
    ResetAirQualityState();
    /*first set temperature to 60 degree*/
    int length = 16;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 1,     1, 1,1, 1,   1,1,1,1, 1,1,1,1};
    int Result[4], Result_complete[length];
    /* set sensor values for test, stuck between thresholds*/
    double sensor_values[5]={0.4,.4,.4,.4,.4};
    SetAirQuality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    SetAirThreshold(0,0,0,0.2);
    SetAirThreshold(0,0,1,0.2);
    SetAirThreshold(0,0,2,0.2);
    SetAirThreshold(0,0,3,0.2);
    SetAirThreshold(0,0,4,0.2);
    /* set red thresholds*/
    SetAirThreshold(0,1,0,0.6);
    SetAirThreshold(0,1,1,0.6);
    SetAirThreshold(0,1,2,0.6);
    SetAirThreshold(0,1,3,0.6);
    SetAirThreshold(0,1,4,0.6);
    int i;
    for (i = 0; i < 2; i++) {
        Statemachine_AirQuality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /** Change the sensor value, bound is in the tests 0.05 for all sensors */
    int j;
    for(j=0;j<5;j++) {
        sensor_values[j] =0.55;
    }
    for (i ; i < 4; i++) {
        Statemachine_AirQuality(0, Result);
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
    ResetAirQualityState();
    /*first set temperature to 60 degree*/
    int length = 16;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 1,     1, 1,1, 1,   1,1,1,2,   2,1,2,2};
    int Result[4], Result_complete[length];
    /* set sensor values for test, stuck between thresholds*/
    double sensor_values[5]={0.4,.4,.4,.4,.4};
    SetAirQuality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    SetAirThreshold(0,0,0,0.2);
    SetAirThreshold(0,0,1,0.2);
    SetAirThreshold(0,0,2,0.2);
    SetAirThreshold(0,0,3,0.2);
    SetAirThreshold(0,0,4,0.2);
    /* set red thresholds*/
    SetAirThreshold(0,1,0,0.6);
    SetAirThreshold(0,1,1,0.6);
    SetAirThreshold(0,1,2,0.6);
    SetAirThreshold(0,1,3,0.6);
    SetAirThreshold(0,1,4,0.6);
    int i;
    for (i = 0; i < 2; i++) {
        Statemachine_AirQuality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /** Change the sensor value, bound is in the tests 0.05 for all sensors */
    int j;
    for(j=0;j<5;j++) {
        sensor_values[j] =0.66;
    }
    SetAirQuality(0,sensor_values);
    for (i ; i < 4; i++) {
        Statemachine_AirQuality(0, Result);
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

/* Switch from GREEN to RED exceed slightly the bound, then change values and switch from RED back to GREEN slightly underneath the limit */
TEST(AirQuality_YELLOW, TEST_AIR_QUALITY_GREEN_TO_RED_TO_YELLOW_THROUGH_SENSOR_CHANGE_WITH_THRESHOLD_CHECK) {
    ResetAirQualityState();
    /*first set temperature to 60 degree*/
    int length = 16;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 2,     2, 1,2, 2,   2,1,2,1,   1,1,1,1};
    int Result[4], Result_complete[length];
    /* set sensor values for test, stuck between thresholds*/
    double sensor_values[5]={0.651,.651,.651,.651,.651};
    SetAirQuality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    SetAirThreshold(0,0,0,0.2);
    SetAirThreshold(0,0,1,0.2);
    SetAirThreshold(0,0,2,0.2);
    SetAirThreshold(0,0,3,0.2);
    SetAirThreshold(0,0,4,0.2);
    /* set red thresholds*/
    SetAirThreshold(0,1,0,0.6);
    SetAirThreshold(0,1,1,0.6);
    SetAirThreshold(0,1,2,0.6);
    SetAirThreshold(0,1,3,0.6);
    SetAirThreshold(0,1,4,0.6);
    int i;
    for (i = 0; i < 2; i++) {
        Statemachine_AirQuality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /** Change the sensor value, bound is in the tests 0.05 for all sensors */
    int j;
    for(j=0;j<5;j++) {
        sensor_values[j] =0.549;
    }
    SetAirQuality(0,sensor_values);
    for (i ; i < 4; i++) {
        Statemachine_AirQuality(0, Result);
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
TEST(AirQuality_YELLOW, TEST_AIR_QUALITY_GREEN_TO_RED_TO_GREEN_THROUGH_SENSOR_CHANGE_WITH_THRESHOLD_CHECK) {
    ResetAirQualityState();
    /*first set temperature to 60 degree*/
    int length = 16;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 2,     2, 1,2, 2,   2,1,2,0,   0,0,0,0};
    int Result[4], Result_complete[length];
    /* set sensor values for test, stuck between thresholds*/
    double sensor_values[5]={0.651,.651,.651,.651,.651};
    SetAirQuality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    SetAirThreshold(0,0,0,0.2);
    SetAirThreshold(0,0,1,0.2);
    SetAirThreshold(0,0,2,0.2);
    SetAirThreshold(0,0,3,0.2);
    SetAirThreshold(0,0,4,0.2);
    /* set red thresholds*/
    SetAirThreshold(0,1,0,0.6);
    SetAirThreshold(0,1,1,0.6);
    SetAirThreshold(0,1,2,0.6);
    SetAirThreshold(0,1,3,0.6);
    SetAirThreshold(0,1,4,0.6);
    int i;
    for (i = 0; i < 2; i++) {
        Statemachine_AirQuality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /** Change the sensor value, bound is in the tests 0.05 for all sensors */
    int j;
    for(j=0;j<5;j++) {
        sensor_values[j] =0.149;
    }
    SetAirQuality(0,sensor_values);
    for (i ; i < 4; i++) {
        Statemachine_AirQuality(0, Result);
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


/* TEST THE RED STAGE */
TEST_GROUP(CHECK_CHANGE_BOUND) {
    void setup() // setup
    {

    }

    void teardown() {

    }
};

TEST(CHECK_CHANGE_BOUND, CHANGE_FROM_GREEN_TO_RED_THROUGH_BOUND_CHANGE) {
    ResetAirQualityState();
    /*first set temperature to 60 degree*/
    int length = 16;
    /* state before, setVentilation setLight state after*/
    int ResultExpected[16] = {0, 0, 0, 1,     1,1,1,1,   1,1,1,2,   2,1,2,2};
    int Result[4], Result_complete[length];
    /* set sensor values for test, stuck between thresholds*/
    double sensor_values[5]={0.62,.62,.62,.62,.62};
    SetAirQuality(0,sensor_values);
    /*set thresholds*/
    /* set yellow thresholds */
    SetAirThreshold(0,0,0,0.2);
    SetAirThreshold(0,0,1,0.2);
    SetAirThreshold(0,0,2,0.2);
    SetAirThreshold(0,0,3,0.2);
    SetAirThreshold(0,0,4,0.2);
    /* set red thresholds*/
    SetAirThreshold(0,1,0,0.6);
    SetAirThreshold(0,1,1,0.6);
    SetAirThreshold(0,1,2,0.6);
    SetAirThreshold(0,1,3,0.6);
    SetAirThreshold(0,1,4,0.6);
    int i=0;
    for (i = 0; i < 2; i++) {
        Statemachine_AirQuality(0, Result);
        Result_complete[i * 4 + 0] = Result[0];
        Result_complete[i * 4 + 1] = Result[1];
        Result_complete[i * 4 + 2] = Result[2];
        Result_complete[i * 4 + 3] = Result[3];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    /** Change the sensor value, bound is in the tests 0.05 for all sensors */
    printf("2 rounds\n");
    int j;
    for(j=0;j<5;j++){
        printf("set hysteresis\n");
        SetHysteresis(1,j,0.01);
    }
    for (i ; i < 4; i++) {
        Statemachine_AirQuality(0, Result);
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

}