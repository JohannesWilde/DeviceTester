#ifndef AVRINTERNALREGISTER_HPP
#define AVRINTERNALREGISTER_HPP

#include <stdint.h>

class AvrInternalRegister
{
public:
    AvrInternalRegister(uint8_t volatile * const registerAddress);

    void setBitMask(uint8_t const bitMask) const;
    void clearBitMask(uint8_t const bitMask) const;
    void toggleBitMask(uint8_t const bitMask) const;
    uint8_t readRegister() const;

private:
    uint8_t volatile * const registerAddress;
};

#endif // AVRINTERNALREGISTER_H
