#include <Adafruit_NeoPixel.h>

/*
  Input Pull-up Serial

  This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a digital
  input on pin 2 and prints the results to the Serial Monitor.

  The circuit:
  - momentary switch attached from pin 2 to ground
  - built-in LED on pin 13

  Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
  20K-ohm resistor is pulled to 5V. This configuration causes the input to read
  HIGH when the switch is open, and LOW when it is closed.

  created 14 Mar 2012
  by Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/InputPullupSerial
*/


#define LED_PIN    2

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 30

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int ledOn;

void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  ledOn = 0;
  pinMode(9, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  strip.begin();
  
  strip.show();
  strip.setBrightness(50);
}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(9);
  //print out the value of the pushbutton
  Serial.println(sensorVal);
  strip.setBrightness(50);
  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  //strip.show();
  uint32_t color;
  strip.clear();
  color = strip.Color(0,254,204);
  if (sensorVal == HIGH) {
    if(ledOn > 0){ledOn--;}
  } else {
    if(ledOn < 29){ledOn++;}
    else{ledOn=0;}
  }
  strip.setPixelColor(ledOn, color);
  strip.setPixelColor(ledOn-1, 0,234,100);
  strip.setPixelColor(ledOn-2, 0,214,50);
  strip.setPixelColor(ledOn-3, 0,194,0);
    for(int i = 0; i < 29, i++)
    {
      strip.setPixelColor(ledOn-i, color);
    }
  }
  strip.show();
  delay(20);
}
