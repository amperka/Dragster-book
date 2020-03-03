#include "Dragster.h"
#include "TroykaLedMatrix.h"

Dragster robot(MMAX_16_OHM);
TroykaLedMatrix matrix;

uint8_t stop[] = {
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
};

void setup() {
  robot.begin();
  matrix.begin();
}

void loop() {
  matrix.clear();
  robot.drive(120, 120);
  delay(1000);

  matrix.drawBitmap(stop);
  robot.drive(0, 0);
  delay(1000);
}

/*
(2) Подключаем библиотеку TroykaLedMatrix.
(5) Заводим объект matrix. Он будет отвечать за передачу пикселей на матрицу.
(7-16) Создаём массив пикселей матрицы: 8 строк по 8 битов. Для наглядности записываем строки в бинарном виде. Заполняем биты единицами, означающими «включить пиксель».
(20) Инициализируем матрицу, то есть запускаем функцию настройки, встроенную в библиотеку.
(24) Очищаем экран матрицы.
(28) Рисуем на матрице массив из пикселей. Получится сплошной квадрат.
*/