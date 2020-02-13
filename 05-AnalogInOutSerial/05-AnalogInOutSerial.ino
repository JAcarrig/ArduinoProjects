/*
  Analog input, serial output, WS2812 out

  Reads multiple analog input pins, maps the results to a range from 0 to 255 and uses
  the result to drive a Neopixel Array.
  Also prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground

  Based on:
  http://www.arduino.cc/en/Tutorial/AnalogInOutSerial
*/

// These constants won't change. They're used to give names to the pins used:
const int analogInPOTPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogInCDSPin = A1;  // Analog input pin that the CDS cell is attached to
const int analogInThermisterPin = A5;  // Analog input pin that the CDS cell is attached to

int potValue = 0;        // value read from the pot
int cdsValue = 0;        // value read from the CDS cell
int thermisterValue = 0; // value read from the thermistert
int potOutputValue = 0;  // value output to the
int cdsOutputValue = 0;  // value output to the
int thermisterOutputValue = 0;  // value output to the

void setup() {
  // initialize serial communications at 115200 bps:
  Serial.begin(115200);
}

void loop() {
  // read the POT analog value:
  potValue = analogRead(analogInPOTPin);
  // map it to the range of the analog out:
  potOutputValue = map(potValue, 0, 1023, 0, 255);

  // read the CDS cell analog value:
  cdsValue = analogRead(analogInCDSPin);
  // map it to the range of the analog out:
  cdsOutputValue = map(cdsValue, 0, 1023, 0, 255);

  // read the thermister analog value:
  thermisterValue = analogRead(analogInThermisterPin);
  // map it to the range of the analog out:
  thermisterOutputValue = map(thermisterValue, 0, 1023, 0, 255);

  // print the results to the Serial Monitor:
  Serial.print("POT = ");
  Serial.print(potValue);
  Serial.print(" -> ");
  Serial.print(potOutputValue);

  Serial.print(",\t CDS = ");
  Serial.print(cdsValue);
  Serial.print(" -> ");
  Serial.print(cdsOutputValue);

  Serial.print(",\t Therm = ");
  Serial.print(thermisterValue);
  Serial.print(" -> ");
  Serial.println(thermisterOutputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
