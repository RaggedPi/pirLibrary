/*
  RaggedPi Project
  PIR Sensor Library
  Written by david durost <david.durost@gmail.com>
*/

#ifndef PIR_H
#define PIR_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif   

class PIR
{
    public: 
      PIR(uint8_t pin, uint8_t state=LOW);          // Constructor 
      void begin();                                 // Initialization
      uint8_t read(unit8_t readTimeInterval=5000);  // Read sensor
      int state(uint8_t state=NULL);                // pir state
      int isOn();                                   // Returns true if pir is on
      int isOff();                                  // Returns true if the pir is off
      void printState();                            // Print current state
    private: 
      uint8_t _state;                               // pir state
      uint8_t _pin;                                 // arduino pin
};

#endif
