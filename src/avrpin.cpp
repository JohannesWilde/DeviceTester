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

uint8_t AvrPin::readPort() const
{
    return checkPinInRegister_(avrRegister->readPort());
}

uint8_t AvrPin::readDdr() const
{
    return checkPinInRegister_(avrRegister->readDdr());
}

uint8_t AvrPin::readPin() const
{
    return checkPinInRegister_(avrRegister->readPin());
}

uint8_t AvrPin::checkPinInRegister_(uint8_t const registerValue) const
{
    return ((registerValue & bitMask) != 0) ? 0x01 : 0x00;
}
