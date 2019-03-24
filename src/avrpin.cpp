#include "avrpin.hpp"
#include "avrregister.hpp"
#include <avr/sfr_defs.h>

AvrPin::AvrPin(AvrRegister const * const avrRegister,
               uint8_t const bitNumber) :
    avrRegister(avrRegister),
    bitMask(static_cast<uint8_t>(_BV(bitNumber)))
{
    // intentionally left empty
}

void AvrPin::setType(PinType const pinType) const
{
    avrRegister->setType(pinType, bitMask);
}

AvrPin::PinState AvrPin::readPort() const
{
    return checkPinInRegister_(avrRegister->readPort());
}

AvrPin::PinState AvrPin::readDdr() const
{
    return checkPinInRegister_(avrRegister->readDdr());
}

AvrPin::PinState AvrPin::readPin() const
{
    return checkPinInRegister_(avrRegister->readPin());
}

AvrPin::PinState AvrPin::checkPinInRegister_(uint8_t const registerValue) const
{
    return ((registerValue & bitMask) != 0) ? AvrPin::HIGH : AvrPin::LOW;
}
