

const int input = A2;
int potValue = 0;
int potOutputValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  digitalWrite(2, HIGH);


  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  potValue = analogRead(input);
  potOutputValue = map(potValue, 0,1023,0,255);


  Serial.print("\n POT = ");
  Serial.print(potValue);
  Serial.print(" -> ");
  Serial.print(potOutputValue);

  delay(2);
}
