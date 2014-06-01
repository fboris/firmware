// vertical_estimator.h
#ifndef FILE_VERTICAL_ESTMATOR_H
#define FILE_VERTICAL_ESTMATOR_H


#include "basic_filter.h"
#include "barometer.h"
#include "attitude_estimator.h"

typedef struct vertical_data
{
	float Z ;
	float Zd ;
	float Zdd ;

}vertical_data;

void vertical_estimator_init(vertical_data* ,vertical_data* );
void vertical_sense(vertical_data* ,vertical_data* ,attitude_t* ,imu_raw_data_t* );
#endif