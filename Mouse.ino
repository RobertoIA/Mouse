#include <Servo.h>

#define SERVO_PIN 0
#define CENTER 90
#define LAT_ANGLE 10
#define FAST_DELAY 20
#define SLOW_DELAY 50

Servo servo;
int angle = 90; // current servo angle.
int dir = 0; // current servo direction.

void setup() {
  servo.attach(SERVO_PIN);
  servo.write(angle);
}

void loop() {
  //test_movement();
}

// DEBUG
void test_movement() {
  for(int i = 0; i < 100; i++)
    move_fast();
  for(int i = 0; i < 100; i++)
    move_slow();
}

void move_fast() {
  move_servo();
  delay(FAST_DELAY);
}

void move_slow() {
  move_servo();
  delay(SLOW_DELAY);
}

void move_servo() {
  if(dir == 0) {
    angle += 1;
    if(angle >= CENTER + LAT_ANGLE) dir = 1;
  } 
  else {
    angle -= 1;
    if(angle <= CENTER - LAT_ANGLE) dir = 0;
  }
  servo.write(angle);
}










