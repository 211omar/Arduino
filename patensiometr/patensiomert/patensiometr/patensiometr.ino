int myVoltPin = A1;
int readVal;
float V2;
int delayTime= 250;
int myPin = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(myVoltPin, INPUT);
  pinMode(myPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal=analogRead(myVoltPin);
  V2= (5./1023.)* readVal;
  Serial.println(V2);

  
  // if (V2>2.0 && V2<3.0) {
  //   digitalWrite(myPin, HIGH);
  // }else {
  // digitalWrite(myPin, LOW);
  // }
  delay(delayTime);
}
