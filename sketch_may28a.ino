#Front Sensor - does not sense the Object then it goes Straight

#As soon as the object is encountered it has to make Right turn as it follows the Wall from
#the left sensor.

#As soon as the wall comes in front that means the right sensor and the left sensor have object
#again it would turn right.

#Corners ? ? ? ? ;

int motor[] = { 8, 9, 10, 11 };
int fs = 7;
int ls = 6;

void setup() {
  // put your setup code here, to run once:

  for (int i = 0; i < 4; i++) {
    pinMode(motor[i], OUTPUT);
  }
  pinMode(ls, INPUT);
  pinMode(fs, INPUT);
}

void stop() {

  for (int i = 0; i < 4; i++) {
    digitalWrite(motor[i], LOW);
  }
  delay(1000);
}

void backward() {

  digitalWrite(motor[0], LOW);
  digitalWrite(motor[1], HIGH);
  digitalWrite(motor[2], LOW);
  digitalWrite(motor[3], HIGH);

  delay(250);
}

void loop() {
  // put your main code here, to run repeatedly:

  int frontRead = digitalRead(fs);
  int leftRead = digitalRead(ls);

  // Follow Slightly Left
  if (frontRead == 1 && leftRead == 1) {
    digitalWrite(motor[0], LOW);
    digitalWrite(motor[1], LOW);
    digitalWrite(motor[2], HIGH);
    digitalWrite(motor[3], LOW);
  }

  // Right Turn to follow the Object
  else if (frontRead == 0 && leftRead == 1) {
    stop();
    backward();
    digitalWrite(motor[0], HIGH);
    digitalWrite(motor[1], LOW);

    digitalWrite(motor[2], LOW);
    digitalWrite(motor[3], HIGH);

    delay(800);
  }

  // Following the left wall
  else if (frontRead == 1 && leftRead == 0) {
    stop();

    digitalWrite(motor[0], HIGH);
    digitalWrite(motor[1], LOW);
    digitalWrite(motor[2], HIGH);
    digitalWrite(motor[3], LOW);
    delay(800);

  }


  // 90 degree wall Encountered
  else if (frontRead == 0 && leftRead == 0) {

    stop();
    backward();

    digitalWrite(motor[0], HIGH);
    digitalWrite(motor[1], LOW);

    digitalWrite(motor[2], LOW);
    digitalWrite(motor[3], HIGH);

    delay(800);
  }
}
