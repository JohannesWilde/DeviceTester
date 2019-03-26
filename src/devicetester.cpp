#include "devicetester.hpp"
#include <util/delay.h>
#include "avrpin.hpp"

DeviceTester::DeviceTester(AvrPin const * const button,
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
                           AvrInputOutput::PinType devicePin11Type,
                           AvrPin const * const devicePin12,
                           AvrInputOutput::PinType devicePin12Type,
                           AvrPin const * const devicePin13,
                           AvrInputOutput::PinType devicePin13Type,
                           AvrPin const * const devicePin14,
                           AvrInputOutput::PinType devicePin14Type,
                           AvrPin const * const devicePin15,
                           AvrInputOutput::PinType devicePin15Type) :
    pinButton_(button),
    pinLed_(led)
{
    // set pins to out- or inputs
    pinButton_->setType(AvrPin::INPUT_PULLUP);
    pinLed_->setType(AvrPin::OUTPUT_LOW);
    pinsDevice_[0] = devicePin0;
    pinsDevice_[0]->setType(devicePin0Type);
    pinsDevice_[1] = devicePin1;
    pinsDevice_[1]->setType(devicePin1Type);
    pinsDevice_[2] = devicePin2;
    pinsDevice_[2]->setType(devicePin2Type);
    pinsDevice_[3] = devicePin3;
    pinsDevice_[3]->setType(devicePin3Type);
    pinsDevice_[4] = devicePin4;
    pinsDevice_[4]->setType(devicePin4Type);
    pinsDevice_[5] = devicePin5;
    pinsDevice_[5]->setType(devicePin5Type);
    pinsDevice_[6] = devicePin6;
    pinsDevice_[6]->setType(devicePin6Type);
    pinsDevice_[7] = devicePin7;
    pinsDevice_[7]->setType(devicePin7Type);
    pinsDevice_[8] = devicePin8;
    pinsDevice_[8]->setType(devicePin8Type);
    pinsDevice_[9] = devicePin9;
    pinsDevice_[9]->setType(devicePin9Type);
    pinsDevice_[10] = devicePin10;
    pinsDevice_[10]->setType(devicePin10Type);
    pinsDevice_[11] = devicePin11;
    pinsDevice_[11]->setType(devicePin11Type);
    pinsDevice_[12] = devicePin12;
    pinsDevice_[12]->setType(devicePin12Type);
    pinsDevice_[13] = devicePin13;
    pinsDevice_[13]->setType(devicePin13Type);
    pinsDevice_[14] = devicePin14;
    pinsDevice_[14]->setType(devicePin14Type);
    pinsDevice_[15] = devicePin15;
    pinsDevice_[15]->setType(devicePin15Type);
}

void DeviceTester::enableLeds() const
{
    pinLed_->setType(AvrPin::OUTPUT_HIGH);
}

void DeviceTester::disableLeds() const
{
    pinLed_->setType(AvrPin::OUTPUT_LOW);
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
        curState = pinButton_->readPin();
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
        curState = pinButton_->readPin();
    }
    while (!(AvrPin::LOW == curState));
}

bool DeviceTester::checkDevicePinPin(uint8_t const pinNumber, AvrInputOutput::PinState const pinState) const
{
    return ( pinsDevice_[pinNumber]->readPin() == pinState );
}

bool DeviceTester::checkDevicePinPort(uint8_t const pinNumber, AvrInputOutput::PinState const pinState) const
{
    return ( pinsDevice_[pinNumber]->readPort() == pinState );
}

bool DeviceTester::checkDevicePinDdr(uint8_t const pinNumber, AvrInputOutput::PinState const pinState) const
{
    return ( pinsDevice_[pinNumber]->readDdr() == pinState );
}
