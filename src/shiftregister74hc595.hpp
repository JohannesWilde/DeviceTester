#ifndef SHIFTREGISTER74HC595_HPP
#define SHIFTREGISTER74HC595_HPP

#include <stdint.h>
#include "avrinputoutput.hpp"
#include "avrpin.hpp"
#include "avrpinhelper.hpp"
#include "shiftregister.hpp"
#include "dummytypes.hpp"

template<unsigned const length_, typename SerialInput_, typename ShiftRegisterClock_,
         typename ShowRegisterClock_, typename InvertedOutputEnable_, typename InvertedShiftRegisterClear_,
         typename SerialOutput_ = DummyAvrPin0>
// length - number of pins
// the rest - AvrPin types
struct ShiftRegister74HC595 : public ShiftRegister<length_, SerialInput_, ShiftRegisterClock_, SerialOutput_>
{
protected:
    typedef ShiftRegister<length_, SerialInput_, ShiftRegisterClock_, SerialOutput_> ShiftRegister_;
public:
    typedef ShowRegisterClock_ ShowRegisterClock;
    typedef InvertedOutputEnable_ InvertedOutputEnable;
    typedef InvertedShiftRegisterClear_ InvertedShiftRegisterClear;

    // This initializes the pin directions [output or input] and turns on the shift register
    // [see turnOn()].
    static void initialize()
    {
        // set data directions of pins and default port states
        InvertedOutputEnable_::setType(AvrInputOutput::OUTPUT_HIGH); // disable output by default
        SerialInput_::setType(AvrInputOutput::OUTPUT_LOW);           // default LOW
        InvertedShiftRegisterClear_::setType(AvrInputOutput::OUTPUT_HIGH); // do not clear the shift register by default
        ShiftRegisterClock_::setType(AvrInputOutput::OUTPUT_LOW);  // default to LOW
        ShowRegisterClock_::setType(AvrInputOutput::OUTPUT_LOW);   // default to LOW
        // the shift and the show register will be cleared during initialization
        clearShiftRegister();                                       // clear both registers
        showShiftRegister();
    }

    // This will, if the register was initialized previously, disable its output [
    // i.e. the pins will be in a high impedance state, "free floating"], clear the
    // shift and the show register and set ShiftRegisterClock_, ShowRegisterClock_,
    // SerialInput_ and InvertedShiftRegisterClear_ to LOW - i.e. all pins managed by
    // this driver will be LOW [Vcc will be someones else's responsibility...].
    static void turnOff()
    {
        // This assumes ShiftRegister74HC595 was initialized previously.
        // Here clearPort() instead of the ShiftRegister74HC595 methods are used in order
        // to emphasize that all ports should be powered off - the actual functionality is not that important.
        SerialInput_::clearPort();
        ShiftRegisterClock_::clearPort();
        InvertedShiftRegisterClear_::clearPort();
        showShiftRegister();
        ShowRegisterClock_::clearPort();
        InvertedOutputEnable_::clearPort();         // this enables the output - which was cleared however.
    }

    // This will, if the register was initialized previously, disable its output [
    // i.e. the pins will be in a high impedance state, "free floating"], clear the
    // shift and the show register and default ShiftRegisterClock_, ShowRegisterClock_
    // and SerialInput_ to LOW.
    static void turnOn()
    {
        // This assumes ShiftRegister74HC595 was initialized previously.
        disableOutput();
//        ShiftRegisterClock_::clearPort(); // currently unneeded, as clearShiftRegister() does so anyway.
        clearShiftRegister();
        ShowRegisterClock_::clearPort();
        SerialInput_::clearPort();
        showShiftRegister();
    }

    static void enableOutput()
    {
        InvertedOutputEnable_::clearPort();
    }

    static void disableOutput()
    {
        InvertedOutputEnable_::setPort();
    }

    static void clearShiftRegister()
    {
        // this method leaves the show register unchanged!
        // ShiftRegisterClock_ is expected to be LOW when unused, but as InvertedShiftRegisterClear_ currently
        // does not reset the internal ShiftRegister permanently while ShiftRegisterClock_ is HIGH, assure
        // so here!
        ShiftRegisterClock_::clearPort();
        lowHighClock<InvertedShiftRegisterClear_>();
    }

    // this does not mean, that the output will be visible, if the output is disabled!
    static void showShiftRegister()
    {
        // toggle here, as thus it shifts in 1 bit regardless of whether ShowRegisterClock_ was HIGH or LOW previously.
        ShowRegisterClock_::togglePort();
        ShowRegisterClock_::togglePort();
    }

    static void shiftInBits(uint8_t const * const bitStreamArray)
    {
        ShiftRegister_::template shiftInBits<ShiftRegister_::LENGTH>(bitStreamArray);
    }

    static void shiftOutBits(uint8_t const * const bitStreamArray)
    {
        ShiftRegister_::template shiftOutBits<ShiftRegister_::LENGTH>(bitStreamArray);
    }

    static void shiftInAndOutBitsSimultaneously(uint8_t const * const bitStreamArrayIn, uint8_t * const bitStreamArrayOut)
    {
        ShiftRegister_::template shiftInAndOutBitsSimultaneously<ShiftRegister_::LENGTH>(bitStreamArrayIn, bitStreamArrayOut);
    }

    static void shiftInAndOutBitsSimultaneously(uint8_t * const bitStreamArray)
    {
        ShiftRegister_::template shiftInAndOutBitsSimultaneously<ShiftRegister_::LENGTH>(bitStreamArray);
    }
};

#endif // SHIFTREGISTER74HC595_HPP
