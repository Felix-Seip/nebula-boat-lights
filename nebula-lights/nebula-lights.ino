#include <FastLED.h>
#define NUM_LEDs 36
#define DATA_PIN 5
#define UPDATES_PER_SECOND 100
#define LED_GROUP 5

CRGB leds[NUM_LEDs];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDs);
}

void loop() {
  
  //blinkLEDs();
  //groupedLEDs();
}

void turnOnOneAfterTheOther(){
  for(int i = 0; i < NUM_LEDs; i++){
    leds[i] = CRGB(0, 255, 255);
    delay(1000 / UPDATES_PER_SECOND);
  }
  resetAllLEDs(true, true);
}

void blinkLEDs(){
  for(int i = 0; i < NUM_LEDs; i++){
    leds[i] = CRGB(0, 255, 255);
  }
  
  delay(1000 / UPDATES_PER_SECOND);
  resetAllLEDs(false, true);
  delay(1000 / UPDATES_PER_SECOND);
    FastLED.show();
}

void groupedLEDs() {
  bool start = true;
  if(start){
    for(int i = 0; i < 5; i++){
      leds[i] = CRGB(0, 255, 255);
      FastLED.delay(1000 / UPDATES_PER_SECOND);
    }
    start = false;
  }
  
  FastLED.show();
  
  for(int i = 4; i < NUM_LEDs; i++){
    leds[i + 1] = CRGB(0, 255, 255);
    leds[i - 4] = CRGB(0, 0, 0);
    FastLED.delay(1000 / UPDATES_PER_SECOND);
  }
  start = true;
  resetAllLEDs(true, false);
}

void resetAllLEDs(const bool withDelay, const bool resetAtBeginning){
  for(int i = resetAtBeginning ? 0 : NUM_LEDs - LED_GROUP; i < NUM_LEDs; i++){
    leds[i] = CRGB(0, 0, 0);
    if(withDelay){
      FastLED.delay(1000 / UPDATES_PER_SECOND);
    }
  }
}
