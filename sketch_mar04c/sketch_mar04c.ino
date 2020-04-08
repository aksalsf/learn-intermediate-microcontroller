int x = 2;
int y = 5;
int z = 10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("x = ");
  Serial.println(x);
  Serial.print("y = ");
  Serial.println(y);
  Serial.print("z = ");
  Serial.println(z);
  Serial.print("x+y = ");
  Serial.println(x+y);
  Serial.print("y-x = ");
  Serial.println(y-x);
  Serial.print("z*y = ");
  Serial.println(z*y);
  Serial.print("z/y = ");
  Serial.println(z / y);
  delay(3000);
}
