#ifndef SHIFTREGISTER_HPP
#define SHIFTREGISTER_HPP

#include <stdint.h>
#include "avrinputoutput.hpp"
#include "avrpin.hpp"
#include "avrpinhelper.hpp"

template<unsigned const length_, typename SerialInput_, typename ShiftRegisterClock_,
         typename ShowRegisterClock_, typename InvertedOutputEnable_, typename InvertedShiftRegisterClear_>
// length - number of pins
// the rest - AvrPin types
struct ShiftRegister
{
public:
    enum
    {
        LENGTH = length_
    };
    typedef SerialInput_ SerialInput;
    typedef ShiftRegisterClock_ ShiftRegisterClock;
    typedef ShowRegisterClock_ ShowRegisterClock;
    typedef InvertedOutputEnable_ InvertedOutputEnable;
    typedef InvertedShiftRegisterClear_ InvertedShiftRegisterClear;

    static void initialize()
    {
        // set data directions of pins and default port states
        InvertedOutputEnable_::setType(AvrInputOutput::OUTPUT_HIGH); // disable output by default
        SerialInput_::setType(AvrInputOutput::OUTPUT_LOW);           // default LOW
        InvertedShiftRegisterClear_::setType(AvrInputOutput::OUTPUT_HIGH); // do not clear the shift register by default
        ShiftRegisterClock_::setType(AvrInputOutput::OUTPUT_HIGH);  // because data is clocked in on LOW->HIGH transition, below methods will always clear
        ShowRegisterClock_::setType(AvrInputOutput::OUTPUT_HIGH);   // and set [in that order], which ensures that a LOW->HIGH transition occurs.
        clearShiftRegister();                                       // clear both registers
        showShiftRegister();
    }

    static void turnOff()
    {
        // This assumes ShiftRegister was initialized previously.
        // Here clearPort() instead of the ShiftRegister methods are used in order
        // to emphasize that all ports should be powered off - the actual functionality is not that important.
        // A side-effect of this is that both the shift and the show register will be cleared afterwards.
        SerialInput_::clearPort();
        InvertedShiftRegisterClear_::clearPort();  // clear the shift register
        showShiftRegister();                       // clear the show register
        ShiftRegisterClock_::clearPort();
        ShowRegisterClock_::clearPort();
        InvertedOutputEnable_::clearPort();
    }


    static void turnOn()
    {
        // This assumes ShiftRegister was initialized previously.
        disableOutput();
        SerialInput_::clearPort();
        ShiftRegisterClock_::setPort();
        clearShiftRegister();
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
        lowHighClock<InvertedShiftRegisterClear_>();
    }

    // this does not mean, that the output will be visible, if the output is disabled!
    static void showShiftRegister()
    {
        lowHighClock<ShowRegisterClock_>();
    }

    // This methods expects an array that contains at least ShiftRegister::length bits.
    // The least significant bit [LSB, 0x01] of the least significant byte [LSBy,
    // bitStreamArray[0]] in the array will be at q0 of the first connected shift-register.
    // The most significant bit [MSB] of the most significant byte [MSBy] will correspondingly
    // be shifted in first.
    static void shiftInBits(uint8_t const * const bitStreamArray)
    {
        if ( length_ > 0 )
        {
            // Because of integer division, one byte more will have to be used [unless length is a multiple of 8],
            // this "+1" however is compensated by the fact, that the offset in the array starts at 0 and not 1.
            uint8_t const curByteNumber = ( (length_ - 1) >> 3 ); // = divide by 8 [integer!]
            // Now find out, how many of the bits in the most significant byte will be used.
            // (length - ( curByteNumber * 8 ) is the number of bits in the most significant byte;
            // because 0x01 has a bit at the first position alreade, subtract 1.
            uint8_t curBitMask = static_cast<uint8_t>(0x01 << (length_ - ( curByteNumber << 3 ) - 1));

            uint8_t const * bitStreamArrayByte = bitStreamArray + curByteNumber; // move pointer to most significant byte
            while (bitStreamArrayByte >= bitStreamArray)
            {
                // Because above calculation causes the last bit to be bit 0 [LSB] of Byte 0 [LSBy], I don't have
                // to check in the following while-loop, whether I don't try to read too many bits.
                while (curBitMask > 0)
                {
                    ( ((*bitStreamArrayByte) & curBitMask) != 0 ) ?
                                SerialInput_::setPort() :
                                SerialInput_::clearPort();
                    curBitMask >>= 1; // next bit [lower significance]
                    lowHighClock<ShiftRegisterClock_>();
                }
                // next byte
                --bitStreamArrayByte; // goto previous byte in array
                curBitMask = 0x01 << 7; // reset bitmask to most significant bit
            }
            // finally set serialInput to low
            SerialInput_::clearPort();
        }
    }
};

#endif // SHIFTREGISTER_H
