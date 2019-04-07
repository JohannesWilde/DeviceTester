// this is only for the QtCreator to find the correct highlighting - this is already defined somewhere before
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "arduinouno.hpp"

int main()
{
    typedef ArduinoUno arduinoUno;
    arduinoUno::LED_BUILTIN::setType(AvrInputOutput::OUTPUT_LOW);
    arduinoUno::A5::setType(AvrInputOutput::OUTPUT_HIGH); // enable leds on device tester
    while (true)
    {
        _delay_ms(500);
        arduinoUno::LED_BUILTIN::togglePort();
    }

    return 0;
}
