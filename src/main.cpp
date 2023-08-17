#include <Arduino.h>
#include "FastShiftIn.h"

/*
  74HC165 Shift Register Demonstration 1
  74hc165-demo.ino
  Read from 8 switches and display values on serial monitor

  DroneBot Workshop 2020
  https://dronebotworkshop.com
*/

// Define Connections to 74HC165

// PL pin 1
int load = 10;
// CE pin 15
int clockEnablePin = 12;
// Q7 pin 7
int dataIn = 11;
// CP pin 2
int clockIn = 9;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);

    while (!Serial)
        ;

    // Setup 74HC165 connections
    pinMode(load, OUTPUT);
    pinMode(clockEnablePin, OUTPUT);
    pinMode(clockIn, OUTPUT);
    pinMode(dataIn, INPUT);
}

const unsigned long SamplePeriod = 500; // sampling period in milliseconds

void loop()
{
    // Read and print inputs at the specified sampling rate
    static unsigned long previousTime = 0;
    unsigned long currentTime = millis();
    if (currentTime - previousTime >= SamplePeriod)
    {
        // interval trigger

        // Write pulse to load pin
        digitalWrite(load, LOW);
        delayMicroseconds(5);
        digitalWrite(load, HIGH);
        delayMicroseconds(5);

        // Get data from 74HC165
        digitalWrite(clockIn, HIGH);
        digitalWrite(clockEnablePin, LOW);
        byte incoming = shiftIn(dataIn, clockIn, LSBFIRST);
        digitalWrite(clockEnablePin, HIGH);

        // Print to serial monitor
        Serial.print("Pin States:\r\n");
        Serial.println(incoming, BIN);

        previousTime = currentTime;
    }
}