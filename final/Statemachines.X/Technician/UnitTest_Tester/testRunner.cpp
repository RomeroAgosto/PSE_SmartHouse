#include <CppUTest/TestHarness.h>
#include <stdio.h>
extern "C" {
#include "../Statemachine_Water/statemachine_watertemp_control.h"

TEST_GROUP(WaterControl)
{
	void setup() // setup 
	{

	}

	void teardown()
	{

	}
};

// Increases the temperature and checks if the Heater is turned on
TEST(WaterControl,SWITCH_TO_INCREASE_WATER_TEMPERATURE){
	reset_state_water_temp();
	int desired_temp = 70;
	int water_temp=60;
	int ResultExpected[6]={0,0,1,1,1,1};


	int Result[3], Result_complete[6];
	set_desired_temperature(desired_temp);
	set_water_temp(water_temp);
	int i;
	for (i = 0; i <2 ; i++) {
		Statemachine_WaterControl(Result);
		Result_complete[i*3+0]=Result[0];
		Result_complete[i*3+1]=Result[1];
		Result_complete[i*3+2]=Result[2];
	}
	for (i = 0; i < 6;i++) {
		//printf("I compare %d %d\n",ResultExpected[i],Result_complete[i]);
		CHECK_EQUAL(ResultExpected[i],Result_complete[i]);
	}

}
// Increases the temperature with temperature change
TEST(WaterControl,INCREASE_WATER_TEMPERATURE_TEMPERATUE_CHANGE){
	reset_state_water_temp();
	/*first set temperature to 60 degree*/
	int desired_temp = 70;
	int water_temp=60;
	/* state before, setHeater state after*/
	int ResultExpected[12]={0,0,1,   1,1,1,  1,1,0,   0,0,0};
	int Result[3], Result_complete[12];
	set_desired_temperature(desired_temp);
	set_water_temp(water_temp);
	int i;
	for (i = 0; i <2 ; i++) {
		Statemachine_WaterControl(Result);
		Result_complete[i*3+0]=Result[0];
		Result_complete[i*3+1]=Result[1];
		Result_complete[i*3+2]=Result[2];
	}
	/*after the set, change temperature*/
	set_water_temp(77);
	for (i ; i <4 ; i++) {
		Statemachine_WaterControl(Result);
		Result_complete[i*3+0]=Result[0];
		Result_complete[i*3+1]=Result[1];
		Result_complete[i*3+2]=Result[2];
	}

	set_water_temp(water_temp);
	for (i = 0; i < 12;i++) {
		//printf("I compare[%d] %d %d\n",i,ResultExpected[i],Result_complete[i]);
		CHECK_EQUAL(ResultExpected[i],Result_complete[i]);
	}
}
// Increases the temperature with desired value change
TEST(WaterControl,INCREASE_WATER_TEMPERATURE_CHANGE_DESIRED_VALUE){
	reset_state_water_temp();
	/*first set temperature to 60 degree*/
	reset_state_water_temp();
	int desired_temp = 70;
	int water_temp=60;
	/* state before, setHeater state after*/
	int ResultExpected[12]={0,0,1,   1,1,1,  1,1,0,   0,0,0};
	int Result[3], Result_complete[12];
	set_desired_temperature(desired_temp);
	set_water_temp(water_temp);
	int i;
	/* go into increse and set the heater*/
	for (i = 0; i <2 ; i++) {
		Statemachine_WaterControl(Result);
		Result_complete[i*3+0]=Result[0];
		Result_complete[i*3+1]=Result[1];
		Result_complete[i*3+2]=Result[2];
	}
	/*after the set, change desired value*/
	set_desired_temperature(50);
	for (i ; i <4 ; i++) {
		Statemachine_WaterControl(Result);
		Result_complete[i*3+0]=Result[0];
		Result_complete[i*3+1]=Result[1];
		Result_complete[i*3+2]=Result[2];
	}

	set_water_temp(water_temp);
	for (i = 0; i < 12;i++) {
		//printf("I compare[%d] %d %d\n",i,ResultExpected[i],Result_complete[i]);
		CHECK_EQUAL(ResultExpected[i],Result_complete[i]);
	}
}
// stay in state desired temperature
TEST(WaterControl,TEST_WaterControl_STAY_DECREASE_TEMPERATURE){
	int reset_state_water_temp();
	int desired_temp = 50;
	int water_temp=60;
	int ResultExpected[3]={0,0,0};


	int Result[3];
	set_desired_temperature(desired_temp);
	set_water_temp(water_temp);
	int i;
	for (i = 0; i <2 ; i++) {
		Statemachine_WaterControl(Result);
	}
	for (i = 0; i < 3;i++) {
		//printf("I compare %d %d\n",ResultExpected[i],Result[i]);
		CHECK_EQUAL(ResultExpected[i],Result[i]);
	}

}

TEST(WaterControl,TEST_WaterControl_TURN_ON_THROUGH_THRESHOLD_CHANGE) {
	int reset_state_water_temp();
	int desired_temp = 50;
	int water_temp = 46;
	int length = 9;
	int ResultExpected[] = {0,0,0, 0,0,1, 1,1,1};
	int Result[3], ResultComplete[length];
	set_desired_temperature(desired_temp);
	set_water_temp(water_temp);
	int i;
	set_water_threshold(10);
	Statemachine_WaterControl(Result);

	for (i = 0; i < 3; i++) {
		ResultComplete[i] = Result[i];
	}
	set_water_threshold(2);
	Statemachine_WaterControl(Result);
	for (i = 3; i < 6; i++) {
		ResultComplete[i] = Result[i-3];
	}
	Statemachine_WaterControl(Result);
	for (i = 6; i < 9; i++) {
		ResultComplete[i] = Result[i-6];
	}
	for (i = 0; i < length; i++) {
		//printf("I compare %d %d\n", ResultExpected[i], ResultComplete[i]);
		CHECK_EQUAL(ResultExpected[i], ResultComplete[i]);
	}
}

TEST(WaterControl,TEST_WaterControl_TURN_OFF_THROUGH_THRESHOLD_CHANGE) {
	int reset_state_water_temp();
	int desired_temp = 50;
	int water_temp = 30;
	int length = 12;
	int ResultExpected[] = {0,0,1, 1,1,1, 1,1,1 ,1,1,0 ,0,0,0};
	int Result[3], ResultComplete[length];
	set_desired_temperature(desired_temp);
	set_water_temp(water_temp);
	int i;
	Statemachine_WaterControl(Result);

	for (i = 0; i < 3; i++) {
		ResultComplete[i] = Result[i];
	}
	Statemachine_WaterControl(Result);
	for (i = 3; i < 6; i++) {
		ResultComplete[i] = Result[i-3];
	}
	water_temp = 55;
	set_water_temp(water_temp);
	Statemachine_WaterControl(Result);
	for (i = 6; i < 9; i++) {
		ResultComplete[i] = Result[i-6];
	}
	set_water_threshold(2);
	Statemachine_WaterControl(Result);
	for (i = 9; i < 12; i++) {
		ResultComplete[i] = Result[i-9];
	}
	Statemachine_WaterControl(Result);
	for (i = 12; i < 15; i++) {
		ResultComplete[i] = Result[i-12];
	}
	for (i = 0; i < length; i++) {
		//printf("I compare %d %d\n", ResultExpected[i], ResultComplete[i]);
		CHECK_EQUAL(ResultExpected[i], ResultComplete[i]);
	}
}
}

