// ATMEL ATMEGA328p
//
//                  +-\/-+
//            PC6  1|    |28  PC5 (AI 5)
//      (D 0) PD0  2|    |27  PC4 (AI 4)
//      (D 1) PD1  3|    |26  PC3 (AI 3)
//      (D 2) PD2  4|    |25  PC2 (AI 2)
// PWM+ (D 3) PD3  5|    |24  PC1 (AI 1)
//      (D 4) PD4  6|    |23  PC0 (AI 0)
//            VCC  7|    |22  GND
//            GND  8|    |21  AREF
//            PB6  9|    |20  AVCC
//            PB7 10|    |19  PB5 (D 13)
// PWM+ (D 5) PD5 11|    |18  PB4 (D 12)
// PWM+ (D 6) PD6 12|    |17  PB3 (D 11) PWM
//      (D 7) PD7 13|    |16  PB2 (D 10) PWM
//      (D 8) PB0 14|    |15  PB1 (D 9) PWM
//                  +----+

#ifndef ARDUINOUNO_HPP
#define ARDUINOUNO_HPP

#ifndef __AVR_ATmega328P__
#warning "An Arduino Uno typically has an Atmega328p - currently something else is #defined."
#endif

#include "avrinternalregister.hpp"
#include "avrioregister.hpp"
#include "avrpin.hpp"

struct ArduinoUno
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

    // The three accessible registers - please note, that B and C are only pins 0 - 5 accessible from the outside.
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
    typedef AvrPin<RegisterB, PORTB0> D8;
    typedef AvrPin<RegisterB, PORTB1> D9;
    typedef AvrPin<RegisterB, PORTB2> D10;
    typedef AvrPin<RegisterB, PORTB3> D11;
    typedef AvrPin<RegisterB, PORTB4> D12;
    typedef AvrPin<RegisterB, PORTB5> D13;
    typedef AvrPin<RegisterC, PORTC0> A0;
    typedef AvrPin<RegisterC, PORTC1> A1;
    typedef AvrPin<RegisterC, PORTC2> A2;
    typedef AvrPin<RegisterC, PORTC3> A3;
    typedef AvrPin<RegisterC, PORTC4> A4;
    typedef AvrPin<RegisterC, PORTC5> A5;

    // convenience names
    typedef D13 LED_BUILTIN;
};

#endif // ARDUINOUNO_H
