int j = 1;
String mystr = "j = ";
int delaytime=2000;
float radius = 2;
float pi= 3.14;
float area;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  area = pi*radius*radius;
  Serial.print("Radiusu ");
  Serial.print(radius);
  Serial.print(" olan dairenin sahesi ");
  Serial.print(area);
  Serial.println(" qederdir.");
  radius+=.5;

  delay(delaytime);
}
