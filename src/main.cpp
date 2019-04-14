// this is only for the QtCreator to find the correct highlighting - this is already defined somewhere before
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
//#include <util/delay.h>
//#include "arduinouno.hpp"
//#include "shiftregister.hpp"
//#include "shiftregistertester.hpp"

#include "avrinternalregister.hpp"

int main()
{
//    typedef ArduinoUno arduinoUno;
//    typedef ShiftRegister<8, arduinoUno::A1, arduinoUno::D12, arduinoUno::D13, arduinoUno::A0, arduinoUno::D11> shiftRegister;
//    typedef ShiftRegisterTester<arduinoUno::A4,
//                                arduinoUno::A5,
//                                arduinoUno::D2,
//                                arduinoUno::D3,
//                                arduinoUno::D4,
//                                arduinoUno::D5,
//                                arduinoUno::D6,
//                                arduinoUno::D7,
//                                arduinoUno::D8,
//                                arduinoUno::D9,
//                                arduinoUno::D10,
//                                arduinoUno::A2,
//                                arduinoUno::A3,
//                                shiftRegister> shiftRegisterTester;

//    while (true)
//    {
//        shiftRegisterTester::test();
//        shiftRegisterTester::waitForButtonPressAndRelease();
//    }

    typedef AvrInternalRegister<-1, uint8_t> dummyAvrInternalRegister;
    dummyAvrInternalRegister::setBitMask(0xaa);
    uint8_t registerValue = dummyAvrInternalRegister::readRegister();
    registerValue--;

    typedef AvrInternalRegister<0, uint8_t> avrInternalRegister;
    avrInternalRegister::setBitMask(0xaa);
//    uint8_t registerValue0 = avrInternalRegister::readRegister();
//    registerValue0--;

    return 0;
}
