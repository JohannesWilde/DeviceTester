#ifndef AVRINTERNALREGISTER_HPP
#define AVRINTERNALREGISTER_HPP

// this is only for the QtCreator to find the correct highlighting - this is already defined somewhere before
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <stdint.h>

// The first 64 [6-bit, 0x40] special function registers [SFRs] can be accessed using specialized
// assembler instructions [e.g. in, out, ... and the first 32 with even more specialized like sbi,
// cbi, ...] - this is called "direct I/O access".
// All further registers [if they exist] however have to be accessed using "data access"
// commands [e.g. ld, st instructions]. As to retain a consistent register access,
// the specially accessible first 64 registers are accessible via ld and st as well.
// Additionally the general purpose registers [which are 32 = 0x20] are mapped to the data
// memory before the SFRs, which thus introduces an offset to the SFR addresses, when using
// ld, st or similar, only!
//
// This leads to the following duplicate names:
// I/O register     | direct acces     | data access
// ---------------------------------------------------------
// 0x00 - 0x3f      | 0x00 - 0x3f      | 0x20 - 0x5f
// 0x40 - END       |     ---          | 0x60 - (END + 0x20)
//
// The avr-gcc and avr-g++ expect data access register names and will
// use direct I/O access where possible.


// Convert a intptr_t to an appropriately typed pointer of RegisterType volatile *.
template<intptr_t registerAddress, typename RegisterType>
RegisterType volatile * const registerPointer()
{
    return reinterpret_cast<RegisterType volatile * const>(registerAddress);
}

// Convert "data access"ible to I/O register address
template<intptr_t registerAddress>
struct SfrIoFromMemoryAddress
{
    static intptr_t const address = registerAddress - __SFR_OFFSET;
};

// Convert I/O register address to "data access"ible address
// This is quite useful when converting the register addresses as stated in the Atmel
// reference documents or their respective device headers to avr-gcc or avr-g++
// usable "data access" register addresses.
template<intptr_t registerAddress>
struct SfrMemoryFromIoAddress
{
    static intptr_t const address = registerAddress + __SFR_OFFSET;
};

// checks whether a "data access" register address is in fact an I/O register address
template<intptr_t registerAddress>
struct IsSfrIoRegister
{
    static bool const value = ((__SFR_OFFSET <= registerAddress) && (registerAddress < (0x40 + __SFR_OFFSET)));
};



template<intptr_t registerAddress, typename RegisterType>
struct AvrInternalRegister
{
    // make RegisterType accessible via "typename AvrInternalRegister<address, type>::Type"
    typedef RegisterType Type;

    // Set all register bits, which are 1 in bitMask, 1 [HIGH].
    static void setBitMask(RegisterType const bitMask)
    {
        *registerPointer<registerAddress, RegisterType>() |= bitMask;
    }

    // Set all register bits, which are 1 in bitMask, 0 [LOW].
    static void clearBitMask(RegisterType const bitMask)
    {
        *registerPointer<registerAddress, RegisterType>() &= ~bitMask;
    }

    // Toggle all bits, which are 1 in bitMask. I.e. for each bit in:
    // bitMask  | prior     | after
    // 0        | 0         | 0         - unchanged
    // 0        | 1         | 1         - unchanged
    // 1        | 0         | 1         - toggled
    // 1        | 1         | 0         - toggled
    static void toggleBitMask(RegisterType const bitMask)
    {
        *registerPointer<registerAddress, RegisterType>() ^= bitMask;
    }

    // Return the value currently in the register.
    // Please note, that for devices with only 8-bit accessible registers
    // this will for RegisterTypes with e.g. 2, 3 or 4 bytes read out the register
    // pointed to by registerAddress and the next 1, 2 or 3 bytes respectively.
    static RegisterType readRegister()
    {
        return *registerPointer<registerAddress, RegisterType>();
    }
};

#endif // AVRINTERNALREGISTER_HPP
