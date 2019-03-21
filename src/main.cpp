// ATMEL ATTINY84 / ARDUINO
//
//                           +-\/-+
//                     VCC  1|    |14  GND
//             (D 10)  PB0  2|    |13  AREF (D  0)
//             (D  9)  PB1  3|    |12  PA1  (D  1) 
//                     PB3  4|    |11  PA2  (D  2) 
//  PWM  INT0  (D  8)  PB2  5|    |10  PA3  (D  3) 
//  PWM        (D  7)  PA7  6|    |9   PA4  (D  4) 
//  PWM        (D  6)  PA6  7|    |8   PA5  (D  5)        PWM
//                           +----+

#define LED_TOP_1 8             // Indirektes Licht 1
#define LED_TOP_2 7             // Indirektes Licht 2
#define LED_TOP_3 6             // Indirektes Licht 3
#define LED_BOTTOM 5            // Direktes Licht
#define POTI_TOP_LEVEL_RANGE 3  // Hub des indirekten Lichts
#define POTI_TOP_LEVEL_MAX 2    // Grundhelligkeit des indirekten Lichts
#define POTI_BOTTOM_LEVEL_MAX 1 // Grundhelligkeit des direkten Lichts

//#define __AVR_ATmega328P__

#include <avr/io.h>
#include <util/delay.h>

int main()
{
    // Set bit 7 of PORTC as output
    DDRC=0x80;
    while (true)
    {
        // Invert the bit 7 of PORTC
        PORTC = PORTC ^ 0x80;

        // Wait 500ms (the leb connectod to the bit 7 of PORTC will blink at 1Hz)
        _delay_ms(500);
    }
    return 0;
}
