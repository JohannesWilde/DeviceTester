// this is only for the QtCreator to find the correct highlighting - this is already defined somewhere before
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "arduinouno.hpp"
#include "shiftregister.hpp"


int main()
{
    typedef ArduinoUno arduinoUno;

    arduinoUno::D2::setType(AvrInputOutput::INPUT);
    arduinoUno::D3::setType(AvrInputOutput::INPUT);
    arduinoUno::D4::setType(AvrInputOutput::INPUT);
    arduinoUno::D5::setType(AvrInputOutput::INPUT);
    arduinoUno::D6::setType(AvrInputOutput::INPUT);
    arduinoUno::D7::setType(AvrInputOutput::INPUT);
    arduinoUno::D8::setType(AvrInputOutput::INPUT);
    arduinoUno::A2::setType(AvrInputOutput::INPUT);

    arduinoUno::D9::setType(AvrInputOutput::OUTPUT_LOW);
    arduinoUno::A3::setType(AvrInputOutput::OUTPUT_HIGH);

    typedef ShiftRegister<2, arduinoUno::A1, arduinoUno::D12, arduinoUno::D13, arduinoUno::A0, arduinoUno::D11> shiftRegister;
    shiftRegister::initialize();
    uint8_t data[1] = {0xff};
    shiftRegister::enableOutput();

    arduinoUno::A5::setType(AvrInputOutput::OUTPUT_HIGH); // enable leds on device tester
    while (true)
    {
        _delay_ms(100);
        shiftRegister::shiftInBits(data);
        shiftRegister::showShiftRegister();
        data[0]--;
    }

    return 0;
}
