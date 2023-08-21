#include "shiftRegInput.h"
#include <SandTimer.h>
#include "../pindefs.h"
#include "../handyTools.h"

const int updateInterval = 50;

// ShiftRegisterInput
class ShiftRegisterInput
{
private:
    byte updateStep = 0;

public:
    SandTimer intervalTimer;
    byte data = 0;
    byte pin_Load;
    byte pin_Clock;
    byte pin_ChipEnable;
    byte pin_Data;
    ShiftRegisterInput(byte PIN_LOAD, byte PIN_CLOCK, byte PIN_CE, byte PIN_DATA)
    {
        pin_Load = PIN_LOAD;
        pin_Clock = PIN_CLOCK;
        pin_ChipEnable = PIN_CE;
        pin_Data = PIN_DATA;
        pinMode(pin_Load, OUTPUT);
        pinMode(pin_Clock, OUTPUT);
        pinMode(pin_ChipEnable, OUTPUT);
        pinMode(pin_Data, INPUT);
        updateStep = 0;
    }
    // call via loop, handles shift register update
    void Update()
    {
        switch (updateStep)
        {
        default:
        case 0:
            // case 0, default, waiting for timer interval
            intervalTimer.start(updateInterval);
            if (intervalTimer.finished())
            {
                updateStep = 1;
            }
            break;
        case 1:
            // pulse low to load pin
            digitalWrite(pin_Load, LOW);
            // delayMicroseconds(5);
            intervalTimer.start(1);
            if (intervalTimer.finished())
            {
            updateStep = 2;
            }
            break;
        case 2:
            // pulse high to load pin
            digitalWrite(pin_Load, HIGH);
            intervalTimer.start(1);
            if (intervalTimer.finished())
            {
            // delayMicroseconds(5);
            updateStep = 3;
            }
            break;
        case 3:
            // read data
            digitalWrite(pin_Clock, HIGH);
            digitalWrite(pin_ChipEnable, LOW);
            data = shiftIn(pin_Data, pin_Clock, LSBFIRST);
            digitalWrite(pin_ChipEnable, HIGH);
            // done!
            updateStep = 0;
            DebugOutputData();
            break;
        }
    }
    // forces a shift register state update, if one is not already occurring
    void ForceUpdate()
    {
        if (updateStep == 0)
        {
            intervalTimer.reset();
            updateStep = 1;
        }
        Update();
    }
    // Is the given pinNum (0-7, bit from byte data) enabled?
    bool PinEnabled(byte pinNum)
    {
        return bitRead(data, pinNum);
    }
    void DebugOutputData()
    {
        ReadByte(data);
    }
};

ShiftRegisterInput sriTimer(PIN_165_TIMER_LOADIN, PIN_165_TIMER_CLOCK, PIN_165_TIMER_CE, PIN_165_TIMER_DATA);
ShiftRegisterInput sriInput(PIN_165_INPUT_LOADIN, PIN_165_INPUT_CLOCK, PIN_165_INPUT_CE, PIN_165_INPUT_DATA);
ShiftRegisterInput sriSound(PIN_165_SOUND_LOADIN, PIN_165_SOUND_CLOCK, PIN_165_SOUND_CE, PIN_165_SOUND_DATA);

void SetupShiftRegInput()
{
}

void LoopShiftRegInput()
{
    sriTimer.Update();
}