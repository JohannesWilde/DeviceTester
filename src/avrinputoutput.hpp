#ifndef AVRINPUTOUTPUT_H
#define AVRINPUTOUTPUT_H

#include <stdint.h>

// This class functions as an interface for input-/output-functinoality of AVRs.
// In order to avoid the overhead of virtual methods, the note to not actually
// instantiate an instance of this class directly is only written here - understandable
// for anyone who reads this but not for the compiler...

// Don't instantiate this class!
class AvrInputOutput
{
public:
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

    /*
     * The following methods are expected to be implemented by childs of this class.
     *
     * void setType(PinType const pinType) const;
     * uint8_t readPort() const;
     * uint8_t readDdr() const;
     * uint8_t readPin() const;
     */
};

#endif // AVRINPUTOUTPUT_H
