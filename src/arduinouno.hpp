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

#ifndef ARDUINOUNO_HPP
#define ARDUINOUNO_HPP

// forward declarations
class AvrInternalRegister;
class AvrRegister;
class AvrPin;

class ArduinoUno
{
public:
    enum Registers {
        REGISTER_B = 0,
        REGISTER_C = 1,
        REGISTER_D = 2
    };

    enum Pins {
        D0 = 0,
        D1 = 1,
        D2 = 2,
        D3 = 3,
        D4 = 4,
        D5 = 5,
        D6 = 6,
        D7 = 7,
        D8 = 8,
        D9 = 9,
        D10 = 10,
        D11 = 11,
        D12 = 12,
        D13 = 13,
        A0 = 14,
        A1 = 15,
        A2 = 16,
        A3 = 17,
        A4 = 18,
        A5 = 19,
        LED_BUILTIN = D13
    };

    ArduinoUno();

    AvrRegister const * getRegister(Registers registerNumber) const;
    AvrPin const * getPin(Pins pinNumber) const;

private:
    // the registers and pins objects only have to be created once - afterwards only references should be passed.
    // these registers combine the port, dd and pin registers for the same pins
    static const AvrRegister avrRegisters[3];
    // these pins correspond to one pin of the Arduino Uno
    static const AvrPin avrPins[20];

    // these are the seperate registers, available in hardware
    enum InternalRegisters {
        REGISTER_PORTB,
        REGISTER_DDRB,
        REGISTER_PINB,
        REGISTER_PORTC,
        REGISTER_DDRC,
        REGISTER_PINC,
        REGISTER_PORTD,
        REGISTER_DDRD,
        REGISTER_PIND
    };
    static const AvrInternalRegister avrInternalRegisters[9];
};

#endif // ARDUINOUNO_H
