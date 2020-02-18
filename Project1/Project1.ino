#include <Adafruit_NeoPixel.h>


#define LED_PIN 2
#define LED_COUNT 3
const int POTin = A5;
const int BUTTONin = A4;
int potValue = 0;
int potOutputValue = 0;
bool newGame = true;
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  //pinMode(2,OUTPUT);
  //digitalWrite(2, HIGH);
  //pinMode(2,OUTPUT);
  pinMode(5, INPUT_PULLUP);
  Serial.begin(9600);

  strip.begin();
  strip.show();
  strip.setBrightness(10);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //get value from POT
  potValue = analogRead(POTin);
  potOutputValue = map(potValue, 0,1023,0,16777216);
  strip.clear();
  //debug printout
  Serial.print("\n POT = ");
  Serial.print(potValue);
  Serial.print(" -> ");
  Serial.print(potOutputValue);
  //if game is starting
    //get array of random colors

    //set n neopixels to colors in array



  
  uint32_t color;
  //set color based on POT value
  int red = (potOutputValue >> 16) & 0xFF;
  int green = (potOutputValue >> 8) & 0xFF;
  int blue = (potOutputValue) & 0xFF;
  
  color = strip.Color(red,green,blue);
  //output to color to neopixel strip
  strip.setPixelColor(0, color);

  //get button state
  if(digitalRead(5) == LOW)
  {
    //do color comparision

    //if comparision returns true, delete color from array
    
    //play animation
  }

  strip.show();
  delay(2);


  //if all colors gone, restart

  
}

bool compareColor(int targetColor, int playerColor)
{
  if(playerColor <= targetColor + 100 && playerColor >= targetColor - 100){return true;}
  else{return false;}
  
}

void hexConverter(int baseNumber)
{
  int values[3];
  int red = (baseNumber >> 16) & 0xFF;
  int green = (baseNumber >> 8) & 0xFF;
  int blue = (baseNumber) & 0xFF;
  values[0] = red;
  values[1] = green;
  values[3] = blue;
  return values;
}
