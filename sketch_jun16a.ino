// Ultrasonic Sensor

// Detects distance of Object

int triggPin = 7;

int echoPin = 6;
void setup() {
  // put your setup code here, to run once:

  pinMode(triggPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);

  Serial.println(
    "Distance measurement using Arduino Uno.");
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:

  /**
  To create a pulse wave
  */

  digitalWrite(triggPin, LOW);

  delayMicroseconds(5);

  digitalWrite(triggPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(triggPin, LOW);



  float duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0344 / 2; // 0.0344 speed of sound
  Serial.println("duration");
  Serial.println(duration);
  Serial.println("distance");
  Serial.println(distance);


  delay(100);
}
