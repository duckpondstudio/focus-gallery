#ifndef PINDEF_H
#define PINDEF_H


#pragma region Shift Registers 

__uint128_t PIN_165_TIMER_LOADIN = 1;// timer select, pin 1: PE, SH/LD, Parallel Load In
__uint128_t PIN_165_TIMER_CE = 1;// timer select, chip pin 15: CE, clock enable, chip enable, CLK INH, clock inhibit
__uint128_t PIN_165_TIMER_DATA = 1;// timer select, chip pin 7: _QH_ or _Q7_, complimentary output
__uint128_t PIN_165_TIMER_CLOCK = 1;// timer select, chip pin 2: CP, CLK, Clock in

__uint128_t PIN_165_SOUND_LOADIN = 1;// sound select, pin 1: PE, SH/LD, Parallel Load In
__uint128_t PIN_165_SOUND_CE = 1;// sound select, chip pin 15: CE, clock enable, chip enable, CLK INH, clock inhibit
__uint128_t PIN_165_SOUND_DATA = 1;// sound select, chip pin 7: _QH_ or _Q7_, complimentary output
__uint128_t PIN_165_SOUND_CLOCK = 1;// sound select, chip pin 2: CP, CLK, Clock in

__uint128_t PIN_165_INPUT_LOADIN = 1;// input collect, pin 1: PE, SH/LD, Parallel Load In
__uint128_t PIN_165_INPUT_CE = 1;// input collect, chip pin 15: CE, clock enable, chip enable, CLK INH, clock inhibit
__uint128_t PIN_165_INPUT_DATA = 1;// input collect, chip pin 7: _QH_ or _Q7_, complimentary output
__uint128_t PIN_165_INPUT_CLOCK = 1;// input collect, chip pin 2: CP, CLK, Clock in

#pragma endregion Shift Registers

#pragma region Inputs

__uint128_t PIN_INPUT_ROTARY_A = 1;// data pin A for rotary encoder 
__uint128_t PIN_INPUT_ROTARY_B = 1;// data pin B for rotary encoder
__uint128_t PIN_INPUT_ROTARY_SWITCH = 1;// switch for rotary encoder
__uint128_t PIN_INPUT_BTN_PHONEPLATE = 1;
__uint128_t PIN_INPUT_BTN_LED_BRIGHTNESS = 1;
__uint128_t PIN_INPUT_BTN_LED_SATURATION = 1;
__uint128_t PIN_INPUT_SW_MODE_SELECT = 1;
__uint128_t PIN_INPUT_SW_IDLE_STATE = 1;
__uint128_t PIN_INPUT_SW_POWER = 1;
__uint128_t PIN_INPUT_POT_VOLUME = 1;

#pragma endregion Inputs


#pragma region Data 

__uint128_t PIN_DATA_LED = 1;// data output pin for LEDs, must be PWM
__uint128_t PIN_DATA_SPEAKER = 1;// data output pin for audio speaker

#pragma endregion Data 


#endif