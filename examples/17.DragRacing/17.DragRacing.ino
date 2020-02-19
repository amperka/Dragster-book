#include ″Dragster.h″
#include "Octoliner.h"
#include "TroykaLedMatrix.h"

Dragster robot(MMAX_16_OHM);
TroykaLedMatrix matrix;
Octoliner octoliner;

byte diagram[8];

void setup() {
  robot.begin();
  matrix.begin();
  octoliner.begin();
  octoliner.setSensitivity(208);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    int adcValue = octoliner.analogRead(i);
    diagram[i] = matrix.map(adcValue, 0, 1024);
    if (diagram[i] < 4) {
      robot.drive(0, 0);
    }
  }
  matrix.drawBitmap(diagram);
  if (robot.readButton() == 0) {
    delay(1000);
    robot.drive(100, 100);
  }
}
