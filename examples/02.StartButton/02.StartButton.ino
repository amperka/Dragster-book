void setup() {
    pinMode(10, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    if (digitalRead(10) == LOW) {
        digitalWrite(LED_BUILTIN, HIGH);
    } else {
        digitalWrite(LED_BUILTIN, LOW);
    }
}
