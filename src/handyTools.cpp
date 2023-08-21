#include <Arduino.h>
#include "handyTools.h"

void ReadByte(byte b) {
    Serial.print("Byte: ");
    for (int i = 0; i < 8; i++)
    {
        Serial.print(bitRead(b, i));
    }
    Serial.print(" = ");
    Serial.println(b);
}