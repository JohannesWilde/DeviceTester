#ifndef DUMMYTYPES_HPP
#define DUMMYTYPES_HPP

#include "dummyavrinternalregister.hpp"
#include "avrioregister.hpp"
#include "avrpin.hpp"

// all the following types are non-fucntional, i.e. should produce no code.

typedef DummyAvrInternalRegister<static_cast<uintptr_t>(-1), uint8_t, false> DummyAvrInternalRegister1;
typedef DummyAvrInternalRegister<static_cast<uintptr_t>(-2), uint8_t, false> DummyAvrInternalRegister2;
typedef DummyAvrInternalRegister<static_cast<uintptr_t>(-3), uint8_t, false> DummyAvrInternalRegister3;

typedef AvrIoRegister<DummyAvrInternalRegister1, DummyAvrInternalRegister2, DummyAvrInternalRegister3> DummyAvrIoRegister;

typedef AvrPin<DummyAvrIoRegister, 0> DummyAvrPin0;
typedef AvrPin<DummyAvrIoRegister, 1> DummyAvrPin1;
typedef AvrPin<DummyAvrIoRegister, 2> DummyAvrPin2;
typedef AvrPin<DummyAvrIoRegister, 3> DummyAvrPin3;
typedef AvrPin<DummyAvrIoRegister, 4> DummyAvrPin4;
typedef AvrPin<DummyAvrIoRegister, 5> DummyAvrPin5;
typedef AvrPin<DummyAvrIoRegister, 6> DummyAvrPin6;
typedef AvrPin<DummyAvrIoRegister, 7> DummyAvrPin7;

#endif // DUMMYTYPES_HPP
