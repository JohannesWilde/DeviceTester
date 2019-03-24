#include "devicetester.hpp"
#include "avrpin.hpp"

DeviceTester::DeviceTester(AvrPin const * const button,
                           AvrPin const * const led) :
    pinButton(button),
    pinLed(led)
{
    // set pins to out- or inputs
    pinButton->setType(AvrPin::INPUT);
    pinLed->setType(AvrPin::OUTPUT_LOW);
}

void DeviceTester::enableLeds()
{
    pinLed->setType(AvrPin::OUTPUT_HIGH);
}

void DeviceTester::disableLeds()
{
    pinLed->setType(AvrPin::OUTPUT_LOW);
}
