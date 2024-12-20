int buzzPin = 2;
int lightPin = A0;
int lightVal;
int lowLightDelay = 20;
int highLightDelay = 500;
int delayT;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(lightPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:


  lightVal = analogRead(lightPin);
  // Serial.println(lightVal);
  // delayMicroseconds(50);
  delayT = (9. / 550.) * lightVal - (1800. / 550.) + 1.;

  // if (lightVal > 180) {
  //   digitalWrite(buzzPin, HIGH);
  //   delayMicroseconds(highLightDelay);
  //   digitalWrite(buzzPin, LOW);
  //   delayMicroseconds(highLightDelay);
  // } else {

  //   digitalWrite(buzzPin, HIGH);
  //   delayMicroseconds(lowLightDelay);
  //   digitalWrite(buzzPin, LOW);
  //   delayMicroseconds(lowLightDelay);
  // }

  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(delayT);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(delayT);
}
