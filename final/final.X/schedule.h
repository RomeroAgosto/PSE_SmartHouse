#ifndef SCHEDULE_H
#define SCHEDULE_H

#define DISABLE -100; 

int ds_initDSchedules();

int  ds_updateDSchedules_time();

int ds_DesiredWaterTemp();

int ds_DesiredAirTemp(int n_air);

int ds_DesiredLigth(int n_ligth);

#endif