int blinkNum;
int redPin = 13;
int delayTime = 200;
void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Enter your blink number: ");

  while (Serial.available() == 0) {
  }

  if (Serial.available() > 0) {

    blinkNum = Serial.parseInt();

    for (int i = 1; i <= blinkNum; i++) {
      digitalWrite(redPin, HIGH);
      delay(delayTime);
      digitalWrite(redPin, LOW);
      delay(delayTime);
    }
  }
}
