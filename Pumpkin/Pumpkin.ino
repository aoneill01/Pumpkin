#include <Servo.h>
#define MIN_POS 60
#define MAX_POS 135
#define NUM_EYES 10

Servo eye[NUM_EYES];

void moveEye(int eyeId, byte position) {
  float factor = constrain(position, 0, 255) / 255.0;
  int servoPosition = (int)(factor * (MAX_POS - MIN_POS) + MIN_POS);
  eye[eyeId].write(servoPosition);
  // Serial.println(servoPosition, DEC);
}

void moveAllEyes(byte position) {
  for (int i = 0; i < NUM_EYES; i++) {
    moveEye(i, position);
    delay(200);
  }
}

void setup() {
  // Serial.begin(9600);
  for (int i = 0; i < NUM_EYES; i++) {
    eye[i].attach(3 + i);
    delay(200);
  }

  moveAllEyes(127);
  delay(500);
  moveAllEyes(0);
  delay(500);
  moveAllEyes(255);
  delay(500);
  moveAllEyes(127);
  delay(500);
}

void loop() {
  moveEye(random(NUM_EYES), (byte)random(255));
  delay(150);
}
