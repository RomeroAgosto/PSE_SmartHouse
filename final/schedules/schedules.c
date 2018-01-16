#include "schedules.h"
#include <stdio.h>

static house home;

int set_id(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int id) {
    home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].id=id;
}

int set_value(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int value) {
    home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].value=value;
}

int set_enable(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int enable) {
    home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].enable=enable;
}

int set_start_time(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int time) {
    home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].start_time=time;
}

int set_stop_time(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int time) {
    home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].stop_time=time;
}

int get_id(int arrayFunction, int arrayRoom, int arraySchedule, int schedule) {
    return home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].id;
}

int get_value(int arrayFunction, int arrayRoom, int arraySchedule, int schedule) {
    return home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].value;
}

int get_enable(int arrayFunction, int arrayRoom, int arraySchedule, int schedule) {
    return home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].enable;
}

int get_start_time(int arrayFunction, int arrayRoom, int arraySchedule, int schedule) {
    return home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].start_time;
}

int get_stop_time(int arrayFunction, int arrayRoom, int arraySchedule, int schedule) {
    return home.array_function[arrayFunction].array_room[arrayRoom].array_schedule[arraySchedule].schedules[schedule].stop_time;
}

//static house home; /*home definition is supposed to be here!*/
