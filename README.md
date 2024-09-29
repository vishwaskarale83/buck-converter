# MSP430 Buck Converter Controller with PID Logic

This project implements a feedback loop buck converter controller using PID logic on an MSP430 microcontroller. The feedback voltage is read from the MSP430's built-in ADC, and PWM is used to control the switching of a MOSFET. The PID control loop runs periodically to adjust the PWM duty cycle based on the feedback voltage.

## Features

- **Buck Converter Control**: Uses PID logic to control the output voltage of a buck converter.
- **PID Control**: Implements proportional, integral, and derivative control logic.
- **PWM Control**: Adjusts PWM duty cycle to regulate the buck converter output voltage.
- **Modular Code Structure**: Split into multiple files for readability and maintainability.

## Project Structure

```plaintext
buck_converter_controller/
│
├── src/
│   ├── main.c                # Main function, initialization, and control loop
│   ├── adc.c                 # ADC initialization and feedback voltage reading
│   ├── adc.h
│   ├── pwm.c                 # PWM setup and duty cycle adjustment
│   ├── pwm.h
│   ├── pid_controller.c       # PID control logic
│   ├── pid_controller.h
│   ├── timer.c               # Timer setup to trigger the PID control loop
│   ├── timer.h
│
├── Makefile                   # Compiles and links the project
└── README.md                  # Project documentation
```

## Building the Project

To build the project, follow these steps:

1. **Clone the repository**:
    ```bash
    git clone https://github.com/vishwaskarale83/buck-converter.git
    cd buck-converter
    ```

2. **Compile the project**:
    Run the `make` command in the project root directory to build the project. This will compile all source files and generate the final executable.
    ```bash
    make
    ```

3. **Flash the code to the MSP430**:
    Use an MSP430 flashing tool (e.g., `mspdebug`) to program the generated executable (`buck_converter_controller.out`) onto your microcontroller:
    ```bash
    mspdebug rf2500 "prog buck_converter_controller.out"
    ```