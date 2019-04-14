#ifndef DUMMYAVRINTERNALREGISTER_HPP
#define DUMMYAVRINTERNALREGISTER_HPP

#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <stdint.h>

// Please try to use invalid 'registerAddress_'es [or at least otherwise unused ones]
// - as to avoid ambiguouties with real 'AvrInternalRegister's.
//
// Also note, that - as c++ templates imply - if you do
//    typedef DummyAvrInternalRegister<static_cast<uintptr_t>(-1), uint8_t> dummyAvrInternalRegister0;
//    typedef DummyAvrInternalRegister<static_cast<uintptr_t>(-1), uint8_t> dummyAvrInternalRegister1;
//    typedef DummyAvrInternalRegister<static_cast<uintptr_t>(-1), uint8_t, false> dummyAvrInternalRegister2;
// then both types [dummyAvrInternalRegister0 and dummyAvrInternalRegister1] will refer
// to the same class and thus the same dummyRegister.
// dummyAvrInternalRegister2 however will refer to another class.

template<uintptr_t registerAddress_, typename RegisterType_, bool functional_ = true>
struct DummyAvrInternalRegister
{
    // make RegisterType accessible via "typename DummyAvrInternalRegister<address, type>::RegisterType"
    typedef RegisterType_ RegisterType;
    static const uintptr_t registerAddress = registerAddress_;
    static const bool functional = functional_;

    // this value is only used if functional_ is true
    static RegisterType dummyRegister; // this is the internal register value

    // Set all register bits, which are 1 in bitMask, 1 [HIGH].
    static void setBitMask(RegisterType const bitMask)
    {
        if (functional_)
        {
            dummyRegister |= bitMask;
        }
    }

    // Set all register bits, which are 1 in bitMask, 0 [LOW].
    static void clearBitMask(RegisterType const bitMask)
    {
        if (functional_)
        {
            dummyRegister &= bitMask;
        }
    }

    // Toggle all bits, which are 1 in bitMask. I.e. for each bit in:
    // bitMask  | prior     | after
    // 0        | 0         | 0         - unchanged
    // 0        | 1         | 1         - unchanged
    // 1        | 0         | 1         - toggled
    // 1        | 1         | 0         - toggled
    static void toggleBitMask(RegisterType const bitMask)
    {
        if (functional_)
        {
            dummyRegister ^= bitMask;
        }
    }

    // Return the value currently in the dummyRegister or 0 [if functional_ == false].
    static RegisterType readRegister()
    {
        RegisterType_ returnVal;
        if (functional_)
        {
            returnVal = dummyRegister;
        }
        else
        {
            returnVal = 0;
        }
        return returnVal;
    }
};


// initialize dummyRegister_ of every class to 0
template<uintptr_t registerAddress_, typename RegisterType_, bool functional_>
RegisterType_ DummyAvrInternalRegister<registerAddress_, RegisterType_, functional_>::dummyRegister = 0;

#endif // DUMMYAVRINTERNALREGISTER_HPP
