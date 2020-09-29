#include <Servo.h>
#define MIN_POS 55
#define MAX_POS 135

Servo eye;

void moveEye(int eyeId, byte position) {
  float factor = constrain(position, 0, 255) / 255.0;
  int servoPosition = (int)(factor * (MAX_POS - MIN_POS) + MIN_POS);
  eye.write(servoPosition);
  // Serial.println(servoPosition, DEC);
}

void setup() {
  // Serial.begin(9600);
  eye.attach(9);

  moveEye(0, 127);
  delay(2000);
  moveEye(0, 0);
  delay(2000);
  moveEye(0, 255);
  delay(2000);
  moveEye(0, 127);
  delay(2000);
}

void loop() {
  moveEye(0, (byte)random(255));
  delay(1000);
}
