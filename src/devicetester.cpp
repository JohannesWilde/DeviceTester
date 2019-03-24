#include "devicetester.hpp"
#include <util/delay.h>
#include "avrpin.hpp"

DeviceTester::DeviceTester(AvrPin const * const button,
                           AvrPin const * const led) :
    pinButton(button),
    pinLed(led)
{
    // set pins to out- or inputs
    pinButton->setType(AvrPin::INPUT_PULLUP);
    pinLed->setType(AvrPin::OUTPUT_LOW);
}

void DeviceTester::enableLeds() const
{
    pinLed->setType(AvrPin::OUTPUT_HIGH);
}

void DeviceTester::disableLeds() const
{
    pinLed->setType(AvrPin::OUTPUT_LOW);
}

void DeviceTester::waitForButtonPressAndRelease() const
{
    // this method checks, that the pin is LOW and afterwards goes HIGH again.
    bool wasLowAtLeastOnce = false;
    AvrPin::PinState curState = AvrPin::HIGH;
    do
    {
        // try to circumvent debounce by waiting a small amount of time between asking again
        _delay_ms(10);
        curState = pinButton->readPin();
        if (curState == 0x00)
        {
            wasLowAtLeastOnce = true;
        }
    }
    while (!(wasLowAtLeastOnce && (AvrPin::HIGH == curState)));
}

void DeviceTester::waitForButtonPress() const
{
    // this method checks, that the pin is LOW
    AvrPin::PinState curState = AvrPin::HIGH;
    do
    {
        // try to circumvent debounce by waiting a small amount of time between asking again
        _delay_ms(10);
        curState = pinButton->readPin();
    }
    while (!(AvrPin::LOW == curState));
}
