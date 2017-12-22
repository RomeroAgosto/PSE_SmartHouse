#include <CppUTest/TestHarness.h>
#include <CppUTest/TestHarness.h>
#include <stdio.h>
extern "C" {

#include "../Statemachine_AirTemperature/statemachine_airtemp_control.h"

TEST_GROUP(AirTemp)
{
    void setup() // setup
    {

    }

    void teardown()
    {

    }
};
/* Increase Temperature */
TEST(AirTemp,TEST_AIR_INCREASE_TEMPERATURE_SIMPLE) {
    reset_state(1);
    /*first set temperature to 60 degree*/
    int length=6;
    /* state before, setHeater state after*/
    int ResultExpected[6] = {0, 0, 1,   1,1,1};
    int Result[3], Result_complete[length];

    int i;
    setdesiredTemp(1,25);
    SetAirTemperature(1,23);
    for (i = 0; i < 2; i++) {
        Statemachine_AirControl(1, Result);
        Result_complete[i * 3 + 0] = Result[0];
        Result_complete[i * 3 + 1] = Result[1];
        Result_complete[i * 3 + 2] = Result[2];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    for (i = 0; i < length; i++) {
        //printf("I compare[%d] %d %d\n",i,ResultExpected[i],Result_complete[i]);
        CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
    }
}
/* stay on off, test limit*/
TEST(AirTemp,TEST_AIR_KEEP_TEMPERATURE_SIMPLE_MINIMALVALUE) {
    reset_state(1);
    /*first set temperature to 60 degree*/
    int length=6;
    /* state before, setHeater state after*/
    int ResultExpected[6] = {0, 0, 0,   0,0,0};
    int Result[3], Result_complete[length];

    int i;
    setdesiredTemp(1,24);
    SetAirTemperature(1,23);
    for (i = 0; i < 2; i++) {
        Statemachine_AirControl(1, Result);
        Result_complete[i * 3 + 0] = Result[0];
        Result_complete[i * 3 + 1] = Result[1];
        Result_complete[i * 3 + 2] = Result[2];
        //printf("result[]= %d\n",Result_complete[i*3]);
    }
    for (i = 0; i < length; i++) {
        //printf("I compare[%d] %d %d\n",i,ResultExpected[i],Result_complete[i]);
        CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
    }
}
/* Increase Temperature -> when in increasing state reduce desired value*/
TEST(AirTemp,TEST_AIR_INCREASE_TEMPERATURE_CHANGE_DESIRED_VALUE) {
	reset_state(1);
	/*first set temperature to 60 degree*/
    int length=12;
	/* state before, setHeater state after*/
	int ResultExpected[12] = {0, 0, 1,   1,1,1,  1,1,0,   0,0,0};
	int Result[3], Result_complete[length];

	int i;
    setdesiredTemp(1,25);
    SetAirTemperature(1,23);
	for (i = 0; i < 2; i++) {
        Statemachine_AirControl(1, Result);
		Result_complete[i * 3 + 0] = Result[0];
		Result_complete[i * 3 + 1] = Result[1];
		Result_complete[i * 3 + 2] = Result[2];
	}
    setdesiredTemp(1,20);
    for (i; i < 4; i++) {
        Statemachine_AirControl(1, Result);
        Result_complete[i * 3 + 0] = Result[0];
        Result_complete[i * 3 + 1] = Result[1];
        Result_complete[i * 3 + 2] = Result[2];
    }
	for (i = 0; i < length; i++) {
		//printf("I compare[%d] %d %d\n",i,ResultExpected[i],Result_complete[i]);
		CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
	}
}

/* Increase Temperature -> when in increasing state reduce desired value*/
TEST(AirTemp,TEST_AIR_INCREASE_TEMPERATURE_CHANGE_TEMPERATURE) {
    reset_state(1);
    /*first set temperature to 60 degree*/
    int length=12;
    /* state before, setHeater state after*/
    int ResultExpected[12] = {0, 0, 1,   1,1,1,  1,1,0,   0,0,0};
    int Result[3], Result_complete[length];

    int i;
    setdesiredTemp(1,25);
    SetAirTemperature(1,23);
    for (i = 0; i < 2; i++) {
        Statemachine_AirControl(1, Result);
        Result_complete[i * 3 + 0] = Result[0];
        Result_complete[i * 3 + 1] = Result[1];
        Result_complete[i * 3 + 2] = Result[2];
    }
    SetAirTemperature(1,27);
    for (i; i < 4; i++) {
        Statemachine_AirControl(1, Result);
        Result_complete[i * 3 + 0] = Result[0];
        Result_complete[i * 3 + 1] = Result[1];
        Result_complete[i * 3 + 2] = Result[2];
    }
    for (i = 0; i < length; i++) {
        //printf("I compare[%d] %d %d\n",i,ResultExpected[i],Result_complete[i]);
        CHECK_EQUAL(ResultExpected[i], Result_complete[i]);
    }
}

/* Increase Temperature -> when in increasing state reduce desired value*/
TEST(AirTemp,TEST_AIR_INCREASE_TEMPERATURE_CHANGE_TEMPERATURE_CHECK_ALL_ROOMS) {
    int j;
    for (j = 0; j <8 ; j++) {
        reset_state(j);
    }

    int room=0;

    /*first set temperature to 60 degree*/
    int length=12;
    /* state before, setHeater state after*/
    int ResultExpected[8][12];
    for (j = 0; j<8;j++) {
        ResultExpected[j][0]=0;
        ResultExpected[j][1]=0;
        ResultExpected[j][2]=1;

        ResultExpected[j][3]=1;
        ResultExpected[j][4]=1;
        ResultExpected[j][5]=1;

        ResultExpected[j][6]=1;
        ResultExpected[j][7]=1;
        ResultExpected[j][8]=0;

        ResultExpected[j][9]=0;
        ResultExpected[j][10]=0;
        ResultExpected[j][11]=0;
    }
    int Result[3], Result_complete[8][length],i;
    for(j=0;j<8;j++) {

        setdesiredTemp(j, 25);
        SetAirTemperature(j, 23);
        for (i = 0; i < 2; i++) {
            Statemachine_AirControl(j, Result);
            Result_complete[j][i * 3 + 0] = Result[0];
            Result_complete[j][i * 3 + 1] = Result[1];
            Result_complete[j][i * 3 + 2] = Result[2];
        }
        SetAirTemperature(j, 27);
        for (i; i < 4; i++) {
            Statemachine_AirControl(j, Result);
            Result_complete[j][i * 3 + 0] = Result[0];
            Result_complete[j][i * 3 + 1] = Result[1];
            Result_complete[j][i * 3 + 2] = Result[2];
        }
        for (i = 0; i < length; i++) {
            //printf("I compare[%d] %d %d\n",i,ResultExpected[i],Result_complete[i]);
            CHECK_EQUAL(ResultExpected[room][i], Result_complete[room][i]);
        }
    }

}

/* Increase Temperature -> when in increasing state reduce desired value*/
TEST(AirTemp,TEST_AIR_INCREASE_TEMPERATURE_CHANGE_DESIRED_VALUE_CHECK_ALL_ROOMS) {
    int j;
    for (j = 0; j <8 ; j++) {
        reset_state(j);
    }

    int room=0;

    /*first set temperature to 60 degree*/
    int length=12;
    /* state before, setHeater state after*/
    int ResultExpected[8][12];
    for (j = 0; j<8;j++) {
        ResultExpected[j][0]=0;
        ResultExpected[j][1]=0;
        ResultExpected[j][2]=1;

        ResultExpected[j][3]=1;
        ResultExpected[j][4]=1;
        ResultExpected[j][5]=1;

        ResultExpected[j][6]=1;
        ResultExpected[j][7]=1;
        ResultExpected[j][8]=0;

        ResultExpected[j][9]=0;
        ResultExpected[j][10]=0;
        ResultExpected[j][11]=0;
    }
    int Result[3], Result_complete[8][length],i;
    for(j=0;j<8;j++) {

        setdesiredTemp(j, 25);
        SetAirTemperature(j, 23);
        for (i = 0; i < 2; i++) {
            Statemachine_AirControl(j, Result);
            Result_complete[j][i * 3 + 0] = Result[0];
            Result_complete[j][i * 3 + 1] = Result[1];
            Result_complete[j][i * 3 + 2] = Result[2];
        }
        setdesiredTemp(j, 20);
        for (i; i < 4; i++) {
            Statemachine_AirControl(j, Result);
            Result_complete[j][i * 3 + 0] = Result[0];
            Result_complete[j][i * 3 + 1] = Result[1];
            Result_complete[j][i * 3 + 2] = Result[2];
        }
        for (i = 0; i < length; i++) {
            //printf("I compare[%d] %d %d\n",i,ResultExpected[i],Result_complete[i]);
            CHECK_EQUAL(ResultExpected[room][i], Result_complete[room][i]);
        }
    }

}
}
