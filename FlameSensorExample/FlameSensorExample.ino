int flamePIN = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(flamePIN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(flamePIN)==HIGH) {
      Serial.println("Flame Detected");
    }
  if (digitalRead(flamePIN)==LOW) {
      Serial.println("Flame NOT Detected");
    }
  delay(1000);
}
