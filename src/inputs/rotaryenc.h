#ifndef ROTARYENC_H
#define ROTARYENC_H

#include <Arduino.h>
// #define ENCODER_DO_NOT_USE_INTERRUPTS // no interrupts for encoder, handle manually 
// #include <Encoder.h>

extern void SetupRotaryEnc();
extern void LoopRotaryEnc();
extern bool RotaryButtonHeld();

// Encoder enc(uint8_t pin1, uint8_t pin2);

#endif