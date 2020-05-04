int relayPIN = 13; //Menginisiasi variabel untuk pin relay
String input;
void setup()
{
  Serial.begin(9600);
  pinMode(relayPIN, OUTPUT);
  while (!Serial);
  Serial.println("PRESS ON or OFF");
}
void loop()
{
  while (Serial.available()>0){
  input = Serial.readStringUntil('\n');
  }
  //  Bila diketikkan on, maka lamp menyala
  if (input=="on"){
    digitalWrite(relayPIN, HIGH);
    Serial.println("LAMP ON");
    delay(1000);
    }
  //  Bila diketikkan off, maka lamp padam
  if (input=="off"){
    digitalWrite(relayPIN, LOW);
    Serial.println("LAMP OFF");
    delay(1000);
    }
}
