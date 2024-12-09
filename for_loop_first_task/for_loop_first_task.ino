int greenPin = 6;
int yellowPin = 9;
int yellowTime = 500;
int greenTime = 500;
int yellowBlink = 5;
int greenBlink = 3;
int j;
void setup() {
  // put your setup code here, to run once:
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//yellow

for(j=1; j<=yellowBlink; j++){
  digitalWrite(yellowPin, HIGH);
  delay(yellowTime);
  digitalWrite(yellowPin, LOW);
  delay(yellowTime);
}

//green

for(j=1;j<=greenBlink;j++){
 digitalWrite(greenPin, HIGH);
  delay(greenTime);
  digitalWrite(greenPin, LOW);
  delay(greenTime);
}

}
