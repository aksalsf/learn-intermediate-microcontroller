#define PINLDR 1 //Mendefinisikan pin yang akan dipakai LDR
#define LED 13 //Mendefinisikan pin yang akan dipakai LED
int sensorLDR = 0;
int output = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorLDR = analogRead(PINLDR);
  output = map(sensorLDR, 0, 1023, 0, 500);
  Serial.println(output);
  if (output <= 300) {
    digitalWrite (LED, HIGH);
  } else {
    digitalWrite (LED, LOW);
  }
  delay(500);
}
