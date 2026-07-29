#ifndef BASE_MOTOR_H
#define BASE_MOTOR_H

#include "driver/mcpwm.h"

class BaseMotor {

    protected:
        int pwm_pin;
        int dir_pin;
        mcpwm_unit_t mcpwm_num;
        mcpwm_timer_t timer_num;
        mcpwm_operator_t op_num;

        float integral_sum;
        float derivative;
        float previous_error;
        bool first_run;


    public:

        //constructor
        BaseMotor(int pin_pwm, int pin_dir, mcpwm_unit_t mcpwm_unit, mcpwm_timer_t timer, mcpwm_io_signals_t io_pwm, mcpwm_operator_t op);

        //running the motor function
        void runMotor(float effort);
};

#endif