#include ″Dragster.h″

Dragster robot(MMAX_16_OHM);
int counter = 0;

void leftEncoder() {
  counter++;
}

void rightEncoder() {

}

void setup() {
  robot.begin();
  robot.encodersBegin(leftEncoder, rightEncoder);
  robot.drive(60, 0);

  Serial.begin(115200);
}

void loop() {
  Serial.println(counter);
  delay(200);
}

/*
(4) Определяем переменную для подсчёта прерываний.
(6-8) Создаём собственную функцию с увеличивающимся счётчиком прерываний для левого энкодера.
(10-12) Функцию для правого энкодера оставим пустой. Пока достаточно одного левого энкодера.
(16) Функция encodersBegin настраивает пины и прерывания. В скобках указываем функцию обработки.
(23,24) Пять раз в секунду выводим на печать количество сработавших прерываний.
*/
