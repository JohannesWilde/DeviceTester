#ifndef SHIFTREGISTER_H
#define SHIFTREGISTER_H

#include <stdint.h>

// forward declaration
class AvrPin;

class ShiftRegister
{
public:
    ShiftRegister(uint8_t const length,
                  AvrPin const * const serialInput,
                  AvrPin const * const shiftRegisterClock,
                  AvrPin const * const showRegisterClock,
                  AvrPin const * const invertedOutputEnable,
                  AvrPin const * const invertedShiftRegisterClear);

private:
    // the "length" describes the number of ouput pins for the shift-register instance [which might
    // get quite big, if several small shift-registers are concatenated and used as one].
    // Currently limited to 255 ouputs [uint8_t].
    uint8_t const length;
    // The following const instance members hold pointers to the volatile pins of the micro-controller.
    AvrPin const * const serialInput;
    AvrPin const * const shiftRegisterClock;
    AvrPin const * const showRegisterClock;
    AvrPin const * const invertedOutputEnable;
    AvrPin const * const invertedShiftRegisterClear;
};

#endif // SHIFTREGISTER_H
