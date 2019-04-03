#ifndef AVRINPUTOUTPUT_HPP
#define AVRINPUTOUTPUT_HPP

#include <stdint.h>

// This namespace holds the enums for convenient HW I/O access

namespace AvrInputOutput
{
    enum PinType {
        OUTPUT_HIGH,
        OUTPUT_LOW,
        INPUT,
        INPUT_PULLUP
    };

    // don't change these PinState-values, as they are the ones hardcoded in the
    // chip and currently not transformed in the reading methods.
    enum PinState {
        LOW=0,
        HIGH=1
    };
}

#endif // AVRINPUTOUTPUT_H
