// int mynum;
// int potVal;
// int potPin = A0;
int buzzer = 8;
int dt1 = 1;
int dt2 = 2;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {

  //active buzz for pot value
  // potVal = analogRead(potPin);
  // Serial.println(potVal);
  // Serial.println();
  // delay(500);
  // if (potVal > 1000) {
  //   digitalWrite(buzzer, HIGH);
  // }else{
  //   digitalWrite(buzzer, LOW);
  // }

  //active buzz for number
  // Serial.println("Enter your number: ");
  // while (!Serial.available()) {

  // }
  // mynum=0;
  // mynum= Serial.parseInt();
  // if (mynum>10) {
  //   digitalWrite(buzzer, HIGH);
  //   delay(200);
  //   digitalWrite(buzzer, LOW);
  // }


  //changing tone of active buzzer
  for (int j = 1; j<=100; j++) {
      digitalWrite(buzzer, HIGH);
      delay(dt1);
      digitalWrite(buzzer, LOW);
      delay(dt1);

  }
  for (int j = 1; j<=100; j++) {
      digitalWrite(buzzer, HIGH);
      delay(dt2);
      digitalWrite(buzzer, LOW);
      delay(dt2);

  }




}
