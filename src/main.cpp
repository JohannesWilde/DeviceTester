// this is only for the QtCreator to find the correct highlighting - this is already defined somewhere before
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include "avrinternalregister.hpp"
#include "avrregister.hpp"

int main()
{
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTB_REGISTER>::address, uint8_t> PortBInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINB_REGISTER>::address, uint8_t> PinBInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRB_REGISTER>::address, uint8_t> DdrBInternal;
    PortBInternal::setBitMask(uint8_t(0x04));
    AvrInternalRegister<SfrMemoryFromIoAddress<PORTB_REGISTER>::address, uint8_t>::toggleBitMask(uint8_t(0x04));
    uint8_t blub = AvrInternalRegister<SfrMemoryFromIoAddress<PORTB_REGISTER>::address, uint8_t>::readRegister();
    ++blub;

    typedef AvrRegister<PortBInternal, DdrBInternal, PinBInternal> PortBIoRegister;
    uint8_t bla = PortBIoRegister::readPin();
    --bla;

//    uintptr_t const bla = reinterpret_cast<uintptr_t>(&PORTB);
//    *reinterpret_cast<uint8_t volatile * const>(bla) &= 0x10;
//    _MMIO_BYTE(PORTB) |= 0x04;
//    PORTB |= 0x04;

    return 0;
}
