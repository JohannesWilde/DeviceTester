#ifndef PINSARDUINO_H
#define PINSARDUINO_H

/*
  Freely after pins_arduino.h - Pin definition functions for Arduino
*/
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <stdint.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

enum {
    LED_BUILTIN = 13,
    A0 = 14,
    A1 = 15,
    A2 = 16,
    A3 = 17,
    A4 = 18,
    A5 = 19
};

uint8_t volatile * const PROGMEM portAddressFromPinNumber[] = {
    &PORTD, /* 0 */
    &PORTD,
    &PORTD,
    &PORTD,
    &PORTD,
    &PORTD,
    &PORTD,
    &PORTD,
    &PORTB, /* 8 */
    &PORTB,
    &PORTB,
    &PORTB,
    &PORTB,
    &PORTB,
    &PORTC, /* 14 */
    &PORTC,
    &PORTC,
    &PORTC,
    &PORTC,
    &PORTC,
};

uint8_t volatile * const PROGMEM pinAddressFromPinNumber[] = {
    &PIND, /* 0 */
    &PIND,
    &PIND,
    &PIND,
    &PIND,
    &PIND,
    &PIND,
    &PIND,
    &PINB, /* 8 */
    &PINB,
    &PINB,
    &PINB,
    &PINB,
    &PINB,
    &PINC, /* 14 */
    &PINC,
    &PINC,
    &PINC,
    &PINC,
    &PINC,
};

uint8_t volatile * const PROGMEM ddAddressFromPinNumber[] = {
    &DDRD, /* 0 */
    &DDRD,
    &DDRD,
    &DDRD,
    &DDRD,
    &DDRD,
    &DDRD,
    &DDRD,
    &DDRB, /* 8 */
    &DDRB,
    &DDRB,
    &DDRB,
    &DDRB,
    &DDRB,
    &DDRC, /* 14 */
    &DDRC,
    &DDRC,
    &DDRC,
    &DDRC,
    &DDRC,
};

uint8_t const PROGMEM bitMaskFromPinNumber[] = {
    _BV(PORTD0), /* 0, port D */
    _BV(PORTD1),
    _BV(PORTD2),
    _BV(PORTD3),
    _BV(PORTD4),
    _BV(PORTD5),
    _BV(PORTD6),
    _BV(PORTD7),
    _BV(PORTB0), /* 8, port B */
    _BV(PORTB1),
    _BV(PORTB2),
    _BV(PORTB3),
    _BV(PORTB4),
    _BV(PORTB5),
    _BV(PORTC0), /* 14, port C */
    _BV(PORTC1),
    _BV(PORTC2),
    _BV(PORTC3),
    _BV(PORTC4),
    _BV(PORTC5),
};

#endif // PINSARDUINO_H
