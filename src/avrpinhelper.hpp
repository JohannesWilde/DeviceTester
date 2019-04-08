#ifndef AVRPINHELPER_HPP
#define AVRPINHELPER_HPP

// Helpers for even more convenient AvrPin handling.
template<typename AvrPin>
static void lowHighClock()
{
    AvrPin::clearPort();
    AvrPin::setPort();
}

template<typename AvrPin>
static void highLowClock()
{
    AvrPin::setPort();
    AvrPin::clearPort();
}


#endif // AVRPINHELPER_HPP
