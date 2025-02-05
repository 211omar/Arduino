int xPin = A0;
int xVal;
int yVal;
int YPin = A1;
int switchPin = 2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(YPin  ,INPUT);
  pinMode(switchPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(xPin);
  yVal  = analogRead(YPin);

  Serial.print("X: ");
  Serial.println(xVal);
  Serial.print("Y: ");
  Serial.println(yVal);
  delay(250);
  }
