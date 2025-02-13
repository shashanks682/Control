/*
  Timing_control.cpp - Library for control devices.
  Created by Csermendy Bendeguz, February 13, 2025.
*/

#include "Arduino.h"
#include "Timing_control.h"

Timing_control::Timing_control(int pin, unsigned long delayTime) {
    _pin = pin;
    _delayTime = delayTime;
    _lastLowTime = 0;
    _lastPinState = HIGH;
    pinMode(pin, INPUT);
}

bool Timing_control::wait() {
    bool outputState = LOW; // Default to LOW
    bool currentPinState = digitalRead(_pin);

    if (currentPinState == LOW) {
        _lastLowTime = millis();
    } else if (millis() - _lastLowTime >= _delayTime) {
        outputState = HIGH;
    }

    _lastPinState = currentPinState;
    return outputState;
}
