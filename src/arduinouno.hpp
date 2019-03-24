#ifndef ARDUINOUNO_H
#define ARDUINOUNO_H

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
