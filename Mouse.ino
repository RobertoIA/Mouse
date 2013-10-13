#include <Servo.h>

#define SERVO_PIN 0
#define PIR_PIN 0 // Analog pin 0
#define LED_PIN 13

#define CENTER 90
#define LAT_ANGLE 10
#define FAST_DELAY 20
#define SLOW_DELAY 100

Servo servo;
int PIR_val = 0;
int angle = 90; // current servo angle.
int dir = 0; // current servo direction.

void setup() {
  pinMode(LED_PIN, OUTPUT);
  servo.write(angle);
  servo.attach(SERVO_PIN);
}

void loop() {
  if(detects_movement()) {
    digitalWrite(LED_PIN, HIGH);
    move_servo(FAST_DELAY);
  }
  else {
    digitalWrite(LED_PIN, LOW);
    move_servo(SLOW_DELAY);
  }

  //test_movement();
}

// DEBUG
void test_movement() {
  for(int i = 0; i < 100; i++)
    move_servo(FAST_DELAY);
  for(int i = 0; i < 100; i++)
    move_servo(SLOW_DELAY);
}

boolean detects_movement() {
  return analogRead(PIR_PIN) != LOW;
}

void move_servo(int servo_delay) {
  if(dir == 0) {
    angle += 1;
    if(angle >= CENTER + LAT_ANGLE) dir = 1;
  } 
  else {
    angle -= 1;
    if(angle <= CENTER - LAT_ANGLE) dir = 0;
  }
  servo.write(angle);
  delay(servo_delay);
}











