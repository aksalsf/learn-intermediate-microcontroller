#define pirPIN 13
#define lampPIN 10
long unsigned int lowIn;
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takeLowTime;
int PIRValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pirPIN, INPUT);
  pinMode(lampPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  PIRSensor();
}

void PIRSensor()
{
 if (digitalRead(pirPIN) == HIGH)
 {
  if (lockLow)
  {
    PIRValue = 1;
    lockLow = false;
    Serial.println("Who is there?");
    digitalWrite(lampPIN, HIGH);
    delay(50);
    }
    takeLowTime = true;
  }
 if (digitalRead(pirPIN) == LOW)  
 {
  if (takeLowTime)
  {
    lowIn = millis();
    takeLowTime = false;
    }
  if (!lockLow && millis() - lowIn > pause)
  {
    PIRValue = 0;
    lockLow = true;
    Serial.println("There's nothing");
    digitalWrite(lampPIN, LOW);
    delay(50);
    }
  }
}
