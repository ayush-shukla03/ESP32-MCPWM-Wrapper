#include "SteerMotor.h"
#include "math.h"

float SteerMotor::computePositionPID(float target_angle, float current_angle, float Kp, float Ki, float Kd, float dt){

    //calculating error
    float raw_error = target_angle - current_angle;

    float error = fmod(raw_error + 180.0, 360.0);
    if (error < 0) {
        error += 360.0;
    }
    error -= 180.0;

    //proportional term
    float p_term = error * Kp;

    //integral term
    integral_sum += error * dt;

    if(integral_sum > 50) integral_sum = 50;
    if(integral_sum < -50) integral_sum = -50;

    float i_term = integral_sum * Ki;

    //derivative term
    if(!first_run && dt > 0.0) derivative = (error - previous_error)/dt;

    float d_term = derivative * Kd;

    //updating state variables
    previous_error = error;
    first_run = false;

    return p_term + i_term + d_term;

}

