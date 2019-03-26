#ifndef SHIFTREGISTERTESTER_HPP
#define SHIFTREGISTERTESTER_HPP

#include "devicetester.hpp"

class ShiftRegisterTester : public DeviceTester
{
public:
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
                        AvrPin const * const parallelOutput7s,
                        AvrPin const * const invertedShiftRegisterClear,
                        AvrPin const * const shiftRegisterClock,
                        AvrPin const * const showRegisterClock,
                        AvrPin const * const invertedOutputEnable,
                        AvrPin const * const serialInput,
                        AvrPin const * const parallelOutput0,
                        AvrPin const * const vcc);
};

#endif // SHIFTREGISTERTESTER_HPP
