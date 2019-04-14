// this is only for the QtCreator to find the correct highlighting - this is already defined somewhere before
#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "arduinouno.hpp"
#include "devicetester.hpp"

int main()
{
    typedef ArduinoUno arduinoUno;
    typedef DeviceTester<arduinoUno::A4,
                        arduinoUno::A5,
                        arduinoUno::D2,
                        arduinoUno::D3,
                        arduinoUno::D4,
                        arduinoUno::D5,
                        arduinoUno::D6,
                        arduinoUno::D7,
                        arduinoUno::D8,
                        arduinoUno::D9,
                        arduinoUno::D10,
                        arduinoUno::D11,
                        arduinoUno::D12,
                        arduinoUno::D13,
                        arduinoUno::A0,
                        arduinoUno::A1,
                        arduinoUno::A2,
                        arduinoUno::A3> deviceTester;

    deviceTester::enableLeds();

    typedef typename deviceTester::DevicePin7 GND;
    typedef typename deviceTester::DevicePin9 nSRCLR;
    typedef typename deviceTester::DevicePin10 SRCLK;
    typedef typename deviceTester::DevicePin11 RCLK;
    typedef typename deviceTester::DevicePin12 nOE;
    typedef typename deviceTester::DevicePin13 SER;
    typedef typename deviceTester::DevicePin15 VCC;

    // supply voltage
    GND::setType(AvrInputOutput::OUTPUT_LOW);
    VCC::setType(AvrInputOutput::OUTPUT_HIGH);

    // pin setup
    nOE::setType(AvrInputOutput::OUTPUT_LOW); // enable  output
    RCLK::setType(AvrInputOutput::OUTPUT_LOW);
    SRCLK::setType(AvrInputOutput::OUTPUT_HIGH);
    nSRCLR::setType(AvrInputOutput::OUTPUT_HIGH); // do not clear

    // shift in 0xff
    SER::setType(AvrInputOutput::OUTPUT_HIGH);
    for (uint8_t pinNumber = 0; pinNumber < 8; ++pinNumber)
    {
        SRCLK::setPort();
        SRCLK::clearPort();
    }
    // clear SER
    SER::clearPort();
    // show shift-in value
    RCLK::clearPort();
    RCLK::setPort();

    // ---------------
    // now clear the shift register
    nSRCLR::clearPort();
    // show cleared
    RCLK::clearPort();
    RCLK::setPort();

    // should be cleared now, so take away the clear-signal
    nSRCLR::setPort();
    // show cleared
    RCLK::clearPort();
    RCLK::setPort();

}
