int sensor = A0;
int relayLamp = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(relayLamp, OUTPUT);
}

void loop()
{
  float ldr = analogRead(sensor);
  Serial.print("Lux: ");
  Serial.println(ldr);
  delay(1000);

  if (ldr < 200)
  {
    digitalWrite(relayLamp, LOW);
    }
  if (ldr > 200)
  {
    digitalWrite(relayLamp, HIGH);
    }
}
