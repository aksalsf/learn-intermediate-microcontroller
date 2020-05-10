int flamePIN = 13;
int LEDPIN = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(flamePIN, INPUT_PULLUP);
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(flamePIN)==HIGH) {
      digitalWrite(LEDPIN, HIGH);
      Serial.println("Flame Detected");
    }
  if (digitalRead(flamePIN)==LOW) {
      digitalWrite(LEDPIN, LOW);
      Serial.println("Flame NOT Detected");
    }
  delay(1000);
}
