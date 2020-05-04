#include <Wire.h>
#include <RTClib.h>
DS1307 rtc;
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  rtc.begin();
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  delay(1000);

  if(!rtc.isrunning()) {
    Serial.println("RTC is NOT running");
    } else {
       rtc.adjust(DateTime("23.04.2020", "06.00.00"));
       Serial.println("RTC is running!");
      }
}

void loop() {
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now();

  // LED Control
  if (now.hour()>=18 || now.hour()<6) {
    digitalWrite(13,HIGH);
    } else if (now.hour()>=6) {
      digitalWrite(13,LOW);
      }
  // Display Clock
  char buf[100];
  strncpy(buf,"DD.MM.YYYY hh:mm:ss\0",100);
  Serial.println(now.format(buf));
  delay(1000);

}
