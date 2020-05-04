int relayPIN = 13;
void setup()
{
  pinMode(relayPIN, OUTPUT);
}
void loop()
{
  digitalWrite(relayPIN, LOW);
  delay(1000);
  digitalWrite(relayPIN, HIGH);
  delay(1000);
}
