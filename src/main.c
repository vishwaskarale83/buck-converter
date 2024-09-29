#include <msp430.h>
#include "adc.h"
#include "pwm.h"
#include "pid_controller.h"
#include "timer.h"

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;  // Stop watchdog timer

    adc_init();   // Initialize ADC for feedback voltage
    pwm_init();   // Initialize PWM
    timer_init(); // Initialize timer for PID control loop

    __enable_interrupt();  // Enable global interrupts

    while (1) {
        __no_operation();  // Main loop does nothing, PID handled in ISR
    }
}

// Timer ISR for PID control loop
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void) {
    pid_control();  // Call PID control logic on timer interrupt
}
