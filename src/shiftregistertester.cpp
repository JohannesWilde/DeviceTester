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
                                         AvrPin const * const serialOutput,
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
                 serialOutput, AvrPin::INPUT,
                 invertedShiftRegisterClear, AvrPin::OUTPUT_LOW,
                 shiftRegisterClock, AvrPin::OUTPUT_LOW,
                 showRegisterClock, AvrPin::OUTPUT_LOW,
                 invertedOutputEnable, AvrPin::OUTPUT_HIGH,
                 serialInput, AvrPin::OUTPUT_LOW,
                 parallelOutput0, AvrPin::INPUT,
                 vcc, AvrPin::OUTPUT_HIGH)
{
    // intentionally left empty
}

bool ShiftRegisterTester::checkOutputEnabled() const
{
    // on LOW the output is enabled
    return checkDevicePinPort(INVERTED_OUTPUT_ENABLE, AvrPin::LOW);
}

bool ShiftRegisterTester::checkInvertedShiftRegisterClear(AvrInputOutput::PinState const pinState) const
{
    return checkDevicePinPort(INVERTED_SHIFT_REGISTER_CLEAR, pinState);
}

bool ShiftRegisterTester::checkShiftRegisterClock(AvrInputOutput::PinState const pinState) const
{
    return checkDevicePinPort(SHIFT_REGISTER_CLOCK, pinState);
}

bool ShiftRegisterTester::checkShowRegisterClock(AvrInputOutput::PinState const pinState) const
{
    return checkDevicePinPort(SHOW_REGISTER_CLOCK, pinState);
}

bool ShiftRegisterTester::checkSerialOutput(AvrInputOutput::PinState const pinState) const
{
    return checkDevicePinPin(SERIAL_OUTPUT, pinState);
}

bool ShiftRegisterTester::checkSerialInput(AvrInputOutput::PinState const pinState) const
{
    return checkDevicePinPort(SERIAL_INPUT, pinState);
}

uint8_t ShiftRegisterTester::checkParallelOutput(uint8_t const expectedBitMask) const
{
    uint8_t curBitMask = 0x01;
    uint8_t unexpectedBitMask = 0x00;
    PinNumber const pinNumbers[8] = {PARALLEL_OUTPUT_0, PARALLEL_OUTPUT_1, PARALLEL_OUTPUT_2, PARALLEL_OUTPUT_3,
                                     PARALLEL_OUTPUT_4, PARALLEL_OUTPUT_5, PARALLEL_OUTPUT_6, PARALLEL_OUTPUT_7};
    for (uint8_t index = 0; index < 8; ++index)
    {
        AvrInputOutput::PinState const expectedState =
                ((curBitMask & expectedBitMask) != 0) ? AvrInputOutput::HIGH : AvrInputOutput::LOW;
        if (!checkDevicePinPin(pinNumbers[index], expectedState))
        {
            // only set the respective bit to one, if above check failed
            unexpectedBitMask |= curBitMask;
        }
        curBitMask <<= 1;
    }
    return unexpectedBitMask;
}
