#include "Dragster.h"
#include "TroykaLedMatrix.h"

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

/*
(9-11) Используем одну и ту же функцию обработки прерываний энкодеров. Сейчас нам не важна точная скорость, поэтому просто складываем значения с каждого колеса без дополнительной обработки.
(15) Передаём в функцию encodersBegin два одинаковых параметра handler.
(22-24) В цикле для каждого столбца матрицы отрисовываем индикатор скорости. «Закрашиваем» все столбики, высота которых численно ниже скорости. Функция matrix.map(val, min, max) преобразует число val в диапазон от min до max, а затем переводит результат в высоту столбика.
(29,30) Каждые 150 миллисекунд обнуляем значение скорости.
*/
