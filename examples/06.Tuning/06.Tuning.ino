#include ″Dragster.h″

Dragster robot(MMAX_16_OHM);
void setup() {
  robot.begin();
}
void loop() {
  robot.drive(110, 50);
  delay(1000);
  robot.drive(50, 110);
  delay(1000);
}
