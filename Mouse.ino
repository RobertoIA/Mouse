#include <Servo.h>

#define SERVO_PIN 0
#define CENTER 90
#define LAT_ANGLE 10

Servo servo;
int angle = 90; // current servo angle.
int dir = 0; // current servo direction.

void setup() {
  servo.attach(SERVO_PIN);
}

void loop() {
  if(dir == 0) {
    angle += 1;
    if(angle >= CENTER + LAT_ANGLE) dir = 1;
  } 
  else {
    angle -= 1;
    if(angle <= CENTER - LAT_ANGLE) dir = 0;
  }
  servo.write(angle);
  delay(50);
}







