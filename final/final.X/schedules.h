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
    day array_wday[7];

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
    function array_type[3];

}house;

house home; /*in the end, this definition should be in get_schedules.c*/

int get_schedule_message(char *to_send);

#endif	/* SCHEDULES_H */

