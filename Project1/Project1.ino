#include <Adafruit_NeoPixel.h>


#define LED_PIN 2
#define LED_COUNT 30
const int leds = 30;
const int POTin = A5;
const int BUTTONin = 4;
int potValue = 0;
int potOutputValue = 0;
bool newGame = true;
bool animating = false;
bool match = false;
const int defaultNums = 10;
int numColors = defaultNums;
int colorsList[defaultNums][3];
int playerPos = 0;
uint32_t pColor;
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  //pinMode(2,OUTPUT);
  //digitalWrite(2, HIGH);
  //pinMode(2,OUTPUT);
  pinMode(BUTTONin, INPUT_PULLUP);
  Serial.begin(9600);

  strip.begin();
  strip.show();
  strip.setBrightness(10);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //get value from POT
  potValue = analogRead(POTin);
  potOutputValue = map(potValue, 0,1023,0,255);
  strip.clear();
  //debug printout
  //Serial.print("\n POT = ");
  //Serial.print(potValue);
  //Serial.print(" -> ");
  //Serial.print(potOutputValue);
  //if game is starting

  
  if(newGame == true)
  {
    //get array of random colors
    for(int i = 0; i < numColors; i++)
    {
        getRandomColor(i);
        
    }
    newGame = false;
    
    //set n neopixels to colors in array
  }
  
  //colorsList[0][0] = 255;
  //colorsList[0][1] = 0;
  //colorsList[0][2] = 0;

  //uint32_t current;
  //current = strip.Color(colorsList[0][0],colorsList[0][1],colorsList[0][2]);

  //strip.setPixelColor(29, current);
  
  for(int i = 0; i < numColors; i++)
  {
    uint32_t current;
    current = strip.Color(colorsList[i][0],colorsList[i][1],colorsList[i][2]);

    strip.setPixelColor(leds-(i+1), current);
  }
  
  
  uint32_t color;
  //set color based on POT value
  color = strip.Color(potOutputValue,-1*potOutputValue,255%potOutputValue);


  
  
  //output to color to neopixel strip
  if(animating == true)
  {
    strip.setPixelColor(playerPos, pColor);
  }
  else
  {
    strip.setPixelColor(playerPos, color);
  }
  
  

  //get button state
  if(digitalRead(BUTTONin) == LOW)//start animation 
  {
    
    //uint32_t current;
    //current = strip.Color(colorsList[0][0],colorsList[0][1],colorsList[0][2]);
    match = compareColor(numColors-1);//compare player's color to next on stack
    animating = true;
    pColor = color;//set color so player cant change while animating
    
    
  }
  strip.show();
  //play animation if button was pressed
  if(animating == true)
  {
    
    playerPos++;//move player up
    if(playerPos > leds - numColors+1)
    {//when player reaches top, reset
      playerPos = 0;
      animating = false;
      if(match)
      {
        numColors--;
      }
      if(numColors <= 0)
      {
        numColors = defaultNums;
        newGame = true;
      }
    }
    else
    {//delay so player can see movement
      delay(100);
    }
  }

  
  delay(2);

  //if all colors gone, restart
}

bool compareColor(int index)
{
  int pR = potOutputValue;
  //int pG = -1*potOutputValue;
  //int pB = 255%potOutputValue;

  int tR = colorsList[index][0];
  //int tG = colorsList[index][1];
  //int tB = colorsList[index][2];

  if(pR <= tR + 10 && pR >= tR - 10/* && pG <= tG && 50 && pG >= tG - 50 && pB <= tB + 50 && pB >= tB - 50*/){return true;}
  else{return false;}
  
  
}




void getRandomColor(int index)
{
  //color = strip.Color(potOutputValue,-1*potOutputValue,255%potOutputValue);
  int newColor;
  int seed = random(0,255);
  colorsList[index][0] = seed;
  colorsList[index][1] = -1 * seed;
  colorsList[index][2] = 255%seed;

}
