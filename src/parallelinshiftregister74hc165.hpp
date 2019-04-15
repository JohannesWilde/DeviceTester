#ifndef PARALLELINSHIFTREGISTER74HC165_HPP
#define PARALLELINSHIFTREGISTER74HC165_HPP

#include <stdint.h>
#include "avrinputoutput.hpp"
#include "avrpin.hpp"
#include "avrpinhelper.hpp"
#include "shiftregister.hpp"
#include "dummytypes.hpp"

template<unsigned const length_, typename InvertedParallelLoad_, typename ShiftRegisterClock_,
         typename InvertedSerialOutput_, typename SerialOutput_,  typename InvertedClockEnable_,
         typename SerialInput_ = DummyAvrPin1>
// length - number of input pins [can be cascaded]
// the rest - AvrPin types
struct ParallelInShiftRegister74HC165 : public ShiftRegister<length_, SerialInput_, ShiftRegisterClock_, SerialOutput_>
{
protected:
    typedef ShiftRegister<length_, SerialInput_, ShiftRegisterClock_, SerialOutput_> ShiftRegister_;
public:
    typedef InvertedParallelLoad_ InvertedParallelLoad;
    typedef InvertedSerialOutput_ InvertedSerialOutput;
    typedef InvertedClockEnable_ InvertedClockEnable;

    // This initializes the pin directions [output or input] and turns on the shift register
    // [see turnOn()].
    static void initialize()
    {
        // set data directions of pins and default port states
        SerialOutput_::setType(AvrInputOutput::INPUT);
        InvertedSerialOutput_::setType(AvrInputOutput::INPUT);

        InvertedParallelLoad_::setType(AvrInputOutput::OUTPUT_HIGH); // disable parallel load by default
        SerialInput_::setType(AvrInputOutput::OUTPUT_LOW); // SerialInput_ LOW by default
        ShiftRegisterClock_::setType(AvrInputOutput::OUTPUT_LOW); // ShiftRegisterClock_ LOW by default
        InvertedClockEnable_::setType(AvrInputOutput::OUTPUT_LOW); // enable now only to shift in default values
        clearShiftRegister();
        disableClock(); // default InvertedClockEnable to HIGH
    }

    // This will, if the register was initialized previously, set ShiftRegisterClock_,
    // SerialInput_, InvertedParallelLoad_ and InvertedClockEnable_ to LOW - i.e. all pins managed by
    // this driver will be LOW [Vcc will be someones else's responsibility...].
    // Please note that for this configuration either InvertedSerialOutput or SerialOutput
    // will stay high as long as VCC is still applied, depending on the input on D7 [
    // which is why it would be senseless to shift in 0s as they will be overwritten from
    // the parallel inputs anyway].
    static void turnOff()
    {
        // This assumes ParallelInShiftRegister74HC165 was initialized previously.
        // Here clearPort() instead of the ParallelInShiftRegister74HC165 methods are used in order
        // to emphasize that all ports should be powered off - the actual functionality is not that important.
        InvertedClockEnable_::clearPort();
        ShiftRegisterClock_::clearPort();
        SerialInput_::clearPort();
        InvertedParallelLoad_::clearPort();
    }

    // This will, if the register was initialized previously, disable parallel load,
    // set SerilaInput_ LOW, shift in the value at SerialInput_ into all bits in the shift register,
    // disable the clock, and set the clock LOW.
    static void turnOn()
    {
        // This assumes ShiftRegister74HC595 was initialized previously.
        ShiftRegisterClock_::clearPort();
        disableParallelLoad();
        enableClock();
//        SerialInput_::clearPort();
        clearShiftRegister();
        disableClock();
    }

    static void enableClock()
    {
        InvertedClockEnable_::clearPort();
    }

    static void disableClock()
    {
        InvertedClockEnable_::setPort();
    }

    static void enableParallelLoad()
    {
        InvertedParallelLoad_::clearPort();
    }

    static void disableParallelLoad()
    {
        InvertedParallelLoad_::setPort();
    }

    static void loadParallelToShiftregister()
    {
        enableParallelLoad();
        disableParallelLoad();
    }

    static bool parallelLoadEnabled()
    {
        return (AvrInputOutput::HIGH == InvertedParallelLoad_::readPin());
    }

    static bool clockEnabled()
    {
        return (AvrInputOutput::HIGH == InvertedClockEnable_::readPin());
    }

    // Please note that is does not make much sense calling the following methods
    // while InvertedParallelLoad or InvertedClockEnable are HIGH - this however is not checked
    // by default - one can do so with just this method however.
    // In case InvertedParallelLoad or InvertedClockEnable are hardwired and not connected
    // to this driver however, this method might be erroneous.
    static bool checkShiftRegisterUsable()
    {
        return parallelLoadEnabled() && clockEnabled();
    }

    static void clearShiftRegister()
    {
        ShiftRegister_::clearShiftRegister();
    }

    static void shiftInBits(uint8_t const * const bitStreamArray)
    {
        ShiftRegister_::template shiftInBits<ShiftRegister_::LENGTH>(bitStreamArray);
    }

    static void shiftOutBits(uint8_t * const bitStreamArray)
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

#endif // PARALLELINSHIFTREGISTER74HC165_HPP
