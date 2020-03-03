#include "TroykaLedMatrix.h"

TroykaLedMatrix matrix;

byte volume[8] = 
    {0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff};
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
  float V = adcValue * 4.2 / 1023.0;
  float Vbat = V * (R1 + R2) / R2;

  int matrixValue = (Vbat - 2.5) * 8;
  for (int i = 0; i < 8; i++) {
    if (i < matrixValue) {
      diagram[i] = volume[i];
    } else {
      diagram[i] = 0x00;
    }
  }
  matrix.drawBitmap(diagram);
}

/*
(5,6) Заводим массив для хранения элементов «лесенки», обозначающей уровень заряда аккумулятора.
(7-9) Определяем сопротивления R1 и R2.
(18-20) Считываем аналоговое значение с пина A1 и преобразуем по формулам.
(22-30) Преобразуем напряжение в столбики на матрице, выводим изображение.
*/
