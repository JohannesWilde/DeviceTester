#ifndef AVRINTERNALREGISTER_HPP
#define AVRINTERNALREGISTER_HPP

#include <stdint.h>

template<uint8_t volatile * const registerAddress>
class AvrInternalRegister
{
public:
    AvrInternalRegister();

    void setBitMask(uint8_t const bitMask) const
    {
        *registerAddress |= bitMask;
    }

    void clearBitMask(uint8_t const bitMask) const
    {
        *registerAddress &= ~bitMask;
    }

    void toggleBitMask(uint8_t const bitMask) const
    {
        *registerAddress ^= bitMask;
    }

    uint8_t readRegister() const
    {
        return *registerAddress;
    }
};

#endif // AVRINTERNALREGISTER_H
