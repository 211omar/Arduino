int redPin = 11;
int buzzPin = 12;  //passive buzzer
int button_first_pin = 2;
int button_second_pin = 3;
int valOne;
int valTwo;
int analogVal = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(button_first_pin, INPUT);
  pinMode(button_second_pin, INPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  valOne = digitalRead(button_first_pin);
  valTwo = digitalRead(button_second_pin);

  // Serial.print("value of first: ");
  // Serial.println(valOne);
  // Serial.print("Value of second: ");
  // Serial.println(valTwo);
  // delay(500);


  while (valTwo == 0) {
    if (analogVal >= 255) {
      return;
    }

    analogWrite(redPin, analogVal+=5);
    delay(50);
    valTwo = digitalRead(button_second_pin);
    digitalWrite(buzzPin, HIGH);
    delayMicroseconds(1);
    digitalWrite(buzzPin, LOW);
    delayMicroseconds(1);
  }
  while (valOne == 0) {
    if (analogVal <= 0) {
      return;
    }
    analogWrite(redPin, analogVal-=5);
    delay(50);
    valOne = digitalRead(button_first_pin);
    digitalWrite(buzzPin, HIGH);
    delayMicroseconds(1);
    digitalWrite(buzzPin, LOW);
    delayMicroseconds(1);
  }
}