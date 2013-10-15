#include <Servo.h>

#define SERVO_PIN 10 // digital pin 10
#define PIR_PIN 11 // digital pin 11
#define LED_PIN 13 // digital pin 13

#define CENTER 90 // rotation center
#define LAT_ANGLE 10 // max angle of rotation (both sides)
#define FAST_DELAY 20 // delay on fast movement
#define SLOW_DELAY 100 // delay on slow movement

Servo servo;
int PIR_val = 0; // val of the PIR sensor
int angle = 90; // current servo angle
int dir = 0; // current servo direction

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  servo.write(angle);
  servo.attach(SERVO_PIN);

  // delay to allow the PIR to calibrate
  delay(15000);
  // ready indicator
  for(int i = 0; i < 10; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  }
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

// checks the PIR sensor
boolean detects_movement() {
  return digitalRead(PIR_PIN) == HIGH;
}

// moves the servo 1 degree
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












