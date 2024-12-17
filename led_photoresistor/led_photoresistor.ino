int lightPin = A0;
int lightVal;
int dt = 250;
int greenPin = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(lightPin, INPUT);

  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  delay(dt);

  if (lightVal > 550) {
    digitalWrite(greenPin, LOW);

  } else {
    digitalWrite(greenPin, HIGH);
  }
}
