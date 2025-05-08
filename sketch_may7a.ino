int infrared = 6;
int led = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(infrared,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int irRead = digitalRead(infrared);
  if (irRead == 1){
    digitalWrite(led,LOW);
    
  }

  if (irRead == 0){
    digitalWrite(led, HIGH);
    delay(5000);
  }

}
