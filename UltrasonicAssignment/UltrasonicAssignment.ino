const int triggerPin = 13; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 12; // Echo Pin of Ultrasonic Sensor
long duration, cm;

void setup()
{
  Serial.begin(9600); // Starting Serial Terminal
  pinMode(11,OUTPUT);
}

void loop()
{
  getUltrasonic();
  turnLED(cm);
  printUltrasonicValue(cm);
}

void getUltrasonic() {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  getUltrasonicValue(duration);
  }

long getUltrasonicValue(long duration) {
  cm = microsecondsToCentimeters(duration);
  return cm;
  }

void printUltrasonicValue(long cm) {
  Serial.print("Jarak: ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  }

void turnLED(long delayByDistance) {
  digitalWrite(11, HIGH);
  delay(delayByDistance);
  digitalWrite(11, LOW);
  delay(delayByDistance);
  }

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
