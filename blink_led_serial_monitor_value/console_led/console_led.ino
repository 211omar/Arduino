String mypin;
String msg = "What color do you want?";
 int red = 5;
 int green = 6;
 int blue = 7;

void setup() {
  Serial.begin(115200);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  Serial.println(msg);
  
  while (!Serial.available()) {
   
  }
  
  mypin = Serial.readStringUntil('\n');
  mypin.toLowerCase();
  mypin.trim();
  
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  

  if (mypin == "red" ) {
    digitalWrite(red, HIGH);
  }
  else if (mypin == "green" ) {
    digitalWrite(green, HIGH);
  }
  else if (mypin == "blue") {
    digitalWrite(blue, HIGH);
  }
}
}





