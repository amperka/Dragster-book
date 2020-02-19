#define DIR1 4
#define DIR2 7
#define EN1 5
#define EN2 6

void setup() {
  pinMode(DIR1, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(DIR2, OUTPUT);

  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, HIGH);

  analogWrite(EN1, 45);
  analogWrite(EN2, 90);
}

void loop() {

}

/*
(1-4) Используем директивы #define для хранения пинов под заданным именем. Это позволяет не запоминать пины, а использовать их понятное обозначение во всей программе.
(7-10) Устанавливаем пины на выход, задавая их имена вместо чисел.
(15-16) Задаём разную скорость двигателей. Робот будет двигаться по окружности.
(19-21) Оставляем цикл loop() пустым. Он будет раз за разом повторять ничего, пока не отключится питание.
*/
