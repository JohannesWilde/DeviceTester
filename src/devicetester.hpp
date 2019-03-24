#ifndef DEVICETESTER_H
#define DEVICETESTER_H

#include <stdint.h>

// forward declarations
class AvrPin;

class DeviceTester
{
public:
    DeviceTester(AvrPin const * const button,
                 AvrPin const * const led);

    void enableLeds();
    void disableLeds();

private:
    AvrPin const * const pinButton;
    AvrPin const * const pinLed;
};

#endif // DEVICETESTER_H
