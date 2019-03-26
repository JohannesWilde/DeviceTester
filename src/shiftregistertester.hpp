#ifndef SHIFTREGISTERTESTER_HPP
#define SHIFTREGISTERTESTER_HPP

#include "devicetester.hpp"
#include "avrinputoutput.hpp"

class ShiftRegisterTester : public DeviceTester
{
public:
    // These values are specific for the used hardware [74HC595].
    // Please note, that changing these won't suffice, but that the constructor will
    // have to be adapted as well.
    enum PinNumber {
        PARALLEL_OUTPUT_1 = 0,
        PARALLEL_OUTPUT_2 = 1,
        PARALLEL_OUTPUT_3 = 2,
        PARALLEL_OUTPUT_4 = 3,
        PARALLEL_OUTPUT_5 = 4,
        PARALLEL_OUTPUT_6 = 5,
        PARALLEL_OUTPUT_7 = 6,
        GND = 7,
        SERIAL_OUTPUT = 8,
        INVERTED_SHIFT_REGISTER_CLEAR = 9,
        SHIFT_REGISTER_CLOCK = 10,
        SHOW_REGISTER_CLOCK = 11,
        INVERTED_OUTPUT_ENABLE = 12,
        SERIAL_INPUT = 13,
        PARALLEL_OUTPUT_0 = 14,
        VCC = 15
    };

    ShiftRegisterTester(AvrPin const * const button,
                        AvrPin const * const led,
                        AvrPin const * const parallelOutput1,
                        AvrPin const * const parallelOutput2,
                        AvrPin const * const parallelOutput3,
                        AvrPin const * const parallelOutput4,
                        AvrPin const * const parallelOutput5,
                        AvrPin const * const parallelOutput6,
                        AvrPin const * const parallelOutput7,
                        AvrPin const * const gnd,
                        AvrPin const * const serialOutput,
                        AvrPin const * const invertedShiftRegisterClear,
                        AvrPin const * const shiftRegisterClock,
                        AvrPin const * const showRegisterClock,
                        AvrPin const * const invertedOutputEnable,
                        AvrPin const * const serialInput,
                        AvrPin const * const parallelOutput0,
                        AvrPin const * const vcc);

    bool checkOutputEnabled() const;
    bool checkInvertedShiftRegisterClear(AvrInputOutput::PinState const pinState) const;
    bool checkShiftRegisterClock(AvrInputOutput::PinState const pinState) const;
    bool checkShowRegisterClock(AvrInputOutput::PinState const pinState) const;
    bool checkSerialOutput(AvrInputOutput::PinState const pinState) const;
    bool checkSerialInput(AvrInputOutput::PinState const pinState) const;
    // Returns an 8-bit bit mask where a 1 denotes mismatch and 0 denotes matching of expectation
    // and measured.
    uint8_t checkParallelOutput(uint8_t const expectedBitMask) const;

};

#endif // SHIFTREGISTERTESTER_HPP
