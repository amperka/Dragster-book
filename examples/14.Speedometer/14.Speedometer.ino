#include ″Dragster.h″
#include ″TroykaLedMatrix.h″

Dragster robot(MMAX_16_OHM);

TroykaLedMatrix matrix;

byte diagram[8];

int speed = 0;

void handler() {
  speed++;
}

void setup() {
  robot.begin();
  robot.encodersBegin(handler, handler);
  robot.drive(40, 80);
  matrix.begin();
}

void loop() {
  for (int i = 0; i < 8; i++) {
    if (speed > i) {
      diagram[i] = matrix.map(8 - (i + 1), 0, 8);
    } else {
      diagram[i] = 0;
    }
  }
  matrix.drawBitmap(diagram);
  speed = 0;
  delay(150);
}
