#include "Dragster.h"
#include "Octoliner.h"
#include "PID_dragster.h"

Dragster robot(MMAX_16_OHM);
Octoliner octoliner;

int lineData[8];

float speed = 0.55;
float KP = 0.5;
float KD = 0.5;
float KI = 0.0;

double output;
PID regulator(&output, KP, KI, KD);

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
(10) Увеличиваем скорость Драгстера.
(13) Добавляем переменную для интегрального коэффициента. Сначала с нулевым значением, затем будем плавно увеличивать от заезда к заезду.
(16) Заменяем 0 на переменную интегральной составляющей.
*/
