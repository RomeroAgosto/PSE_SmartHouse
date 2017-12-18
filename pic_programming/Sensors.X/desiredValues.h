/* 
 * File:   desiredValues.h
 * Author: Ricardo
 *
 * Created on 17 December 2017, 23:59
 */

#ifndef DESIREDVALUES_H
#define	DESIREDVALUES_H

#ifdef	__cplusplus
extern "C" {
#endif

int compareHour(int time1, int time2);

int  updateTimeDesiredValue();

int desiredWaterTemperature();

int desiredAirTemperature(int n_air);

int desiredLigth(int n_ligth);

#ifdef	__cplusplus
}
#endif

#endif	/* DESIREDVALUES_H */

