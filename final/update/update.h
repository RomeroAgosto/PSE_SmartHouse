#ifndef UPDATE_H
#define UPDATE_H

#include "struct_lib.h"


int updateSensors();

int GetAirQuality(int n_air, int* p);

int SetVentilatorState(int room_id, int state);

int GetVentilatorState();

int GetAirTemperature(int n_air);

int SetHeatingAirState(int n_air,int state);

int GetLigthControl(int n_ligth);

int SetLightState(int n_ligth,int state);

int GetLightState(int n_ligth);

int GetWaterTemperature();

int SetWaterHeaterSate(int state);

int GetWaterHeater();

void print();
#endif