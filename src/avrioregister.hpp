#ifndef AVRIOREGISTER_HPP
#define AVRIOREGISTER_HPP

#include <stdint.h>
#include <avrinputoutput.hpp>
#include "avrinternalregister.hpp"

// template "methods" to check whether provided types are equal

// in case the template parameters differ, set value to -1
// in this case, is_same will try to initialize an array of size -1 and fail during compilation
template<typename T, typename U>
struct is_same_
{
    static const int value = -1;
};

// in case both template parameters are the same, set the value to 1
// in this case, is_same will initialize an array of size 1 and not fail during compilation
template<typename T>
struct is_same_<T, T>
{
    static const int value = 1;
};

// depending on whether T and U are the same type or not, this will not or will fail during compilation
// this method should be kept in this module, in order to know the failure context [otherwise the error
// message is rather uninformative]!
template<typename T, typename U>
struct is_same
{
    static const char unequalTypes[is_same_<T,U>::value];
};


// The actual register

template<typename PortRegister, typename DdrRegister, typename PinRegister>
struct AvrIoRegister
{
private:
    // all three registers should have the same Type, thus choose one.
    is_same<typename PortRegister::Type, typename PinRegister::Type> sameTypesPortPin;
    is_same<typename PortRegister::Type, typename DdrRegister::Type> sameTypesPortDdr;

public:
    typedef typename DdrRegister::Type Type;
    typedef PortRegister Port;
    typedef DdrRegister Ddr;
    typedef PinRegister Pin;

    // setType(PinType const pinType, uint8_t const bitMask) only set those bits, that are 0b1 in bitMask
    static void setType(AvrInputOutput::PinType const pinType, Type const bitMask)
    {
        switch (pinType)
        {
        case AvrInputOutput::OUTPUT_HIGH:
            DdrRegister::setBitMask(bitMask);       // output
            PortRegister::setBitMask(bitMask);      // high
            break;
        case AvrInputOutput::OUTPUT_LOW:
            DdrRegister::setBitMask(bitMask);       // output
            PortRegister::clearBitMask(bitMask);    // low
            break;
        case AvrInputOutput::INPUT:
            DdrRegister::clearBitMask(bitMask);     // input
            PortRegister::clearBitMask(bitMask);    // no pull-up
            break;
        case AvrInputOutput::INPUT_PULLUP:
            DdrRegister::clearBitMask(bitMask);     // input
            PortRegister::setBitMask(bitMask);      // pull-up [PUD in MCUCR needs to be low]
            // break;
        }
    }

    static void togglePort(Type const bitMask)
    {
        // Newer AVRs can toggle a PORT pin by writing a 1 [HIGH] to the respective PIN pin.
        // For very old AVRs thus below method will have to be changed...
//        PortRegister::toggleBitMask(bitMask);
        PinRegister::setBitMask(bitMask);
    }

    static void setPort(Type const bitMask)
    {
        PortRegister::setBitMask(bitMask);
    }

    static void clearPort(Type const bitMask)
    {
        PortRegister::clearBitMask(bitMask);
    }

    static typename PortRegister::Type readPort()
    {
        return PortRegister::readRegister();
    }

    static typename DdrRegister::Type readDdr()
    {
        return DdrRegister::readRegister();
    }

    static typename PinRegister::Type readPin()
    {
        return PinRegister::readRegister();
    }
};

#endif // AVRIOREGISTER_H
