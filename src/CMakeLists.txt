#####################################################################
# simple AVR executable
#####################################################################
add_avr_executable(
   main
   main.cpp
   avrinternalregister.cpp
   avrregister.cpp
   avrpin.cpp
   arduinouno.cpp
   devicetester.cpp
   shiftregister.cpp
   )

#####################################################################
# libraries to link to
#####################################################################
#target_link_libraries(
#   )
