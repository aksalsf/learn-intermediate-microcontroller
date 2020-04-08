double Light (int RawADC0) //Method untuk menghitung nilai lux
{
  double Vout=RawADC0*0.0048828125;
  int lux=(2500/Vout-500)/10;
  return lux;
}

void setup() {
  Serial.begin(9600);
  for (int i=13;i>=11;i--) {
    pinMode(i,OUTPUT);
    } 
}

void loop() {
  double daylight = double(Light(analogRead(0)));
  Serial.print("Light Intensity:");
  Serial.print(daylight);
  Serial.println(" Lux");delay(1000);
  delay(1000);
  if (daylight < 1) { //Bila Flux kurang dari 1, maka Malam
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    Serial.println("[Malam]");delay(1000);
    } else if (daylight <= 50) { //Bila flux kurang dari 50, maka petang
      digitalWrite(13, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      Serial.println("[Senja]");delay(1000);
      } else if (daylight <= 400) { //Bila flux kurang dari 400, maka Sore
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(11, LOW);
        Serial.println("[Sore]");delay(1000);
        } else { //Bila lebih dari 400, maka siang
          digitalWrite(13, LOW);
          digitalWrite(12, LOW);
          digitalWrite(11, LOW);
          Serial.println("[Siang]");delay(1000);
          }
} // Referensi nilai Lux https://id.wikipedia.org/wiki/Lux
