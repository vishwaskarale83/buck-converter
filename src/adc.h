#ifndef ADC_H
#define ADC_H

// Initializes the ADC to read feedback voltage
void adc_init();

// Reads the feedback voltage and converts it to a usable value
float read_feedback_voltage();

#endif
