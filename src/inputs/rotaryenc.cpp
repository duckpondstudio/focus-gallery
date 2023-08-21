#include "../pindefs.h"
#include <Arduino.h>
#include <limits.h>

// ref: https://github.com/PaulStoffregen/Encoder/tree/master/examples

// #define ENCODER_DO_NOT_USE_INTERRUPTS // no interrupts for encoder, handle manually
// #include <Encoder.h>

#include <EncoderButton.h>

// Encoder enc(PIN_INPUT_ROTARY_A, PIN_INPUT_ROTARY_B);

EncoderButton eb1(A4, A5);

// long rotaryPos = LONG_MIN;

void onEb1Encoder(EncoderButton& eb)
{
    Serial.print("eb1 incremented by: ");
    Serial.println(eb.increment());
    Serial.print("eb1 position is: ");
    Serial.println(eb.position());
}

void SetupRotaryEnc()
{
    Serial.println("SETUP ROTARY ENC");
    eb1.setEncoderHandler(onEb1Encoder);
}

void LoopRotaryEnc()
{
    eb1.update();

    // long newPos = enc.read();
    // if (newPos != rotaryPos)
    // {
    //     rotaryPos = newPos;
    //     Serial.print("Position: ");
    //     Serial.println(rotaryPos);
    // }
}

bool RotaryButtonHeld()
{
    return false;
}