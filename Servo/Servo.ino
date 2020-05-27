#include <Servo.h>
int ServoPIN = 6;
Servo MyServo;
int atDegree = 0;
void setup() {
  // put your setup code here, to run once:
  MyServo.attach(ServoPIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (atDegree = 0; atDegree < 180; atDegree++) {
    MyServo.write(atDegree);
    delay(15);
    }
  for (atDegree = 180; atDegree > 0; atDegree--) {
    MyServo.write(atDegree);
    delay(15);
    }
}
