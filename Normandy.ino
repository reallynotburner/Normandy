/*
  SSV Normandy SR1
  Scale model of the BioWare video game Mass Effect 1 & 2 spacecraft "Normandy"
  The "engines" light up with a flickering to imply power, and to resemble the loading screen animations.
  The "portholes" flicker more slowly and with greater amplitude to imply crew members moving around inside.

  I am limiting the microcontroller to 4 mA current per output.  I'm using two DRV8871 h-bridge drivers to power
  of the LED's to their full 20 mA capacity.

  Pinouts
  0 - low battery warning / collision navigation strobes
  1 - 
  4 - port outboard engine
  5 - port inboard engine
  8 - starboard inboard engine
  9 - starboard outboard engine
  16 -
  18 -
  19 -
  26 - 
  27 - brightness adjustment input
  29 - battery voltage monitor
*/

#include <FastLED.h>

const int hp_1 = 4;
const int hp_2 = 5;
const int hp_3 = 8;
const int hp_4 = 9;


void setup() {
    initShip();
}

void loop() {
  // service the engine animation frequently
  animateEngines();
}

void animateEngines() { // consider allowing a variable to be passed for intensity
  // Use millis() scaled down as the time coordinate for the noise function
  uint32_t timeCoord = millis() * 1; // Multiplier controls the flicker speed
  
  // inoise8 generates a smooth value between 0 and 255
  uint8_t noiseVal1 = inoise8(timeCoord);
  uint8_t noiseVal2 = inoise8(timeCoord + 55555);
  uint8_t noiseVal3 = inoise8(timeCoord + 77777);
  uint8_t noiseVal4 = inoise8(timeCoord + 99999);

  // Map the noise output to a rocket brightness
  // 150 to 255 seems a match for the loading screen animations
  // 0 to 255 and a time factor of .02 to .04 could animate porthole lights
  int brightness1 = map(noiseVal1, 0, 255, 150, 255);
  int brightness2 = map(noiseVal2, 0, 255, 150, 255);
  int brightness3 = map(noiseVal3, 0, 255, 150, 255);
  int brightness4 = map(noiseVal4, 0, 255, 150, 255);

  lightA(brightness1);
  lightB(brightness2);
  lightC(brightness3);
  lightD(brightness4);
}

void allOn() {
  lightA(255);
  lightB(255);
  lightC(255);
  lightD(255);
}

void allStop() {
  lightA(0);
  lightB(0);
  lightC(0);
  lightD(0);
}

void lightA(int brightness) {
  analogWrite(hp_1, brightness);
}

void lightB(int brightness) {
  analogWrite(hp_2, brightness);
}

void lightC(int brightness) {
  analogWrite(hp_3, brightness);
}

void lightD(int brightness) {
  analogWrite(hp_4, brightness);
}

void initShip() {
    pinMode(hp_1, OUTPUT);
    pinMode(hp_2, OUTPUT);
    pinMode(hp_3, OUTPUT);
    pinMode(hp_4, OUTPUT);
}
