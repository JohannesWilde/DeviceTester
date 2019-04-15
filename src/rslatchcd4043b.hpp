#ifndef RSLATCHCD4043B_HPP
#define RSLATCHCD4043B_HPP

#include <stdint.h>
#include "avrinputoutput.hpp"
#include "avrpin.hpp"
#include "avrpinhelper.hpp"
#include "rslatch.hpp"
#include "dummytypes.hpp"

template<typename Set0Pin_, typename Reset0Pin_,
         typename Set1Pin_, typename Reset1Pin_,
         typename Set2Pin_, typename Reset2Pin_,
         typename Set3Pin_, typename Reset3Pin_,
         typename OutputEnablePin_>
// all - AvrPin types
struct RsLatchCd4043B
{
protected:
    // these RsLatches only have a dummy OutputEnablePin - as otherwise RsLatch0 could affect RsLatch1 here.
    typedef RsLatch<Set0Pin_, Reset0Pin_, DummyAvrPin1> RsLatch0_;
    typedef RsLatch<Set1Pin_, Reset1Pin_, DummyAvrPin1> RsLatch1_;
    typedef RsLatch<Set2Pin_, Reset2Pin_, DummyAvrPin1> RsLatch2_;
    typedef RsLatch<Set3Pin_, Reset3Pin_, DummyAvrPin1> RsLatch3_;

    // for the global outputEnable also use the RsLatch functionality.
    typedef RsLatch<DummyAvrPin1, DummyAvrPin1, OutputEnablePin_> RsLatchOutputEnable_;

public:
    typedef Set0Pin_ Set0Pin;
    typedef Reset0Pin_ Reset0Pin;
    typedef Set1Pin_ Set1Pin;
    typedef Reset1Pin_ Reset1Pin;
    typedef Set2Pin_ Set2Pin;
    typedef Reset2Pin_ Reset2Pin;
    typedef Set3Pin_ Set3Pin;
    typedef Reset3Pin_ Reset3Pin;
    typedef OutputEnablePin_ OutputEnablePin;

    static void initialize()
    {
        // set data directions of pins and default port states
        RsLatchOutputEnable_::initialize();
        RsLatch0_::initialize();
        RsLatch1_::initialize();
        RsLatch2_::initialize();
        RsLatch3_::initialize();
    }

    static void turnOff()
    {
        RsLatchOutputEnable_::turnOff();
        RsLatch0_::turnOff();
        RsLatch1_::turnOff();
        RsLatch2_::turnOff();
        RsLatch3_::turnOff();
    }


    static void turnOn()
    {
        RsLatchOutputEnable_::turnOn();
        RsLatch0_::turnOn();
        RsLatch1_::turnOn();
        RsLatch2_::turnOn();
        RsLatch3_::turnOn();
    }

    static void enableOutput()
    {
        RsLatchOutputEnable_::enableOutput();
    }

    static void disableOutput()
    {
        RsLatchOutputEnable_::disableOutput();
    }

    static void setAll()
    {
        RsLatch0_::set();
        RsLatch1_::set();
        RsLatch2_::set();
        RsLatch3_::set();
    }

    static void resetAll()
    {
        RsLatch0_::reset();
        RsLatch1_::reset();
        RsLatch2_::reset();
        RsLatch3_::reset();
    }

    static void set0()
    {
        RsLatch0_::set();
    }

    static void reset0()
    {
        RsLatch0_::reset();
    }

    static void set1()
    {
        RsLatch1_::set();
    }

    static void reset1()
    {
        RsLatch1_::reset();
    }

    static void set2()
    {
        RsLatch2_::set();
    }

    static void reset2()
    {
        RsLatch2_::reset();
    }

    static void set3()
    {
        RsLatch3_::set();
    }

    static void reset3()
    {
        RsLatch3_::reset();
    }
};

#endif // RSLATCHCD4043B_HPP
