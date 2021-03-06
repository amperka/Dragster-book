#include "Dragster.h"
#include "Octoliner.h"
#include "PID_dragster.h"

Dragster robot(MMAX_16_OHM);
Octoliner octoliner;

int lineData[8];

float speed = 0.5;
float KP = 1;
float KD = 1;

double output;
PID regulator(&output, KP, 0, KD);

void setup() {
  robot.begin();
  octoliner.begin();
  octoliner.setSensitivity(208);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    lineData[i] = octoliner.analogRead(i);
  }
  double error = octoliner.trackLine(lineData);
  regulator.compute(error);
  robot.driveF(speed * (1 - output), speed * (1 + output));
}

/*
(10) Немного увеличиваем скорость.
(12) Добавляем дифференциальный коэффициент. Он ускорит ответную реакцию на возникающую ошибку.
(15) Не забываем передать переменную в регулятор.
*/
