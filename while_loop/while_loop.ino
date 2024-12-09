int redPin = 7;
int potVal;
int potPin = A0;
int delayTime = 200;
void setup() {
  // put your setup code here, to run once:
  pinMode(potPin, INPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  Serial.println(potVal);
  delay(delayTime);


  while (potVal > 1000) {
    digitalWrite(redPin, HIGH);
    potVal = analogRead(potPin);
    Serial.println(potVal);
    delay(delayTime);
  }
  digitalWrite(redPin, LOW);
}
