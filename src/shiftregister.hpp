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

    void enableOutput() const;
    void disableOutput() const;
    void clearShiftRegister() const;
    void showShiftRegister() const;
    // This methods expects an array that contains at least ShiftRegister::length bits.
    // The least significant bit [LSB, 0x01] of the least significant byte [LSBy,
    // bitStreamArray[0]] in the array will be at q0 of the first connected shift-register.
    // The most significant bit [MSB] of the most significant byte [MSBy] will correspondingly
    // be shifted in first.
    void shiftInBits(uint8_t const * const bitStreamArray) const;

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

    void lowHighClock(AvrPin const * const avrPin) const;
    void highLowClock(AvrPin const * const avrPin) const;
};

#endif // SHIFTREGISTER_H
