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
    D0 = 0,
    D1 = 1,
    D2 = 2,
    D3 = 3,
    D4 = 4,
    D5 = 5,
    D6 = 6,
    D7 = 7,
    D8 = 8,
    D9 = 9,
    D10 = 10,
    D11 = 11,
    D12 = 12,
    D13 = 13,
    A0 = 14,
    A1 = 15,
    A2 = 16,
    A3 = 17,
    A4 = 18,
    A5 = 19
};

uint8_t volatile * const portAddressFromPinNumber[] = {
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


/*
 * ATmega328p Manual:
 * "18.2.2 Toggling the Pin
 * Writing a '1' to PINxn toggles the value of PORTxn, independent on the value of DDRxn. The SBI
 * instruction can be used to toggle one single bit in a port."
 *
 * This however can also be achieved by XOR-ing the respective PORTxn with 0b1 - so it is prohibited
 * here by declaring the volatile value pointed to as const [i.e. not constant but unmodifyable].
 * This might not be as fast as a single-instruction "sbi PINx, n" - but backward-compatible.
 */

uint8_t const volatile * const pinAddressFromPinNumber[] = {
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

uint8_t volatile * const ddAddressFromPinNumber[] = {
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

uint8_t const bitNumberFromPinNumber[] = {
    PORTD0, /* 0, port D */
    PORTD1,
    PORTD2,
    PORTD3,
    PORTD4,
    PORTD5,
    PORTD6,
    PORTD7,
    PORTB0, /* 8, port B */
    PORTB1,
    PORTB2,
    PORTB3,
    PORTB4,
    PORTB5,
    PORTC0, /* 14, port C */
    PORTC1,
    PORTC2,
    PORTC3,
    PORTC4,
    PORTC5,
};

uint8_t const bitMaskFromPinNumber[] = {
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[0])), /* 0, port D */
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[1])),
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[2])),
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[3])),
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[4])),
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[5])),
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[6])),
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[7])),
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[0])), /* 8, port B */
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[1])),
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[2])),
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[3])),
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[4])),
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[5])),
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[0])), /* 14, port C */
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[1])),
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[2])),
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[3])),
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[4])),
    static_cast<uint8_t const>(_BV(bitNumberFromPinNumber[5])),
};

#endif // PINSARDUINO_H
