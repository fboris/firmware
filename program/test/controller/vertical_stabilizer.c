#include "vertical_stabilizer.h"


#define LOOP_DT  (0.00025f)

void PID_vertical_Zd(vertical_pid_t* PID_control,vertical_data * vertical_filtered_data){


	float error = (PID_control -> setpoint) - (vertical_filtered_data -> Zd);

	float P = error * (PID_control -> kp);


	PID_control -> integral += (error * (PID_control -> ki)) * LOOP_DT;

	PID_control -> integral = bound_float(PID_control -> integral,-20.0f,+20.0f);

	(PID_control -> output) = P+(PID_control -> integral);


}