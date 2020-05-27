int PWM = 6;
void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(PWM, OUTPUT);
  digitalWrite(7, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  analogWrite(PWM,10);
  delay(1000);
  analogWrite(PWM,50);
  delay(1000);
  analogWrite(PWM,100);
  delay(1000);
  analogWrite(PWM,150);
  delay(1000);
  analogWrite(PWM,255);
  delay(1000);
}
