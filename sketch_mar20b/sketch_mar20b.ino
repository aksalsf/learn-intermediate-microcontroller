void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i=13;i>=6;i--) {
    pinMode(i,OUTPUT);
    } 
  while (!Serial);
  Serial.println("PRESS UP or DOWN to PLAY");
}

void loop() {
  // put your main code here, to run repeatedly:
 String input;
 while (Serial.available()>0){
  input = Serial.readStringUntil('\n');
  }
 if(input=="up"){
  Serial.println("LED Turned ON 13 to 6");
  for (int i=13;i>=6;i--) {
    digitalWrite(i, HIGH);
    delay(1000);
    }
  for (int i=13;i>=6;i--) {
    digitalWrite(i, LOW);
    }
  }
 if(input=="down"){
  Serial.println("LED Turned ON 6 to 13");
  for (int i=6;i<=13;i++) {
    digitalWrite(i, HIGH);
    delay(1000);
    }
  for (int i=13;i>=6;i--) {
    digitalWrite(i, LOW);
    }
  }
}
