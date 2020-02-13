#include <Adafruit_NeoPixel.h>

#define LED_PIN 2

#define LED_COUNT 3

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show(); 
  strip.setBrightness(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  strip.setPixelColor(0,255,0,0);
  strip.setPixelColor(1,0,255,0);
  strip.setPixelColor(2,0,0,255);
  strip.show();
}
