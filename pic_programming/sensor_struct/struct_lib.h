
struct water_data
{
    char temp;
    char state;
};

struct ligth_data
{
    char state;
};

struct air_quality_data
{
    char p10;
    char co;
    char co2;
    char o3;
    char humity;
    char state;
};

struct air_temperature_data
{
    char temp;
    char state;
};

typedef struct water_data water;
typedef struct ligth_data ligths[8];
typedef struct air_quality_data air_quality[4];
typedef struct air_temperature_data air_temperature[8];


/*
 //How to use:
 air_quality air_q; // this create a variable that use the array struct
 
 //i will do function in sensors files that you can use like this:
 get_air_quality( &air_q ); // the funct =>  void get_air_quality(air_quality_data *air_q ){...}
 */
/* *****************************************************************************
 End of File
 */