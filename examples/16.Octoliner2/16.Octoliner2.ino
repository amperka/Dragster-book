#include ″Octoliner.h″
#include ″TroykaLedMatrix.h″

const byte images[][8] = { // *1
    { 0x38, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x38 },
    { 0x10, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38 },
    { 0x38, 0x44, 0x04, 0x04, 0x08, 0x10, 0x20, 0x7c },
    { 0x38, 0x44, 0x04, 0x18, 0x04, 0x04, 0x44, 0x38 },
    { 0x04, 0x0c, 0x14, 0x24, 0x44, 0x7c, 0x04, 0x04 },
    { 0x7c, 0x40, 0x40, 0x78, 0x04, 0x04, 0x44, 0x38 },
    { 0x38, 0x44, 0x40, 0x78, 0x44, 0x44, 0x44, 0x38 },
    { 0x7c, 0x04, 0x04, 0x08, 0x10, 0x20, 0x20, 0x20 },
    { 0x38, 0x44, 0x44, 0x38, 0x44, 0x44, 0x44, 0x38 },
    { 0x38, 0x44, 0x44, 0x44, 0x3c, 0x04, 0x44, 0x38 },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x38, 0x44, 0x44, 0x08, 0x10, 0x00, 0x10, 0x10 }
};

byte result[5][8]; // *2

const int IMAGES_LEN = sizeof(images) / 8;
const int RESULT_LEN = sizeof(result) / 8;

TroykaLedMatrix matrix;

Octoliner octoliner;

byte shift = 0;

byte getX__(byte c) { return c / 100; } // *3
byte get_X_(byte c) { return (c - floor(c / 100) * 100) / 10; } //
byte get__X(byte c) { return (c - floor(c / 10) * 10); } //

void copyPattern(byte position, byte value) { // *4
    for (byte i = 0; i < 8; i++) {
        result[position][i] = images[value][i];
    }
}

void setup() {
    byte optimal;
    Serial.begin(115200);
    matrix.begin();
    octoliner.begin();
    delay(1000);
    while (digitalRead(10) != 0)
        ; // *5
    matrix.drawBitmap(images[11]); // *6
    octoliner.optimizeSensitivityOnBlack(); // *7
    optimal = octoliner.getSensitivity();
    Serial.print(optimal); // *8
    copyPattern(0, 10);
    copyPattern(1, 10); // *9
    copyPattern(2, getX__(optimal)); // *10
    copyPattern(3, get_X_(optimal)); //
    copyPattern(4, get__X(optimal)); //
}

void loop() {
    delay(70);
    matrix.marquee(result, RESULT_LEN, shift++); // *11
    if (shift == RESULT_LEN * 8) {
        shift = 0;
    } //
}