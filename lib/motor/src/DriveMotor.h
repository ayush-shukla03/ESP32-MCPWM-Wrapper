#ifndef DRIVE_MOTOR_H
#define DRIVE_MOTOR_H

#include "BaseMotor.h"


class DriveMotor : public BaseMotor {

    public:
        DriveMotor(int pin_pwm, int pin_dir, mcpwm_unit_t mcpwm_unit, mcpwm_timer_t timer, mcpwm_io_signals_t io_pwm, mcpwm_operator_t op) 
      : BaseMotor(pin_pwm, pin_dir, mcpwm_unit, timer, io_pwm, op) {}


        //velocity pid for drive motors
        float computeVelocityPID(float target_rpm, float current_rpm, float Kp, float Ki, float Kd, float dt);
};

#endif
