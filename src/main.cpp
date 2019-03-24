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

#define LED_TOP_1 8             // Indirektes Licht 1
#define LED_TOP_2 7             // Indirektes Licht 2
#define LED_TOP_3 6             // Indirektes Licht 3
#define LED_BOTTOM 5            // Direktes Licht
#define POTI_TOP_LEVEL_RANGE 3  // Hub des indirekten Lichts
#define POTI_TOP_LEVEL_MAX 2    // Grundhelligkeit des indirekten Lichts
#define POTI_BOTTOM_LEVEL_MAX 1 // Grundhelligkeit des direkten Lichts

//#define __AVR_ATmega328P__   - find out, hwere this is defined before!

#include <avr/io.h>
#include <util/delay.h>

int main()
{
    // Set bit 7 of PORTC as output
    DDRB=0x01 << 5;
    while (true)
    {
        // Invert the bit 7 of PORTC
        PORTB = PORTB ^ (0x01 << 5);

        // Wait 500ms (the leb connectod to the bit 7 of PORTC will blink at 1Hz)
        _delay_ms(500);
    }
    return 0;
}
