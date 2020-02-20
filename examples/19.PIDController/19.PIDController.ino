#include ″Dragster.h″
#include "Octoliner.h"
#include "PID_dragster.h"

Dragster robot(MMAX_16_OHM);
Octoliner octoliner;

int lineData[8];

float speed = 0.4;
float KP = 1;

double output;
PID regulator(&output, KP, 0, 0);

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
(10-11) Задаем значения скорости в диапазоне от 0 до 1 и пропорционального коэффициента — от 0 до 3. Так проще работать с коэффициентами при подборе параметров.
(13-14) Настраиваем ПИД-регулятор. Переменная output — выходное значение регулятора, на эту величину необходимо изменить скорость двигателей. Применяем только пропорциональный коэффициент, остальные пока не используем.
(26-27) Обновляем информацию о текущей ошибке. Записываем в переменную error. Вызываем функцию ПИД-регулятора для обновления выходного значения output.
(28) Используем output в функции robot.driveF().
*/
