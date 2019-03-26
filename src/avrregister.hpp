#ifndef AVRREGISTER_HPP
#define AVRREGISTER_HPP

#include <stdint.h>
#include <avrinputoutput.hpp>

// forward declaration
class AvrInternalRegister;

class AvrRegister : public AvrInputOutput
{
public:
    AvrRegister(AvrInternalRegister const * const portRegister,
                AvrInternalRegister const * const ddrRegister,
                AvrInternalRegister const * const pinRegister);

    // setType(PinType const pinType, uint8_t const bitMask) only set those bits, that are 0b1 in bitMask
    void setType(PinType const pinType, uint8_t const bitMask = 0xff) const;
    uint8_t readPort() const;
    uint8_t readDdr() const;
    uint8_t readPin() const;

private:
    AvrInternalRegister const * const portRegister;
    AvrInternalRegister const * const ddrRegister;
    AvrInternalRegister const * const pinRegister;
};

#endif // AVRREGISTER_H
