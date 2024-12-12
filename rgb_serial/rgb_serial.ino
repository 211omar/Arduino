int red = 8;
int green = 9;
int blue = 10;

String mycolor;
String msg = "What color fo you want?";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);

  while (!Serial.available()) {
  }

  mycolor = Serial.readStringUntil("\n");
  mycolor.trim();
  mycolor.toLowerCase();

  if (mycolor == "red") {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  } else if (mycolor == "green") {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
  } else if (mycolor == "blue") {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
  } else if (mycolor == "aqua") {
    digitalWrite(red, LOW);
    analogWrite(green, 165);
    analogWrite(blue, 100);
  } else if (mycolor == "off") {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  } else {
    Serial.println("NO such a colour!");
  }
}
