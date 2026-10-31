#include <FastLED.h>

const int hp_1 = 8;
const int hp_3 = 4;


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
  uint8_t noiseVal = inoise8(timeCoord);
  uint8_t noiseVal2 = inoise8(timeCoord + 55555);

  // Map the noise output to a rocket brightness
  // 150 to 255 seems a match for the loading screen animations
  // 0 to 255 and a time factor of .02 to .04 could animate porthole lights
  int brightness = map(noiseVal, 0, 255, 150, 255);
  int brightness2 = map(noiseVal2, 0, 255, 150, 255);

  lightA(brightness);
  lightB(brightness2);
}

void allOn() {
  lightA(255);
  lightB(255);
}

void allStop() {
  lightA(0);
  lightB(0);
}

void lightA(int brightness) {
  analogWrite(hp_1, brightness);
}

void lightB(int brightness) {
  analogWrite(hp_3, brightness);
}

void initShip() {
    pinMode(hp_1, OUTPUT);
    pinMode(hp_3, OUTPUT);
}
