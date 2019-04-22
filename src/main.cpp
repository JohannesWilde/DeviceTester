// this is only for the QtCreator to find the correct highlighting - this is already defined somewhere before
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "ArduinoDrivers/arduinouno.hpp"
#include "devicetester.hpp"

//#include "ArduinoDrivers/rslatchcd4043b.hpp"
//#include "rslatchcd4043btester.hpp"

//#include "ArduinoDrivers/shiftregister74hc595.hpp"
//#include "shiftregister74hc595tester.hpp"

#include "ArduinoDrivers/parallelinshiftregister74hc165.hpp"
#include "parallelinshiftregister74hc165tester.hpp"

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

//    typedef RsLatchCd4043B<deviceTester::DevicePin3,
//                           deviceTester::DevicePin2,
//                           deviceTester::DevicePin5,
//                           deviceTester::DevicePin6,
//                           deviceTester::DevicePin11,
//                           deviceTester::DevicePin10,
//                           deviceTester::DevicePin13,
//                           deviceTester::DevicePin14,
//                           deviceTester::DevicePin4> rsLatchCd4043B;
//    typedef RsLatchCd4043BTester<deviceTester::ButtonPin,
//                                  deviceTester::LedPin,
//                                  deviceTester::DevicePin7,
//                                  deviceTester::DevicePin15,
//                                  deviceTester::DevicePin1,
//                                  deviceTester::DevicePin8,
//                                  deviceTester::DevicePin9,
//                                  deviceTester::DevicePin0,
//                                  deviceTester::DevicePin12,
//                                  rsLatchCd4043B> rsLatchCd4043BTester;
//    rsLatchCd4043BTester::initialize();
//    rsLatchCd4043B::initialize();

//    while (true)
//    {
//        rsLatchCd4043BTester::waitForButtonPressAndRelease();
//        rsLatchCd4043BTester::TestResult testResult = rsLatchCd4043BTester::test();
//        rsLatchCd4043BTester::showTestResult(testResult);
//    }


//    typedef ShiftRegister74HC595<8,
//            deviceTester::DevicePin13,
//            deviceTester::DevicePin10,
//            deviceTester::DevicePin11,
//            deviceTester::DevicePin12,
//            deviceTester::DevicePin9,
//            deviceTester::DevicePin8> shiftRegister;
//    typedef ShiftRegister74HC595Tester<deviceTester::ButtonPin,
//                                       deviceTester::LedPin,
//                                       deviceTester::DevicePin0,
//                                       deviceTester::DevicePin1,
//                                       deviceTester::DevicePin2,
//                                       deviceTester::DevicePin3,
//                                       deviceTester::DevicePin4,
//                                       deviceTester::DevicePin5,
//                                       deviceTester::DevicePin6,
//                                       deviceTester::DevicePin7,
//                                       deviceTester::DevicePin14,
//                                       deviceTester::DevicePin15,
//                                       shiftRegister> shiftRegisterTester;
//    shiftRegisterTester::initialize();
//    shiftRegister::initialize();

//    while (true)
//    {
//        shiftRegisterTester::waitForButtonPressAndRelease();
//        shiftRegisterTester::TestResult testResult = shiftRegisterTester::test();
//        shiftRegisterTester::showTestResult(testResult);
//    }


    typedef ParallelInShiftRegister74HC165<8,
            deviceTester::DevicePin0,
            deviceTester::DevicePin1,
            deviceTester::DevicePin6,
            deviceTester::DevicePin8,
            deviceTester::DevicePin14,
            deviceTester::DevicePin9> parallelInShiftRegister;
    typedef ParallelInShiftRegister74HC165Tester<deviceTester::ButtonPin,
                                       deviceTester::LedPin,
                                       deviceTester::DevicePin2,
                                       deviceTester::DevicePin3,
                                       deviceTester::DevicePin4,
                                       deviceTester::DevicePin5,
                                       deviceTester::DevicePin7,
                                       deviceTester::DevicePin10,
                                       deviceTester::DevicePin11,
                                       deviceTester::DevicePin12,
                                       deviceTester::DevicePin13,
                                       deviceTester::DevicePin15,
                                       parallelInShiftRegister> parallelInShiftRegisterTester;
    parallelInShiftRegisterTester::initialize();
    parallelInShiftRegister::initialize();

    while (true)
    {
        parallelInShiftRegisterTester::waitForButtonPressAndRelease();
        parallelInShiftRegisterTester::TestResult testResult = parallelInShiftRegisterTester::test();
        parallelInShiftRegisterTester::showTestResult(testResult);
    }
}
