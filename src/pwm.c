#include <msp430.h>
#include "pwm.h"

#define MAX_DUTY_CYCLE  1023

void pwm_init() {
    P1DIR |= BIT2;              // Set P1.2 as output
    P1SEL |= BIT2;              // Select Timer A function for P1.2
    TA0CCR0 = MAX_DUTY_CYCLE;   // PWM period (10-bit resolution)
    TA0CCTL1 = OUTMOD_7;        // Reset/set mode
    TA0CCR1 = 512;              // Start with 50% duty cycle
    TA0CTL = TASSEL_2 + MC_1;   // SMCLK, up mode
}

void set_pwm_duty_cycle(unsigned int duty_cycle) {
    TA0CCR1 = duty_cycle;  // Set the duty cycle for PWM output
}
