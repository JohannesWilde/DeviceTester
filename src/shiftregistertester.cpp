#include "shiftregistertester.hpp"

#include "avrpin.hpp"


ShiftRegisterTester::ShiftRegisterTester(AvrPin const * const button,
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
                                         AvrPin const * const vcc) :
    DeviceTester(button,    // button
                 led,    // leds
                 parallelOutput1, AvrPin::INPUT,   // pin0
                 parallelOutput2, AvrPin::INPUT,
                 parallelOutput3, AvrPin::INPUT,
                 parallelOutput4, AvrPin::INPUT,
                 parallelOutput5, AvrPin::INPUT,
                 parallelOutput6, AvrPin::INPUT,
                 parallelOutput7, AvrPin::INPUT,
                 gnd, AvrPin::OUTPUT_LOW,
                 parallelOutput7s, AvrPin::INPUT,
                 invertedShiftRegisterClear, AvrPin::OUTPUT_LOW,
                 shiftRegisterClock, AvrPin::OUTPUT_LOW,
                 showRegisterClock, AvrPin::OUTPUT_LOW,
                 invertedOutputEnable, AvrPin::OUTPUT_HIGH,
                 serialInput, AvrPin::OUTPUT_LOW,
                 parallelOutput0, AvrPin::INPUT,
                 vcc, AvrPin::OUTPUT_HIGH)
{

}
