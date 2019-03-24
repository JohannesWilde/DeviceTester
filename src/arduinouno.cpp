#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include "arduinouno.hpp"
#include <avr/io.h>
#include "avrinternalregister.hpp"
#include "avrregister.hpp"
#include "avrpin.hpp"

AvrInternalRegister const ArduinoUno::avrInternalRegisters[] =
{
    AvrInternalRegister(&PORTB),
    AvrInternalRegister(&DDRB),
    AvrInternalRegister(&PINB),
    AvrInternalRegister(&PORTC),
    AvrInternalRegister(&DDRC),
    AvrInternalRegister(&PINC),
    AvrInternalRegister(&PORTD),
    AvrInternalRegister(&DDRD),
    AvrInternalRegister(&PIND),
};

AvrRegister const ArduinoUno::avrRegisters[] =
{
    AvrRegister(&avrInternalRegisters[REGISTER_PORTB], &avrInternalRegisters[REGISTER_DDRB], &avrInternalRegisters[REGISTER_PINB]),
    AvrRegister(&avrInternalRegisters[REGISTER_PORTC], &avrInternalRegisters[REGISTER_DDRC], &avrInternalRegisters[REGISTER_PINC]),
    AvrRegister(&avrInternalRegisters[REGISTER_PORTD], &avrInternalRegisters[REGISTER_DDRD], &avrInternalRegisters[REGISTER_PINC]),
};

AvrPin const ArduinoUno::avrPins[] =
{
    AvrPin(&avrRegisters[REGISTER_D], PORTD0),
    AvrPin(&avrRegisters[REGISTER_D], PORTD1),
    AvrPin(&avrRegisters[REGISTER_D], PORTD2),
    AvrPin(&avrRegisters[REGISTER_D], PORTD3),
    AvrPin(&avrRegisters[REGISTER_D], PORTD4),
    AvrPin(&avrRegisters[REGISTER_D], PORTD5),
    AvrPin(&avrRegisters[REGISTER_D], PORTD6),
    AvrPin(&avrRegisters[REGISTER_D], PORTD7),
    AvrPin(&avrRegisters[REGISTER_B], PORTB0),
    AvrPin(&avrRegisters[REGISTER_B], PORTB1),
    AvrPin(&avrRegisters[REGISTER_B], PORTB2),
    AvrPin(&avrRegisters[REGISTER_B], PORTB3),
    AvrPin(&avrRegisters[REGISTER_B], PORTB4),
    AvrPin(&avrRegisters[REGISTER_B], PORTB5),
    AvrPin(&avrRegisters[REGISTER_C], PORTC0),
    AvrPin(&avrRegisters[REGISTER_C], PORTC1),
    AvrPin(&avrRegisters[REGISTER_C], PORTC2),
    AvrPin(&avrRegisters[REGISTER_C], PORTC3),
    AvrPin(&avrRegisters[REGISTER_C], PORTC4),
    AvrPin(&avrRegisters[REGISTER_C], PORTC5),
};

ArduinoUno::ArduinoUno()
{

}

AvrRegister const * ArduinoUno::getRegister(Registers registerNumber) const
{
    return &avrRegisters[registerNumber];
}

AvrPin const * ArduinoUno::getPin(Pins pinNumber) const
{
    return &avrPins[pinNumber];
}

