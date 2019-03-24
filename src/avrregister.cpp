#include "avrregister.hpp"
#include "avrinternalregister.hpp"

AvrRegister::AvrRegister(AvrInternalRegister const * const portRegister,
                         AvrInternalRegister const * const ddrRegister,
                         AvrInternalRegister const * const pinRegister) :
    portRegister(portRegister),
    ddrRegister(ddrRegister),
    pinRegister(pinRegister)
{
    // intentionally left empty
}

//void AvrRegister::setType(PinType const pinType) const
//{
//    setType(pinType, 0xff);
//}

void AvrRegister::setType(PinType const pinType, uint8_t const bitMask) const
{
    switch (pinType)
    {
    case OUTPUT_HIGH:
        ddrRegister->setBitMask(bitMask);       // output
        portRegister->setBitMask(bitMask);      // high
        break;
    case OUTPUT_LOW:
        ddrRegister->setBitMask(bitMask);       // output
        portRegister->clearBitMask(bitMask);    // low
        break;
    case INPUT:
        ddrRegister->clearBitMask(bitMask);     // input
        portRegister->clearBitMask(bitMask);    // no pull-up
        break;
    case INPUT_PULLUP:
        ddrRegister->clearBitMask(bitMask);     // input
        portRegister->setBitMask(bitMask);      // pull-up [PUD in MCUCR needs to be low]
        // break;
    }
}

uint8_t AvrRegister::readPort() const
{
    return portRegister->readRegister();
}

uint8_t AvrRegister::readDdr() const
{
    return ddrRegister->readRegister();
}

uint8_t AvrRegister::readPin() const
{
    return pinRegister->readRegister();
}
