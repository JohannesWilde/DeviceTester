#ifndef RSLATCHTESTER_HPP
#define RSLATCHTESTER_HPP

#include "devicetester.hpp"
#include "avrinputoutput.hpp"
#include "avrpin.hpp"
#include "dummytypes.hpp"

template< typename Button_,
          typename Led_,
          typename Gnd_,
          typename Vcc_,
          typename Output_,
          typename RsLatchDriver_>
struct RsLatchTester : public DeviceTester<Button_,
                                         Led_,
                                         Gnd_,
                                         Vcc_,
                                         Output_,
                                         typename RsLatchDriver_::SetPin,
                                         typename RsLatchDriver_::ResetPin,
                                         typename RsLatchDriver_::OutputEnablePin,
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
                         Output_,
                         typename RsLatchDriver_::SetPin,
                         typename RsLatchDriver_::ResetPin,
                         typename RsLatchDriver_::OutputEnablePin,
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
    typedef Gnd_ GndPin;
    typedef Vcc_ VccPin;
    typedef Output_ OutputPin;
    typedef typename RsLatchDriver_::SetPin SetPin;
    typedef typename RsLatchDriver_::ResetPin ResetPin;
    typedef typename RsLatchDriver_::OutputEnablePin OutputEnablePin;

    // this will reconfigure the ports - so set the sheftRegister driver after having called this.
    static void initialize()
    {
        DeviceTester_::initialize(AvrInputOutput::OUTPUT_LOW,   // Gnd
                                  AvrInputOutput::OUTPUT_HIGH,  // Vcc
                                  AvrInputOutput::INPUT_PULLUP, // Output
                                  AvrInputOutput::OUTPUT_LOW,   // Set
                                  AvrInputOutput::OUTPUT_LOW,   // Reset
                                  AvrInputOutput::OUTPUT_LOW,   // OutputEnable
                                  AvrInputOutput::INPUT,        // ----------------------------------
                                  AvrInputOutput::INPUT,        // values for dummy-pins should be meaningsless
                                  AvrInputOutput::INPUT,        // the safest guess however is INPUT [no current in or out].
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT,
                                  AvrInputOutput::INPUT);
    }

    static bool checkOutputEnabled()
    {
        return checkOutputEnable(AvrInputOutput::HIGH);
    }

    static bool checkOutputEnable(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<OutputEnablePin>(pinState);
    }

    static bool checkOutput(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<OutputPin>(pinState);
    }

    static bool checkSet(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<SetPin>(pinState);
    }

    static bool checkReset(AvrInputOutput::PinState const pinState)
    {
        return DeviceTester_::template checkDevicePinPin<ResetPin>(pinState);
    }

    struct TestResult : DeviceTester_::TestResult
    {
        TestResult () :
            DeviceTester_::TestResult(),
            disableOutput(false),
            enableOutput(false),
            turnOff(false),
            turnOn(false),
            set(false),
            reset(false)
        {
            // intentionally left empty
        }

        bool disableOutput : 1;
        bool enableOutput : 1;
        bool turnOff : 1;
        bool turnOn : 1;
        bool set : 1;
        bool reset : 1;
    };

    static TestResult test()
    {
        // test result
        TestResult testResult;

        // initialize
        initialize();
        RsLatchDriver_::initialize();

        testResult.disableOutput = testDisableOutput();

        testResult.enableOutput = testEnableOutput();

        testResult.turnOff = testTurnOff();

        testResult.turnOn = testTurnOn();

        testResult.set = testSet();

        testResult.reset = testReset();

        // set test success
        if (testResult.disableOutput &&
            testResult.enableOutput &&
            testResult.turnOff &&
            testResult.turnOn &&
            testResult.set &&
            testResult.reset)
        {
            testResult.success = true;
        }

        // finally turn the device off
        turnOffDevice();
        return testResult;
    }

    static void turnOffDevice()
    {
        RsLatchDriver_::turnOff();
        Output_::clearPort();       // INPUT [i.e. no pullup!]
        Vcc_::clearPort();          // OUTPUT_LOW
        DeviceTester_::turnOffDevice();
    }

    static void turnOnDevice()
    {
        DeviceTester_::turnOnDevice();
        Vcc_::setPort();            // OUTPUT_HIGH
        Output_::setPort();         // INPUT_PULLUP [i.e. no voltage!]
        RsLatchDriver_::turnOn();
    }

    // all test routines expect the rsLatchDriver to be initialized,
    // i.e. output disabled, set LOW, reset LOW and the lath in reset state.

    static bool testTurnOff()
    {
        bool testSuccess = true;
        testSuccess &= !checkOutputEnabled();
        testSuccess &= checkSet(AvrInputOutput::LOW);
        testSuccess &= checkReset(AvrInputOutput::LOW);

        testSuccess &= checkOutput(AvrInputOutput::HIGH); // internal pull-up pulls high for disabled output

        RsLatchDriver_::enableOutput();
        testSuccess &= checkOutput(AvrInputOutput::LOW);

        RsLatchDriver_::disableOutput();

        return testSuccess;
    }

    static bool testTurnOn()
    {
        // turnOn and turnOff are currently the same
        return testTurnOff();
    }

    static bool testDisableOutput()
    {
        bool testSuccess = true;

        // assure the latch is reset
        RsLatchDriver_::reset();

        // read the states before disableOutput()
        AvrInputOutput::PinState const setState = SetPin::readPin();
        AvrInputOutput::PinState const resetState = ResetPin::readPin();

        RsLatchDriver_::disableOutput();
        testSuccess &= !checkOutputEnabled();

        // check that set and reset are unaffected
        testSuccess &= checkSet(setState);
        testSuccess &= checkReset(resetState);

        // internal pull-up pulls high for disabled output
        testSuccess &= checkOutput(AvrInputOutput::HIGH);

        return testSuccess;
    }

    static bool testEnableOutput()
    {
        bool testSuccess = true;

        // assure the latch is reset
        RsLatchDriver_::reset();

        // read the states before enableOutput()
        AvrInputOutput::PinState const setState = SetPin::readPin();
        AvrInputOutput::PinState const resetState = ResetPin::readPin();

        RsLatchDriver_::enableOutput();
        testSuccess &= checkOutputEnabled();

        // check that set and reset are unaffected
        testSuccess &= checkSet(setState);
        testSuccess &= checkReset(resetState);

        // because the internal pull-up pulls high for disabled output, reset above and check here for LOW
        testSuccess &= checkOutput(AvrInputOutput::LOW);

        RsLatchDriver_::disableOutput();
        return testSuccess;
    }

    static bool testSet()
    {
        bool testSuccess = true;

        // assure the latch is reset
        RsLatchDriver_::reset();
        RsLatchDriver_::enableOutput();

        testSuccess &= checkSet(AvrInputOutput::LOW);
        testSuccess &= checkReset(AvrInputOutput::LOW);
        testSuccess &= checkOutput(AvrInputOutput::LOW);

        RsLatchDriver_::set();

        testSuccess &= checkSet(AvrInputOutput::LOW);
        testSuccess &= checkReset(AvrInputOutput::LOW);
        testSuccess &= checkOutput(AvrInputOutput::HIGH);

        RsLatchDriver_::disableOutput();
        return testSuccess;
    }

    static bool testReset()
    {
        bool testSuccess = true;

        // assure the latch is reset
        RsLatchDriver_::set();
        RsLatchDriver_::enableOutput();

        testSuccess &= checkSet(AvrInputOutput::LOW);
        testSuccess &= checkReset(AvrInputOutput::LOW);
        testSuccess &= checkOutput(AvrInputOutput::HIGH);

        RsLatchDriver_::reset();

        testSuccess &= checkSet(AvrInputOutput::LOW);
        testSuccess &= checkReset(AvrInputOutput::LOW);
        testSuccess &= checkOutput(AvrInputOutput::LOW);

        RsLatchDriver_::disableOutput();
        return testSuccess;
    }

    static void showTestResult(TestResult const testResult)
    {
        turnOnDevice();
        DeviceTester_::enableLeds();
        RsLatchDriver_::enableOutput();

        if (testResult.success)
        {
            RsLatchDriver_::set();
        }
        else
        {
            RsLatchDriver_::reset();
        }

        DeviceTester_::waitForButtonPressAndRelease();
        DeviceTester_::disableLeds();
        RsLatchDriver_::disableOutput();
    }

};

#endif // RSLATCHTESTER_HPP
