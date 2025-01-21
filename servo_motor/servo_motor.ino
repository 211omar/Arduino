#include <Servo.h>

int servoPin = 9;
int servoPos = 0;
int prPin = A5;
int prVal;
Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);
}

void loop() {
  // Serial.println("Enter angle (0-180): ");

  // while (!Serial.available()) {}  // Wait for input

  // servoPos = Serial.parseInt();

  // // Clear the buffer
  // while(Serial.available()) {
  //   Serial.read();
  // }

  // // Bounds checking
  // if (servoPos >= 0 && servoPos <= 180) {
  //   myservo.write(servoPos);
  // } else {
  //   Serial.println("Invalid angle! Please enter a value between 0 and 180.");
  // }



  Serial.print("The light value is: ");
  prVal = analogRead(prPin);

  Serial.println(prVal);


  if (prVal < 450) {
    servoPos = 90;
    myservo.write(servoPos);
  }
  if (prVal > 450) {
    servoPos = 180;
    myservo.write(servoPos);
  }

  delay(200);
}