/* 
 * File:   schedules.h
 * Author: sascha
 *
 * Created on December 17, 2017, 1:55 AM
 */

#ifndef SCHEDULES_H
#define	SCHEDULES_H

typedef union{
    struct{
        int id;
        int value;
        int enable;
        int start_time;
        int stop_time;
    };
    int options[5];

}schedule;

typedef union{
    struct {
        schedule schedule1;
        schedule schedule2;
        schedule schedule3;
        schedule schedule4;
    };
    schedule schedules[4];

}day;

typedef union{
    struct {
        day monday;
        day tuesday;
        day wednesday;
        day thursday;
        day friday;
        day saturday;
        day sunday;
    };
    day array_schedule[7];

}room;

typedef union{
    struct {
        room room1;
        room room2;
        room room3;
        room room4;
        room room5;
        room room6;
        room room7;
        room room8;
    };
    room array_room[8];

}function;

typedef union {
    struct {
        function water_temperature;
        function air_temperature;
        function light;

    };
    function array_function[3];

}house;

int get_schedule_message(char *to_send);

int set_id(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int id);

int set_value(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int value);

int set_enable(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int enable);

int set_start_time(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int time);

int set_stop_time(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int time);

int get_id(int arrayFunction, int arrayRoom, int arraySchedule, int schedule);

int get_value(int arrayFunction, int arrayRoom, int arraySchedule, int schedule);

int get_enable(int arrayFunction, int arrayRoom, int arraySchedule, int schedule);

int get_start_time(int arrayFunction, int arrayRoom, int arraySchedule, int schedule);

int get_stop_time(int arrayFunction, int arrayRoom, int arraySchedule, int schedule);

#endif	/* SCHEDULES_H */

