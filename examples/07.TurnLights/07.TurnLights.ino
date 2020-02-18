#include ″Dragster.h″
#include ″TroykaLedMatrix.h″

Dragster robot(MMAX_16_OHM);

TroykaLedMatrix matrix;

const byte IMAGES[][8] = {
    { 0x18, 0x3c, 0x7e, 0xdb, 0x99, 0x18, 0x18, 0x18 },
    { 0x18, 0x18, 0x18, 0x99, 0xdb, 0x7e, 0x3c, 0x18 }
};

const int IMAGES_LEN = sizeof(IMAGES) / 8;

void setup() {
    robot.begin();
    matrix.begin();
}

void loop() {
    matrix.drawBitmap(IMAGES[0]);
    robot.drive(110, 60);
    delay(1000);

    matrix.drawBitmap(IMAGES[1]);
    robot.drive(60, 110);
    delay(1000);
}
