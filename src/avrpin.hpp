#ifndef AVRPIN_H
#define AVRPIN_H

#include <stdint.h>
#include "avrinputoutput.hpp"

class AvrRegister;

class AvrPin : public AvrInputOutput
{
public:
    AvrPin(AvrRegister const * const avrRegister,
           uint8_t const bitNumber);

    void setType(PinType const pinType) const;
    uint8_t readPort() const;
    uint8_t readDdr() const;
    uint8_t readPin() const;

protected:
    inline uint8_t checkPinInRegister_(uint8_t const registerValue) const;

private:
    AvrRegister const * const avrRegister;
    uint8_t const bitMask;

};

#endif // AVRPIN_H
