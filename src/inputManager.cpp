#include "inputManager.h"
#include "inputs/rotaryenc.h"
#include "inputs/buttons.h"
#include "inputs/shiftRegInput.h"

void SetupInputManager() {
    SetupShiftRegInput();
    SetupRotaryEnc();
    SetupButtons();
}

void LoopInputManager() {
    LoopShiftRegInput();
    LoopRotaryEnc();
}