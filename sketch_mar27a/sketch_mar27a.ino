float sensorADCData;
int pin=0; //analog input pin
int delayTime=1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorADCData = analogRead(pin);
  Serial.print("ADC DATA: ");
  Serial.println(sensorADCData);
  Serial.println(" ");
  delay(delayTime);
  //konversi temp ke celcius
  // 500mV/1024=.48828125
  sensorADCData = sensorADCData * 0.48828125;
  Serial.print("CELSIUS: ");
  Serial.print(sensorADCData);
  Serial.println("deg C");
  Serial.println(" ");
  delay(delayTime);
  //konversi celcius ke fahrenheit
  sensorADCData = sensorADCData *9 / 5;
  sensorADCData = sensorADCData + 32;
  Serial.print("FAHRENHEIT: ");
  Serial.print(sensorADCData);
  Serial.println("deg F");
  Serial.println(" ");
  delay(delayTime);
}
