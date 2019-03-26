#include "shiftregistertester.hpp"

#include "avrpin.hpp"


ShiftRegisterTester::ShiftRegisterTester(AvrPin const * const button,
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
                                         AvrPin const * const vcc) :
    DeviceTester(button,    // button
                 led,    // leds
                 q1, AvrPin::INPUT,   // pin0
                 q2, AvrPin::INPUT,
                 q3, AvrPin::INPUT,
                 q4, AvrPin::INPUT,
                 q5, AvrPin::INPUT,
                 q6, AvrPin::INPUT,
                 q7, AvrPin::INPUT,
                 gnd, AvrPin::OUTPUT_LOW,
                 q7s, AvrPin::INPUT,
                 invertedShiftRegisterClear, AvrPin::OUTPUT_LOW,
                 shiftRegisterClock, AvrPin::OUTPUT_LOW,
                 showRegisterClock, AvrPin::OUTPUT_LOW,
                 invertedOutputEnable, AvrPin::OUTPUT_HIGH,
                 serialInput, AvrPin::OUTPUT_LOW,
                 q0, AvrPin::INPUT,
                 vcc, AvrPin::OUTPUT_HIGH)
{

}
