#include ″Dragster.h″

#define ENC1 0

Dragster robot(MMAX_16_OHM);

void setup() {
  pinMode(ENC1, INPUT);
  robot.begin();
  robot.drive(120, 0);
  Serial.begin(115200);
}

void loop() {
  Serial.println(digitalRead(ENC1));
  delay(100);
}
