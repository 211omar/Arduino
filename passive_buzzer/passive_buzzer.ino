int potPin = A0;
int potVal;
int buzzer = 8;
int tonee;
//lowest good tone is 10000 microseconds
//highest good tone is 60 microseconds

int buzzTime = 5;
float buzzTime2 = 100;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // digitalWrite(buzzer, HIGH);
  // //accespts microseconds
  // delayMicroseconds(buzzTime2);
  // digitalWrite(buzzer, LOW);
  // delayMicroseconds(buzzTime2);



  potVal= analogRead(potPin);

 

  tonee = (9940./1023.)*potVal+60;


  digitalWrite(buzzer, HIGH);
  delayMicroseconds(tonee);
  digitalWrite(buzzer, LOW);
  delayMicroseconds(tonee);

  //  Serial.print("potensioment value: ");
  // Serial.println(potVal);

  // delay(1000);

  //   Serial.print("microseconds: ");
  // Serial.println(tonee);

  // Serial.println();

}
