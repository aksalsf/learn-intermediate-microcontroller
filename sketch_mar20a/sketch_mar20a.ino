void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i=13;i>=6;i--) {
    pinMode(i,OUTPUT);
    } 
  while (!Serial);
  Serial.println("PRESS 1 - 8 to TURN ON");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    int state = Serial.parseInt();
    if (state == 1) {
      digitalWrite(13,HIGH);
      Serial.println("LED 13 Turned ON");
      } else {
        digitalWrite(13,LOW);
        Serial.println("LED 13 Turned OFF");
        }
    if (state == 2) {
      digitalWrite(12,HIGH);
      Serial.println("LED 12 Turned ON");
      } else {
        digitalWrite(12,LOW);
        Serial.println("LED 12 Turned OFF");
        }
    if (state == 3) {
      digitalWrite(11,HIGH);
      Serial.println("LED 11 Turned ON");
      } else {
        digitalWrite(11,LOW);
        Serial.println("LED 11 Turned OFF");
        }
    if (state == 4) {
      digitalWrite(10,HIGH);
      Serial.println("LED 10 Turned ON");
      } else {
        digitalWrite(10,LOW);
        Serial.println("LED 10 Turned OFF");
        }
    if (state == 5) {
      digitalWrite(9,HIGH);
      Serial.println("LED 9 Turned ON");
      } else {
        digitalWrite(9,LOW);
        Serial.println("LED 9 Turned OFF");
        }
    if (state == 6) {
      digitalWrite(8,HIGH);
      Serial.println("LED 8 Turned ON");
      } else {
        digitalWrite(8,LOW);
        Serial.println("LED 8 Turned OFF");
        }
    if (state == 7) {
      digitalWrite(7,HIGH);
      Serial.println("LED 7 Turned ON");
      } else {
        digitalWrite(7,LOW);
        Serial.println("LED 7 Turned OFF");
        }
    if (state == 8) {
      digitalWrite(6,HIGH);
      Serial.println("LED 6 Turned ON");
      } else {
        digitalWrite(6,LOW);
        Serial.println("LED 6 Turned OFF");
        }
    }
}
