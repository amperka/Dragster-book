#include ″Dragster.h″
#include ″TroykaLedMatrix.h″

Dragster robot(MMAX_16_OHM);

TroykaLedMatrix matrix;

uint8_t stop[] = {
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11111111,
};

void setup() {
    robot.begin();
    matrix.begin();
}

void loop() {
    matrix.clear();
    robot.drive(120, 120);
    delay(1000);

    matrix.drawBitmap(stop);
    robot.drive(0, 0);
    delay(1000);
}
