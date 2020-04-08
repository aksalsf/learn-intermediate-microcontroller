// Sensor Suhu Tegangan Referensi 5 Volt
const int pinSuhu = A0; //Mendefinisikan pin yang digunakan sensor ADC
float suhu, data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinSuhu, INPUT); //Mengaktifkan tegangan referensi 5 volt di pin A0
}

void loop() {
  // put your main code here, to run repeatedly:
  data = analogRead(pinSuhu); //Mengambil data dari sensor
  suhu = data / 2.0479; // Mengkonversi ke suhu satuan Celcius
  Serial.print("Nilai Pin: ");
  Serial.println(data); //Mencetak nilai dari data sensor
  delay(1000);
  Serial.print("Suhu: ");
  Serial.println(suhu); //Mencetak hasil konversi ke celcius
  delay(1000);
}
