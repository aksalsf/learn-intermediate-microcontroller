void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char datachar;
  if (Serial.available()) {
    datachar = Serial.read();
    }
    delay(1000);
    Serial.print(datachar);
}
