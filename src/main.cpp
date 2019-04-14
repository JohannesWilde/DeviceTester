// this is only for the QtCreator to find the correct highlighting - this is already defined somewhere before
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "arduinouno.hpp"
#include "devicetester.hpp"

//#include "shiftregister.hpp"
//#include "shiftregistertester.hpp"

#include "rslatch.hpp"
#include "rslatchtester.hpp"

int main()
{
    typedef ArduinoUno arduinoUno;
    typedef DeviceTester<arduinoUno::A4,
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
                        arduinoUno::A3> deviceTester;

    typedef RsLatch<deviceTester::DevicePin3,
                    deviceTester::DevicePin2,
                    deviceTester::DevicePin4> rsLatch;

    typedef RsLatchTester<deviceTester::ButtonPin,
                          deviceTester::LedPin,
                          deviceTester::DevicePin7,
                          deviceTester::DevicePin15,
                          deviceTester::DevicePin1,
                          rsLatch> rsLatchTester;
    rsLatchTester::initialize();
    rsLatch::initialize();

    while (true)
    {
        rsLatchTester::waitForButtonPressAndRelease();
        rsLatchTester::TestResult testResult = rsLatchTester::test();
        rsLatchTester::showTestResult(testResult);
    }


//    while (true)
//    {
//        rsLatchTester::test();
//        rsLatchTester::waitForButtonPressAndRelease();
//    }

//    typedef ShiftRegister<8, deviceTester::DevicePin13, deviceTester::DevicePin10, deviceTester::DevicePin11, deviceTester::DevicePin12, deviceTester::DevicePin9> shiftRegister;
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
//    shiftRegisterTester::initialize();
//    shiftRegister::initialize();

//    while (true)
//    {
//        shiftRegisterTester::waitForButtonPressAndRelease();
//        shiftRegisterTester::TestResult testResult = shiftRegisterTester::test();
//        shiftRegisterTester::showTestResult(testResult);
//    }

    return 0;
}
