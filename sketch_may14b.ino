// Object avoider principle

// Object is present
int motor[] = { 8, 9, 10, 11 };

int rs = 7;
int ls = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(motor[i], OUTPUT);
  }
  pinMode(rs, INPUT);
  pinMode(ls, INPUT);
  Serial.println("initializing......");
}

// If one has to turn right then right motor should run backward and left motor should run forward

void stop() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(motor[i], LOW);
  }

  delay(5000);
}
void loop() {
  // put your main code here, to run repeatedly:

  int rightRead = digitalRead(rs);
  int leftRead = digitalRead(ls);

  // No object detected thus car moves forward;
  if (rightRead == 1 && leftRead == 1) {
    digitalWrite(motor[0], HIGH);
    digitalWrite(motor[1], LOW);
    digitalWrite(motor[2], HIGH);
    digitalWrite(motor[3], LOW);
    Serial.println("Forward");
  }

  // That means right sensor detected the object thus avoiding turn left;

  else if (rightRead == 0 && leftRead == 1) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(motor[i], LOW);
    }
    delay(2000);
    digitalWrite(motor[0], LOW);
    digitalWrite(motor[1], HIGH);
    digitalWrite(motor[2], LOW);
    digitalWrite(motor[3], HIGH);

    delay(200);

    digitalWrite(motor[0], LOW);
    digitalWrite(motor[1], HIGH);
    digitalWrite(motor[2], HIGH);
    digitalWrite(motor[3], LOW);
    delay(180);
  }

  // That means left sensor detected the object thus avoiding turn right;
  else if (rightRead == 1 && leftRead == 0) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(motor[i], LOW);
    }
    delay(2000);
    digitalWrite(motor[0], LOW);
    digitalWrite(motor[1], HIGH);
    digitalWrite(motor[2], LOW);
    digitalWrite(motor[3], HIGH);

    delay(100);


    digitalWrite(motor[0], HIGH);
    digitalWrite(motor[1], LOW);
    digitalWrite(motor[2], LOW);
    digitalWrite(motor[3], HIGH);

    delay(180);
  }

  // That means both the sensor have detected object;

  else if (rightRead == 0 && leftRead == 0) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(motor[i], LOW);
    }
    delay(2000);
    digitalWrite(motor[0], LOW);
    digitalWrite(motor[1], HIGH);
    digitalWrite(motor[2], LOW);
    digitalWrite(motor[3], HIGH);
    delay(100);



    digitalWrite(motor[0], HIGH);
    digitalWrite(motor[1], LOW);
    digitalWrite(motor[2], LOW);
    digitalWrite(motor[3], HIGH);
    delay(180);
  }
}
