#include ″TroykaLedMatrix.h″
#include ″Octoliner.h″

Octoliner octoliner;
TroykaLedMatrix matrix;

byte diagram[8];

void setup() {
    matrix.begin();
    octoliner.begin();
    octoliner.setSensitivity();
}

void loop() {
    for (int i = 0; i < 8; i++) {
        int analogValue = octoliner.analogRead(i);
        diagram[i] = matrix.map(analogValue, 0, 1023);
    }
    matrix.drawBitmap(diagram);
}
