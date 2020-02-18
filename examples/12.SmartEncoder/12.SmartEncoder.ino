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
