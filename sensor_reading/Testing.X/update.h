#ifndef UPDATE_H
#define UPDATE_H

#include "struct_lib.h"


int updateSensors();

int GetAirQuality(int n_air, double* p);

int SetVentilatorState(int n_air,int state);

int GetAirTemperature(int n_air);

int SetHeatingAirState(int n_air,int state);

int GetLigthControl(int n_ligth,int *sensor_values);

int SetLightSate(int n_ligth,int state);

int GetWaterTemperature();

int SetWaterHeaterSate(int state);

#endif