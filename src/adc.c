#include <msp430.h>
#include "adc.h"

#define ADC_VREF        3.3f
#define ADC_MAX_VALUE   1023

void adc_init() {
    // Set up ADC (assuming input on A0)
    ADC12CTL0 = ADC12SHT0_2 | ADC12ON;  // Sample and hold time, ADC on
    ADC12CTL1 = ADC12SHP;               // Use sampling timer
    ADC12MCTL0 = ADC12INCH_0;           // Input channel A0
    ADC12CTL0 |= ADC12ENC;              // Enable conversion
}

float read_feedback_voltage() {
    ADC12CTL0 |= ADC12SC;              // Start ADC conversion
    while (ADC12CTL1 & ADC12BUSY);     // Wait for conversion to complete
    unsigned int adc_value = ADC12MEM0;  // Read ADC result
    return (adc_value * (ADC_VREF / ADC_MAX_VALUE));  // Convert ADC value to voltage
}
