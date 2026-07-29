#ifndef STEER_MOTOR_H
#define STEER_MOTOR_H

#include "BaseMotor.h"
#include <math.h>

class SteerMotor : public BaseMotor {

    public:
        SteerMotor(int pin_pwm, int pin_dir, mcpwm_unit_t mcpwm_unit, mcpwm_timer_t timer, mcpwm_io_signals_t io_pwm, mcpwm_operator_t op) 
      : BaseMotor(pin_pwm, pin_dir, mcpwm_unit, timer, io_pwm, op) {}

        //position PID for steer motors
        float computePositionPID(float target_angle, float current_angle, float Kp, float Ki, float Kd, float dt);
};

#endif