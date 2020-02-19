#define DIR1 4
#define DIR2 7
#define EN1 5
#define EN2 6

void setup() {
  pinMode(DIR1, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(DIR2, OUTPUT);
  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, HIGH);
  analogWrite(EN1, 45);
  analogWrite(EN2, 90);
}

void loop() {
}
