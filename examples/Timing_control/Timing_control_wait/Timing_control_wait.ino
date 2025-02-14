#include <Timing_control.h>

const int pin = 2; // Define your pin here
const unsigned long delayTime = 1000; // Define your delay time in milliseconds

Timing_control timingControl(pin, delayTime);

void setup() {
    Serial.begin(9600); // Initialize serial communication
}

void loop() {
    bool result = timingControl.wait();
    Serial.println(result); // Write the returned value to the serial monitor
}
