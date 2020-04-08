int integer = 15;
float decimal = 15.5;
char character = 15;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("This is String");
  delay(1000);
  Serial.println(integer);
  delay(1000);
  Serial.println(decimal);
  delay(1000);
  Serial.println(character);
  delay(1000);
  Serial.println("I'll show to you a data type conversion");
  delay(1000);
  Serial.println(integer, HEX);
  delay(1000);
  Serial.println(integer, BIN);
}
