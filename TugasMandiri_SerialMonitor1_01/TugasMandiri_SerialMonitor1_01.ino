char letter='A';
int number=1;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
for (letter='A';letter!='[';letter++){
  Serial.println(letter);
  Serial.println(number);
  number++;
  Serial.println(number);
  number++;
  Serial.println(number);
  number++;
  delay(1000);
}
}
