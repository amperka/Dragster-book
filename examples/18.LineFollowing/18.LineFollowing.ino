#include ″Dragster.h″
#include "Octoliner.h"
#include "TroykaLedMatrix.h"

Dragster robot(MMAX_16_OHM);
TroykaLedMatrix matrix;
Octoliner octoliner;

byte diagram[8];
float weight[] = { -1, -0.75, -0.5, -0.25, 0.25, 0.5, 0.75, 1 };
float Kp = 2;

void setup() {
  robot.begin();
  matrix.begin();
  octoliner.begin();
  octoliner.setSensitivity(208);
}

void loop() {
  float error = 0;
  float sum = 0;
  float sumWeighted = 0;

  for (int i = 0; i < 8; i++) {
    int adcValue = octoliner.analogRead(i);
    diagram[i] = matrix.map(adcValue, 0, 1024);
    sum += adcValue;
    sumWeighted += adcValue * weight[i];
  }
  if (sum != 0.0) {
    error = sumWeighted / sum;
  }
  matrix.drawBitmap(diagram);

  robot.driveF(0.35 * (1 - error * Kp), 0.35 * (1 + error * Kp));
}

/*
(9-11) Переносим объявление переменных наверх для порядка.
(36) Запускаем робота в полсилы и изменяем скорость вращения колёс пропорционально ошибке.
*/
