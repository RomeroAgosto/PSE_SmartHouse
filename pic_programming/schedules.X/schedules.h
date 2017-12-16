#ifndef COMMUNICATION_SCHEDULES_H
#define COMMUNICATION_SCHEDULES_H

#define disable -100

typedef union{
    struct{
        int id;
        int value;
        int start_time;
        int stop_time;
        int enable;
    };
    int options[4];

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
house home; /*in the end, this definition should be in get_schedules.c*/

#endif //COMMUNICATION_SCHEDULES_H
