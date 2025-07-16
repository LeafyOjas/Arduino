
int ENA = 3;
int ENB = 5;

int motor[] = { 8, 9, 10, 11 };
int frontSensor = 7;
int leftSensor = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(motor[i], OUTPUT);
  }
  pinMode(frontSensor, INPUT);
  pinMode(leftSensor, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int frontRead = digitalRead(frontSensor);
  int leftRead = digitalRead(leftSensor);

  // SlightLeft Movement by slowing down speed of left motors
  // This gets closer to left wall
  if (frontRead == HIGH && leftRead == HIGH) {

    analogWrite(ENA, 150);
    analogWrite(ENB, 255);

    digitalWrite(motor[0], LOW);
    digitalWrite(motor[1], HIGH);

    digitalWrite(motor[2], HIGH);
    digitalWrite(motor[3], LOW);

    Serial.println("SlightLeft");
    Serial.println(frontRead);
    Serial.println(leftRead);

  }

  // SlightRight Movement by slowing down the right motors
  // This gets away from the left wall
  else if (frontRead == HIGH && leftRead == LOW) {

    for (int i = 0; i < 4; i++) {
      digitalWrite(motor[i], LOW);
    }
    delay(200);
    analogWrite(ENB, 255 / 2);
    analogWrite(ENA, 255);

    digitalWrite(motor[0], HIGH);
    digitalWrite(motor[1], LOW);
    digitalWrite(motor[2], LOW);
    digitalWrite(motor[3], HIGH);

    delay(100);

    Serial.println("SlightRight");
    Serial.println(frontRead);
    Serial.println(leftRead);
  }

  // This is the L - junction b/w the wall
  // Stops / Reverse / Move right slowly
  else if (frontRead == LOW && leftRead == LOW) {

    for (int i = 0; i < 4; i++) {
      digitalWrite(motor[i], LOW);
    }

    delay(1000);
    analogWrite(ENB, 255);
    analogWrite(ENA, 255);

    digitalWrite(motor[0], LOW);
    digitalWrite(motor[1], HIGH);
    digitalWrite(motor[2], LOW);
    digitalWrite(motor[3], HIGH);

    delay(200);

    digitalWrite(motor[0], HIGH);
    digitalWrite(motor[1], LOW);
    digitalWrite(motor[2], LOW);
    digitalWrite(motor[3], HIGH);

    delay(500);
    Serial.println("Stop/reverse");
    Serial.println(frontRead);
    Serial.println(leftRead);
  }

  // Here the frontWall is detected so it should go back and turn right to face the left side
  // towards the wall
  else if (frontRead == LOW && leftRead == HIGH) {

    for (int i = 0; i < 4; i++) {
      digitalWrite(motor[i], LOW);
    }
    delay(1000);

    analogWrite(ENB, 255 / 3);
    analogWrite(ENA, 255 / 3);

    digitalWrite(motor[0], LOW);
    digitalWrite(motor[1], HIGH);
    digitalWrite(motor[2], LOW);
    digitalWrite(motor[3], HIGH);

    delay(200);

    digitalWrite(motor[0], HIGH);
    digitalWrite(motor[1], LOW);
    digitalWrite(motor[2], LOW);
    digitalWrite(motor[3], HIGH);

    delay(500);

    Serial.println("Frontwall is detected");
    Serial.println(frontRead);
    Serial.println(leftRead);
  }
}
