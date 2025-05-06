int Leda = 8;
int Ledb = 9;
int Ledc = 10;
int Ledd = 11;


void setup() {
  pinMode(Leda, OUTPUT);
  pinMode(Ledb, OUTPUT);
  pinMode(Ledc, OUTPUT);
  pinMode(Ledd, OUTPUT);
}

void delaySame() {
  delay(100);
}
void loop() {
  digitalWrite(Leda, HIGH);
  delaySame();

  digitalWrite(Ledb, HIGH);
  delaySame();

  digitalWrite(Ledc, HIGH);
  delaySame();

  digitalWrite(Ledd, HIGH);
  delaySame();

  digitalWrite(Ledd, LOW);
  delaySame();

  digitalWrite(Ledc, LOW);
  delaySame();

  digitalWrite(Ledb, LOW);
  delaySame();

  digitalWrite(Leda, LOW);
  delaySame();
}