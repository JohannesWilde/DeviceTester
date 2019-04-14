#ifndef DEVICETESTER_HPP
#define DEVICETESTER_HPP

#include <stdint.h>
#include <util/delay.h>
#include "avrinputoutput.hpp"
#include "avrpin.hpp"


template<typename ButtonPin_,
         typename LedPin_,
         typename DevicePin0_,
         typename DevicePin1_,
         typename DevicePin2_,
         typename DevicePin3_,
         typename DevicePin4_,
         typename DevicePin5_,
         typename DevicePin6_,
         typename DevicePin7_,
         typename DevicePin8_,
         typename DevicePin9_,
         typename DevicePin10_,
         typename DevicePin11_,
         typename DevicePin12_,
         typename DevicePin13_,
         typename DevicePin14_,
         typename DevicePin15_ >
struct DeviceTester
{
public:
    // make the pins publically available
    typedef LedPin_ LedPin;
    typedef ButtonPin_ ButtonPin;
    typedef DevicePin0_ DevicePin0;
    typedef DevicePin1_ DevicePin1;
    typedef DevicePin2_ DevicePin2;
    typedef DevicePin3_ DevicePin3;
    typedef DevicePin4_ DevicePin4;
    typedef DevicePin5_ DevicePin5;
    typedef DevicePin6_ DevicePin6;
    typedef DevicePin7_ DevicePin7;
    typedef DevicePin8_ DevicePin8;
    typedef DevicePin9_ DevicePin9;
    typedef DevicePin10_ DevicePin10;
    typedef DevicePin11_ DevicePin11;
    typedef DevicePin12_ DevicePin12;
    typedef DevicePin13_ DevicePin13;
    typedef DevicePin14_ DevicePin14;
    typedef DevicePin15_ DevicePin15;


    // This DeviceTester is for 16-pin devices and additionally has a button [which uses an internal pullup
    // and when pressed should connect to ground] and a port to en-/disable the leds.
    // The pin type is from the perspective of the tester, i.e. if the device under test:
    //  - requires VCC then use OUTPUT_HIGH
    //  - requires GND then use OUTPUT_LOW
    //  - has an output itself then use INPUT or INPUT_PULLUP [depending on the device under test]
    // for that pin.
    static void initialize(AvrInputOutput::PinType devicePin0Type,
                             AvrInputOutput::PinType devicePin1Type,
                             AvrInputOutput::PinType devicePin2Type,
                             AvrInputOutput::PinType devicePin3Type,
                             AvrInputOutput::PinType devicePin4Type,
                             AvrInputOutput::PinType devicePin5Type,
                             AvrInputOutput::PinType devicePin6Type,
                             AvrInputOutput::PinType devicePin7Type,
                             AvrInputOutput::PinType devicePin8Type,
                             AvrInputOutput::PinType devicePin9Type,
                             AvrInputOutput::PinType devicePin10Type,
                             AvrInputOutput::PinType devicePin11Type,
                             AvrInputOutput::PinType devicePin12Type,
                             AvrInputOutput::PinType devicePin13Type,
                             AvrInputOutput::PinType devicePin14Type,
                             AvrInputOutput::PinType devicePin15Type)
    {
        LedPin_::setType(AvrInputOutput::OUTPUT_LOW); // leds disabled by default
        ButtonPin_::setType(AvrInputOutput::INPUT_PULLUP); // internal pull-up required!
        DevicePin0_::setType(devicePin0Type);
        DevicePin1_::setType(devicePin1Type);
        DevicePin2_::setType(devicePin2Type);
        DevicePin3_::setType(devicePin3Type);
        DevicePin4_::setType(devicePin4Type);
        DevicePin5_::setType(devicePin5Type);
        DevicePin6_::setType(devicePin6Type);
        DevicePin7_::setType(devicePin7Type);
        DevicePin8_::setType(devicePin8Type);
        DevicePin9_::setType(devicePin9Type);
        DevicePin10_::setType(devicePin10Type);
        DevicePin11_::setType(devicePin11Type);
        DevicePin12_::setType(devicePin12Type);
        DevicePin13_::setType(devicePin13Type);
        DevicePin14_::setType(devicePin14Type);
        DevicePin15_::setType(devicePin15Type);
    }

    static void enableLeds()
    {
        LedPin_::setPort();
    }

    static void disableLeds()
    {
        LedPin_::clearPort();
    }

    static void enableButton()
    {
        ButtonPin_::setPort();
    }

    static void disableButton()
    {
        ButtonPin_::clearPort();
    }

    // wait until button is pressed
    static void waitForButtonPressAndRelease()
    {
        // this method checks, that the pin is LOW and afterwards goes HIGH again.
        bool wasLowAtLeastOnce = false;
        AvrInputOutput::PinState curState = AvrInputOutput::HIGH;
        do
        {
            // try to circumvent debounce by waiting a small amount of time between asking again
            _delay_ms(10);
            curState = ButtonPin_::readPin();
            if (curState == AvrInputOutput::LOW)
            {
                wasLowAtLeastOnce = true;
            }
        }
        while (!(wasLowAtLeastOnce && (AvrInputOutput::HIGH == curState)));
    }

    // wait until button was pressed at least once
    static void waitForButtonPress()
    {
        // this method checks, that the pin is LOW
        AvrInputOutput::PinState curState = AvrInputOutput::HIGH;
        do
        {
            // try to circumvent debounce by waiting a small amount of time between asking again
            _delay_ms(10);
            curState = ButtonPin_::readPin();
        }
        while (!(AvrInputOutput::LOW == curState));
    }

    template<typename DevicePin>
    static bool checkDevicePinPin(AvrInputOutput::PinState const pinState)
    {
        return ( DevicePin::readPin() == pinState );
    }

    template<typename DevicePin>
    static bool checkDevicePinPort(AvrInputOutput::PinState const pinState)
    {
        return ( DevicePin::readPort() == pinState );
    }

    template<typename DevicePin>
    static bool checkDevicePinDdr(AvrInputOutput::PinState const pinState)
    {
        return ( DevicePin::readDdr() == pinState );
    }

    struct TestResult
    {
        // This constructor is supposed to take care of the default initialization
        // of the bit-field members.
        TestResult () :
            success(false)
        {
            // intentionally left empty
        }

        bool success : 1;
    };

    static bool test()
    {
        // every device tester should implement a test() method
        // the return value will show whether the test was successfull or not
        TestResult testResult;
        return testResult;
    }

    // Every device tester should implement a turnOffDevice() method.
    // This is supposed to set all OUTPUT_HIGH to OUTPUT_LOW and all
    // INPUT_PULLUP to INPUT in the correct order, i.e. VCC typically last.
    static void turnOffDevice()
    {
        enableButton();  // button enabled
        enableLeds();    // leds enabled to see erroneous behaviour
    }

    // Please note: Typicall the order of what is turned off should be reversed when turning it back on again.

    // Every device tester should implement a turnOnDevice() method.
    // This is supposed to set all OUTPUT_HIGH and INPUT_PULLUP
    // in the correct order, i.e. VCC typically first.
    static void turnOnDevice()
    {
        disableLeds();   // leds disabled by default
        enableButton();  // button enabled
    }
};

#endif // DEVICETESTER_H
