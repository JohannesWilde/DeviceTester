#ifndef AVRPIN_HPP
#define AVRPIN_HPP

#include <stdint.h>
#include "avrinputoutput.hpp"

// Struct for handling a single pin in a register conveniently.
template<typename AvrIoRegister, unsigned pinNumber_>
struct AvrPin
{
    typedef AvrIoRegister Register;
    enum { pinNumber = pinNumber_,
           bitMask = _BV(pinNumber) };

    static void setType(AvrInputOutput::PinType const pinType)
    {
        AvrIoRegister::setType(pinType, bitMask);
    }

    static void togglePort()
    {
        AvrIoRegister::togglePort(bitMask);
    }

    static typename AvrInputOutput::PinState readPort()
    {
        return checkPinState_(AvrIoRegister::readPort());
    }

    static typename AvrInputOutput::PinState readPin()
    {
        return checkPinState_(AvrIoRegister::readPin());
    }

    static typename AvrInputOutput::PinState readDdr()
    {
        return checkPinState_(AvrIoRegister::readDdr());
    }

protected:
    // this checks, whether the pin is set in the registerValue or not -
    // if it is, this method returns HIGH, otherwise LOW.
    static typename AvrInputOutput::PinState checkPinState_(typename AvrIoRegister::Type const registerValue)
    {
        return ((registerValue & bitMask) != 0) ? AvrInputOutput::HIGH : AvrInputOutput::LOW;
    }
};

#endif // AVRPIN_H
