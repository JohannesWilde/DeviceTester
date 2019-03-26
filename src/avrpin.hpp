#ifndef AVRPIN_HPP
#define AVRPIN_HPP

#include <stdint.h>
#include "avrinputoutput.hpp"

class AvrRegister;

class AvrPin : public AvrInputOutput
{
public:
    AvrPin(AvrRegister const * const avrRegister,
           uint8_t const bitNumber);

    void setType(PinType const pinType) const;
    PinState readPort() const;
    PinState readDdr() const;
    PinState readPin() const;

protected:
    inline PinState checkPinInRegister_(uint8_t const registerValue) const;

private:
    AvrRegister const * const avrRegister;
    uint8_t const bitMask;

};

#endif // AVRPIN_H
