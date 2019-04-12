// this is only for the QtCreator to find the correct highlighting - this is already defined somewhere before
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "arduinouno.hpp"
#include "shiftregister.hpp"
#include "shiftregistertester.hpp"


int main()
{
    typedef ArduinoUno arduinoUno;
    typedef ShiftRegisterTester<arduinoUno::A4,
                                arduinoUno::A5,
                                arduinoUno::D2,
                                arduinoUno::D3,
                                arduinoUno::D4,
                                arduinoUno::D5,
                                arduinoUno::D6,
                                arduinoUno::D7,
                                arduinoUno::D8,
                                arduinoUno::D9,
                                arduinoUno::D10,
                                arduinoUno::D11,
                                arduinoUno::D12,
                                arduinoUno::D13,
                                arduinoUno::A0,
                                arduinoUno::A1,
                                arduinoUno::A2,
                                arduinoUno::A3> shiftRegisterTester;

    shiftRegisterTester::initialize();

    typedef ShiftRegister<8, arduinoUno::A1, arduinoUno::D12, arduinoUno::D13, arduinoUno::A0, arduinoUno::D11> shiftRegister;
    shiftRegister::initialize();
    uint8_t data[1] = {0xff};
    shiftRegister::enableOutput();

    data[0] = 0xff;
    shiftRegister::shiftInBits(data);
    shiftRegister::showShiftRegister();
    _delay_ms(1000);

    shiftRegisterTester::enableLeds();
    _delay_ms(1000);

    if ( shiftRegisterTester::checkOutputEnabled() )
    {
        data[0] = 0x55;
        shiftRegister::shiftInBits(data);
        shiftRegister::showShiftRegister();
    }


    while (true)
    {
        _delay_ms(500);
        shiftRegister::shiftInBits(data);
        shiftRegister::showShiftRegister();

        if (!shiftRegisterTester::checkParallelOutput(data[0]))
        {
            data[0] = shiftRegisterTester::compareParallelOutputTo(data[0]);
            while (true)
            {
                shiftRegister::shiftInBits(data);
                shiftRegister::showShiftRegister();
                _delay_ms(500);
                data[0] = ~data[0];
            }
        }

        data[0]--;
    }

    return 0;
}
