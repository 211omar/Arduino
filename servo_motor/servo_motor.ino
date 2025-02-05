#include <Servo.h>

int servoPin = 9;
int servoPos = 0;
int prPin = A5;
int lightVal;
Servo myservo;

void setup() {
  Serial.begin(9600);
  pinMode(servoPin, OUTPUT);
  pinMode(prPin, INPUT);
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

  lightVal = analogRead(prPin);

  Serial.println(lightVal);
  delay(200);


  servoPos = (-0.4 * lightVal) + 240;
  myservo.write(servoPos);

 
}