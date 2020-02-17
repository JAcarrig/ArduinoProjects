#include <Adafruit_NeoPixel.h>


#define LED_PIN 2
#define LED_COUNT 3
const int input = A2;
int potValue = 0;
int potOutputValue = 0;
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  //pinMode(2,OUTPUT);
  //digitalWrite(2, HIGH);
  Serial.begin(9600);

  strip.begin();
  strip.show();
  strip.setBrightness(50);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  potValue = analogRead(input);
  potOutputValue = map(potValue, 0,1023,0,255);


  Serial.print("\n POT = ");
  Serial.print(potValue);
  Serial.print(" -> ");
  Serial.print(potOutputValue);

  uint32_t color;
  strip.clear();
  //set color based on POT value
  color = strip.Color(potOutputValue,0,0);
  //output to color to neopixel strip
  strip.setPixelColor(0, color);

  strip.show();
  delay(2);

  
}
