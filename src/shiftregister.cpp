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
    disableOutput();
    serialInput->setType(AvrPin::OUTPUT_LOW);
    clearShiftRegister();
    showShiftRegister();
}

void ShiftRegister::enableOutput() const
{
    invertedOutputEnable->setType(AvrPin::OUTPUT_LOW);
}

void ShiftRegister::disableOutput() const
{
    invertedOutputEnable->setType(AvrPin::OUTPUT_HIGH);
}

void ShiftRegister::clearShiftRegister() const
{
    invertedShiftRegisterClear->setType(AvrPin::OUTPUT_LOW);
    invertedShiftRegisterClear->setType(AvrPin::OUTPUT_HIGH);
}

void ShiftRegister::showShiftRegister() const
{
    showRegisterClock->setType(AvrPin::OUTPUT_HIGH);
    showRegisterClock->setType(AvrPin::OUTPUT_LOW);
}

void ShiftRegister::shiftInBits(uint8_t const * const bitStreamArray) const
{
    if ( length > 0 )
    {
        // Because of integer division, one byte more will have to be used [unless length is a multiple of 8]
        uint8_t const curByteNumber = ( (length - 1) >> 3 ) + 1; // = divide by 8 [integer!]
        // Now find out, how many of the bits in the most significant byte will be used.
        // (length - ( (curByteNumber - 1) * 8 ) is the number of bits in the most significant byte;
        // because 0x01 has a bit at the first position alreade, subtract 1.
        uint8_t curBitMask = static_cast<uint8_t>(0x01 << (length - ( (curByteNumber - 1) << 3 ) - 1));

        uint8_t const * bitStreamArrayByte = bitStreamArray + curByteNumber; // move pointer to most significant byte
        while (bitStreamArrayByte >= bitStreamArray)
        {
            // Because above calculation causes the last bit to be bit 0 [LSB] of Byte 0 [LSBy], I don't have
            // to check in the following while-loop, whether I don't try to read to many bits.
            while (curBitMask > 0)
            {
                ( ((*bitStreamArrayByte) & curBitMask) != 0 ) ? serialInput->setType(AvrPin::OUTPUT_HIGH) : serialInput->setType(AvrPin::OUTPUT_LOW);
                curBitMask >>= 1; // next bit [lower significance]
            }
            // next byte
            --bitStreamArrayByte; // goto previous byte in array
            curBitMask = 0x01 << 7; // reset bitmask to most significant bit
        }
    }
}
