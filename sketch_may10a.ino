
int rmf = 8;
int rmb = 9;
int lmf = 10;
int lmb = 11;
int rs = 6;
int ls = 7;
int led = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(rs, INPUT);
  pinMode(ls, INPUT);

  pinMode(rmf, OUTPUT);
  pinMode(rmb, OUTPUT);
  pinMode(lmf, OUTPUT);
  pinMode(lmb, OUTPUT);

  pinMode(led, OUTPUT);
}

void left(int rs, int ls) {

  if (ls == 1 && rs == 0) {
    digitalWrite(rmf, LOW);
    digitalWrite(lmf, HIGH);
    digitalWrite(rmb, HIGH);
    digitalWrite(lmb, LOW);

    digitalWrite(led, HIGH);
  }
}

void right(int rs, int ls) {
  if (rs == 1 && ls == 0) {
    digitalWrite(rmf, HIGH);
    digitalWrite(lmf, LOW);
    digitalWrite(rmb, LOW);
    digitalWrite(lmb, HIGH);

    digitalWrite(led, HIGH);
  }
}

void backward() {
  digitalWrite(rmf, LOW);
  digitalWrite(lmf, LOW);
  digitalWrite(lmb, HIGH);
  digitalWrite(rmb, HIGH);
}

void forward() {
  digitalWrite(rmf, HIGH);
  digitalWrite(lmf, HIGH);
 
  digitalWrite(led, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int rs = digitalRead(6);
  int ls = digitalRead(7);

  if ((rs == 0) && (ls == 0)) {
    forward();
  }

  if ((rs == 1) && (ls == 1)) {
    digitalWrite(rmf, LOW);
    digitalWrite(lmf, LOW);
    digitalWrite(rmb, LOW);
    digitalWrite(lmb, LOW);
    digitalWrite(led, LOW);

    delay(500);
    backward();
    delay(100);
    right(rs, ls);
  }

  // left(rs, ls);
  

  // right(rs, ls);
}