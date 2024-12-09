int potPin = A1;
int led = 11;
int potVal;
float ledVal;
void setup() {
  // put your setup code here, to run once:
  pinMode(potPin, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  ledVal=(255./1023.)*potVal;
  analogWrite(led, ledVal);
  Serial.print("Pot value: ");
  Serial.println(potVal);
  Serial.print("LED value: ");
  Serial.println(ledVal);

  delay(1000);
}
