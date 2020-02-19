#include ″TroykaLedMatrix.h″

TroykaLedMatrix matrix;

const byte IMAGES[][8] = {
  { 0x30, 0x78, 0xcc, 0xcc, 0xfc, 0xcc, 0xcc, 0x00 },
  { 0xc6, 0xee, 0xfe, 0xfe, 0xd6, 0xc6, 0xc6, 0x00 },
  { 0xfc, 0x66, 0x66, 0x7c, 0x60, 0x60, 0xf0, 0x00 },
  { 0xfe, 0x62, 0x68, 0x78, 0x68, 0x62, 0xfe, 0x00 },
  { 0xfc, 0x66, 0x66, 0x7c, 0x6c, 0x66, 0xe6, 0x00 },
  { 0xe6, 0x66, 0x6c, 0x78, 0x6c, 0x66, 0xe6, 0x00 },
  { 0x30, 0x78, 0xcc, 0xcc, 0xfc, 0xcc, 0xcc, 0x00 },
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }
};
const int IMAGES_LEN = sizeof(IMAGES) / 8;

byte shift = 0;

void setup() {
  matrix.begin();
}

void loop() {
  delay(70);
  matrix.marquee(IMAGES, IMAGES_LEN, shift++);
  if (shift == IMAGES_LEN * 8) {
    shift = 0;
  }
}

/*
(5-14) Создаём 8 символов для бегущей строки.
(17) Переменная shift будет отвечать за сдвиг символов в строке.
(25) Функция marquee отображает часть бегущей строки IMAGES длиной IMAGES_LEN со сдвигом shift. Сразу после вызова функции оператор ++ увеличит переменную shift на 1.
(26-28) Если величина shift достигла длины строки, обнуляем переменную.
*/