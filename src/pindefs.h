#ifndef PINDEF_H
#define PINDEF_H

#include <stdint.h>
#include <Arduino.h>


// Shift Registers 

const uint8_t PIN_165_TIMER_LOADIN = 8;// timer select, pin 1: PE, SH/LD, Parallel Load In
const uint8_t PIN_165_TIMER_CE = 6;// timer select, chip pin 15: CE, clock enable, chip enable, CLK INH, clock inhibit
const uint8_t PIN_165_TIMER_DATA = 7;// timer select, chip pin 7: _QH_ or _Q7_, complimentary output
const uint8_t PIN_165_TIMER_CLOCK = 9;// timer select, chip pin 2: CP, CLK, Clock in

const uint8_t PIN_165_SOUND_LOADIN = 8;// sound select, pin 1: PE, SH/LD, Parallel Load In
const uint8_t PIN_165_SOUND_CE = 6;// sound select, chip pin 15: CE, clock enable, chip enable, CLK INH, clock inhibit
const uint8_t PIN_165_SOUND_DATA = 7;// sound select, chip pin 7: _QH_ or _Q7_, complimentary output
const uint8_t PIN_165_SOUND_CLOCK = 9;// sound select, chip pin 2: CP, CLK, Clock in

const uint8_t PIN_165_INPUT_LOADIN = 10;// input collect, pin 1: PE, SH/LD, Parallel Load In
const uint8_t PIN_165_INPUT_CE = 12;// input collect, chip pin 15: CE, clock enable, chip enable, CLK INH, clock inhibit
const uint8_t PIN_165_INPUT_DATA = 11;// input collect, chip pin 7: _QH_ or _Q7_, complimentary output
const uint8_t PIN_165_INPUT_CLOCK = 9;// input collect, chip pin 2: CP, CLK, Clock in


// Inputs

const uint8_t PIN_INPUT_ROTARY_A = A4;// data pin A for rotary encoder 
const uint8_t PIN_INPUT_ROTARY_B = A5;// data pin B for rotary encoder
const uint8_t PIN_INPUT_ROTARY_SWITCH = 1;// switch for rotary encoder
const uint8_t PIN_INPUT_BTN_PHONEPLATE = 1;
const uint8_t PIN_INPUT_BTN_LED_BRIGHTNESS = 1;
const uint8_t PIN_INPUT_BTN_LED_SATURATION = 1;
const uint8_t PIN_INPUT_SW_MODE_SELECT = 1;
const uint8_t PIN_INPUT_SW_IDLE_STATE = 1;
const uint8_t PIN_INPUT_SW_POWER = 1;
const uint8_t PIN_INPUT_POT_VOLUME = 1;


// Data 

const uint8_t PIN_DATA_LED = 1;// data output pin for LEDs, must be PWM
const uint8_t PIN_DATA_SPEAKER = 1;// data output pin for audio speaker


#endif