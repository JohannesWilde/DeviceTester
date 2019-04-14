#ifndef RSLATCHCD4043BTESTER_HPP
#define RSLATCHCD4043BTESTER_HPP

#include "devicetester.hpp"
#include "avrinputoutput.hpp"
#include "avrpin.hpp"
#include "dummytypes.hpp"
#include "rslatchtester.hpp"
#include "rslatch.hpp"

template< typename Button_,
          typename Led_,
          typename Gnd_,
          typename Vcc_,
          typename Output0_,
          typename Output1_,
          typename Output2_,
          typename Output3_,
          typename NotConnected_,
          typename RsLatchCD4043BDriver_>
struct RsLatchCd4043BTester : public DeviceTester<Button_,
                                         Led_,
                                         Output3_,
                                         Output0_,
                                         typename RsLatchCD4043BDriver_::Reset0Pin,
                                         typename RsLatchCD4043BDriver_::Set0Pin,
                                         typename RsLatchCD4043BDriver_::OutputEnablePin,
                                         typename RsLatchCD4043BDriver_::Set1Pin,
                                         typename RsLatchCD4043BDriver_::Reset1Pin,
                                         Gnd_,
                                         Output1_,
                                         Output2_,
                                         typename RsLatchCD4043BDriver_::Reset2Pin,
                                         typename RsLatchCD4043BDriver_::Set2Pin,
                                         NotConnected_,
                                         typename RsLatchCD4043BDriver_::Set3Pin,
                                         typename RsLatchCD4043BDriver_::Reset3Pin,
                                         Vcc_>
{
protected:
    typedef DeviceTester<Button_,
                         Led_,
                         Output3_,
                         Output0_,
                         typename RsLatchCD4043BDriver_::Reset0Pin,
                         typename RsLatchCD4043BDriver_::Set0Pin,
                         typename RsLatchCD4043BDriver_::OutputEnablePin,
                         typename RsLatchCD4043BDriver_::Set1Pin,
                         typename RsLatchCD4043BDriver_::Reset1Pin,
                         Gnd_,
                         Output1_,
                         Output2_,
                         typename RsLatchCD4043BDriver_::Reset2Pin,
                         typename RsLatchCD4043BDriver_::Set2Pin,
                         NotConnected_,
                         typename RsLatchCD4043BDriver_::Set3Pin,
                         typename RsLatchCD4043BDriver_::Reset3Pin,
                         Vcc_> DeviceTester_;

    // Every RsLatchTester will need the OutputEnablePin_ - otherwise the tests will fail.
    // With these types however only the single latches can be tested - not potential crosstalk!

    typedef RsLatchTester<Button_, Led_, Gnd_, Vcc_, Output0_,
                            RsLatch<typename RsLatchCD4043BDriver_::Set0Pin,
                                    typename RsLatchCD4043BDriver_::Reset0Pin,
                                    typename RsLatchCD4043BDriver_::OutputEnablePin>
                            > RsLatchTester0_;
    typedef RsLatchTester<Button_, Led_, Gnd_, Vcc_, Output1_,
                            RsLatch<typename RsLatchCD4043BDriver_::Set1Pin,
                                    typename RsLatchCD4043BDriver_::Reset1Pin,
                                    typename RsLatchCD4043BDriver_::OutputEnablePin>
                            > RsLatchTester1_;
    typedef RsLatchTester<Button_, Led_, Gnd_, Vcc_, Output2_,
                            RsLatch<typename RsLatchCD4043BDriver_::Set2Pin,
                                    typename RsLatchCD4043BDriver_::Reset2Pin,
                                    typename RsLatchCD4043BDriver_::OutputEnablePin>
                            > RsLatchTester2_;
    typedef RsLatchTester<Button_, Led_, Gnd_, Vcc_, Output3_,
                            RsLatch<typename RsLatchCD4043BDriver_::Set3Pin,
                                    typename RsLatchCD4043BDriver_::Reset3Pin,
                                    typename RsLatchCD4043BDriver_::OutputEnablePin>
                            > RsLatchTester3_;

public:
    // make the pins publically available
    typedef Gnd_ GndPin;
    typedef Vcc_ VccPin;
    typedef Output0_ Output0Pin;
    typedef Output1_ Output1Pin;
    typedef Output2_ Output2Pin;
    typedef Output3_ Output3Pin;
    typedef NotConnected_ NotConnectedPin;
    typedef typename RsLatchCD4043BDriver_::Set0Pin Set0Pin;
    typedef typename RsLatchCD4043BDriver_::Reset0Pin Reset0Pin;
    typedef typename RsLatchCD4043BDriver_::Set1Pin Set1Pin;
    typedef typename RsLatchCD4043BDriver_::Reset1Pin Reset1Pin;
    typedef typename RsLatchCD4043BDriver_::Set2Pin Set2Pin;
    typedef typename RsLatchCD4043BDriver_::Reset2Pin Reset2Pin;
    typedef typename RsLatchCD4043BDriver_::Set3Pin Set3Pin;
    typedef typename RsLatchCD4043BDriver_::Reset3Pin Reset3Pin;
    typedef typename RsLatchCD4043BDriver_::OutputEnablePin OutputEnablePin;

    // this will reconfigure the ports - so set the sheftRegister driver after having called this.
    static void initialize()
    {
        DeviceTester_::initialize(AvrInputOutput::INPUT_PULLUP,     // Output3
                                  AvrInputOutput::INPUT_PULLUP,     // Output0
                                  AvrInputOutput::OUTPUT_LOW,       // Reset0
                                  AvrInputOutput::OUTPUT_LOW,       // Set0
                                  AvrInputOutput::OUTPUT_LOW,       // OutputEnable
                                  AvrInputOutput::OUTPUT_LOW,       // Set1
                                  AvrInputOutput::OUTPUT_LOW,       // Reset1
                                  AvrInputOutput::OUTPUT_LOW,       // Gnd
                                  AvrInputOutput::INPUT_PULLUP,     // Output1
                                  AvrInputOutput::INPUT_PULLUP,     // Output2
                                  AvrInputOutput::OUTPUT_LOW,       // Reset2
                                  AvrInputOutput::OUTPUT_LOW,       // Set2
                                  AvrInputOutput::INPUT_PULLUP,     // NotConnected
                                  AvrInputOutput::OUTPUT_LOW,       // Set3
                                  AvrInputOutput::OUTPUT_LOW,       // Reset3
                                  AvrInputOutput::OUTPUT_HIGH);     // Vcc
    }

    static bool checkOutputEnabled()
    {
        return RsLatchTester0_::checkOutputEnabled();
    }

    static bool checkOutputEnable(AvrInputOutput::PinState const pinState)
    {
        return RsLatchTester0_::checkOutputEnable(pinState);
    }

    static bool checkOutput0(AvrInputOutput::PinState const pinState)
    {
        return RsLatchTester0_::checkOutput(pinState);
    }

    static bool checkSet0(AvrInputOutput::PinState const pinState)
    {
        return RsLatchTester0_::checkSet(pinState);
    }

    static bool checkReset0(AvrInputOutput::PinState const pinState)
    {
        return RsLatchTester0_::checkReset(pinState);
    }

    static bool checkOutput1(AvrInputOutput::PinState const pinState)
    {
        return RsLatchTester1_::checkOutput(pinState);
    }

    static bool checkSet1(AvrInputOutput::PinState const pinState)
    {
        return RsLatchTester1_::checkSet(pinState);
    }

    static bool checkReset1(AvrInputOutput::PinState const pinState)
    {
        return RsLatchTester1_::checkReset(pinState);
    }

    static bool checkOutput2(AvrInputOutput::PinState const pinState)
    {
        return RsLatchTester2_::checkOutput(pinState);
    }

    static bool checkSet2(AvrInputOutput::PinState const pinState)
    {
        return RsLatchTester2_::checkSet(pinState);
    }

    static bool checkReset2(AvrInputOutput::PinState const pinState)
    {
        return RsLatchTester2_::checkReset(pinState);
    }

    static bool checkOutput3(AvrInputOutput::PinState const pinState)
    {
        return RsLatchTester3_::checkOutput(pinState);
    }

    static bool checkSet3(AvrInputOutput::PinState const pinState)
    {
        return RsLatchTester3_::checkSet(pinState);
    }

    static bool checkReset3(AvrInputOutput::PinState const pinState)
    {
        return RsLatchTester3_::checkReset(pinState);
    }

    struct TestResult : DeviceTester_::TestResult
    {
        TestResult () :
            DeviceTester_::TestResult(),
            testResult0(),
            testResult1(),
            testResult2(),
            testResult3()
        {
            // intentionally left empty
        }

        typename RsLatchTester0_::TestResult testResult0;
        typename RsLatchTester1_::TestResult testResult1;
        typename RsLatchTester2_::TestResult testResult2;
        typename RsLatchTester3_::TestResult testResult3;
    };

    static TestResult test()
    {
        // test result
        TestResult testResult;
        turnOnDevice();

        testResult.testResult0 = RsLatchTester0_::test();
        testResult.testResult1 = RsLatchTester1_::test();
        testResult.testResult2 = RsLatchTester2_::test();
        testResult.testResult3 = RsLatchTester3_::test();

        // set test success
        if (testResult.testResult0.success &&
            testResult.testResult1.success &&
            testResult.testResult2.success &&
            testResult.testResult1.success)
        {
            testResult.success = true;
        }

        // finally turn the device off
        turnOffDevice();
        return testResult;
    }

    static void turnOffDevice()
    {
        RsLatchTester0_::turnOffDevice();
        RsLatchTester1_::turnOffDevice();
        RsLatchTester2_::turnOffDevice();
        RsLatchTester3_::turnOffDevice();
        DeviceTester_::turnOffDevice();
    }

    static void turnOnDevice()
    {
        DeviceTester_::turnOnDevice();
        RsLatchTester0_::turnOnDevice();
        RsLatchTester1_::turnOnDevice();
        RsLatchTester2_::turnOnDevice();
        RsLatchTester3_::turnOnDevice();
    }

    static void showTestResult(TestResult const testResult)
    {
        turnOnDevice();
        DeviceTester_::enableLeds();
        RsLatchCD4043BDriver_::enableOutput();

        testResult.testResult0.success ? RsLatchCD4043BDriver_::set0() : RsLatchCD4043BDriver_::reset0();
        testResult.testResult1.success ? RsLatchCD4043BDriver_::set1() : RsLatchCD4043BDriver_::reset1();
        testResult.testResult2.success ? RsLatchCD4043BDriver_::set2() : RsLatchCD4043BDriver_::reset2();
        testResult.testResult3.success ? RsLatchCD4043BDriver_::set3() : RsLatchCD4043BDriver_::reset3();

        DeviceTester_::waitForButtonPressAndRelease();
        DeviceTester_::disableLeds();
        RsLatchCD4043BDriver_::disableOutput();
    }

};

#endif // RSLATCHCD4043BTESTER_HPP
