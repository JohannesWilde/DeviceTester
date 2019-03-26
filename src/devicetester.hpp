#ifndef DEVICETESTER_H
#define DEVICETESTER_H

#include <stdint.h>
#include "avrinputoutput.hpp"

// forward declarations
class AvrPin;

class DeviceTester
{
public:
    // This DeviceTester is for 16-pin devices and additionally has a button [which uses an internal pullup
    // and when pressed should connect to ground] and a port to en-/disable the leds.
    // The pin type is from the perspective of the tester, i.e. if the device under test:
    //  - requires VCC then use OUTPUT_HIGH
    //  - requires GND then use OUTPUT_LOW
    //  - has an output itself then use INPUT or INPUT_PULLUP [depending on the device under test]
    // for that pin.
    DeviceTester(AvrPin const * const button,
                 AvrPin const * const led,
                 AvrPin const * const devicePin0,
                 AvrInputOutput::PinType devicePin0Type,
                 AvrPin const * const devicePin1,
                 AvrInputOutput::PinType devicePin1Type,
                 AvrPin const * const devicePin2,
                 AvrInputOutput::PinType devicePin2Type,
                 AvrPin const * const devicePin3,
                 AvrInputOutput::PinType devicePin3Type,
                 AvrPin const * const devicePin4,
                 AvrInputOutput::PinType devicePin4Type,
                 AvrPin const * const devicePin5,
                 AvrInputOutput::PinType devicePin5Type,
                 AvrPin const * const devicePin6,
                 AvrInputOutput::PinType devicePin6Type,
                 AvrPin const * const devicePin7,
                 AvrInputOutput::PinType devicePin7Type,
                 AvrPin const * const devicePin8,
                 AvrInputOutput::PinType devicePin8Type,
                 AvrPin const * const devicePin9,
                 AvrInputOutput::PinType devicePin9Type,
                 AvrPin const * const devicePin10,
                 AvrInputOutput::PinType devicePin10Type,
                 AvrPin const * const devicePin11,
                 AvrInputOutput::PinType devicePinT11ype,
                 AvrPin const * const devicePin12,
                 AvrInputOutput::PinType devicePin12Type,
                 AvrPin const * const devicePin13,
                 AvrInputOutput::PinType devicePin13Type,
                 AvrPin const * const devicePin14,
                 AvrInputOutput::PinType devicePin14Type,
                 AvrPin const * const devicePin15,
                 AvrInputOutput::PinType devicePin15Type);

    void enableLeds() const;
    void disableLeds() const;

    // wait until button is pressed
    void waitForButtonPressAndRelease() const;

    // wait until button was pressed at least once
    void waitForButtonPress() const;

private:
    AvrPin const * const pinButton_;
    AvrPin const * const pinLed_;
    // this array has non-const members only, because the C++ standard before C++11 does not allow for its initialization
    AvrPin const * pinsDevice_[16];
};

#endif // DEVICETESTER_H
