#include "Pattern.h"

#define LED_PIN D4
#define NUM_LEDS 30
#define BRIGHTNESS 50

Adafruit_NeoPixel leds = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_RGBW + NEO_KHZ800);

void setup(){
  leds.begin();
  leds.setBrightness(BRIGHTNESS);
  leds.show();
}

void loop(){
  leds.pong(255, 0, 0, true, 100); // Red
  leds.clear();
}
