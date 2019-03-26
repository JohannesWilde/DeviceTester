#ifndef SHIFTREGISTERTESTER_HPP
#define SHIFTREGISTERTESTER_HPP

#include "devicetester.hpp"

class ShiftRegisterTester : public DeviceTester
{
public:
    ShiftRegisterTester(AvrPin const * const button,
                        AvrPin const * const led,
                        AvrPin const * const q1,
                        AvrPin const * const q2,
                        AvrPin const * const q3,
                        AvrPin const * const q4,
                        AvrPin const * const q5,
                        AvrPin const * const q6,
                        AvrPin const * const q7,
                        AvrPin const * const gnd,
                        AvrPin const * const q7s,
                        AvrPin const * const invertedShiftRegisterClear,
                        AvrPin const * const shiftRegisterClock,
                        AvrPin const * const showRegisterClock,
                        AvrPin const * const invertedOutputEnable,
                        AvrPin const * const serialInput,
                        AvrPin const * const q0,
                        AvrPin const * const vcc);
};

#endif // SHIFTREGISTERTESTER_HPP
