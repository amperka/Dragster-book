#include ″Dragster.h″

Dragster robot(MMAX_16_OHM);
float left = 0;
float right = 0;

void leftEncoder() {
  left = left + 9.42;
}

void rightEncoder() {
  right = right + 9.42;
}

void setup() {
  robot.begin();
  robot.encodersBegin(leftEncoder, rightEncoder);
  robot.drive(100, 120);
  Serial.begin(115200);
}

void loop() {
  Serial.print(left);
  Serial.print(″ ″);
  Serial.print(right);
  Serial.println();
  delay(20);
}

/*
(4-5) Объявляем переменные для хранения пройденного расстояния обоими колёсами. Тип float означает число c плавающей точкой, то есть действительное.
(7-13) Накапливаем в каждом обработчике пройденное расстояние. Iskra Neo умеет хранить максимум 2 знака после дробной точки.
(23-25) Последовательно выводим в одну строку: пройденное расстояние левым колесом, пробел, затем расстояние правого колеса. По пробельному символу Плоттер понимает, что числа в строке относятся к разным графикам.
(26) Печатаем символ переноса строки.
*/
