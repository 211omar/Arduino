int redPin = 5;
int greenPin = 6;
int bluePin = 7;
void setup() {
  // Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // setColor(255,0,0);


  int ran1= random(256);
  int ran2= random(256);
  int ran3= random(256);
  // Serial.println(ran1);
  // Serial.println(ran2);
  // Serial.println(ran3);

  setColor(ran1,ran2,ran3);
  delay(2000);



}

void setColor(int redValue,int greenValue,int blueValue){
  // analogWrite(redPin, redValue);
  // analogWrite(greenPin, greenValue);
  // analogWrite(bluePin, blueValue);
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
