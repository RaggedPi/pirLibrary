/*
  RaggedPi Project
  PIR Sensor Library
  Written by david durost <david.durost@gmail.com>
*/

//#include "WProgram.h"   
#include "Pir.h"

/**
 * Constructor
 */
PIR::PIR(uint8_t pin, uint8_t state) {
  _pin=pin;
  _state=state;
}

/**
 * Begin
 */
void PIR::begin() {
  pinMode(_pin, OUTPUT);
  state(_state);

  Serial.print("Calibrating motion sensor");
  for (int i=0; i<_calibrationTime; i++) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Done.");
}

/**
 * Read Sensor
 * @param  unit8_t readTimeInterval
 * @return unit8_t
 */
uint8_t PIR::read(unit8_t readTimeInterval) {
  unsigned long cTime = (unsigned long) micros()-_lastReadTime;
  if (LOW==_state && cTime<readTimeInterval) _state = digitalRead(_pin);
  return _state;
}

/**
 * Pir state
 * @return integer state
 */
int PIR::state(uint8_t state) {
  if (NULL!=state) { 
    _state = state;
  }
  return(_state);
}

/**
 * Is Pir on
 * @return integer
 */
int PIR::isOn() {
  if (_state==HIGH) 
    return true; 
  else
    return false; 
}

/**
 * Is Pir off
 * @return integer
 */
int PIR::isOff() {
  if (_state==LOW) 
    return true; 
  else
    return false; 
}

void PIR::printState() {
  Serial.println("Motion detection active.");
  Serial.print("Motion is currently ");
  if (isOn()) Serial.println("detected!");
  else Serial.println("not detected.");
}