#include "TroykaLedMatrix.h"

TroykaLedMatrix matrix;

byte volume[8] = { 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff };

byte diagram[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

float R1 = 10000;
float R2 = 36000;

void setup() {
    matrix.begin();
    pinMode(A1, INPUT);
}

void loop() {
    delay(200);
    int adcValue = analogRead(A1);
    float V = adcValue * 5.0 / 1023.0;
    float Vbat = V * (R1 + R2) / R2;
    int matrixValue = (Vbat - 3.2) * 8;
    for (int i = 0; i < 8; i++) {
        if (i < matrixValue) {
            diagram[i] = volume[i];
        } else {
            diagram[i] = 0x00;
        }
    }
    matrix.drawBitmap(diagram);
}