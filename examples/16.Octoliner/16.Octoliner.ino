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

/*
(2) Подключаем библиотеку Octoliner.h.
(4) Объявляем объект octoliner для работы с датчиком.
(12) Запускаем датчик линии. В функцию octoliner.setSensitivity() передаём значение чувствитель­ности датчиков в каждом из восьми датчиков модуля. Она задаётся в диапазоне от 0 до 255. Сначала впиши любое значение наугад
(17) Запрашиваем у модуля значение на каждом аналоговом приёмнике. Функция octoliner.analogRead вернёт целое число в диапазоне от 0 до 4095.
(18) Переводим цифровое значение напряжения в высоту столбика на матрице.
*/
