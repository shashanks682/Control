/*
  Timing_control.h - Library for control devices.
  Created by Csermendy Bendeguz, February 13, 2025.
*/

#ifndef Timing_control_h
#define Timing_control_h

#include <Arduino.h>

class Timing_control {
public:
    Timing_control(int pin, unsigned long delayTime);
    bool wait();

private:
    int _pin;
    unsigned long _delayTime;
    unsigned long _lastLowTime;
    bool _lastPinState;
};

#endif
