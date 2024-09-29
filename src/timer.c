#include <msp430.h>
#include "timer.h"

void timer_init() {
    // Set up Timer for PID control loop (10ms interval)
    TA0CCR0 = 10485;           // ~10ms at 1MHz
    TA0CCTL0 = CCIE;           // Enable interrupt
    TA0CTL = TASSEL_2 + MC_1;  // SMCLK, up mode
}
