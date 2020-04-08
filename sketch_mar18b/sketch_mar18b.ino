void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int number = 0;
  char datachar;
  int receive;
  if (Serial.available()) {
    datachar = Serial.read();
    while (datachar != '\n') {
      if(isdigit(datachar)) {
        number = number * 10 + (datachar - '0');
        }
        datachar = Serial.read();
      }
      receive =  number;
    }
   Serial.print(receive);
   delay(1000);
}
