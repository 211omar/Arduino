#include <Servo.h>
int xPin = A0;
int YPin = A1;
int xVal;
int yVal;
int sVal;
int switchPin = 3;
int servoPin = 9;
int servoPos = 0;
int buzzPin = 13;
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(YPin  ,INPUT);
  pinMode(switchPin, INPUT);
  myservo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:


  xVal = analogRead(xPin);
  yVal  = analogRead(YPin);
  sVal = digitalRead(switchPin);
  Serial.print("X: ");
  Serial.println(xVal);
  Serial.print("Y: ");
  Serial.println(yVal);
  Serial.print("switch: ");
  Serial.println(sVal);
  delay(250);

  servoPos = (180./1023.) *xVal;
  

  myservo.write(servoPos);





  }
