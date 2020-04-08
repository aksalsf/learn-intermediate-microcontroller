//LM35 x LED
const int pinSuhu = A0;
float suhu, data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinSuhu, INPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  data = analogRead(pinSuhu);
  suhu = (data*500/1023);
  Serial.print("Sensor Data: ");
  Serial.println(data);
  delay(1000);
  Serial.print("Suhu: ");
  Serial.println(suhu);
  delay(1000);
  ledIndicator(suhu); //Memanggil method ledIndicator
}

void ledIndicator(float suhu) {
  if (suhu<27) { //Ketika suhu kurang dari 27 derajat celcius, maka LED hijau menyala
    digitalWrite(4, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(13, LOW);
    } else if(suhu<=59) { //Ketika suhu kurang dari sama dengan 59 derajat celcius, maka LED kuning menyala
    digitalWrite(8, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(13, LOW);
    } else { //Ketika suhu di atas 50 derajat celcius, maka LED merah menyala
    digitalWrite(13, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(8, LOW);
    }
}
