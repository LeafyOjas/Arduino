int led[] = {8 , 9 , 10 , 11 , 12 , 13};

int num = sizeof(led) / sizeof(led[0]);

int brightness = 255;  // Variable to store the LED brightness
int fadeAmount = 10;  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < num; i++) {
    pinMode(led[i], OUTPUT);
  }
}

void patternIncrement(int start, int end, int flag) {

  for (int i = start; i < end; i++) {
    digitalWrite(led[i], flag);
    delay(500);
  }
}

void patternDecrement(int start, int end, int flag) {
  for (int i = start; i >= end; i--) {
    digitalWrite(led[i], flag);
    delay(500);
  }
}

bool validateIndexBoundaryHigh(int point){
  if (point < 0 || point >= num){
    return false;
  }
  digitalWrite(led[point] , HIGH);
  return true;
}

bool validateIndexBoundaryLow(int point){
  if (point < 0 || point >= num){
    return false;
  }
  digitalWrite(led[point] , LOW);
  return true;
}

void patternAlternate() {

  int mid = num / 2;
  int start = mid, end = mid;
  Serial.print(mid);

  if(num%2 == 0){
    start -=1;
  }

  while (start >= 0 || end < num) {
    validateIndexBoundaryHigh(start);
    validateIndexBoundaryHigh(end);
    delay(500);

    validateIndexBoundaryLow(start);
    validateIndexBoundaryLow(end);

    delay(200);

    start -= 1;
    end += 1;
  }
}

void patternAlternateReverse() {

  int start = 1, end = num - 2;
  while (start <=end) {
    validateIndexBoundaryHigh(start);
    validateIndexBoundaryHigh(end);
    delay(500);

    validateIndexBoundaryLow(start);
    validateIndexBoundaryLow(end);

    delay(200);

    start++;
    end--;
  }
}

void blinking() {
  analogWrite(led[1], brightness);  // Set the LED brightness
  analogWrite(led[2], brightness);
  analogWrite(led[3], brightness);

  if(brightness <=0 || brightness >255){
    fadeAmount  = -fadeAmount ;
    }
  
  brightness = brightness - fadeAmount;  // Change brightness
  delay(200); 
}

void loop() {
  // put your main code here, to run repeatedly:

  patternDecrement(2, 0, HIGH);
  patternIncrement(0, 2, LOW);
  patternIncrement(2, num, HIGH);
  blinking();
  patternDecrement(num - 1, 2, LOW);
  patternAlternate();
  patternAlternateReverse();



}
