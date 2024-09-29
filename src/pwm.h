#ifndef PWM_H
#define PWM_H

// Initializes PWM on P1.2
void pwm_init();

// Sets the PWM duty cycle
void set_pwm_duty_cycle(unsigned int duty_cycle);

#endif
