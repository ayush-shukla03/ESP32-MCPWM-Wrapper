#include "DriveMotor.h"

//velocity PID implementation

float DriveMotor::computeVelocityPID(float target_rpm, float current_rpm, float Kp, float Ki, float Kd, float dt){

    //calculate error
    float error = target_rpm - current_rpm;

    //proportional term
    float p_term = error * Kp;

    //integral term
    integral_sum += error * dt;

    if(integral_sum > 100.0) integral_sum = 100.0;
    if(integral_sum < -100.0) integral_sum = -100.0;

    float i_term = integral_sum * Ki;

    //derivative term
    if(!first_run && dt > 0.0) derivative = (error - previous_error)/dt;

    float d_term = derivative * Kd;

    //updating state variables
    previous_error = error;
    first_run = false;

    return p_term + i_term + d_term;
}