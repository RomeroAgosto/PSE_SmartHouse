typedef union{
    struct{
        char air_temp_0;
        char air_temp_1;
        char air_temp_2;
        char air_temp_3;
        char air_temp_4;
        char air_temp_5;
        char air_temp_6;
        char air_temp_7;
        char air_status_0;
        char air_status_1;
        char air_status_2;
        char air_status_3;
        char air_status_4;
        char air_status_5;
        char air_status_6;
        char air_status_7;
        char water_temp;
        char water_state;
        char air_quality_0;
        char air_quality_1;
        char air_quality_2;
        char air_quality_3;
        char ligth_0;
        char ligth_1;
        char ligth_2;
        char ligth_3;
        char ligth_4;
        char ligth_5;
        char ligth_6;
        char ligth_7;
    };  char sensor_data[30];
} measured_data;


typedef union{
    struct{
        measured_data measurement_0;
        measured_data measurement_1;
        measured_data measurement_2;
        measured_data measurement_3;
        measured_data measurement_4;
        measured_data measurement_5;
        measured_data measurement_6;
        measured_data measurement_7;
        measured_data measurement_8;
        measured_data measurement_9;
        measured_data measurement_10;
        measured_data measurement_11;
        measured_data measurement_12;
        measured_data measurement_13;
        measured_data measurement_14;
        measured_data measurement_15;
        measured_data measurement_16;
        measured_data measurement_17;
        measured_data measurement_18;
        measured_data measurement_19;
        measured_data measurement_20;
        measured_data measurement_21;
        measured_data measurement_22;
        measured_data measurement_23;
        measured_data measurement_24;
        measured_data measurement_25;
        measured_data measurement_26;
        measured_data measurement_27;
        measured_data measurement_28;
        measured_data measurement_29;
        measured_data measurement_30;
        measured_data measurement_31;
        measured_data measurement_32;
        measured_data measurement_33;
        measured_data measurement_34;
        measured_data measurement_35;
        measured_data measurement_36;
        measured_data measurement_37;
        measured_data measurement_38;
        measured_data measurement_39;
        measured_data measurement_40;
        measured_data measurement_41;
        measured_data measurement_42;
        measured_data measurement_43;
        measured_data measurement_44;
        measured_data measurement_45;
        measured_data measurement_46;
        measured_data measurement_47;
        
    }; measured_data data[48];
} log;