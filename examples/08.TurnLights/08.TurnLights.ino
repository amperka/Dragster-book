#include "Dragster.h"
#include "TroykaLedMatrix.h"

Dragster robot(MMAX_16_OHM);
TroykaLedMatrix matrix;

const byte IMAGES[][8] = {
  { 0x18, 0x3c, 0x7e, 0xdb, 0x99, 0x18, 0x18, 0x18 },
  { 0x18, 0x18, 0x18, 0x99, 0xdb, 0x7e, 0x3c, 0x18 }
};
const int IMAGES_LEN = sizeof(IMAGES) / 8;

void setup() {
  robot.begin();
  matrix.begin();
}

void loop() {
  matrix.drawBitmap(IMAGES[0]);
  robot.drive(110, 60);
  delay(1000);

  matrix.drawBitmap(IMAGES[1]);
  robot.drive(60, 110);
  delay(1000);
}

/*
(7-10) Массив IMAGE из двух изображений. Каждое из них содержит массив строк матрицы.
(11) Константа IMAGE_LEN хранит длину массива IMAGES — количество изображений. Сейчас это не понадобится.
(19,20) Выводим изображение стрелки вправо и поворачиваем направо.
(23,24) Меняем изображение на стрелку влево и поворачиваем налево.
*/
