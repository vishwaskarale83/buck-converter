# Target MCU
MCU = msp430g2553

# Toolchain
CC = msp430-gcc
CFLAGS = -mmcu=$(MCU) -Wall -O2

# Source files
SRCS = main.c adc.c pwm.c pid_controller.c timer.c

# Object files
OBJS = $(SRCS:.c=.o)

# Output executable
TARGET = buck_converter_controller.out

# Default target to build the project
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile each C file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)
