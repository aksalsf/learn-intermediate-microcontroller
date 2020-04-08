void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  while (!Serial);
  Serial.println("O = ON, I = OFF");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    char state = Serial.read();
    if (state == 'o') {
      digitalWrite(13,HIGH);
      Serial.println("LED Turned ON");
      }
      if(state == 'i') {
        digitalWrite(13,LOW);
        Serial.println("LED Turned OFF");
        }
    }
}
