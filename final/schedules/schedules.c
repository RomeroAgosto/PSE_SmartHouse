#include "schedules.h"
#include <stdio.h>

static house home;

int setId(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int id) {
    home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].id=id;
}

int setValue(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int value) {
    home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].value=value;
}

int setEnable(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int enable) {
    home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].enable=enable;
}

int setStartTime(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int time) {
    home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].start_time=time;
}

int setStopTime(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int time) {
    home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].stop_time=time;
}

int getId(int arrayFunction, int arrayRoom, int arraySchedule, int schedule) {
    return home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].id;
}

int getValue(int arrayFunction, int arrayRoom, int arraySchedule, int schedule) {
    return home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].value;
}

int getEnable(int arrayFunction, int arrayRoom, int arraySchedule, int schedule) {
    return home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].enable;
}

int getStartTime(int arrayFunction, int arrayRoom, int arraySchedule, int schedule) {
    return home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].start_time;
}

int getStopTime(int arrayFunction, int arrayRoom, int arraySchedule, int schedule) {
    return home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].stop_time;
}

//static house home; /*home definition is supposed to be here!*/