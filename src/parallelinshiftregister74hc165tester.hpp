#ifndef PARALLELINSHIFTREGISTER74HC165TESTER_HPP
#define PARALLELINSHIFTREGISTER74HC165TESTER_HPP

#include "devicetester.hpp"
#include "ArduinoDrivers/avrinputoutput.hpp"
#include "ArduinoDrivers/avrpin.hpp"

template< typename Button_,
          typename Led_,
          typename ParallelInput4_,
          typename ParallelInput5_,
          typename ParallelInput6_,
          typename ParallelInput7_,
          typename Gnd_,
          typename ParallelInput0_,
          typename ParallelInput1_,
          typename ParallelInput2_,
          typename ParallelInput3_,
          typename Vcc_,
          typename ParallelInShiftRegisterDriver_>
struct ParallelInShiftRegister74HC165Tester :
        public DeviceTester<Button_,
                            Led_,
                            typename ParallelInShiftRegisterDriver_::InvertedParallelLoad,
                            typename ParallelInShiftRegisterDriver_::ShiftRegisterClock,
                            ParallelInput4_,
                            ParallelInput5_,
                            ParallelInput6_,
                            ParallelInput7_,
                            typename ParallelInShiftRegisterDriver_::InvertedSerialOutput,
                            Gnd_,
                            typename ParallelInShiftRegisterDriver_::SerialOutput,
                            typename ParallelInShiftRegisterDriver_::SerialInput,
                            ParallelInput0_,
                            ParallelInput1_,
                            ParallelInput2_,
                            ParallelInput3_,
                            typename ParallelInShiftRegisterDriver_::InvertedClockEnable,
                            Vcc_>
{
protected:
    typedef DeviceTester<Button_,
                        Led_,
                        typename ParallelInShiftRegisterDriver_::InvertedParallelLoad,
                        typename ParallelInShiftRegisterDriver_::ShiftRegisterClock,
                        ParallelInput4_,
                        ParallelInput5_,
                        ParallelInput6_,
                        ParallelInput7_,
                        typename ParallelInShiftRegisterDriver_::InvertedSerialOutput,
                        Gnd_,
                        typename ParallelInShiftRegisterDriver_::SerialOutput,
                        typename ParallelInShiftRegisterDriver_::SerialInput,
                        ParallelInput0_,
                        ParallelInput1_,
                        ParallelInput2_,
                        ParallelInput3_,
                        typename ParallelInShiftRegisterDriver_::InvertedClockEnable,
                        Vcc_> DeviceTester_;
public:
    // make the pins publically available
    typedef ParallelInShiftRegisterDriver_ ParallelInShiftRegisterDriver;
    typedef typename ParallelInShiftRegisterDriver_::InvertedParallelLoad InvertedParallelLoad;
    typedef typename ParallelInShiftRegisterDriver_::ShiftRegisterClock ShiftRegisterClock;
    typedef ParallelInput4_ ParallelInput4Pin;
    typedef ParallelInput5_ ParallelInput5Pin;
    typedef ParallelInput6_ ParallelInput6Pin;
    typedef ParallelInput7_ ParallelInput7Pin;
    typedef typename ParallelInShiftRegisterDriver_::InvertedSerialOutput InvertedSerialOutput;
    typedef Gnd_ GndPin;
    typedef typename ParallelInShiftRegisterDriver_::SerialOutput SerialOutput;
    typedef typename ParallelInShiftRegisterDriver_::SerialInput SerialInput;
    typedef ParallelInput0_ ParallelInput0Pin;
    typedef ParallelInput1_ ParallelInput1Pin;
    typedef ParallelInput2_ ParallelInput2Pin;
    typedef ParallelInput3_ ParallelInput3Pin;
    typedef typename ParallelInShiftRegisterDriver_::InvertedClockEnable InvertedClockEnable;
    typedef Vcc_ VccPin;

    // this will reconfigure the ports - so set the sheftRegister driver after having called this.
    static void initialize()
    {
        DeviceTester_::initialize(AvrInputOutput::OUTPUT_HIGH, // InvertedParallelLoad
                                  AvrInputOutput::OUTPUT_LOW,  // ShiftRegisterClock
                                  AvrInputOutput::OUTPUT_LOW,  // ParallelInput4
                                  AvrInputOutput::OUTPUT_LOW,  // ParallelInput5
                                  AvrInputOutput::OUTPUT_LOW,  // ParallelInput6
                                  AvrInputOutput::OUTPUT_LOW,  // ParallelInput7
                                  AvrInputOutput::INPUT,       // InvertedSerialOutput
                                  AvrInputOutput::OUTPUT_LOW,  // Gnd
                                  AvrInputOutput::INPUT,       // SerialOutput
                                  AvrInputOutput::OUTPUT_LOW,  // SerialInput
                                  AvrInputOutput::OUTPUT_LOW,  // ParallelInput0
                                  AvrInputOutput::OUTPUT_LOW,  // ParallelInput1
                                  AvrInputOutput::OUTPUT_LOW,  // ParallelInput2
                                  AvrInputOutput::OUTPUT_LOW,  // ParallelInput3
                                  AvrInputOutput::OUTPUT_HIGH, // InvertedClockEnable
                                  AvrInputOutput::OUTPUT_HIGH  // Vcc
                                  );
    }

    static bool checkSerialOutput(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<SerialOutput>(pinState);
    }

    static bool checkInvertedSerialOutput(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<InvertedSerialOutput>(pinState);
    }

    static bool checkSerialInput(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<SerialInput>(pinState);
    }

    static bool checkInvertedClockEnable(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<InvertedClockEnable>(pinState);
    }

    static bool checkShiftRegisterClock(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<ShiftRegisterClock>(pinState);
    }

    static bool checkInvertedParallelLoad(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<InvertedParallelLoad>(pinState);
    }

    static bool checkParallelInput(uint8_t const expectedBitMask)
    {
        return 0x00 == compareParallelInputTo(expectedBitMask);
    }

    // Returns an 8-bit bit mask where a 1 denotes mismatch and 0 denotes matching of expectation
    // and measured.
    static uint8_t compareParallelInputTo(uint8_t const expectedBitMask)
    {
        uint8_t const curBitMask = readParallelInput();
        uint8_t const unexpectedBitMask = curBitMask ^ expectedBitMask;
        return unexpectedBitMask;
    }

    static uint8_t readParallelInput()
    {
        uint8_t currentBitMask = 0x00;
        currentBitMask |= static_cast<uint8_t>(ParallelInput0_::readPin()) << 0;
        currentBitMask |= static_cast<uint8_t>(ParallelInput1_::readPin()) << 1;
        currentBitMask |= static_cast<uint8_t>(ParallelInput2_::readPin()) << 2;
        currentBitMask |= static_cast<uint8_t>(ParallelInput3_::readPin()) << 3;
        currentBitMask |= static_cast<uint8_t>(ParallelInput4_::readPin()) << 4;
        currentBitMask |= static_cast<uint8_t>(ParallelInput5_::readPin()) << 5;
        currentBitMask |= static_cast<uint8_t>(ParallelInput6_::readPin()) << 6;
        currentBitMask |= static_cast<uint8_t>(ParallelInput7_::readPin()) << 7;
        return currentBitMask;
    }

    static void writeParallelInput(uint8_t const bitMask)
    {
        ((bitMask & (0x01 << 0)) != 0) ? ParallelInput0_::setPort() : ParallelInput0_::clearPort();
        ((bitMask & (0x01 << 1)) != 0) ? ParallelInput1_::setPort() : ParallelInput1_::clearPort();
        ((bitMask & (0x01 << 2)) != 0) ? ParallelInput2_::setPort() : ParallelInput2_::clearPort();
        ((bitMask & (0x01 << 3)) != 0) ? ParallelInput3_::setPort() : ParallelInput3_::clearPort();
        ((bitMask & (0x01 << 4)) != 0) ? ParallelInput4_::setPort() : ParallelInput4_::clearPort();
        ((bitMask & (0x01 << 5)) != 0) ? ParallelInput5_::setPort() : ParallelInput5_::clearPort();
        ((bitMask & (0x01 << 6)) != 0) ? ParallelInput6_::setPort() : ParallelInput6_::clearPort();
        ((bitMask & (0x01 << 7)) != 0) ? ParallelInput7_::setPort() : ParallelInput7_::clearPort();
    }

    struct TestResult : DeviceTester_::TestResult
    {
        TestResult () :
            DeviceTester_::TestResult(),
            turnOff(false),
            turnOn(false),
            enableClock(false),
            disableClock(false),
            enableParallelLoad(false),
            disableParallelLoad(false),
            parallelLoadEnabled(false),
            clockEnabled(false),
            loadParallelToShiftregister(false),
            clearShiftRegister(false),
            shiftInBits(false),
            shiftOutBits(false)
        {
            // intentionally left empty
        }

        bool turnOff : 1;
        bool turnOn : 1;
        bool enableClock : 1;
        bool disableClock : 1;
        bool enableParallelLoad : 1;
        bool disableParallelLoad : 1;
        bool parallelLoadEnabled : 1;
        bool clockEnabled : 1;
        bool loadParallelToShiftregister : 1;
        bool clearShiftRegister : 1;
        bool shiftInBits : 1;
        bool shiftOutBits : 1;
    };

    static TestResult test()
    {
        // test result
        TestResult testResult;
        turnOnDevice();

        testResult.turnOn = testTurnOn();
        testResult.turnOff = testTurnOff();

        testResult.enableClock = testEnableClock();
        testResult.disableClock = testDisableClock();

        testResult.enableParallelLoad = testEnableParallelLoad();
        testResult.disableParallelLoad = testDisableParallelLoad();

        testResult.parallelLoadEnabled = testParallelLoadEnabled();
        testResult.clockEnabled = testClockEnabled();

        testResult.loadParallelToShiftregister = testLoadParallelToShiftregister();
        testResult.clearShiftRegister = testClearShiftRegister();

        testResult.shiftInBits = testShiftInBits();
        testResult.shiftOutBits = testShiftOutBits();

        // set test success
        if (testResult.turnOff &&
            testResult.turnOn &&
            testResult.enableClock &&
            testResult.disableClock &&
            testResult.enableParallelLoad &&
            testResult.disableParallelLoad &&
            testResult.loadParallelToShiftregister &&
            testResult.parallelLoadEnabled &&
            testResult.clockEnabled &&
            testResult.clearShiftRegister &&
            testResult.shiftInBits &&
            testResult.shiftOutBits)
        {
            testResult.success = true;
        }

        // finally turn the device off
        turnOffDevice();
        return testResult;
    }

    static void turnOffDevice()
    {
        ParallelInput0_::clearPort();
        ParallelInput1_::clearPort();
        ParallelInput2_::clearPort();
        ParallelInput3_::clearPort();
        ParallelInput4_::clearPort();
        ParallelInput5_::clearPort();
        ParallelInput6_::clearPort();
        ParallelInput7_::clearPort();
        ParallelInShiftRegisterDriver::turnOff();
        Vcc_::clearPort();
        DeviceTester_::turnOffDevice();
    }

    static void turnOnDevice()
    {
        DeviceTester_::turnOnDevice();
        Vcc_::setPort();
        ParallelInShiftRegisterDriver::turnOn();
        ParallelInput0_::clearPort();
        ParallelInput1_::clearPort();
        ParallelInput2_::clearPort();
        ParallelInput3_::clearPort();
        ParallelInput4_::clearPort();
        ParallelInput5_::clearPort();
        ParallelInput6_::clearPort();
        ParallelInput7_::clearPort();
    }

    // all test routines expect the shiftRegisterDriver to be initialized,
    // i.e. clock disabled, parallel load disabled, ShiftRegisterClock LOW,
    // SerialInput LOW, SerialOutput LOW, InvertedSerialOutput HIGH and the
    // internal register to be 0x00.

    static bool testTurnOn()
    {
        writeParallelInput(0xaa); // write out non-zero and non-0xff input
        ParallelInShiftRegisterDriver_::enableParallelLoad();
        ParallelInShiftRegisterDriver_::enableClock();
        // init
        bool testSuccess = false;
        // function under test
        ParallelInShiftRegisterDriver_::turnOn();
        bool readBack1 = true;
        readBack1 = readBack1 && checkShiftRegisterClock(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkInvertedParallelLoad(AvrInputOutput::HIGH);
        readBack1 = readBack1 && checkSerialInput(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkSerialOutput(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkInvertedSerialOutput(AvrInputOutput::HIGH);

        // read out internal shift register value
        ParallelInShiftRegisterDriver_::enableClock();
        uint8_t readBack0 = 0xff;
        ParallelInShiftRegisterDriver_::shiftOutBits(&readBack0);

        if (0x00 == readBack0 && readBack1)
        {
            testSuccess = true;
        }

        ParallelInShiftRegisterDriver_::turnOn();
        return testSuccess;
    }

    static bool testTurnOff()
    {
        bool testSuccess = false;
        bool readBack1 = true;
        uint8_t input = 0x00 - 1;
        do
        {
            ++input;
            writeParallelInput(input); // write out non-zero and non-0xff input
            InvertedClockEnable::setPort();
            ShiftRegisterClock::setPort();
            SerialInput::setPort();
            InvertedParallelLoad::setPort();

            // function under test
            ParallelInShiftRegisterDriver_::turnOff();
            // investigation
            readBack1 = readBack1 && checkShiftRegisterClock(AvrInputOutput::LOW);
            readBack1 = readBack1 && checkInvertedParallelLoad(AvrInputOutput::LOW);
            readBack1 = readBack1 && checkShiftRegisterClock(AvrInputOutput::LOW);
            readBack1 = readBack1 && checkSerialInput(AvrInputOutput::LOW);
            if ((input & (0x01 << 7)) == 0)
            {
                readBack1 = readBack1 && checkSerialOutput(AvrInputOutput::LOW);
                readBack1 = readBack1 && checkInvertedSerialOutput(AvrInputOutput::HIGH);
            }
            else
            {
                readBack1 = readBack1 && checkSerialOutput(AvrInputOutput::HIGH);
                readBack1 = readBack1 && checkInvertedSerialOutput(AvrInputOutput::LOW);
            }
        }
        while (input < 0xff && readBack1);

        if (readBack1)
        {
            testSuccess = true;
        }

        writeParallelInput(0x00);
        ParallelInShiftRegisterDriver_::turnOn();
        return testSuccess;
    }

    static bool testEnableClock()
    {
        bool testSuccess = false;
        InvertedClockEnable::setPort();
        // function under test
        ParallelInShiftRegisterDriver_::enableClock();
        bool readBack1 = checkInvertedClockEnable(AvrInputOutput::LOW);

        if (readBack1)
        {
            testSuccess = true;
        }

        ParallelInShiftRegisterDriver_::turnOn();
        return testSuccess;
    }

    static bool testDisableClock()
    {
        bool testSuccess = false;
        InvertedClockEnable::clearPort();
        // function under test
        ParallelInShiftRegisterDriver_::disableClock();
        bool readBack1 = checkInvertedClockEnable(AvrInputOutput::HIGH);

        if (readBack1)
        {
            testSuccess = true;
        }

        ParallelInShiftRegisterDriver_::turnOn();
        return testSuccess;
    }

    static bool testEnableParallelLoad()
    {
        bool testSuccess = false;
        InvertedParallelLoad::setPort();
        // function under test
        ParallelInShiftRegisterDriver_::enableParallelLoad();
        bool readBack1 = checkInvertedParallelLoad(AvrInputOutput::LOW);

        if (readBack1)
        {
            testSuccess = true;
        }

        ParallelInShiftRegisterDriver_::turnOn();
        return testSuccess;
    }

    static bool testDisableParallelLoad()
    {
        bool testSuccess = false;
        InvertedParallelLoad::clearPort();
        // function under test
        ParallelInShiftRegisterDriver_::disableParallelLoad();
        bool readBack1 = checkInvertedParallelLoad(AvrInputOutput::HIGH);

        if (readBack1)
        {
            testSuccess = true;
        }

        ParallelInShiftRegisterDriver_::turnOn();
        return testSuccess;
    }

    static bool testParallelLoadEnabled()
    {
        bool testSuccess = false;
        InvertedParallelLoad::clearPort();
        // function under test
        bool const enabled = ParallelInShiftRegisterDriver_::parallelLoadEnabled();

        InvertedParallelLoad::setPort();
        bool const disabled = !ParallelInShiftRegisterDriver_::parallelLoadEnabled();

        if (enabled && disabled)
        {
            testSuccess = true;
        }

        ParallelInShiftRegisterDriver_::turnOn();
        return testSuccess;
    }

    static bool testClockEnabled()
    {
        bool testSuccess = false;
        InvertedClockEnable::clearPort();
        // function under test
        bool const enabled = ParallelInShiftRegisterDriver_::clockEnabled();

        InvertedClockEnable::setPort();
        bool const disabled = !ParallelInShiftRegisterDriver_::clockEnabled();

        if (enabled && disabled)
        {
            testSuccess = true;
        }

        ParallelInShiftRegisterDriver_::turnOn();
        return testSuccess;
    }

    static bool testLoadParallelToShiftregister()
    {
        DeviceTester_::enableLeds();

        bool testSuccess = false;
        uint8_t const data = 0x55;
        writeParallelInput(data);
        uint8_t const writtenData = readParallelInput();

        ParallelInShiftRegisterDriver_::enableClock();
        ParallelInShiftRegisterDriver_::clearShiftRegister();

        // function under test
        ParallelInShiftRegisterDriver_::loadParallelToShiftregister();

        writeParallelInput(0x00);

        bool parallelLoadDisabled = checkInvertedParallelLoad(AvrInputOutput::HIGH);

        uint8_t shiftregisterContent = 0xff;
        ParallelInShiftRegisterDriver_::shiftOutBits(&shiftregisterContent);


        if ((writtenData == data) && parallelLoadDisabled && (data == shiftregisterContent))
        {
            testSuccess = true;
        }

        ParallelInShiftRegisterDriver_::turnOn();
        return testSuccess;
    }

    static bool testClearShiftRegister()
    {
        bool testSuccess = false;
        writeParallelInput(0x55);
        ParallelInShiftRegisterDriver_::loadParallelToShiftregister();
        writeParallelInput(0x00);

        ParallelInShiftRegisterDriver_::enableClock();
        ParallelInShiftRegisterDriver_::disableParallelLoad();

        // function under test
        ParallelInShiftRegisterDriver_::clearShiftRegister();

        bool readBack1 = checkInvertedParallelLoad(AvrInputOutput::HIGH);
        readBack1 = readBack1 && checkSerialOutput(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkInvertedSerialOutput(AvrInputOutput::HIGH);
        readBack1 = readBack1 && checkSerialInput(AvrInputOutput::LOW);

        uint8_t shiftregisterContent = 0xff;
        ParallelInShiftRegisterDriver_::shiftOutBits(&shiftregisterContent);


        if (readBack1 && (0x00 == shiftregisterContent))
        {
            testSuccess = true;
        }

        ParallelInShiftRegisterDriver_::turnOn();
        return testSuccess;
    }

    static bool testShiftInBits()
    {
        bool testSuccess = false;
        writeParallelInput(0x00);
        ParallelInShiftRegisterDriver_::loadParallelToShiftregister();

        ParallelInShiftRegisterDriver_::enableClock();
        ParallelInShiftRegisterDriver_::disableParallelLoad();

        uint8_t const data = 0xaa;
        // function under test
        ParallelInShiftRegisterDriver_::shiftInBits(&data);

        bool readBack1 = checkInvertedParallelLoad(AvrInputOutput::HIGH);
        readBack1 = readBack1 && checkSerialOutput(AvrInputOutput::HIGH);
        readBack1 = readBack1 && checkInvertedSerialOutput(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkSerialInput(AvrInputOutput::LOW);

        uint8_t shiftregisterContent = 0xff;
        ParallelInShiftRegisterDriver_::shiftOutBits(&shiftregisterContent);


        if ((data == shiftregisterContent) && readBack1)
        {
            testSuccess = true;
        }

        ParallelInShiftRegisterDriver_::turnOn();
        return testSuccess;
    }

    static bool testShiftOutBits()
    {
        bool testSuccess = false;
        uint8_t const inputData = 0x55;
        writeParallelInput(inputData);
        ParallelInShiftRegisterDriver_::loadParallelToShiftregister();
        writeParallelInput(0x00);

        SerialInput::clearPort();
        ParallelInShiftRegisterDriver_::enableClock();
        ParallelInShiftRegisterDriver_::disableParallelLoad();

        uint8_t data = 0xaa;
        // function under test
        ParallelInShiftRegisterDriver_::shiftOutBits(&data);

        bool readBack1 = checkInvertedParallelLoad(AvrInputOutput::HIGH);
        readBack1 = readBack1 && checkSerialOutput(AvrInputOutput::LOW);
        readBack1 = readBack1 && checkInvertedSerialOutput(AvrInputOutput::HIGH);
        readBack1 = readBack1 && checkSerialInput(AvrInputOutput::LOW);

        if ((inputData == data) && readBack1)
        {
            testSuccess = true;
        }

        ParallelInShiftRegisterDriver_::turnOn();
        return testSuccess;
    }

    // show results
    static void showTestResult(TestResult const testResult)
    {
        turnOnDevice();
        DeviceTester_::enableLeds();

        if (testResult.turnOff && testResult.turnOn)
        {
            DeviceTester_::DevicePin2::setPort();
        }
        if (testResult.enableClock && testResult.disableClock)
        {
            DeviceTester_::DevicePin3::setPort();
        }
        if (testResult.enableParallelLoad && testResult.disableParallelLoad)
        {
            DeviceTester_::DevicePin4::setPort();
        }
        if (testResult.loadParallelToShiftregister)
        {
            DeviceTester_::DevicePin5::setPort();
        }
        if (testResult.parallelLoadEnabled)
        {
            DeviceTester_::DevicePin10::setPort();
        }
        if (testResult.clockEnabled)
        {
            DeviceTester_::DevicePin11::setPort();
        }
        if (testResult.clearShiftRegister)
        {
            DeviceTester_::DevicePin12::setPort();
        }
        if (testResult.shiftInBits && testResult.shiftOutBits)
        {
            DeviceTester_::DevicePin13::setPort();
        }

        DeviceTester_::waitForButtonPressAndRelease();
        turnOffDevice();
    }

};


#endif // PARALLELINSHIFTREGISTER74HC165TESTER_HPP
