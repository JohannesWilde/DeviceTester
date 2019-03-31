#ifndef AVRINTERNALREGISTER_HPP
#define AVRINTERNALREGISTER_HPP

// load asm-compatible special function register macros.
// backup whether _SFR_ASM_COMPAT was defined true or false [false is default]
#ifdef _SFR_ASM_COMPAT
    #if _SFR_ASM_COMPAT
        #define _SFR_ASM_COMPAT_BACKUP 1 // true
    #else
        #define _SFR_ASM_COMPAT_BACKUP 0 // false
    #endif
    #undef _SFR_ASM_COMPAT
#endif
// backup whether sfr_devs.h was included prior
#ifdef _AVR_SFR_DEFS_H_
    #define _AVR_SFR_DEFS_H__BACKUP
    #undef _AVR_SFR_DEFS_H_
#endif
// load asm-compatible state, but with C specific parts
// however PORTx returns the internal register address and not an assignable l-value to that register!
#define _SFR_ASM_COMPAT 1
#include <avr/sfr_defs.h>


#include <stdint.h>

namespace // anonymous namespace
{

//    template<uintptr_t const registerAddress>
//    void setBitMask_(uint8_t const bitMask)
//    {
//        _MMIO_BYTE(registerAddress) |= bitMask;
//    }

//    template<uint8_t volatile * const registerAddress>
//    void clearBitMask(uint8_t const bitMask)
//    {
//        *registerAddress &= ~bitMask;
//    }

//    template<uint8_t volatile * const registerAddress>
//    void toggleBitMask(uint8_t const bitMask)
//    {
//        *registerAddress ^= bitMask;
//    }

//    template<uint8_t volatile * const registerAddress>
//    uint8_t readRegister()
//    {
//        return *registerAddress;
//    }

}

namespace AvrInternalRegister
{
    enum RegisterAddress
    {
        Portb = PORTB
    };

    template<RegisterAddress const registerAddress>
    void setBitMask(uint8_t const bitMask)
    {
        _MMIO_BYTE(registerAddress) |= bitMask;
    }


}

// restore previous state of setup for next include.
// check whether _SFR_ASM_COMPAT was defined already
#undef _SFR_ASM_COMPAT
#ifdef _SFR_ASM_COMPAT_BACKUP
    #if _SFR_ASM_COMPAT_BACKUP
        #define _SFR_ASM_COMPAT 1 // true
    #else
        #define _SFR_ASM_COMPAT 0 // false
    #endif
#endif
// check whether sfr_devs.h was included prior
// make sure, sfr_defs.h is included with the next include-statement anew
#undef _AVR_SFR_DEFS_H_
#ifdef _AVR_SFR_DEFS_H__BACKUP
    // in case it was previously loaded already, reload it here with the previous parameters
    #include <avr/sfr_defs.h>
#endif

#endif // AVRINTERNALREGISTER_H
