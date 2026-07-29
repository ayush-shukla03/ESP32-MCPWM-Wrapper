#include "BaseMotor.h"
#include <Arduino.h>

//the constructor, runs once when the onbject is declared
BaseMotor::BaseMotor(int pin_pwm, int pin_dir, mcpwm_unit_t mcpwm_unit, mcpwm_timer_t timer, mcpwm_io_signals_t io_pwm, mcpwm_operator_t op){

    pwm_pin = pin_pwm;
    dir_pin = pin_dir;
    mcpwm_num = mcpwm_unit;
    timer_num = timer;
    op_num = op;

    //set the pins as OUTPUT
    pinMode(dir_pin, OUTPUT);

    //routing MCPWM to PWM pin
    mcpwm_gpio_init(mcpwm_num, io_pwm, pwm_pin);

    //configuring the mcpwm for cytron 20Hz
    mcpwm_config_t pwm_config;
    pwm_config.frequency = 20000;
    pwm_config.cmpr_a = 0.0;
    pwm_config.cmpr_b = 0.0;
    pwm_config.counter_mode = MCPWM_UP_COUNTER;
    pwm_config.duty_mode = MCPWM_DUTY_MODE_0;

    mcpwm_init(mcpwm_num, timer_num, &pwm_config);

    //initializing pid variables
    integral_sum = 0.0;
    derivative = 0.0;
    previous_error = 0.0;
    first_run = true;
}

//the hardware driver
void BaseMotor::runMotor(float effort){

    //clamping the max and min values
    if(effort  > 100.0) effort = 100.0;
    if(effort < -100.0) effort = -100.0;

    if(effort > 0){

        digitalWrite(dir_pin, HIGH);
        mcpwm_set_duty(mcpwm_num, timer_num, op_num, effort);
    }

    else if(effort < 0){
        digitalWrite(dir_pin, LOW);
        mcpwm_set_duty(mcpwm_num, timer_num, op_num, abs(effort));
    }

    else{
        mcpwm_set_duty(mcpwm_num, timer_num, op_num, 0.0);
    }
}
