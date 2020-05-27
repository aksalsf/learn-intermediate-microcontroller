#define FirstMotor 7
#define SecondMotor 6
int FirstButton = 13;
int SecondButton = 12;
int isFirstButtonPressed = 0;
int isSecondButtonPressed = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(FirstButton, INPUT);
  pinMode(SecondButton, INPUT);
  pinMode(FirstMotor, OUTPUT);
  pinMode(SecondMotor, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  isFirstButtonPressed = digitalRead(FirstButton);
  isSecondButtonPressed = digitalRead(SecondButton);
  if (isFirstButtonPressed == HIGH && isSecondButtonPressed == LOW) {
    digitalWrite(FirstMotor, HIGH);
    digitalWrite(SecondMotor, LOW);
    } else if (isFirstButtonPressed == LOW && isSecondButtonPressed == HIGH) {
      digitalWrite(FirstMotor, LOW);
      digitalWrite(SecondMotor, HIGH);
      }
}
