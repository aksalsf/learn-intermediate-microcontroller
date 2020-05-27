#include <Servo.h>
int FirstButton = 13;
int SecondButton = 12;
int ThirdButton = 11;
int ServoPIN = 3;
int isFirstButtonPressed = 0;
int isSecondButtonPressed = 0;
int isThirdButtonPressed = 0;
Servo MyServo;
void setup() {
  // put your setup code here, to run once:
  MyServo.attach(ServoPIN);
  pinMode(FirstButton, INPUT);
  pinMode(SecondButton, INPUT);
  pinMode(ThirdButton, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  isFirstButtonPressed = digitalRead(FirstButton);
  isSecondButtonPressed = digitalRead(SecondButton);
  isThirdButtonPressed = digitalRead(ThirdButton);
  if (isFirstButtonPressed == HIGH){
    Wheeling(45);
    }
  if (isSecondButtonPressed == HIGH){
    Wheeling(90);
    }
  if (isThirdButtonPressed == HIGH){
    Wheeling(180);
    }
}

void Wheeling(int DerajatPutar) {
  MyServo.write(0);
  delay(500);
  MyServo.write(DerajatPutar);
  delay(500);
  }
