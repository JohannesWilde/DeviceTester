#include "avrinternalregister.hpp"

AvrInternalRegister::AvrInternalRegister(uint8_t volatile * const registerAddress) :
    registerAddress(registerAddress)
{
    // intentionally left empty
}

void AvrInternalRegister::setBitMask(uint8_t const bitMask) const
{
    *registerAddress |= bitMask;
}

void AvrInternalRegister::clearBitMask(uint8_t const bitMask) const
{
    *registerAddress &= ~bitMask;
}

void AvrInternalRegister::toggleBitMask(uint8_t const bitMask) const
{
    *registerAddress ^= bitMask;
}

uint8_t AvrInternalRegister::readRegister() const
{
    return *registerAddress;
}

