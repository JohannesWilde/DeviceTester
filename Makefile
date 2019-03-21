CPPFLAGS += -std=gnu++1y

MCU          = atmega328p
F_CPU        = 16000000
 
# Avrdude code
ARDUINO_PORT = /dev/ttyUSB0
AVRDUDE_ARD_PROGRAMMER = arduino
AVRDUDE_ARD_BAUDRATE = 115200

#OPTIMIZATION_LEVEL = s
