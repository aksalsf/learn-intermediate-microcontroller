void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  while (!Serial);
  Serial.println("1 = ON, 2 = OFF");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    int state = Serial.parseInt();
    if (state == 1) {
      digitalWrite(13,HIGH);
      Serial.println("LED Turned ON");
      }
      if(state == 2) {
        digitalWrite(13,LOW);
        Serial.println("LED Turned OFF");
        }
    }
}
