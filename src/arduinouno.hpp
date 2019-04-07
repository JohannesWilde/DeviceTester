// ATMEL ATMEGA328p
//
//                  +-\/-+
// Reset      PC6  1|    |28  PC5 (AI 5)
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

#include "atmega328p.hpp"

struct ArduinoUno : Atmega328p
{
public:
    // The individual Arduino Pins.
    typedef typename Atmega328p::B0 D8;
    typedef typename Atmega328p::B1 D9;
    typedef typename Atmega328p::B2 D10;
    typedef typename Atmega328p::B3 D11;
    typedef typename Atmega328p::B4 D12;
    typedef typename Atmega328p::B5 D13;
    typedef typename Atmega328p::C0 A0;
    typedef typename Atmega328p::C1 A1;
    typedef typename Atmega328p::C2 A2;
    typedef typename Atmega328p::C3 A3;
    typedef typename Atmega328p::C4 A4;
    typedef typename Atmega328p::C5 A5;
};

#endif // ARDUINOUNO_H
