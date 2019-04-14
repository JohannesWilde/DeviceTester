#ifndef SHIFTREGISTER_HPP
#define SHIFTREGISTER_HPP

#include <stdint.h>
#include "avrinputoutput.hpp"
#include "avrpin.hpp"
#include "avrpinhelper.hpp"

template<unsigned const length_,
         typename SerialInput_,
         typename ShiftRegisterClock_,
         typename SerialOutput_>
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
    typedef SerialOutput_ SerialOutput;

    // This initializes the pin directions [output or input] and turns on the shift register
    // [see turnOn()].
    static void initialize()
    {
        // set data directions of pins and default port states
        SerialInput_::setType(AvrInputOutput::OUTPUT_LOW);           // default LOW
        ShiftRegisterClock_::setType(AvrInputOutput::OUTPUT_LOW);  // default to LOW
        SerialOutput_::setType(AvrInputOutput::INPUT);
        clearShiftRegister();
    }

    // This will, if the register was initialized previously, clear the
    // shift register and default ShiftRegisterClock_, and SerialInput_ to LOW.
    static void turnOff()
    {
        turnOn();
    }

    // This will, if the register was initialized previously, clear the
    // shift register and default ShiftRegisterClock_, and SerialInput_ to LOW.
    static void turnOn()
    {
//        SerialOutput_::clearPort(); // pull-up should not be enabled at anytime
        ShiftRegisterClock_::clearPort();
//        SerialInput_::clearPort(); // is done in clearShiftRegister()
        clearShiftRegister();
    }

    static void clearShiftRegister()
    {
        // shift in length_ 0s
        SerialInput_::clearPort();
        for (unsigned pinNumber = 0; pinNumber < length_; ++pinNumber)
        {
            toggleTwice<ShiftRegisterClock_>();
        }
    }

    // "In" means into the shiftRegister.
    // This methods expects an array that contains at least lengthInBits_ bits.
    // The least significant bit [LSB, 0x01] of the least significant byte [LSBy,
    // bitStreamArray[0]] in the array will be at q0 of the first connected shift-register.
    // The most significant bit [MSB] of the most significant byte [MSBy] will correspondingly
    // be shifted in first [the MSB that is, which is length_ from the LSB of the LSBy "distant"].
    template<unsigned lengthInBits_>
    static void shiftInBits(uint8_t const * const bitStreamArray)
    {
        if ( lengthInBits_ > 0 )
        {
            // Because of integer division, one byte more will have to be used [unless length is a multiple of 8],
            // this "+1" however is compensated by the fact, that the offset in the array starts at 0 and not 1.
            uint8_t const curByteNumber = ( (lengthInBits_ - 1) >> 3 ); // = divide by 8 [integer!]
            // Now find out, how many of the bits in the most significant byte will be used.
            // (length - ( curByteNumber * 8 )) is the number of bits in the most significant byte;
            // because 0x01 has a bit at the first position alreade, subtract 1.
            uint8_t curBitMask = static_cast<uint8_t>(0x01 << (lengthInBits_ - ( curByteNumber << 3 ) - 1));

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
                    // toggle here, as thus it shifts in 1 bit regardless of whether ShowRegisterClock_ was HIGH or LOW previously.
                    toggleTwice<ShiftRegisterClock_>();
                }
                // next byte
                --bitStreamArrayByte; // goto previous byte in array
                curBitMask = 0x01 << 7; // reset bitmask to most significant bit
            }
            // finally set serialInput to low
            SerialInput_::clearPort();
        }
    }

    // "Out" means out from the shiftRegister.
    // This methods expects an array that contains at least lengthInBits_ bits.
    // The first read in bit will be in the MSBy at the most significant position [not
    // necessarily MSB], while the last read in bit will be in the LSBy at the LSB.
    // This means, if only 6 bits are read in, then the first read in bit will be
    // [MSB - bit 7, LSB - bit 0] at bit 6 and the last one at bit 0.
    template<unsigned lengthInBits_>
    static void shiftOutBits(uint8_t * const bitStreamArray)
    {
        // shift in 0s instead
        SerialInput_::clearPort();

        if ( lengthInBits_ > 0 )
        {
            // Because of integer division, one byte more will have to be used [unless length is a multiple of 8],
            // this "+1" however is compensated by the fact, that the offset in the array starts at 0 and not 1.
            uint8_t const curByteNumber = ( (lengthInBits_ - 1) >> 3 ); // = divide by 8 [integer!]
            // Now find out, how many of the bits in the most significant byte will be used.
            // (length - ( curByteNumber * 8 )) is the number of bits in the most significant byte;
            // because 0x01 has a bit at the first position alreade, subtract 1.
            uint8_t curBitMask = static_cast<uint8_t>(0x01 << (lengthInBits_ - ( curByteNumber << 3 ) - 1));

            uint8_t * bitStreamArrayByte = bitStreamArray + curByteNumber; // move pointer to most significant byte
            while (bitStreamArrayByte >= bitStreamArray)
            {
                // Because above calculation causes the last bit to be bit 0 [LSB] of Byte 0 [LSBy], I don't have
                // to check in the following while-loop, whether I don't try to read too many bits.
                while (curBitMask > 0)
                {
                    (AvrInputOutput::HIGH == SerialOutput_::readPin()) ?
                              (*bitStreamArrayByte) |= curBitMask :      // set bit in array
                              (*bitStreamArrayByte) &= ~curBitMask;      // clear bit in array
                    curBitMask >>= 1; // next bit [lower significance]
                    // toggle here, as thus it shifts in 1 bit regardless of whether ShowRegisterClock_ was HIGH or LOW previously.
                    toggleTwice<ShiftRegisterClock_>();
                }
                // next byte
                --bitStreamArrayByte; // goto previous byte in array
                curBitMask = 0x01 << 7; // reset bitmask to most significant bit
            }
        }
    }

    // Combines above methods, does os however at the same time.
    // Please note that this is not the same as calling the two methods above consecutively,
    // as shifInBits() will overwrite the bits in the shiftRegister and shiftOutBits()
    // will shift in 0s.
    // This method only affects the bits in bitStreamArrayOut, that are actually read in
    // [i.e. if 6 bits are read in, bit 6 and bit7 are left unchanged [MSB - bit 7, LSB - bit 0]].
    template<unsigned lengthInBits_>
    static void shiftInAndOutBitsSimultaneously(uint8_t const * const bitStreamArrayIn, uint8_t * const bitStreamArrayOut)
    {
        if ( lengthInBits_ > 0 )
        {
            // Because of integer division, one byte more will have to be used [unless length is a multiple of 8],
            // this "+1" however is compensated by the fact, that the offset in the array starts at 0 and not 1.
            uint8_t const curByteNumber = ( (lengthInBits_ - 1) >> 3 ); // = divide by 8 [integer!]
            // Now find out, how many of the bits in the most significant byte will be used.
            // (length - ( curByteNumber * 8 )) is the number of bits in the most significant byte;
            // because 0x01 has a bit at the first position alreade, subtract 1.
            uint8_t curBitMask = static_cast<uint8_t>(0x01 << (lengthInBits_ - ( curByteNumber << 3 ) - 1));

            uint8_t const * bitStreamArrayInByte = bitStreamArrayIn + curByteNumber; // move pointer to most significant byte
            uint8_t * bitStreamArrayOutByte = bitStreamArrayOut + curByteNumber; // move pointer to most significant byte
            while (bitStreamArrayInByte >= bitStreamArrayIn)
            {
                // Because above calculation causes the last bit to be bit 0 [LSB] of Byte 0 [LSBy], I don't have
                // to check in the following while-loop, whether I don't try to read too many bits.
                while (curBitMask > 0)
                {
                    ( ((*bitStreamArrayInByte) & curBitMask) != 0 ) ?
                                SerialInput_::setPort() :
                                SerialInput_::clearPort();

                    (AvrInputOutput::HIGH == SerialOutput_::readPin()) ?
                              (*bitStreamArrayOutByte) |= curBitMask :      // set bit in array
                              (*bitStreamArrayOutByte) &= ~curBitMask;      // clear bit in array

                    curBitMask >>= 1; // next bit [lower significance]
                    // toggle here, as thus it shifts in 1 bit regardless of whether ShowRegisterClock_ was HIGH or LOW previously.
                    toggleTwice<ShiftRegisterClock_>();
                }
                // next byte
                --bitStreamArrayInByte; // goto previous byte in array
                --bitStreamArrayOutByte; // goto previous byte in array
                curBitMask = 0x01 << 7; // reset bitmask to most significant bit
            }
        }
    }

    // Same as above, however it writes it output over its input and thus does not
    // need another array for its read out values.
    template<unsigned lengthInBits_>
    static void shiftInAndOutBitsSimultaneously(uint8_t * const bitStreamArray)
    {
        if ( lengthInBits_ > 0 )
        {
            // Because of integer division, one byte more will have to be used [unless length is a multiple of 8],
            // this "+1" however is compensated by the fact, that the offset in the array starts at 0 and not 1.
            uint8_t const curByteNumber = ( (lengthInBits_ - 1) >> 3 ); // = divide by 8 [integer!]
            // Now find out, how many of the bits in the most significant byte will be used.
            // (length - ( curByteNumber * 8 )) is the number of bits in the most significant byte;
            // because 0x01 has a bit at the first position alreade, subtract 1.
            uint8_t curBitMask = static_cast<uint8_t>(0x01 << (lengthInBits_ - ( curByteNumber << 3 ) - 1));

            uint8_t * bitStreamArrayByte = bitStreamArray + curByteNumber; // move pointer to most significant byte
            while (bitStreamArrayByte >= bitStreamArray)
            {
                // Because above calculation causes the last bit to be bit 0 [LSB] of Byte 0 [LSBy], I don't have
                // to check in the following while-loop, whether I don't try to read too many bits.
                while (curBitMask > 0)
                {
                    // first setup serialInput_
                    ( ((*bitStreamArrayByte) & curBitMask) != 0 ) ?
                                SerialInput_::setPort() :
                                SerialInput_::clearPort();
                    // then read in current value at serialOutput_
                    (AvrInputOutput::HIGH == SerialOutput_::readPin()) ?
                              (*bitStreamArrayByte) |= curBitMask :      // set bit in array
                              (*bitStreamArrayByte) &= ~curBitMask;      // clear bit in array

                    curBitMask >>= 1; // next bit [lower significance]
                    // toggle here, as thus it shifts in 1 bit regardless of whether ShowRegisterClock_ was HIGH or LOW previously.
                    toggleTwice<ShiftRegisterClock_>();
                }
                // next byte
                --bitStreamArrayByte; // goto previous byte in array
                curBitMask = 0x01 << 7; // reset bitmask to most significant bit
            }
        }
    }
};

#endif // SHIFTREGISTER_HPP
