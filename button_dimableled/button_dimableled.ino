int redPin = 11;
int button_first_pin = 2;
int button_second_pin = 3;
int valOne;
int valTwo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(button_first_pin, INPUT);
  pinMode(button_second_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  valOne= digitalRead(button_first_pin);
  valTwo= digitalRead(button_second_pin);
  Serial.print("value of first: ");
  Serial.println(valOne);
  Serial.print("Value of second: ");
  Serial.println(valTwo);
  delay(500);


  while (valTwo == 0) {
  analogWrite(redPin, 1++);
  }
}