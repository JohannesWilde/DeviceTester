#ifndef ATMEGA328P_HPP
#define ATMEGA328P_HPP

// ATMEL ATMEGA328p
//
//                  +-\/-+
// Reset      PC6  1|    |28  PC5
//            PD0  2|    |27  PC4
//            PD1  3|    |26  PC3
//            PD2  4|    |25  PC2
// PWM+       PD3  5|    |24  PC1
//            PD4  6|    |23  PC0
//            VCC  7|    |22  GND
//            GND  8|    |21  AREF
//            PB6  9|    |20  AVCC
//            PB7 10|    |19  PB5
// PWM+       PD5 11|    |18  PB4
// PWM+       PD6 12|    |17  PB3  PWM
//            PD7 13|    |16  PB2  PWM
//            PB0 14|    |15  PB1  PWM
//                  +----+

#ifndef __AVR_ATmega328P__
#warning "This struct is for an Atmega328p - so for any real-world scenario this should also be #defined."
#endif

#include "avrinternalregister.hpp"
#include "avrioregister.hpp"
#include "avrpin.hpp"

struct Atmega328p
{
public:
    // you can access these registers - but only do so if using the higher level AvrIoRegister or even AvrPin
    // is really not sufficient.
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTB_REGISTER>::address, uint8_t> PortBInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINB_REGISTER>::address, uint8_t> PinBInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRB_REGISTER>::address, uint8_t> DdrBInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTC_REGISTER>::address, uint8_t> PortCInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINC_REGISTER>::address, uint8_t> PinCInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRC_REGISTER>::address, uint8_t> DdrCInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTD_REGISTER>::address, uint8_t> PortDInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PIND_REGISTER>::address, uint8_t> PinDInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRD_REGISTER>::address, uint8_t> DdrDInternal;

    // The three accessible registers - please note, that for B and C are only pins 0 - 5 are accessible from the outside.
    typedef AvrIoRegister<PortBInternal, DdrBInternal, PinBInternal> RegisterB;
    typedef AvrIoRegister<PortCInternal, DdrCInternal, PinCInternal> RegisterC;
    typedef AvrIoRegister<PortDInternal, DdrDInternal, PinDInternal> RegisterD;

    // The individual Arduino Pins.
    typedef AvrPin<RegisterD, PORTD0> D0;
    typedef AvrPin<RegisterD, PORTD1> D1;
    typedef AvrPin<RegisterD, PORTD2> D2;
    typedef AvrPin<RegisterD, PORTD3> D3;
    typedef AvrPin<RegisterD, PORTD4> D4;
    typedef AvrPin<RegisterD, PORTD5> D5;
    typedef AvrPin<RegisterD, PORTD6> D6;
    typedef AvrPin<RegisterD, PORTD7> D7;
    typedef AvrPin<RegisterB, PORTB0> B0;
    typedef AvrPin<RegisterB, PORTB1> B1;
    typedef AvrPin<RegisterB, PORTB2> B2;
    typedef AvrPin<RegisterB, PORTB3> B3;
    typedef AvrPin<RegisterB, PORTB4> B4;
    typedef AvrPin<RegisterB, PORTB5> B5;
    typedef AvrPin<RegisterC, PORTC0> C0;
    typedef AvrPin<RegisterC, PORTC1> C1;
    typedef AvrPin<RegisterC, PORTC2> C2;
    typedef AvrPin<RegisterC, PORTC3> C3;
    typedef AvrPin<RegisterC, PORTC4> C4;
    typedef AvrPin<RegisterC, PORTC5> C5;

    // convenience names
    typedef B5 LED_BUILTIN;
};

#endif // ATMEGA328P_HPP
