#####################################################################
# simple AVR executable
#####################################################################
add_avr_executable(
   main
   main.cpp
   avrregister.cpp
   avrpin.cpp
   arduinouno.cpp
   devicetester.cpp
   shiftregistertester.cpp
   shiftregister.cpp
   )

#####################################################################
# libraries to link to
#####################################################################
#target_link_libraries(
#   )
