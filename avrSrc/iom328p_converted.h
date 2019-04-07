/* Copyright (c) 2007 Atmel Corporation
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. 
*/

/* $Id: iom328p.h 2444 2014-08-11 22:10:47Z joerg_wunsch $ */

/* avr/iom328p.h - definitions for ATmega328P. */

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iom328p.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 


#ifndef _AVR_IOM328P_H_
#define _AVR_IOM328P_H_ 1

/* Registers and associated bit numbers */

#define PINB_REGISTER 0x03
#define PINB_TYPE uint8_t
#define PINB_ACCESS _SFR_IO8
#define PINB PINB_ACCESS(PINB_REGISTER)
#define PINB0 0
#define PINB1 1
#define PINB2 2
#define PINB3 3
#define PINB4 4
#define PINB5 5
#define PINB6 6
#define PINB7 7

#define DDRB_REGISTER 0x04
#define DDRB_TYPE uint8_t
#define DDRB_ACCESS _SFR_IO8
#define DDRB DDRB_ACCESS(DDRB_REGISTER)
#define DDB0 0
#define DDB1 1
#define DDB2 2
#define DDB3 3
#define DDB4 4
#define DDB5 5
#define DDB6 6
#define DDB7 7

#define PORTB_REGISTER 0x05
#define PORTB_TYPE uint8_t
#define PORTB_ACCESS _SFR_IO8
#define PORTB PORTB_ACCESS(PORTB_REGISTER)
#define PORTB0 0
#define PORTB1 1
#define PORTB2 2
#define PORTB3 3
#define PORTB4 4
#define PORTB5 5
#define PORTB6 6
#define PORTB7 7

#define PINC_REGISTER 0x06
#define PINC_TYPE uint8_t
#define PINC_ACCESS _SFR_IO8
#define PINC PINC_ACCESS(PINC_REGISTER)
#define PINC0 0
#define PINC1 1
#define PINC2 2
#define PINC3 3
#define PINC4 4
#define PINC5 5
#define PINC6 6

#define DDRC_REGISTER 0x07
#define DDRC_TYPE uint8_t
#define DDRC_ACCESS _SFR_IO8
#define DDRC DDRC_ACCESS(DDRC_REGISTER)
#define DDC0 0
#define DDC1 1
#define DDC2 2
#define DDC3 3
#define DDC4 4
#define DDC5 5
#define DDC6 6

#define PORTC_REGISTER 0x08
#define PORTC_TYPE uint8_t
#define PORTC_ACCESS _SFR_IO8
#define PORTC PORTC_ACCESS(PORTC_REGISTER)
#define PORTC0 0
#define PORTC1 1
#define PORTC2 2
#define PORTC3 3
#define PORTC4 4
#define PORTC5 5
#define PORTC6 6

#define PIND_REGISTER 0x09
#define PIND_TYPE uint8_t
#define PIND_ACCESS _SFR_IO8
#define PIND PIND_ACCESS(PIND_REGISTER)
#define PIND0 0
#define PIND1 1
#define PIND2 2
#define PIND3 3
#define PIND4 4
#define PIND5 5
#define PIND6 6
#define PIND7 7

#define DDRD_REGISTER 0x0A
#define DDRD_TYPE uint8_t
#define DDRD_ACCESS _SFR_IO8
#define DDRD DDRD_ACCESS(DDRD_REGISTER)
#define DDD0 0
#define DDD1 1
#define DDD2 2
#define DDD3 3
#define DDD4 4
#define DDD5 5
#define DDD6 6
#define DDD7 7

#define PORTD_REGISTER 0x0B
#define PORTD_TYPE uint8_t
#define PORTD_ACCESS _SFR_IO8
#define PORTD PORTD_ACCESS(PORTD_REGISTER)
#define PORTD0 0
#define PORTD1 1
#define PORTD2 2
#define PORTD3 3
#define PORTD4 4
#define PORTD5 5
#define PORTD6 6
#define PORTD7 7

#define TIFR0_REGISTER 0x15
#define TIFR0_TYPE uint8_t
#define TIFR0_ACCESS _SFR_IO8
#define TIFR0 TIFR0_ACCESS(TIFR0_REGISTER)
#define TOV0 0
#define OCF0A 1
#define OCF0B 2

#define TIFR1_REGISTER 0x16
#define TIFR1_TYPE uint8_t
#define TIFR1_ACCESS _SFR_IO8
#define TIFR1 TIFR1_ACCESS(TIFR1_REGISTER)
#define TOV1 0
#define OCF1A 1
#define OCF1B 2
#define ICF1 5

#define TIFR2_REGISTER 0x17
#define TIFR2_TYPE uint8_t
#define TIFR2_ACCESS _SFR_IO8
#define TIFR2 TIFR2_ACCESS(TIFR2_REGISTER)
#define TOV2 0
#define OCF2A 1
#define OCF2B 2

#define PCIFR_REGISTER 0x1B
#define PCIFR_TYPE uint8_t
#define PCIFR_ACCESS _SFR_IO8
#define PCIFR PCIFR_ACCESS(PCIFR_REGISTER)
#define PCIF0 0
#define PCIF1 1
#define PCIF2 2

#define EIFR_REGISTER 0x1C
#define EIFR_TYPE uint8_t
#define EIFR_ACCESS _SFR_IO8
#define EIFR EIFR_ACCESS(EIFR_REGISTER)
#define INTF0 0
#define INTF1 1

#define EIMSK_REGISTER 0x1D
#define EIMSK_TYPE uint8_t
#define EIMSK_ACCESS _SFR_IO8
#define EIMSK EIMSK_ACCESS(EIMSK_REGISTER)
#define INT0 0
#define INT1 1

#define GPIOR0_REGISTER 0x1E
#define GPIOR0_TYPE uint8_t
#define GPIOR0_ACCESS _SFR_IO8
#define GPIOR0 GPIOR0_ACCESS(GPIOR0_REGISTER)
#define GPIOR00 0
#define GPIOR01 1
#define GPIOR02 2
#define GPIOR03 3
#define GPIOR04 4
#define GPIOR05 5
#define GPIOR06 6
#define GPIOR07 7

#define EECR_REGISTER 0x1F
#define EECR_TYPE uint8_t
#define EECR_ACCESS _SFR_IO8
#define EECR EECR_ACCESS(EECR_REGISTER)
#define EERE 0
#define EEPE 1
#define EEMPE 2
#define EERIE 3
#define EEPM0 4
#define EEPM1 5

#define EEDR_REGISTER 0x20
#define EEDR_TYPE uint8_t
#define EEDR_ACCESS _SFR_IO8
#define EEDR EEDR_ACCESS(EEDR_REGISTER)
#define EEDR0 0
#define EEDR1 1
#define EEDR2 2
#define EEDR3 3
#define EEDR4 4
#define EEDR5 5
#define EEDR6 6
#define EEDR7 7

#define EEAR_REGISTER 0x21
#define EEAR_TYPE uint16_t
#define EEAR_ACCESS _SFR_IO16
#define EEAR EEAR_ACCESS(EEAR_REGISTER)

#define EEARL_REGISTER 0x21
#define EEARL_TYPE uint8_t
#define EEARL_ACCESS _SFR_IO8
#define EEARL EEARL_ACCESS(EEARL_REGISTER)
#define EEAR0 0
#define EEAR1 1
#define EEAR2 2
#define EEAR3 3
#define EEAR4 4
#define EEAR5 5
#define EEAR6 6
#define EEAR7 7

#define EEARH_REGISTER 0x22
#define EEARH_TYPE uint8_t
#define EEARH_ACCESS _SFR_IO8
#define EEARH EEARH_ACCESS(EEARH_REGISTER)
#define EEAR8 0
#define EEAR9 1

#define _EEPROM_REG_LOCATIONS_ 1F2021

#define GTCCR_REGISTER 0x23
#define GTCCR_TYPE uint8_t
#define GTCCR_ACCESS _SFR_IO8
#define GTCCR GTCCR_ACCESS(GTCCR_REGISTER)
#define PSRSYNC 0
#define PSRASY 1
#define TSM 7

#define TCCR0A_REGISTER 0x24
#define TCCR0A_TYPE uint8_t
#define TCCR0A_ACCESS _SFR_IO8
#define TCCR0A TCCR0A_ACCESS(TCCR0A_REGISTER)
#define WGM00 0
#define WGM01 1
#define COM0B0 4
#define COM0B1 5
#define COM0A0 6
#define COM0A1 7

#define TCCR0B_REGISTER 0x25
#define TCCR0B_TYPE uint8_t
#define TCCR0B_ACCESS _SFR_IO8
#define TCCR0B TCCR0B_ACCESS(TCCR0B_REGISTER)
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM02 3
#define FOC0B 6
#define FOC0A 7

#define TCNT0_REGISTER 0x26
#define TCNT0_TYPE uint8_t
#define TCNT0_ACCESS _SFR_IO8
#define TCNT0 TCNT0_ACCESS(TCNT0_REGISTER)
#define TCNT0_0 0
#define TCNT0_1 1
#define TCNT0_2 2
#define TCNT0_3 3
#define TCNT0_4 4
#define TCNT0_5 5
#define TCNT0_6 6
#define TCNT0_7 7

#define OCR0A_REGISTER 0x27
#define OCR0A_TYPE uint8_t
#define OCR0A_ACCESS _SFR_IO8
#define OCR0A OCR0A_ACCESS(OCR0A_REGISTER)
#define OCR0A_0 0
#define OCR0A_1 1
#define OCR0A_2 2
#define OCR0A_3 3
#define OCR0A_4 4
#define OCR0A_5 5
#define OCR0A_6 6
#define OCR0A_7 7

#define OCR0B_REGISTER 0x28
#define OCR0B_TYPE uint8_t
#define OCR0B_ACCESS _SFR_IO8
#define OCR0B OCR0B_ACCESS(OCR0B_REGISTER)
#define OCR0B_0 0
#define OCR0B_1 1
#define OCR0B_2 2
#define OCR0B_3 3
#define OCR0B_4 4
#define OCR0B_5 5
#define OCR0B_6 6
#define OCR0B_7 7

#define GPIOR1_REGISTER 0x2A
#define GPIOR1_TYPE uint8_t
#define GPIOR1_ACCESS _SFR_IO8
#define GPIOR1 GPIOR1_ACCESS(GPIOR1_REGISTER)
#define GPIOR10 0
#define GPIOR11 1
#define GPIOR12 2
#define GPIOR13 3
#define GPIOR14 4
#define GPIOR15 5
#define GPIOR16 6
#define GPIOR17 7

#define GPIOR2_REGISTER 0x2B
#define GPIOR2_TYPE uint8_t
#define GPIOR2_ACCESS _SFR_IO8
#define GPIOR2 GPIOR2_ACCESS(GPIOR2_REGISTER)
#define GPIOR20 0
#define GPIOR21 1
#define GPIOR22 2
#define GPIOR23 3
#define GPIOR24 4
#define GPIOR25 5
#define GPIOR26 6
#define GPIOR27 7

#define SPCR_REGISTER 0x2C
#define SPCR_TYPE uint8_t
#define SPCR_ACCESS _SFR_IO8
#define SPCR SPCR_ACCESS(SPCR_REGISTER)
#define SPR0 0
#define SPR1 1
#define CPHA 2
#define CPOL 3
#define MSTR 4
#define DORD 5
#define SPE 6
#define SPIE 7

#define SPSR_REGISTER 0x2D
#define SPSR_TYPE uint8_t
#define SPSR_ACCESS _SFR_IO8
#define SPSR SPSR_ACCESS(SPSR_REGISTER)
#define SPI2X 0
#define WCOL 6
#define SPIF 7

#define SPDR_REGISTER 0x2E
#define SPDR_TYPE uint8_t
#define SPDR_ACCESS _SFR_IO8
#define SPDR SPDR_ACCESS(SPDR_REGISTER)
#define SPDR0 0
#define SPDR1 1
#define SPDR2 2
#define SPDR3 3
#define SPDR4 4
#define SPDR5 5
#define SPDR6 6
#define SPDR7 7

#define ACSR_REGISTER 0x30
#define ACSR_TYPE uint8_t
#define ACSR_ACCESS _SFR_IO8
#define ACSR ACSR_ACCESS(ACSR_REGISTER)
#define ACIS0 0
#define ACIS1 1
#define ACIC 2
#define ACIE 3
#define ACI 4
#define ACO 5
#define ACBG 6
#define ACD 7

#define SMCR_REGISTER 0x33
#define SMCR_TYPE uint8_t
#define SMCR_ACCESS _SFR_IO8
#define SMCR SMCR_ACCESS(SMCR_REGISTER)
#define SE 0
#define SM0 1
#define SM1 2
#define SM2 3

#define MCUSR_REGISTER 0x34
#define MCUSR_TYPE uint8_t
#define MCUSR_ACCESS _SFR_IO8
#define MCUSR MCUSR_ACCESS(MCUSR_REGISTER)
#define PORF 0
#define EXTRF 1
#define BORF 2
#define WDRF 3

#define MCUCR_REGISTER 0x35
#define MCUCR_TYPE uint8_t
#define MCUCR_ACCESS _SFR_IO8
#define MCUCR MCUCR_ACCESS(MCUCR_REGISTER)
#define IVCE 0
#define IVSEL 1
#define PUD 4
#define BODSE 5
#define BODS 6

#define SPMCSR_REGISTER 0x37
#define SPMCSR_TYPE uint8_t
#define SPMCSR_ACCESS _SFR_IO8
#define SPMCSR SPMCSR_ACCESS(SPMCSR_REGISTER)
#define SELFPRGEN 0 /* only for backwards compatibility with previous
		     * avr-libc versions; not an official name */
#define SPMEN 0
#define PGERS 1
#define PGWRT 2
#define BLBSET 3
#define RWWSRE 4
#define SIGRD 5
#define RWWSB 6
#define SPMIE 7

#define WDTCSR_REGISTER 0x60
#define WDTCSR_TYPE uint8_t
#define WDTCSR_ACCESS _SFR_MEM8
#define WDTCSR WDTCSR_ACCESS(WDTCSR_REGISTER)
#define WDP0 0
#define WDP1 1
#define WDP2 2
#define WDE 3
#define WDCE 4
#define WDP3 5
#define WDIE 6
#define WDIF 7

#define CLKPR_REGISTER 0x61
#define CLKPR_TYPE uint8_t
#define CLKPR_ACCESS _SFR_MEM8
#define CLKPR CLKPR_ACCESS(CLKPR_REGISTER)
#define CLKPS0 0
#define CLKPS1 1
#define CLKPS2 2
#define CLKPS3 3
#define CLKPCE 7

#define PRR_REGISTER 0x64
#define PRR_TYPE uint8_t
#define PRR_ACCESS _SFR_MEM8
#define PRR PRR_ACCESS(PRR_REGISTER)
#define PRADC 0
#define PRUSART0 1
#define PRSPI 2
#define PRTIM1 3
#define PRTIM0 5
#define PRTIM2 6
#define PRTWI 7

#define __AVR_HAVE_PRR	((1<<PRADC)|(1<<PRUSART0)|(1<<PRSPI)|(1<<PRTIM1)|(1<<PRTIM0)|(1<<PRTIM2)|(1<<PRTWI))
#define __AVR_HAVE_PRR_PRADC
#define __AVR_HAVE_PRR_PRUSART0
#define __AVR_HAVE_PRR_PRSPI
#define __AVR_HAVE_PRR_PRTIM1
#define __AVR_HAVE_PRR_PRTIM0
#define __AVR_HAVE_PRR_PRTIM2
#define __AVR_HAVE_PRR_PRTWI

#define OSCCAL_REGISTER 0x66
#define OSCCAL_TYPE uint8_t
#define OSCCAL_ACCESS _SFR_MEM8
#define OSCCAL OSCCAL_ACCESS(OSCCAL_REGISTER)
#define CAL0 0
#define CAL1 1
#define CAL2 2
#define CAL3 3
#define CAL4 4
#define CAL5 5
#define CAL6 6
#define CAL7 7

#define PCICR_REGISTER 0x68
#define PCICR_TYPE uint8_t
#define PCICR_ACCESS _SFR_MEM8
#define PCICR PCICR_ACCESS(PCICR_REGISTER)
#define PCIE0 0
#define PCIE1 1
#define PCIE2 2

#define EICRA_REGISTER 0x69
#define EICRA_TYPE uint8_t
#define EICRA_ACCESS _SFR_MEM8
#define EICRA EICRA_ACCESS(EICRA_REGISTER)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define PCMSK0_REGISTER 0x6B
#define PCMSK0_TYPE uint8_t
#define PCMSK0_ACCESS _SFR_MEM8
#define PCMSK0 PCMSK0_ACCESS(PCMSK0_REGISTER)
#define PCINT0 0
#define PCINT1 1
#define PCINT2 2
#define PCINT3 3
#define PCINT4 4
#define PCINT5 5
#define PCINT6 6
#define PCINT7 7

#define PCMSK1_REGISTER 0x6C
#define PCMSK1_TYPE uint8_t
#define PCMSK1_ACCESS _SFR_MEM8
#define PCMSK1 PCMSK1_ACCESS(PCMSK1_REGISTER)
#define PCINT8 0
#define PCINT9 1
#define PCINT10 2
#define PCINT11 3
#define PCINT12 4
#define PCINT13 5
#define PCINT14 6

#define PCMSK2_REGISTER 0x6D
#define PCMSK2_TYPE uint8_t
#define PCMSK2_ACCESS _SFR_MEM8
#define PCMSK2 PCMSK2_ACCESS(PCMSK2_REGISTER)
#define PCINT16 0
#define PCINT17 1
#define PCINT18 2
#define PCINT19 3
#define PCINT20 4
#define PCINT21 5
#define PCINT22 6
#define PCINT23 7

#define TIMSK0_REGISTER 0x6E
#define TIMSK0_TYPE uint8_t
#define TIMSK0_ACCESS _SFR_MEM8
#define TIMSK0 TIMSK0_ACCESS(TIMSK0_REGISTER)
#define TOIE0 0
#define OCIE0A 1
#define OCIE0B 2

#define TIMSK1_REGISTER 0x6F
#define TIMSK1_TYPE uint8_t
#define TIMSK1_ACCESS _SFR_MEM8
#define TIMSK1 TIMSK1_ACCESS(TIMSK1_REGISTER)
#define TOIE1 0
#define OCIE1A 1
#define OCIE1B 2
#define ICIE1 5

#define TIMSK2_REGISTER 0x70
#define TIMSK2_TYPE uint8_t
#define TIMSK2_ACCESS _SFR_MEM8
#define TIMSK2 TIMSK2_ACCESS(TIMSK2_REGISTER)
#define TOIE2 0
#define OCIE2A 1
#define OCIE2B 2

#ifndef __ASSEMBLER__
#define ADC_REGISTER 0x78
#define ADC_TYPE uint16_t
#define ADC_ACCESS _SFR_MEM16
#define ADC ADC_ACCESS(ADC_REGISTER)
#endif
#define ADCW_REGISTER 0x78
#define ADCW_TYPE uint16_t
#define ADCW_ACCESS _SFR_MEM16
#define ADCW ADCW_ACCESS(ADCW_REGISTER)

#define ADCL_REGISTER 0x78
#define ADCL_TYPE uint8_t
#define ADCL_ACCESS _SFR_MEM8
#define ADCL ADCL_ACCESS(ADCL_REGISTER)
#define ADCL0 0
#define ADCL1 1
#define ADCL2 2
#define ADCL3 3
#define ADCL4 4
#define ADCL5 5
#define ADCL6 6
#define ADCL7 7

#define ADCH_REGISTER 0x79
#define ADCH_TYPE uint8_t
#define ADCH_ACCESS _SFR_MEM8
#define ADCH ADCH_ACCESS(ADCH_REGISTER)
#define ADCH0 0
#define ADCH1 1
#define ADCH2 2
#define ADCH3 3
#define ADCH4 4
#define ADCH5 5
#define ADCH6 6
#define ADCH7 7

#define ADCSRA_REGISTER 0x7A
#define ADCSRA_TYPE uint8_t
#define ADCSRA_ACCESS _SFR_MEM8
#define ADCSRA ADCSRA_ACCESS(ADCSRA_REGISTER)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE 3
#define ADIF 4
#define ADATE 5
#define ADSC 6
#define ADEN 7

#define ADCSRB_REGISTER 0x7B
#define ADCSRB_TYPE uint8_t
#define ADCSRB_ACCESS _SFR_MEM8
#define ADCSRB ADCSRB_ACCESS(ADCSRB_REGISTER)
#define ADTS0 0
#define ADTS1 1
#define ADTS2 2
#define ACME 6

#define ADMUX_REGISTER 0x7C
#define ADMUX_TYPE uint8_t
#define ADMUX_ACCESS _SFR_MEM8
#define ADMUX ADMUX_ACCESS(ADMUX_REGISTER)
#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define DIDR0_REGISTER 0x7E
#define DIDR0_TYPE uint8_t
#define DIDR0_ACCESS _SFR_MEM8
#define DIDR0 DIDR0_ACCESS(DIDR0_REGISTER)
#define ADC0D 0
#define ADC1D 1
#define ADC2D 2
#define ADC3D 3
#define ADC4D 4
#define ADC5D 5

#define DIDR1_REGISTER 0x7F
#define DIDR1_TYPE uint8_t
#define DIDR1_ACCESS _SFR_MEM8
#define DIDR1 DIDR1_ACCESS(DIDR1_REGISTER)
#define AIN0D 0
#define AIN1D 1

#define TCCR1A_REGISTER 0x80
#define TCCR1A_TYPE uint8_t
#define TCCR1A_ACCESS _SFR_MEM8
#define TCCR1A TCCR1A_ACCESS(TCCR1A_REGISTER)
#define WGM10 0
#define WGM11 1
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A1 7

#define TCCR1B_REGISTER 0x81
#define TCCR1B_TYPE uint8_t
#define TCCR1B_ACCESS _SFR_MEM8
#define TCCR1B TCCR1B_ACCESS(TCCR1B_REGISTER)
#define CS10 0
#define CS11 1
#define CS12 2
#define WGM12 3
#define WGM13 4
#define ICES1 6
#define ICNC1 7

#define TCCR1C_REGISTER 0x82
#define TCCR1C_TYPE uint8_t
#define TCCR1C_ACCESS _SFR_MEM8
#define TCCR1C TCCR1C_ACCESS(TCCR1C_REGISTER)
#define FOC1B 6
#define FOC1A 7

#define TCNT1_REGISTER 0x84
#define TCNT1_TYPE uint16_t
#define TCNT1_ACCESS _SFR_MEM16
#define TCNT1 TCNT1_ACCESS(TCNT1_REGISTER)

#define TCNT1L_REGISTER 0x84
#define TCNT1L_TYPE uint8_t
#define TCNT1L_ACCESS _SFR_MEM8
#define TCNT1L TCNT1L_ACCESS(TCNT1L_REGISTER)
#define TCNT1L0 0
#define TCNT1L1 1
#define TCNT1L2 2
#define TCNT1L3 3
#define TCNT1L4 4
#define TCNT1L5 5
#define TCNT1L6 6
#define TCNT1L7 7

#define TCNT1H_REGISTER 0x85
#define TCNT1H_TYPE uint8_t
#define TCNT1H_ACCESS _SFR_MEM8
#define TCNT1H TCNT1H_ACCESS(TCNT1H_REGISTER)
#define TCNT1H0 0
#define TCNT1H1 1
#define TCNT1H2 2
#define TCNT1H3 3
#define TCNT1H4 4
#define TCNT1H5 5
#define TCNT1H6 6
#define TCNT1H7 7

#define ICR1_REGISTER 0x86
#define ICR1_TYPE uint16_t
#define ICR1_ACCESS _SFR_MEM16
#define ICR1 ICR1_ACCESS(ICR1_REGISTER)

#define ICR1L_REGISTER 0x86
#define ICR1L_TYPE uint8_t
#define ICR1L_ACCESS _SFR_MEM8
#define ICR1L ICR1L_ACCESS(ICR1L_REGISTER)
#define ICR1L0 0
#define ICR1L1 1
#define ICR1L2 2
#define ICR1L3 3
#define ICR1L4 4
#define ICR1L5 5
#define ICR1L6 6
#define ICR1L7 7

#define ICR1H_REGISTER 0x87
#define ICR1H_TYPE uint8_t
#define ICR1H_ACCESS _SFR_MEM8
#define ICR1H ICR1H_ACCESS(ICR1H_REGISTER)
#define ICR1H0 0
#define ICR1H1 1
#define ICR1H2 2
#define ICR1H3 3
#define ICR1H4 4
#define ICR1H5 5
#define ICR1H6 6
#define ICR1H7 7

#define OCR1A_REGISTER 0x88
#define OCR1A_TYPE uint16_t
#define OCR1A_ACCESS _SFR_MEM16
#define OCR1A OCR1A_ACCESS(OCR1A_REGISTER)

#define OCR1AL_REGISTER 0x88
#define OCR1AL_TYPE uint8_t
#define OCR1AL_ACCESS _SFR_MEM8
#define OCR1AL OCR1AL_ACCESS(OCR1AL_REGISTER)
#define OCR1AL0 0
#define OCR1AL1 1
#define OCR1AL2 2
#define OCR1AL3 3
#define OCR1AL4 4
#define OCR1AL5 5
#define OCR1AL6 6
#define OCR1AL7 7

#define OCR1AH_REGISTER 0x89
#define OCR1AH_TYPE uint8_t
#define OCR1AH_ACCESS _SFR_MEM8
#define OCR1AH OCR1AH_ACCESS(OCR1AH_REGISTER)
#define OCR1AH0 0
#define OCR1AH1 1
#define OCR1AH2 2
#define OCR1AH3 3
#define OCR1AH4 4
#define OCR1AH5 5
#define OCR1AH6 6
#define OCR1AH7 7

#define OCR1B_REGISTER 0x8A
#define OCR1B_TYPE uint16_t
#define OCR1B_ACCESS _SFR_MEM16
#define OCR1B OCR1B_ACCESS(OCR1B_REGISTER)

#define OCR1BL_REGISTER 0x8A
#define OCR1BL_TYPE uint8_t
#define OCR1BL_ACCESS _SFR_MEM8
#define OCR1BL OCR1BL_ACCESS(OCR1BL_REGISTER)
#define OCR1BL0 0
#define OCR1BL1 1
#define OCR1BL2 2
#define OCR1BL3 3
#define OCR1BL4 4
#define OCR1BL5 5
#define OCR1BL6 6
#define OCR1BL7 7

#define OCR1BH_REGISTER 0x8B
#define OCR1BH_TYPE uint8_t
#define OCR1BH_ACCESS _SFR_MEM8
#define OCR1BH OCR1BH_ACCESS(OCR1BH_REGISTER)
#define OCR1BH0 0
#define OCR1BH1 1
#define OCR1BH2 2
#define OCR1BH3 3
#define OCR1BH4 4
#define OCR1BH5 5
#define OCR1BH6 6
#define OCR1BH7 7

#define TCCR2A_REGISTER 0xB0
#define TCCR2A_TYPE uint8_t
#define TCCR2A_ACCESS _SFR_MEM8
#define TCCR2A TCCR2A_ACCESS(TCCR2A_REGISTER)
#define WGM20 0
#define WGM21 1
#define COM2B0 4
#define COM2B1 5
#define COM2A0 6
#define COM2A1 7

#define TCCR2B_REGISTER 0xB1
#define TCCR2B_TYPE uint8_t
#define TCCR2B_ACCESS _SFR_MEM8
#define TCCR2B TCCR2B_ACCESS(TCCR2B_REGISTER)
#define CS20 0
#define CS21 1
#define CS22 2
#define WGM22 3
#define FOC2B 6
#define FOC2A 7

#define TCNT2_REGISTER 0xB2
#define TCNT2_TYPE uint8_t
#define TCNT2_ACCESS _SFR_MEM8
#define TCNT2 TCNT2_ACCESS(TCNT2_REGISTER)
#define TCNT2_0 0
#define TCNT2_1 1
#define TCNT2_2 2
#define TCNT2_3 3
#define TCNT2_4 4
#define TCNT2_5 5
#define TCNT2_6 6
#define TCNT2_7 7

#define OCR2A_REGISTER 0xB3
#define OCR2A_TYPE uint8_t
#define OCR2A_ACCESS _SFR_MEM8
#define OCR2A OCR2A_ACCESS(OCR2A_REGISTER)
#define OCR2_0 0
#define OCR2_1 1
#define OCR2_2 2
#define OCR2_3 3
#define OCR2_4 4
#define OCR2_5 5
#define OCR2_6 6
#define OCR2_7 7

#define OCR2B_REGISTER 0xB4
#define OCR2B_TYPE uint8_t
#define OCR2B_ACCESS _SFR_MEM8
#define OCR2B OCR2B_ACCESS(OCR2B_REGISTER)
#define OCR2_0 0
#define OCR2_1 1
#define OCR2_2 2
#define OCR2_3 3
#define OCR2_4 4
#define OCR2_5 5
#define OCR2_6 6
#define OCR2_7 7

#define ASSR_REGISTER 0xB6
#define ASSR_TYPE uint8_t
#define ASSR_ACCESS _SFR_MEM8
#define ASSR ASSR_ACCESS(ASSR_REGISTER)
#define TCR2BUB 0
#define TCR2AUB 1
#define OCR2BUB 2
#define OCR2AUB 3
#define TCN2UB 4
#define AS2 5
#define EXCLK 6

#define TWBR_REGISTER 0xB8
#define TWBR_TYPE uint8_t
#define TWBR_ACCESS _SFR_MEM8
#define TWBR TWBR_ACCESS(TWBR_REGISTER)
#define TWBR0 0
#define TWBR1 1
#define TWBR2 2
#define TWBR3 3
#define TWBR4 4
#define TWBR5 5
#define TWBR6 6
#define TWBR7 7

#define TWSR_REGISTER 0xB9
#define TWSR_TYPE uint8_t
#define TWSR_ACCESS _SFR_MEM8
#define TWSR TWSR_ACCESS(TWSR_REGISTER)
#define TWPS0 0
#define TWPS1 1
#define TWS3 3
#define TWS4 4
#define TWS5 5
#define TWS6 6
#define TWS7 7

#define TWAR_REGISTER 0xBA
#define TWAR_TYPE uint8_t
#define TWAR_ACCESS _SFR_MEM8
#define TWAR TWAR_ACCESS(TWAR_REGISTER)
#define TWGCE 0
#define TWA0 1
#define TWA1 2
#define TWA2 3
#define TWA3 4
#define TWA4 5
#define TWA5 6
#define TWA6 7

#define TWDR_REGISTER 0xBB
#define TWDR_TYPE uint8_t
#define TWDR_ACCESS _SFR_MEM8
#define TWDR TWDR_ACCESS(TWDR_REGISTER)
#define TWD0 0
#define TWD1 1
#define TWD2 2
#define TWD3 3
#define TWD4 4
#define TWD5 5
#define TWD6 6
#define TWD7 7

#define TWCR_REGISTER 0xBC
#define TWCR_TYPE uint8_t
#define TWCR_ACCESS _SFR_MEM8
#define TWCR TWCR_ACCESS(TWCR_REGISTER)
#define TWIE 0
#define TWEN 2
#define TWWC 3
#define TWSTO 4
#define TWSTA 5
#define TWEA 6
#define TWINT 7

#define TWAMR_REGISTER 0xBD
#define TWAMR_TYPE uint8_t
#define TWAMR_ACCESS _SFR_MEM8
#define TWAMR TWAMR_ACCESS(TWAMR_REGISTER)
#define TWAM0 0
#define TWAM1 1
#define TWAM2 2
#define TWAM3 3
#define TWAM4 4
#define TWAM5 5
#define TWAM6 6

#define UCSR0A_REGISTER 0xC0
#define UCSR0A_TYPE uint8_t
#define UCSR0A_ACCESS _SFR_MEM8
#define UCSR0A UCSR0A_ACCESS(UCSR0A_REGISTER)
#define MPCM0 0
#define U2X0 1
#define UPE0 2
#define DOR0 3
#define FE0 4
#define UDRE0 5
#define TXC0 6
#define RXC0 7

#define UCSR0B_REGISTER 0xC1
#define UCSR0B_TYPE uint8_t
#define UCSR0B_ACCESS _SFR_MEM8
#define UCSR0B UCSR0B_ACCESS(UCSR0B_REGISTER)
#define TXB80 0
#define RXB80 1
#define UCSZ02 2
#define TXEN0 3
#define RXEN0 4
#define UDRIE0 5
#define TXCIE0 6
#define RXCIE0 7

#define UCSR0C_REGISTER 0xC2
#define UCSR0C_TYPE uint8_t
#define UCSR0C_ACCESS _SFR_MEM8
#define UCSR0C UCSR0C_ACCESS(UCSR0C_REGISTER)
#define UCPOL0 0
#define UCSZ00 1
#define UCPHA0 1
#define UCSZ01 2
#define UDORD0 2
#define USBS0 3
#define UPM00 4
#define UPM01 5
#define UMSEL00 6
#define UMSEL01 7

#define UBRR0_REGISTER 0xC4
#define UBRR0_TYPE uint16_t
#define UBRR0_ACCESS _SFR_MEM16
#define UBRR0 UBRR0_ACCESS(UBRR0_REGISTER)

#define UBRR0L_REGISTER 0xC4
#define UBRR0L_TYPE uint8_t
#define UBRR0L_ACCESS _SFR_MEM8
#define UBRR0L UBRR0L_ACCESS(UBRR0L_REGISTER)
#define UBRR0_0 0
#define UBRR0_1 1
#define UBRR0_2 2
#define UBRR0_3 3
#define UBRR0_4 4
#define UBRR0_5 5
#define UBRR0_6 6
#define UBRR0_7 7

#define UBRR0H_REGISTER 0xC5
#define UBRR0H_TYPE uint8_t
#define UBRR0H_ACCESS _SFR_MEM8
#define UBRR0H UBRR0H_ACCESS(UBRR0H_REGISTER)
#define UBRR0_8 0
#define UBRR0_9 1
#define UBRR0_10 2
#define UBRR0_11 3

#define UDR0_REGISTER 0xC6
#define UDR0_TYPE uint8_t
#define UDR0_ACCESS _SFR_MEM8
#define UDR0 UDR0_ACCESS(UDR0_REGISTER)
#define UDR0_0 0
#define UDR0_1 1
#define UDR0_2 2
#define UDR0_3 3
#define UDR0_4 4
#define UDR0_5 5
#define UDR0_6 6
#define UDR0_7 7



/* Interrupt Vectors */
/* Interrupt Vector 0 is the reset vector. */

#define INT0_vect_num     1
#define INT0_vect         _VECTOR(1)   /* External Interrupt Request 0 */

#define INT1_vect_num     2
#define INT1_vect         _VECTOR(2)   /* External Interrupt Request 1 */

#define PCINT0_vect_num   3
#define PCINT0_vect       _VECTOR(3)   /* Pin Change Interrupt Request 0 */

#define PCINT1_vect_num   4
#define PCINT1_vect       _VECTOR(4)   /* Pin Change Interrupt Request 0 */

#define PCINT2_vect_num   5
#define PCINT2_vect       _VECTOR(5)   /* Pin Change Interrupt Request 1 */

#define WDT_vect_num      6
#define WDT_vect          _VECTOR(6)   /* Watchdog Time-out Interrupt */

#define TIMER2_COMPA_vect_num 7
#define TIMER2_COMPA_vect _VECTOR(7)   /* Timer/Counter2 Compare Match A */

#define TIMER2_COMPB_vect_num 8
#define TIMER2_COMPB_vect _VECTOR(8)   /* Timer/Counter2 Compare Match A */

#define TIMER2_OVF_vect_num   9
#define TIMER2_OVF_vect   _VECTOR(9)   /* Timer/Counter2 Overflow */

#define TIMER1_CAPT_vect_num  10
#define TIMER1_CAPT_vect  _VECTOR(10)  /* Timer/Counter1 Capture Event */

#define TIMER1_COMPA_vect_num 11
#define TIMER1_COMPA_vect _VECTOR(11)  /* Timer/Counter1 Compare Match A */

#define TIMER1_COMPB_vect_num 12
#define TIMER1_COMPB_vect _VECTOR(12)  /* Timer/Counter1 Compare Match B */ 

#define TIMER1_OVF_vect_num   13
#define TIMER1_OVF_vect   _VECTOR(13)  /* Timer/Counter1 Overflow */

#define TIMER0_COMPA_vect_num 14
#define TIMER0_COMPA_vect _VECTOR(14)  /* TimerCounter0 Compare Match A */

#define TIMER0_COMPB_vect_num 15
#define TIMER0_COMPB_vect _VECTOR(15)  /* TimerCounter0 Compare Match B */

#define TIMER0_OVF_vect_num  16
#define TIMER0_OVF_vect   _VECTOR(16)  /* Timer/Couner0 Overflow */

#define SPI_STC_vect_num  17
#define SPI_STC_vect      _VECTOR(17)  /* SPI Serial Transfer Complete */

#define USART_RX_vect_num 18
#define USART_RX_vect     _VECTOR(18)  /* USART Rx Complete */

#define USART_UDRE_vect_num   19
#define USART_UDRE_vect   _VECTOR(19)  /* USART, Data Register Empty */

#define USART_TX_vect_num 20
#define USART_TX_vect     _VECTOR(20)  /* USART Tx Complete */

#define ADC_vect_num      21
#define ADC_vect          _VECTOR(21)  /* ADC Conversion Complete */

#define EE_READY_vect_num 22
#define EE_READY_vect     _VECTOR(22)  /* EEPROM Ready */

#define ANALOG_COMP_vect_num  23
#define ANALOG_COMP_vect  _VECTOR(23)  /* Analog Comparator */

#define TWI_vect_num      24
#define TWI_vect          _VECTOR(24)  /* Two-wire Serial Interface */

#define SPM_READY_vect_num    25
#define SPM_READY_vect    _VECTOR(25)  /* Store Program Memory Read */

#define _VECTORS_SIZE (26 * 4)



/* Constants */
#define SPM_PAGESIZE 128
#define RAMSTART     (0x100)
#define RAMEND       0x8FF     /* Last On-Chip SRAM Location */
#define XRAMSIZE     0
#define XRAMEND      RAMEND
#define E2END        0x3FF
#define E2PAGESIZE   4
#define FLASHEND     0x7FFF



/* Fuses */
#define FUSE_MEMORY_SIZE 3

/* Low Fuse Byte */
#define FUSE_CKSEL0 (unsigned char)~_BV(0)  /* Select Clock Source */
#define FUSE_CKSEL1 (unsigned char)~_BV(1)  /* Select Clock Source */
#define FUSE_CKSEL2 (unsigned char)~_BV(2)  /* Select Clock Source */
#define FUSE_CKSEL3 (unsigned char)~_BV(3)  /* Select Clock Source */
#define FUSE_SUT0   (unsigned char)~_BV(4)  /* Select start-up time */
#define FUSE_SUT1   (unsigned char)~_BV(5)  /* Select start-up time */
#define FUSE_CKOUT  (unsigned char)~_BV(6)  /* Clock output */
#define FUSE_CKDIV8 (unsigned char)~_BV(7) /* Divide clock by 8 */
#define LFUSE_DEFAULT (FUSE_CKSEL0 & FUSE_CKSEL2 & FUSE_CKSEL3 & FUSE_SUT0 & FUSE_CKDIV8)

/* High Fuse Byte */
#define FUSE_BOOTRST (unsigned char)~_BV(0)
#define FUSE_BOOTSZ0 (unsigned char)~_BV(1)
#define FUSE_BOOTSZ1 (unsigned char)~_BV(2)
#define FUSE_EESAVE    (unsigned char)~_BV(3)  /* EEPROM memory is preserved through chip erase */
#define FUSE_WDTON     (unsigned char)~_BV(4)  /* Watchdog Timer Always On */
#define FUSE_SPIEN     (unsigned char)~_BV(5)  /* Enable Serial programming and Data Downloading */
#define FUSE_DWEN      (unsigned char)~_BV(6)  /* debugWIRE Enable */
#define FUSE_RSTDISBL  (unsigned char)~_BV(7)  /* External reset disable */
#define HFUSE_DEFAULT (FUSE_BOOTSZ0 & FUSE_BOOTSZ1 & FUSE_SPIEN)

/* Extended Fuse Byte */
#define FUSE_BODLEVEL0 (unsigned char)~_BV(0)  /* Brown-out Detector trigger level */
#define FUSE_BODLEVEL1 (unsigned char)~_BV(1)  /* Brown-out Detector trigger level */
#define FUSE_BODLEVEL2 (unsigned char)~_BV(2)  /* Brown-out Detector trigger level */
#define EFUSE_DEFAULT  (0xFF)



/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST 


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x95
#if defined(__AVR_ATmega328__)
#  define SIGNATURE_2 0x14
#else /* ATmega328P */
#  define SIGNATURE_2 0x0F
#endif

#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_ADC (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_PWR_SAVE (0x03<<1)
#define SLEEP_MODE_STANDBY (0x06<<1)
#define SLEEP_MODE_EXT_STANDBY (0x07<<1)

#endif  /* _AVR_IOM328P_H_ */
