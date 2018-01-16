/**
 * @file schedules.h
 * @author Deep Impact
 * @date 15 Dez 2017
 * @brief This file creates a structure to save all the schedules and all the information about each one, such as the id of the associated room, the desired value of temperature when applicable, if it's \
 * enabled or not, the start and stop time.
 * 
 * 
 * Company  Deep Impact
 * 
 * ==============================================
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

/**
 * @brief get_schedule_message, this function will interprete the message from the pc and write the schedule into the structure
 * 
 * @param *to_send-> message from the pc
 * @return 0
 * ==============================================
 */    
int get_schedule_message(char *to_send);

/**
 * @brief set_id,this funtion sets the id variable in the structure
 * 
 * @param arrayFunction -> identifier for which function the schedule is being set for
 * @param arrayRoom -> identifier for which room the schedule is being set for
 * @param arraySchedule -> identifier for which day the schedule is being set for
 * @param schedule -> identifier for which schedule number the schedule is being set for
 * @param id -> identifier for id value the schedule is being set for
 * @return 0
 * ==============================================
 */    

int set_id(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int id);

/**
 * @brief set_value,this funtion sets the value variable in the structure
 * 
 * @param arrayFunction -> identifier for which function the schedule is being set for
 * @param arrayRoom -> identifier for which room the schedule is being set for
 * @param arraySchedule -> identifier for which day the schedule is being set for
 * @param schedule -> identifier for which schedule number the schedule is being set for
 * @param value -> identifier for value value the schedule is being set for
 * @return 0
 * ==============================================
 */ 

int set_value(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int value);

/**
 * @brief set_enable,this funtion sets the id variable in the structure
 * 
 * @param arrayFunction -> identifier for which function the schedule is being set for
 * @param arrayRoom -> identifier for which room the schedule is being set for
 * @param arraySchedule -> identifier for which day the schedule is being set for
 * @param schedule -> identifier for which schedule number the schedule is being set for
 * @param enable -> identifier for enable value the schedule is being set for
 * @return 0
 * ==============================================
 */ 

int set_enable(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int enable);

/**
 * @brief set_start_time,this funtion sets the start time variable in the structure
 * 
 * @param arrayFunction -> identifier for which function the schedule is being set for
 * @param arrayRoom -> identifier for which room the schedule is being set for
 * @param arraySchedule -> identifier for which day the schedule is being set for
 * @param schedule -> identifier for which schedule number the schedule is being set for
 * @param time -> identifier for start time the schedule is being set for
 * @return 0
 * ==============================================
 */ 

int set_start_time(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int time);

/**
 * @brief set_stop_time,this funtion sets the stop time variable in the structure
 * 
 * @param arrayFunction -> identifier for which function the schedule is being set for
 * @param arrayRoom -> identifier for which room the schedule is being set for
 * @param arraySchedule -> identifier for which day the schedule is being set for
 * @param schedule -> identifier for which schedule number the schedule is being set for
 * @param time -> identifier for stop time the schedule is being set for
 * @return 0
 * ==============================================
 */ 

int set_stop_time(int arrayFunction, int arrayRoom, int arraySchedule, int schedule, int time);

/**
 * @brief get_id,this funtion returns the id variable in the structure
 * 
 * @param arrayFunction -> identifier for which function the schedule is being set for
 * @param arrayRoom -> identifier for which room the schedule is being set for
 * @param arraySchedule -> identifier for which day the schedule is being set for
 * @param schedule -> identifier for which schedule number the schedule is being set for
 * @return desired id
 * ==============================================
 */ 

int get_id(int arrayFunction, int arrayRoom, int arraySchedule, int schedule);

/**
 * @brief get_value,this funtion returns the value variable in the structure
 * 
 * @param arrayFunction -> identifier for which function the schedule is being set for
 * @param arrayRoom -> identifier for which room the schedule is being set for
 * @param arraySchedule -> identifier for which day the schedule is being set for
 * @param schedule -> identifier for which schedule number the schedule is being set for
 * @return desired value
 * ==============================================
 */ 

int get_value(int arrayFunction, int arrayRoom, int arraySchedule, int schedule);

/**
 * @brief get_enable,this funtion returns the enable variable in the structure
 * 
 * @param arrayFunction -> identifier for which function the schedule is being set for
 * @param arrayRoom -> identifier for which room the schedule is being set for
 * @param arraySchedule -> identifier for which day the schedule is being set for
 * @param schedule -> identifier for which schedule number the schedule is being set for
 * @return desired enablue value
 * ==============================================
 */ 

int get_enable(int arrayFunction, int arrayRoom, int arraySchedule, int schedule);

/**
 * @brief get_start_time,this funtion returns the start time variable in the structure
 * 
 * @param arrayFunction -> identifier for which function the schedule is being set for
 * @param arrayRoom -> identifier for which room the schedule is being set for
 * @param arraySchedule -> identifier for which day the schedule is being set for
 * @param schedule -> identifier for which schedule number the schedule is being set for
 * @return desired start time
 * ==============================================
 */ 

int get_start_time(int arrayFunction, int arrayRoom, int arraySchedule, int schedule);

/**
 * @brief get_stop_time,this funtion returns the stop time variable in the structure
 * 
 * @param arrayFunction -> identifier for which function the schedule is being set for
 * @param arrayRoom -> identifier for which room the schedule is being set for
 * @param arraySchedule -> identifier for which day the schedule is being set for
 * @param schedule -> identifier for which schedule number the schedule is being set for
 * @return desired stop time
 * ==============================================
 */ 

int get_stop_time(int arrayFunction, int arrayRoom, int arraySchedule, int schedule);

#endif	/* SCHEDULES_H */

