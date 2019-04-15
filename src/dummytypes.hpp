#ifndef DUMMYTYPES_HPP
#define DUMMYTYPES_HPP

#include "dummyavrinternalregister.hpp"
#include "avrioregister.hpp"
#include "avrpin.hpp"

// all the following types are non-fucntional, i.e. should produce no code.

// this register will always return 0x00
typedef DummyAvrInternalRegister<static_cast<uintptr_t>(-1), uint8_t, false, 0x00> DummyAvrInternalRegister1;
// this register will always return 0xff
typedef DummyAvrInternalRegister<static_cast<uintptr_t>(-2), uint8_t, false, 0xff> DummyAvrInternalRegister2;

// this I/O register will always return 0x00 [Pin], INPUT
typedef AvrIoRegister<DummyAvrInternalRegister1, DummyAvrInternalRegister1, DummyAvrInternalRegister1> DummyAvrIoRegister1;
// this I/O register will always return 0xff [Pin], OUTPUT_HIGH
typedef AvrIoRegister<DummyAvrInternalRegister2, DummyAvrInternalRegister2, DummyAvrInternalRegister2> DummyAvrIoRegister2;

// this pin will always read LOW [0]
typedef AvrPin<DummyAvrIoRegister1, 0> DummyAvrPin1;
// this pin will always read HIGH [1]
typedef AvrPin<DummyAvrIoRegister2, 0> DummyAvrPin2;

#endif // DUMMYTYPES_HPP
