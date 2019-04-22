#ifndef SHIFTREGISTERTESTER_HPP
#define SHIFTREGISTERTESTER_HPP

#include "devicetester.hpp"
#include "ArduinoDrivers/avrinputoutput.hpp"
#include "ArduinoDrivers/avrpin.hpp"
#include "ArduinoDrivers/dummytypes.hpp"

template< typename Button_,
          typename Led_,
          typename Gnd_,
          typename Vcc_,
          typename ShiftRegisterDriver_>
struct ShiftRegisterTester :
        public DeviceTester<Button_,
                            Led_,
                            Gnd_,
                            Vcc_,
                            typename ShiftRegisterDriver_::ShiftRegisterClock,
                            typename ShiftRegisterDriver_::SerialOutput,
                            typename ShiftRegisterDriver_::SerialInput,
                            DummyAvrPin1,
                            DummyAvrPin1,
                            DummyAvrPin1,
                            DummyAvrPin1,
                            DummyAvrPin1,
                            DummyAvrPin1,
                            DummyAvrPin1,
                            DummyAvrPin1,
                            DummyAvrPin1,
                            DummyAvrPin1,
                            DummyAvrPin1>
{
protected:
    typedef DeviceTester<Button_,
                        Led_,
                        Gnd_,
                        Vcc_,
                        typename ShiftRegisterDriver_::ShiftRegisterClock,
                        typename ShiftRegisterDriver_::SerialOutput,
                        typename ShiftRegisterDriver_::SerialInput,
                        DummyAvrPin1,
                        DummyAvrPin1,
                        DummyAvrPin1,
                        DummyAvrPin1,
                        DummyAvrPin1,
                        DummyAvrPin1,
                        DummyAvrPin1,
                        DummyAvrPin1,
                        DummyAvrPin1,
                        DummyAvrPin1,
                        DummyAvrPin1> DeviceTester_;
public:
    // make the pins publically available
    typedef ShiftRegisterDriver_ ShiftRegisterDriver;
    typedef Gnd_ GndPin;
    typedef Vcc_ VccPin;
    typedef typename ShiftRegisterDriver_::ShiftRegisterClock ShiftRegisterClock;
    typedef typename ShiftRegisterDriver_::SerialOutput SerialOutput;
    typedef typename ShiftRegisterDriver_::SerialInput SerialInput;

    // this will reconfigure the ports - so set the sheftRegister driver after having called this.
    static void initialize()
    {
        DeviceTester_::initialize(AvrInputOutput::OUTPUT_LOW,  // Gnd
                                  AvrInputOutput::OUTPUT_HIGH, // Vcc
                                  AvrInputOutput::OUTPUT_LOW,  // ShiftRegisterClock
                                  AvrInputOutput::INPUT,       // SerialOutput
                                  AvrInputOutput::OUTPUT_LOW,  // SerialInput
                                  AvrInputOutput::INPUT,        // ----------------------------------
                                  AvrInputOutput::INPUT,        // values for dummy-pins should be meaningsless
                                  AvrInputOutput::INPUT,        // the safest guess however is INPUT [no current in or out].
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT
                                  );
    }

    static bool checkSerialOutput(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<SerialOutput>(pinState);
    }

    static bool checkSerialInput(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<SerialInput>(pinState);
    }

    static bool checkShiftRegisterClock(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<ShiftRegisterClock>(pinState);
    }

    struct TestResult : DeviceTester_::TestResult
    {
        TestResult () :
            DeviceTester_::TestResult(),
            turnOff(false),
            turnOn(false),
            clearShiftRegister(false),
            shiftInAndOutBits(false)
        {
            // intentionally left empty
        }

        bool turnOff : 1;
        bool turnOn : 1;
        bool clearShiftRegister : 1;
        bool shiftInAndOutBits : 1;
    };

    static TestResult test()
    {
        // test result
        TestResult testResult;
        turnOnDevice();

        testResult.turnOn = testTurnOn();
        testResult.turnOff = testTurnOff();

        testResult.clearShiftRegister = testClearShiftRegister();

        testResult.shiftInAndOutBits = testShiftInAndOutBits();

        // set test success
        if (testResult.turnOff &&
            testResult.turnOn &&
            testResult.clearShiftRegister &&
            testResult.shiftInAndOutBits)
        {
            testResult.success = true;
        }

        // finally turn the device off
        turnOffDevice();
        return testResult;
    }

    static void turnOffDevice()
    {
        ShiftRegisterDriver_::turnOff();
        Vcc_::clearPort();
        DeviceTester_::turnOffDevice();
    }

    static void turnOnDevice()
    {
        DeviceTester_::turnOnDevice();
        Vcc_::setPort();
        ShiftRegisterDriver_::turnOn();
    }

    // all test routines expect the shiftRegisterDriver to be initialized,
    // i.e. ShiftRegisterClock LOW, SerialInput LOW, SerialOutput LOW and
    // the internal register to be 0x00.

    static bool testTurnOn()
    {
        // init
        bool testSuccess = false;
        // function under test
        ShiftRegisterDriver_::turnOn();
        bool readBack1 = true;
        readBack1 = readBack1 && checkShiftRegisterClock(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkSerialInput(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkSerialOutput(AvrInputOutput::LOW);

        // read out internal shift register value
        uint8_t readBack0 = 0xff;
        ShiftRegisterDriver_::template shiftOutBits<ShiftRegisterDriver_::LENGTH>(&readBack0);

        if (0x00 == readBack0 && readBack1)
        {
            testSuccess = true;
        }

        ShiftRegisterDriver_::turnOn();
        return testSuccess;
    }

    static bool testTurnOff()
    {
        // init
        bool testSuccess = false;
        // function under test
        ShiftRegisterDriver_::turnOff();
        bool readBack1 = true;
        readBack1 = readBack1 && checkShiftRegisterClock(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkSerialInput(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkSerialOutput(AvrInputOutput::LOW);

        // read out internal shift register value
        uint8_t readBack0 = 0xff;
        ShiftRegisterDriver_::template shiftOutBits<ShiftRegisterDriver_::LENGTH>(&readBack0);

        if (0x00 == readBack0 && readBack1)
        {
            testSuccess = true;
        }

        ShiftRegisterDriver_::turnOn();
        return testSuccess;
    }

    static bool testClearShiftRegister()
    {
        bool testSuccess = false;
        // shift in something to clear first
        uint8_t const inputData = 0xff;
        ShiftRegisterDriver_::template shiftInBits<ShiftRegisterDriver_::LENGTH>(&inputData);
        // consistency check whether successfully shifted in
        bool readBack1 = checkSerialOutput(AvrInputOutput::HIGH);

        // function under test
        ShiftRegisterDriver_::clearShiftRegister();

        readBack1 = readBack1 && checkSerialOutput(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkSerialInput(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkShiftRegisterClock(AvrInputOutput::LOW);

        uint8_t shiftregisterContent = 0xff;
        ShiftRegisterDriver_::template shiftOutBits<ShiftRegisterDriver_::LENGTH>(&shiftregisterContent);

        if (readBack1 && (0x00 == shiftregisterContent))
        {
            testSuccess = true;
        }

        ShiftRegisterDriver_::turnOn();
        return testSuccess;
    }

    static bool testShiftInAndOutBits()
    {
        DeviceTester_::enableLeds();

        bool testSuccess = false;

        uint8_t const data0 = 0xaa;
        uint8_t const data1 = 0x23;
        uint8_t const data2 = 0x0f;
        // function under test - 0
        ShiftRegisterDriver_::template shiftInBits<ShiftRegisterDriver_::LENGTH>(&data0);

        bool readBack1 = true;
        // as one can't directly access the shift-register content, at least read back SerialOutput and check for consistency.
        readBack1 = readBack1 && checkSerialOutput(serialOutputFromContent<ShiftRegisterDriver_::LENGTH>(&data0));
        readBack1 = readBack1 && checkSerialInput(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkShiftRegisterClock(AvrInputOutput::LOW);


        uint8_t shiftregisterContent = 0xff;
        // function under test - 1
        ShiftRegisterDriver_::template shiftOutBits<ShiftRegisterDriver_::LENGTH>(&shiftregisterContent);

        readBack1 = readBack1 && (data0 == shiftregisterContent);
        readBack1 = readBack1 && checkSerialOutput(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkSerialInput(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkShiftRegisterClock(AvrInputOutput::LOW);


        // Restore non-zero content after having shifted out everything.
        ShiftRegisterDriver_::template shiftInBits<ShiftRegisterDriver_::LENGTH>(&data0);
        shiftregisterContent = 0xff;
        // function under test - 2
        ShiftRegisterDriver_::template shiftInAndOutBitsSimultaneously<ShiftRegisterDriver_::LENGTH>(&data1, &shiftregisterContent);

        // shifting in and out simultaneously always yields the previous! register content, thus check against that.
        readBack1 = readBack1 && checkSerialOutput(serialOutputFromContent<ShiftRegisterDriver_::LENGTH>(&data1));
        readBack1 = readBack1 && checkSerialInput(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkShiftRegisterClock(AvrInputOutput::LOW);

        readBack1 = readBack1 && (data0 == shiftregisterContent);


        shiftregisterContent = data2;
        // function under test - 3
        ShiftRegisterDriver_::template shiftInAndOutBitsSimultaneously<ShiftRegisterDriver_::LENGTH>(&shiftregisterContent);

        readBack1 = readBack1 && checkSerialOutput(serialOutputFromContent<ShiftRegisterDriver_::LENGTH>(&data2));
        readBack1 = readBack1 && checkSerialInput(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkShiftRegisterClock(AvrInputOutput::LOW);

        readBack1 = readBack1 && (data1 == shiftregisterContent);

        shiftregisterContent = ~data2;
        ShiftRegisterDriver_::template shiftOutBits<ShiftRegisterDriver_::LENGTH>(&shiftregisterContent);
        readBack1 = readBack1 && (data2 == shiftregisterContent);


        if (readBack1)
        {
            testSuccess = true;
        }

        ShiftRegisterDriver_::turnOn();
        return testSuccess;
    }

    // show results
    static void showTestResult(TestResult const testResult)
    {
        turnOnDevice();
        DeviceTester_::enableLeds();

        if (testResult.turnOff && testResult.turnOn)
        {
            Vcc_::setPort();

            if (testResult.clearShiftRegister)
            {
                ShiftRegisterDriver_::SerialInput::setPort();
            }
            if (testResult.shiftInAndOutBits)
            {
                ShiftRegisterDriver_::ShiftRegisterClock::setPort();
            }
        }
        else
        {
            Vcc_::clearPort();
        }

        DeviceTester_::waitForButtonPressAndRelease();
        turnOffDevice();
    }

    template<unsigned lengthInBits_>
    static AvrInputOutput::PinState serialOutputFromContent(uint8_t const * const shiftRegisterContent)
    {
        uint8_t const * bitStreamArrayByte;
        uint8_t curBitMask;
        ShiftRegisterDriver_::template pointerAndBitmaskAtBitoffset<lengthInBits_>(shiftRegisterContent, &bitStreamArrayByte, &curBitMask);
        AvrInputOutput::PinState const serialOutputPinState = ((*bitStreamArrayByte & curBitMask) != 0) ? AvrInputOutput::HIGH : AvrInputOutput::LOW;
        return serialOutputPinState;
    }

};


#endif // SHIFTREGISTERTESTER_HPP
