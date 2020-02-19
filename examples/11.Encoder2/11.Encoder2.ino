#include ″Dragster.h″

#define ENC1 0
#define ENC2 1

Dragster robot(MMAX_16_OHM);

void setup() {
  Serial.begin(115200);
  pinMode(ENC1, INPUT);
  pinMode(ENC2, INPUT);
  robot.begin();
  robot.drive(120, 120);
}

void loop() {
  Serial.print(digitalRead(ENC1));
  Serial.print(" ");
  Serial.println(digitalRead(ENC2));
  delay(100);
}
