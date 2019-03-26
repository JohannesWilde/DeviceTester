// this is only for the QtCreator to find the correct highlighting - this is already defined somewhere before
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include "arduinouno.hpp"
#include "devicetester.hpp"
#include "shiftregister.hpp"

#include "avrinternalregister.hpp"
#include "avrregister.hpp"
#include "avrpin.hpp"


int main()
{
    ArduinoUno arduinoUno;

//    // dummy register for unused parameters
//    uint8_t dummyRegister;
//    AvrInternalRegister const avrInternalRegisterDummy(&dummyRegister);
//    AvrRegister const avrRegisterDummy(&avrInternalRegisterDummy, &avrInternalRegisterDummy, &avrInternalRegisterDummy);
//    AvrPin const avrPinDummy(&avrRegisterDummy, static_cast<uint8_t>(~0x00));

    DeviceTester deviceTester(arduinoUno.getPin(ArduinoUno::A4),    // button
                              arduinoUno.getPin(ArduinoUno::A5),    // leds
                              arduinoUno.getPin(ArduinoUno::D2), AvrPin::INPUT,   // pin0
                              arduinoUno.getPin(ArduinoUno::D3), AvrPin::INPUT,
                              arduinoUno.getPin(ArduinoUno::D4), AvrPin::INPUT,
                              arduinoUno.getPin(ArduinoUno::D5), AvrPin::INPUT,
                              arduinoUno.getPin(ArduinoUno::D6), AvrPin::INPUT,
                              arduinoUno.getPin(ArduinoUno::D7), AvrPin::INPUT,
                              arduinoUno.getPin(ArduinoUno::D8), AvrPin::INPUT,
                              arduinoUno.getPin(ArduinoUno::D9), AvrPin::OUTPUT_LOW,
                              arduinoUno.getPin(ArduinoUno::D10), AvrPin::INPUT,
                              arduinoUno.getPin(ArduinoUno::D11), AvrPin::OUTPUT_LOW,
                              arduinoUno.getPin(ArduinoUno::D12), AvrPin::OUTPUT_LOW,
                              arduinoUno.getPin(ArduinoUno::D13), AvrPin::OUTPUT_LOW,
                              arduinoUno.getPin(ArduinoUno::A0), AvrPin::OUTPUT_HIGH,
                              arduinoUno.getPin(ArduinoUno::A1), AvrPin::OUTPUT_LOW,
                              arduinoUno.getPin(ArduinoUno::A2), AvrPin::INPUT,
                              arduinoUno.getPin(ArduinoUno::A3), AvrPin::OUTPUT_HIGH     // pin15
                              );
    deviceTester.enableLeds();


    ShiftRegister shiftRegister(6,                                  // length
                                arduinoUno.getPin(ArduinoUno::A1),  // serialInput
                                arduinoUno.getPin(ArduinoUno::D12), // shiftRegisterClock
                                arduinoUno.getPin(ArduinoUno::D13), // showRegisterClock
                                arduinoUno.getPin(ArduinoUno::A0),  // invertedOutputEnable
                                arduinoUno.getPin(ArduinoUno::D11)  // invertedShiftRegisterClear
                                );

    uint8_t arrayToShow[1] = { 0xff };

    deviceTester.waitForButtonPressAndRelease();
    shiftRegister.enableOutput();

    while (true)
    {
        shiftRegister.shiftInBits(arrayToShow);
        shiftRegister.showShiftRegister();
        deviceTester.waitForButtonPressAndRelease();
        --arrayToShow[0];
    }

    shiftRegister.disableOutput();
    return 0;
}
