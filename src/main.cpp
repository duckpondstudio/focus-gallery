#include <Arduino.h>
// #include "FastShiftIn.h"

const byte i1_dataPin = 2;
const byte i1_latchPin = 3;
const byte i1_clockPin = 4;

const byte i2_dataPin = 8;
const byte i2_latchPin = 9;
const byte i2_clockPin = 10;

const byte i1_inputA = 7; // saturation btn
const byte i1_inputB = 6; // brightness btn
const byte i1_inputC = 5; // idle action switch
const byte i1_inputD = 4; // mode select switch
const byte i1_inputE = 3; // main plate pressed
const byte i1_inputF = 2; // encoder button
const byte i1_inputG = 1; //
const byte i1_inputH = 0; //

const byte i2_inputA = 0; // multi-select positions
const byte i2_inputB = 1; // ...
const byte i2_inputC = 2; //
const byte i2_inputD = 3; //
const byte i2_inputE = 4; //
const byte i2_inputF = 5; //
const byte i2_inputG = 6; //
const byte i2_inputH = 7; // ...

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);

    while (!Serial);

    pinMode(i1_dataPin, INPUT);
    pinMode(i2_dataPin, INPUT);
    pinMode(i1_latchPin, OUTPUT);
    pinMode(i2_latchPin, OUTPUT);
    pinMode(i1_clockPin, OUTPUT);
    pinMode(i2_clockPin, OUTPUT);
}

const unsigned long SamplePeriod = 3000; // sampling period in milliseconds

uint8_t isrReadRegister(byte data, byte latch, byte clock)
{
    uint8_t inputs = 0;
    digitalWrite(clock, HIGH);               // preset clock to retrieve first bit
    digitalWrite(latch, HIGH);               // disable input latching and enable shifting
    inputs = shiftIn(data, clock, MSBFIRST); // capture input values
    digitalWrite(latch, LOW);                // disable shifting and enable input latching
    return inputs;
}
int isrDigitalRead(boolean i1, uint8_t pin)
{
    uint8_t value = i1 ? isrReadRegister(i1_dataPin, i1_latchPin, i1_clockPin) : isrReadRegister(i2_dataPin, i2_latchPin, i2_clockPin);
    return bitRead(value, pin);
}
void readInputsWithDigitalRead(boolean i1)
{
    // Read and print individual inputs
    Serial.print(i1 ? "Input 1 " : "Input 2 ");
    Serial.print("Input A = ");
    Serial.println(isrDigitalRead(i1, i1 ? i1_inputA : i2_inputA) ? "HIGH" : "LOW");
    Serial.print(i1 ? "Input 1 " : "Input 2 ");
    Serial.print("Input B = ");
    Serial.println(isrDigitalRead(i1, i1 ? i1_inputB : i2_inputB) ? "HIGH" : "LOW");
    Serial.print(i1 ? "Input 1 " : "Input 2 ");
    Serial.print("Input C = ");
    Serial.println(isrDigitalRead(i1, i1 ? i1_inputC : i2_inputC) ? "HIGH" : "LOW");
    Serial.print(i1 ? "Input 1 " : "Input 2 ");
    Serial.print("Input D = ");
    Serial.println(isrDigitalRead(i1, i1 ? i1_inputD : i2_inputD) ? "HIGH" : "LOW");
    Serial.print(i1 ? "Input 1 " : "Input 2 ");
    Serial.print("Input E = ");
    Serial.println(isrDigitalRead(i1, i1 ? i1_inputE : i2_inputE) ? "HIGH" : "LOW");
    Serial.print(i1 ? "Input 1 " : "Input 2 ");
    Serial.print("Input F = ");
    Serial.println(isrDigitalRead(i1, i1 ? i1_inputF : i2_inputF) ? "HIGH" : "LOW");
    Serial.print(i1 ? "Input 1 " : "Input 2 ");
    Serial.print("Input G = ");
    Serial.println(isrDigitalRead(i1, i1 ? i1_inputG : i2_inputG) ? "HIGH" : "LOW");
    Serial.print(i1 ? "Input 1 " : "Input 2 ");
    Serial.print("Input H = ");
    Serial.println(isrDigitalRead(i1, i1 ? i1_inputH : i2_inputH) ? "HIGH" : "LOW");
    Serial.println();
}

void readInputsWithBinaryValues(boolean i1) {
   // Read and print all inputs from shift register in binary format
   Serial.print("Inputs: 0b");
   uint8_t value = i1 ? isrReadRegister(i1_dataPin, i1_latchPin, i1_clockPin) : isrReadRegister(i2_dataPin, i2_latchPin, i2_clockPin);
   Serial.println(value, BIN);
}


void loop()
{
    // Read and print inputs at the specified sampling rate
    static unsigned long previousTime = 0;
    unsigned long currentTime = millis();
    if (currentTime - previousTime >= SamplePeriod)
    {
        readInputsWithBinaryValues(true);
        // readInputsWithDigitalRead(false);
        previousTime = currentTime;
    }
}