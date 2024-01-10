#include <Arduino.h>
#include "inputManager.h"


void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);

    SetupInputManager();
}


void loop()
{
    LoopInputManager();
}