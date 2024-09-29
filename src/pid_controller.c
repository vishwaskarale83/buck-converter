#include "adc.h"
#include "pwm.h"
#include "pid_controller.h"

// PID control parameters
#define KP  1.0f
#define KI  0.1f
#define KD  0.01f

// Target output voltage
#define TARGET_VOLTAGE  5.0f

// PID variables
float error, prev_error, integral, derivative;
unsigned int duty_cycle = 512;

void pid_control() {
    // Read feedback voltage from ADC
    float actual_voltage = read_feedback_voltage();

    // Calculate error (difference between target and actual voltage)
    error = TARGET_VOLTAGE - actual_voltage;

    // Calculate integral and derivative terms
    integral += error;
    derivative = error - prev_error;

    // Calculate PID output
    float pid_output = (KP * error) + (KI * integral) + (KD * derivative);

    // Adjust duty cycle based on PID output
    duty_cycle += (unsigned int)pid_output;

    // Constrain duty cycle within limits
    if (duty_cycle > 1023) duty_cycle = 1023;
    if (duty_cycle < 0) duty_cycle = 0;

    // Set the new duty cycle
    set_pwm_duty_cycle(duty_cycle);

    // Store current error for the next iteration
    prev_error = error;
}
