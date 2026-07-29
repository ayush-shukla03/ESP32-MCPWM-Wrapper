#include <Arduino.h>
#include <DriveMotor.h>
#include <SteerMotor.h>

//FRONT LEFT WHEEL (Shares Unit 0, Timer 0)
DriveMotor fl_drive(18, 19, MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM0A, MCPWM_OPR_A);
SteerMotor fl_steer(21, 22, MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM0B, MCPWM_OPR_B);

//FRONT RIGHT WHEEL (Shares Unit 0, Timer 1)
DriveMotor fr_drive(23, 25, MCPWM_UNIT_0, MCPWM_TIMER_1, MCPWM1A, MCPWM_OPR_A);
SteerMotor fr_steer(26, 27, MCPWM_UNIT_0, MCPWM_TIMER_1, MCPWM1B, MCPWM_OPR_B);

//REAR LEFT WHEEL (Shares Unit 0, Timer 2)
DriveMotor rl_drive(32, 33, MCPWM_UNIT_0, MCPWM_TIMER_2, MCPWM2A, MCPWM_OPR_A);
SteerMotor rl_steer(2, 4,   MCPWM_UNIT_0, MCPWM_TIMER_2, MCPWM2B, MCPWM_OPR_B);

//REAR RIGHT WHEEL (Switches to Unit 1, Shares Timer 0)
DriveMotor rr_drive(12, 13, MCPWM_UNIT_1, MCPWM_TIMER_0, MCPWM0A, MCPWM_OPR_A);
SteerMotor rr_steer(14, 15, MCPWM_UNIT_1, MCPWM_TIMER_0, MCPWM0B, MCPWM_OPR_B);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}

