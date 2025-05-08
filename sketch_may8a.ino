
int exitLed = 8;
int entryLed = 9;

int entryIR = 10;
int exitIR = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(entryLed, OUTPUT);
  pinMode(entryIR, INPUT);

  pinMode(exitLed, OUTPUT);
  pinMode(exitIR, INPUT);
}

void homeAutomation(int entryRead, int exitRead) {

  if (entryRead == LOW) {
    digitalWrite(entryLed, HIGH);
  }

  else if (exitRead == LOW) {
    digitalWrite(entryLed, LOW);
  }
}

void homeAutomationWithTwoLed(int entryRead , int exitRead){
  int exitVal = exitRead == LOW ? HIGH : LOW;
  int entryVal = entryRead == LOW ? HIGH: LOW;

  digitalWrite(exitLed , exitVal);
  digitalWrite(entryLed , entryVal);
}

void loop() {
  // put your main code here, to run repeatedly:

  int exitRead = digitalRead(exitIR);
  int entryRead = digitalRead(entryIR);

  homeAutomation(entryRead, exitRead);

}
