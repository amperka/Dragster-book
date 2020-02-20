void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  digitalWrite(4, HIGH);
  digitalWrite(7, HIGH);
}

void loop() {
  analogWrite(5, 64);
  analogWrite(6, 64);
  delay(1000);

  analogWrite(5, 0);
  analogWrite(6, 0);
  delay(1000);
}

/*
(1-4) Настраиваем пины DIR и EN на выход. Номера пинов указаны на плате Драгстера.
(7-8) Задаём направление вращения двигателей. HIGH — в одну сторону, LOW — в другую.
(12-13) Задаём коэффициент заполнения импульсов примерно 25%, Драгстер начнёт медленно двигаться.
(16-17) Отключаем ШИМ, заставляя робота остановиться.
*/