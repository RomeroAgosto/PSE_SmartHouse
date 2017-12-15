#include <stdio.h>

typedef union{
	struct{
		int id;
		int value;
		int start_time;
		int stop_time;
	}
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

house house1;

int main() {
    house1.air_temperature.room1.schedule1.id=2;
    house1.air_temperature.room1.schedule1.enable_flag=1;
    house1.air_temperature.room1.schedule1.monday=0;
    house1.air_temperature.room1.schedule1.tuesday=1;
    house1.air_temperature.room1.schedule1.wednesday=2;
    house1.air_temperature.room1.schedule1.start_time=600;
    house1.air_temperature.room1.schedule1.stop_time=800;
    house1.air_temperature.room1.schedule1.target_value=25;
    set_schedule();
    printf("size of the structure is: %ld\n", sizeof(house1));
}


int set_schedule()
    {

        int i,j,k,l;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 8; j++) {
                for (k = 0; k < 5; k++) {
                    for (l = 0; l < 6; l++) {
                        printf("house1.array_function[%d].array_room[%d].array_schedule[%d].option[%d]=%d\n",i,j,k,l,house1.array_function[i].array_room[j].array_schedule[k].option[l]);
                    }

                }

            }

        }
        return 0;

    }


    
