#define motor1 7
#define motor2 6

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
}
