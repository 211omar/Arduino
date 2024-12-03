int LED_one = 8;
int LED_two = 7;
int LED_three = 6;
int LED_four = 5;


void setup() {
  // put your setup code here, to run once:

  pinMode(LED_one, OUTPUT);
  pinMode(LED_two, OUTPUT);
  pinMode(LED_three, OUTPUT);
  pinMode(LED_four, OUTPUT);
}

void loop() {

  //put your main code here, to run repeatedly:
  //1
  digitalWrite(LED_one, HIGH);
  delay(200);
  digitalWrite(LED_one, LOW);
  delay(200);

  delay(1000);
  //2

  digitalWrite(LED_two, HIGH);
  delay(200);
  digitalWrite(LED_two, LOW);
  delay(200);

  delay(1000);


  //3
  digitalWrite(LED_one, HIGH);
  digitalWrite(LED_two, HIGH);
  delay(200);

  digitalWrite(LED_one, LOW);
  digitalWrite(LED_two, LOW);
  delay(200);

  delay(1000);

  //4

  digitalWrite(LED_three, HIGH);
  delay(200);
  digitalWrite(LED_three, LOW);
  delay(200);

  delay(1000);


  //5
  digitalWrite(LED_one, HIGH);
  digitalWrite(LED_three, HIGH);
  delay(200);
  digitalWrite(LED_one, LOW);
  digitalWrite(LED_three, LOW);
  delay(200);


  delay(1000);


  //6
  digitalWrite(LED_two, HIGH);
  digitalWrite(LED_three, HIGH);

  delay(200);
  digitalWrite(LED_two, LOW);
  digitalWrite(LED_three, LOW);

  delay(200);


  delay(1000);

  //7

  digitalWrite(LED_two, HIGH);
  digitalWrite(LED_three, HIGH);
  digitalWrite(LED_one, HIGH);

  delay(200);
  digitalWrite(LED_two, LOW);
  digitalWrite(LED_three, LOW);
  digitalWrite(LED_one, LOW);


  delay(200);


  delay(1000);


  //8
  digitalWrite(LED_four, HIGH);
  delay(200);
  digitalWrite(LED_four, LOW);
  delay(200);


  delay(1000);

  //9
  digitalWrite(LED_four, HIGH);
  digitalWrite(LED_one, HIGH);

  delay(200);

  digitalWrite(LED_four, LOW);
  digitalWrite(LED_one, LOW);

  delay(200);


  delay(1000);

  //10
  digitalWrite(LED_four, HIGH);
  digitalWrite(LED_two, HIGH);

  delay(200);

  digitalWrite(LED_four, LOW);
  digitalWrite(LED_two, LOW);

  delay(200);


  delay(1000);

  //11
  digitalWrite(LED_four, HIGH);
  digitalWrite(LED_two, HIGH);
  digitalWrite(LED_one, HIGH);

  delay(200);

  digitalWrite(LED_four, LOW);
  digitalWrite(LED_two, LOW);
  digitalWrite(LED_one, LOW);


  delay(200);


  delay(1000);

  //12
  digitalWrite(LED_four, HIGH);
  digitalWrite(LED_three, HIGH);

    delay(200);

  digitalWrite(LED_four, LOW);
  digitalWrite(LED_three, LOW);



    delay(200);


  delay(1000);

  //13
  digitalWrite(LED_four, HIGH);
  digitalWrite(LED_three, HIGH);
    digitalWrite(LED_one, HIGH);

      delay(200);

  digitalWrite(LED_four, LOW);
  digitalWrite(LED_three, LOW);
    digitalWrite(LED_one, LOW);



      delay(200);


  delay(1000);

  //14
  digitalWrite(LED_four, HIGH);
  digitalWrite(LED_three, HIGH);
    digitalWrite(LED_two, HIGH);

      delay(200);

  digitalWrite(LED_four, LOW);
  digitalWrite(LED_three, LOW);
    digitalWrite(LED_two, LOW);



      delay(200);


  delay(1000);

  //15
  digitalWrite(LED_four, HIGH);
  digitalWrite(LED_three, HIGH);
    digitalWrite(LED_two, HIGH);
      digitalWrite(LED_one, HIGH);

        delay(200);

  digitalWrite(LED_four, LOW);
  digitalWrite(LED_three, LOW);
    digitalWrite(LED_two, LOW);
      digitalWrite(LED_one, LOW);



        delay(200);


  delay(1000);


  //end
  delay(2500);
}
