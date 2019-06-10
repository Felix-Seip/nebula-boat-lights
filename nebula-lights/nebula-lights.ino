#include <FastLED.h>
#define NUM_LEDs = 10

CRGB leds[NUM_LEDs];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDs);
}

void loop() {
  for(int i = 0; i < NUM_LEDs; i++){
    leds[i] = CRGB(255, 255, 255);
    delay(500);
  }
}
