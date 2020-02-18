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
