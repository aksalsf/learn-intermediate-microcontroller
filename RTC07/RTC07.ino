#include <Wire.h>

#include <RTClib.h>

DS1307 rtc;
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  rtc.begin();
  Serial.begin(9600);
  delay(1000);

  if(!rtc.isrunning()) {
    Serial.println("RTC is NOT running");
    } else {
       //following line sets the RTC to the date & time this sketch was compiled
       //rtc.adjust(DateTime("01.01.2020", "00.00.00"));
       //rtc.adjust(DateTime(__DATE__, __TIME__));
       Serial.println("RTC is running!");
      }
}

void loop() {
  // put your main code here, to run repeatedly:
DateTime now = rtc.now();
/*
 Serial.print(now.year(), DEC);
 Serial.print('/');
 Serial.print(now.month(), DEC);
 Serial.print('/');
 Serial.print(now.day(), DEC);
 Serial.print(' ');
 Serial.print(now.hour(), DEC);
 Serial.print(':');
 Serial.print(now.minute(), DEC);
 Serial.print(':');
 Serial.print(now.second(), DEC);
 Serial.println();
*/
 char buf[100];
 strncpy(buf,"DD.MM.YYYY hh:mm:ss\0",100);
 Serial.println(now.format(buf));

 delay(1000);

}
