const int triggerPin1 = 13; // Trigger Pin of Ultrasonic Sensor
const int echoPin1 = 12; // Echo Pin of Ultrasonic Sensor
const int triggerPin2 = 10; // Trigger Pin of Ultrasonic Sensor
const int echoPin2 = 9; // Echo Pin of Ultrasonic Sensor
long duration, cm;

void setup()
{
  Serial.begin(9600); // Starting Serial Terminal
  pinMode(11,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop()
{
  getUltrasonicOne();
  getUltrasonicTwo();
}

void getUltrasonicOne() {
  pinMode(triggerPin1, OUTPUT);
  digitalWrite(triggerPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin1, LOW);
  pinMode(echoPin1, INPUT);
  duration = pulseIn(echoPin1, HIGH);
  getUltrasonicOneValue(duration);
  printUltrasonicOneValue(cm);
  turnLEDOne(cm);
  }

long getUltrasonicOneValue(long duration) {
  cm = microsecondsToCentimeters(duration);
  return cm;
  }

void printUltrasonicOneValue(long cm) {
  Serial.print("Ultrasonik 1: ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  }

void getUltrasonicTwo() {
  pinMode(triggerPin2, OUTPUT);
  digitalWrite(triggerPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin2, LOW);
  pinMode(echoPin2, INPUT);
  duration = pulseIn(echoPin2, HIGH);
  getUltrasonicTwoValue(duration);
  printUltrasonicTwoValue(cm);
  turnLEDTwo(cm);
  }

long getUltrasonicTwoValue(long duration) {
  cm = microsecondsToCentimeters(duration);
  return cm;
  }

void printUltrasonicTwoValue(long cm) {
  Serial.print("Ultrasonik 2: ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  }

void turnLEDOne(int cm) {
  if(cm < 30) {
    digitalWrite(11, HIGH);
    } else {
      digitalWrite(11, LOW);
      }
  }

void turnLEDTwo(int cm) {
  if(cm < 30) {
    digitalWrite(8, HIGH);
    } else {
      digitalWrite(8, LOW);
      }
  }  

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
