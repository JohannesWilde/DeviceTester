// this is only for the QtCreator to find the correct highlighting - this is already defined somewhere before
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include "avrinternalregister.hpp"
#include "avrioregister.hpp"
#include "avrpin.hpp"

int main()
{
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTB_REGISTER>::address, uint8_t> PortBInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINB_REGISTER>::address, uint8_t> PinBInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRB_REGISTER>::address, uint8_t> DdrBInternal;
    PortBInternal::setBitMask(uint8_t(0x04));
    PortBInternal::toggleBitMask(uint8_t(0x04));
    uint8_t blub = PortBInternal::readRegister();
    ++blub;

    typedef AvrIoRegister<PortBInternal, DdrBInternal, PinBInternal> PortBIoRegister;
    uint8_t bla = PortBIoRegister::readPin();
    --bla;
    PortBIoRegister::togglePort(0x20);

    typedef AvrPin<PortBIoRegister, PORTB3> PortBIo3;
    PortBIo3::setType(AvrInputOutput::INPUT_PULLUP);
    PortBIo3::togglePort();

    return 0;
}
