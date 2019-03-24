#include "shiftregister.hpp"
#include "avrpin.hpp"

ShiftRegister::ShiftRegister(uint8_t const length,
                             AvrPin const * const serialInput,
                             AvrPin const * const shiftRegisterClock,
                             AvrPin const * const showRegisterClock,
                             AvrPin const * const invertedOutputEnable,
                             AvrPin const * const invertedShiftRegisterClear) :
    length(length),
    serialInput(serialInput),
    shiftRegisterClock(shiftRegisterClock),
    showRegisterClock(showRegisterClock),
    invertedOutputEnable(invertedOutputEnable),
    invertedShiftRegisterClear(invertedShiftRegisterClear)
{
    // set pins to outputs
    serialInput->setType(AvrPin::OUTPUT_LOW);

    // adapt instance methods depending whether invertedOutputEnable and invertedShiftRegisterClear are nullptr or not
}
