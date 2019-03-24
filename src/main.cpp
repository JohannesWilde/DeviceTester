// ATMEL ATMEGA328p
//
//                  +-\/-+
//            PC6  1|    |28  PC5 (AI 5)
//      (D 0) PD0  2|    |27  PC4 (AI 4)
//      (D 1) PD1  3|    |26  PC3 (AI 3)
//      (D 2) PD2  4|    |25  PC2 (AI 2)
// PWM+ (D 3) PD3  5|    |24  PC1 (AI 1)
//      (D 4) PD4  6|    |23  PC0 (AI 0)
//            VCC  7|    |22  GND
//            GND  8|    |21  AREF
//            PB6  9|    |20  AVCC
//            PB7 10|    |19  PB5 (D 13)
// PWM+ (D 5) PD5 11|    |18  PB4 (D 12)
// PWM+ (D 6) PD6 12|    |17  PB3 (D 11) PWM
//      (D 7) PD7 13|    |16  PB2 (D 10) PWM
//      (D 8) PB0 14|    |15  PB1 (D 9) PWM
//                  +----+

// this is only for the QtCreator to find the correct highlighting - this is already defined somewhere before
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include "arduinouno.hpp"
#include "devicetester.hpp"
#include "shiftregister.hpp"

#include "avrpin.hpp"


//enum {
//    DEVICE_TESTER_PIN_0 = D2,
//    DEVICE_TESTER_PIN_1 = D3,
//    DEVICE_TESTER_PIN_2 = D4,
//    DEVICE_TESTER_PIN_3 = D5,
//    DEVICE_TESTER_PIN_4 = D6,
//    DEVICE_TESTER_PIN_5 = D7,
//    DEVICE_TESTER_PIN_6 = D8,
//    DEVICE_TESTER_PIN_7 = D9,
//    DEVICE_TESTER_PIN_8 = D10,
//    DEVICE_TESTER_PIN_9 = D11,
//    DEVICE_TESTER_PIN_10 = D12,
//    DEVICE_TESTER_PIN_11 = D13,
//    DEVICE_TESTER_PIN_12 = A0,
//    DEVICE_TESTER_PIN_13 = A1,
//    DEVICE_TESTER_PIN_14 = A2,
//    DEVICE_TESTER_PIN_15 = A3,
//    DEVICE_TESTER_BUTTON = ArduinoUno::A4,
//    DEVICE_TESTER_LEDS = ArduinoUno::A5
//};

//enum {
//    SHIFT_REGISTER_Q1 = D2,
//    SHIFT_REGISTER_Q2 = D3,
//    SHIFT_REGISTER_Q3 = D4,
//    SHIFT_REGISTER_Q4 = D5,
//    SHIFT_REGISTER_Q5 = D6,
//    SHIFT_REGISTER_Q6 = D7,
//    SHIFT_REGISTER_Q7 = D8,
//    SHIFT_REGISTER_GND = D9,
//    SHIFT_REGISTER_Q7S = D10,
//    SHIFT_REGISTER_NSRCLR = D11,
//    SHIFT_REGISTER_SRCLK = D12,
//    SHIFT_REGISTER_RCLK = D13,
//    SHIFT_REGISTER_NOE = A0,
//    SHIFT_REGISTER_SER = A1,
//    SHIFT_REGISTER_Q0 = A2,
//    SHIFT_REGISTER_VCC = A3,
//    SHIFT_REGISTER_LENGTH = 8
//};


int main()
{
    ArduinoUno arduinoUno;

    arduinoUno.getPin(ArduinoUno::A3)->setType(AvrPin::OUTPUT_HIGH); // VCC
    arduinoUno.getPin(ArduinoUno::A2)->setType(AvrPin::INPUT);
    arduinoUno.getPin(ArduinoUno::D10)->setType(AvrPin::INPUT);
    arduinoUno.getPin(ArduinoUno::D9)->setType(AvrPin::OUTPUT_LOW); // GND
    arduinoUno.getPin(ArduinoUno::D8)->setType(AvrPin::INPUT);
    arduinoUno.getPin(ArduinoUno::D7)->setType(AvrPin::INPUT);
    arduinoUno.getPin(ArduinoUno::D6)->setType(AvrPin::INPUT);
    arduinoUno.getPin(ArduinoUno::D5)->setType(AvrPin::INPUT);
    arduinoUno.getPin(ArduinoUno::D4)->setType(AvrPin::INPUT);
    arduinoUno.getPin(ArduinoUno::D3)->setType(AvrPin::INPUT);
    arduinoUno.getPin(ArduinoUno::D2)->setType(AvrPin::INPUT);

    DeviceTester deviceTester(arduinoUno.getPin(ArduinoUno::A4),    // button
                              arduinoUno.getPin(ArduinoUno::A5)     // leds
                              );
    deviceTester.enableLeds();

    ShiftRegister shiftRegister(8,
                                arduinoUno.getPin(ArduinoUno::A1),  // serialInput
                                arduinoUno.getPin(ArduinoUno::D12), // shiftRegisterClock
                                arduinoUno.getPin(ArduinoUno::D13), // showRegisterClock
                                arduinoUno.getPin(ArduinoUno::A0),  // invertedOutputEnable
                                arduinoUno.getPin(ArduinoUno::D11)  // invertedShiftRegisterClear
                                );

    while (true)
    {
        // do nothing
    }
    return 0;
}
