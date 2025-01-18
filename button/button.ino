int redPin = 8;
int buttonPin = 12;
int dt = 200;
int ledState = 0;
int buttonNew;
int buttonOld = 1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {


  buttonNew = digitalRead(buttonPin);

  if (buttonNew == 1 && buttonOld == 0) {
    if (ledState == 0) {
      digitalWrite(redPin, HIGH);
      ledState = 1;
    } else {
      digitalWrite(redPin, LOW);
      ledState = 0;
    }
  }

  buttonOld = buttonNew;
  delay(dt);
}
