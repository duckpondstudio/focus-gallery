#include "inputManager.h"
#include "inputs/rotaryenc.h"
#include "inputs/buttons.h"

void SetupInputManager() {
    SetupRotaryEnc();
    SetupButtons();
}