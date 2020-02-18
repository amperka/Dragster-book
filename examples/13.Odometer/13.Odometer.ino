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
