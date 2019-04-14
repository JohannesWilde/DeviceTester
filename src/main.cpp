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
#include "dummyavrinternalregister.hpp"

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

    typedef DummyAvrInternalRegister<static_cast<uintptr_t>(-1), uint8_t> dummyAvrInternalRegister;
    dummyAvrInternalRegister::setBitMask(0xaa);
    uint8_t registerValue = dummyAvrInternalRegister::readRegister();
    registerValue--;

    typedef DummyAvrInternalRegister<static_cast<uintptr_t>(-2), uint8_t> dummyAvrInternalRegister1;
    dummyAvrInternalRegister1::setBitMask(0xaa);
    uint8_t registerValue1 = dummyAvrInternalRegister1::readRegister();
    registerValue1--;

    typedef AvrInternalRegister<0x25, uint8_t> avrInternalRegister;
    avrInternalRegister::setBitMask(registerValue + registerValue1);

// Above translates to [-Os, avr-gcc 5.4.0]
//    0000008a <main>:
//      8a:	80 91 01 01 	lds	r24, 0x0101	; 0x800101 <_ZN24DummyAvrInternalRegisterILj65535EhLb1EE13dummyRegisterE>
//      8e:	8a 6a       	ori	r24, 0xAA	; 170
//      90:	80 93 01 01 	sts	0x0101, r24	; 0x800101 <_ZN24DummyAvrInternalRegisterILj65535EhLb1EE13dummyRegisterE>
//      94:	90 91 00 01 	lds	r25, 0x0100	; 0x800100 <_edata>
//      98:	9a 6a       	ori	r25, 0xAA	; 170
//      9a:	90 93 00 01 	sts	0x0100, r25	; 0x800100 <_edata>
//      9e:	25 b1       	in	r18, 0x05	; 5
//      a0:	89 0f       	add	r24, r25
//      a2:	82 50       	subi	r24, 0x02	; 2
//      a4:	82 2b       	or	r24, r18
//      a6:	85 b9       	out	0x05, r24	; 5


    return 0;
}
