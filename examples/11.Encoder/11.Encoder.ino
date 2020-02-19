#include ″Dragster.h″

#define ENC1 0

Dragster robot(MMAX_16_OHM);

void setup() {
  pinMode(ENC1, INPUT);
  robot.begin();
  robot.drive(120, 0);

  Serial.begin(115200);
}

void loop() {
  Serial.println(digitalRead(ENC1));
  delay(100);
}

/*
(1-3) Подключаем библиотеку Dragster.h и задаём имя пину энкодера.
(8) Устанавливаем пин энкодера на вход.
(12) Запускаем последовательный порт. В скобках функции begin указываем скорость передачи данных — 115 200 бит в секунду.
(16,17) Каждые 100 миллисекунд выводим на печать значение пина ENC1.
*/