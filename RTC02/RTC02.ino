#include <virtuabotixRTC.h>
virtuabotixRTC myRTC(7, 6, 5);
//Urutan PIN: SCLK, DAT/IO, RST
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay (1000);
  // following line sets the RTC to the date & time this sketch was compiled
  //hh,mm,sec,dow,mm,dd,yyyy
  //myRTC.setDS1302Time(00, 00, 00, 6, 25, 05, 2020);
}

void loop() {
  // put your main code here, to run repeatedly:
  myRTC.updateTime();
  // Start printing elements as individuals
  Serial.print("Current Date / Time: ");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print(" ");
  Serial.print(myRTC.hours);
  Serial.print(":");
  Serial.print(myRTC.minutes);
  Serial.print(":");
  Serial.println(myRTC.seconds);
  delay(1000); 
}
