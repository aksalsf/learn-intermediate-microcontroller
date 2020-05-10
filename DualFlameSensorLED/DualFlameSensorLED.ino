int flameSensorOne = 13;
int flameSensorTwo = 12;
int ledOne = 10;
int ledTwo = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(flameSensorOne, INPUT_PULLUP);
  pinMode(flameSensorTwo, INPUT_PULLUP);
  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(flameSensorOne) == HIGH && digitalRead(flameSensorTwo) == HIGH) {
      digitalWrite(ledOne, HIGH); digitalWrite(ledTwo, LOW);
    } else if (digitalRead(flameSensorOne) == HIGH && digitalRead(flameSensorTwo) == LOW){
      digitalWrite(ledOne, HIGH); digitalWrite(ledTwo, LOW);
      } else if (digitalRead(flameSensorOne) == LOW && digitalRead(flameSensorTwo) == HIGH) {
        digitalWrite(ledTwo, HIGH); digitalWrite(ledOne, LOW);
        } else {
          digitalWrite(ledOne, LOW); digitalWrite(ledTwo, LOW);
          }
}
