#include <Password.h>
#include <Key.h>
#include <Keypad.h>

// Define LED PIN
int LED = 6;

//Menyimpan apakah password benar atau salah
boolean isPasswordMatch = false, isAllowTyping = false;

// Define PIR PIN
#define pinOfPIR 5

// Konfigurasi PIR
long unsigned int lowIn;
long unsigned int pause = 100;
boolean lockLow = true;
boolean takeLowTime;
int PIRValue = 0;

//initialize password to 1234
//you can use password.set(newPassword) to overwrite it
Password password = Password( "1234" );

byte maxPasswordLength = 6;
byte currentPasswordLength = 0;

// Konfigurasi Keypad
const byte ROWS = 4;
const byte COLS = 3;
char hexaKeys[ROWS][COLS] = { 
 {'1','2','3'},
 {'4','5','6'},
 {'7','8','9'},
 {'*','0','#'}
};

byte rowPins[ROWS] = {7,8,9,10};
byte colPins[COLS] = {11,12,13};
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);  
  pinMode(pinOfPIR, INPUT);
}

void loop(){
  PIRSensor();

  if ( isPasswordMatch == true ) {
      digitalWrite(LED, HIGH);
    } else {
      digitalWrite(LED, LOW);
      }
}

void PIRSensor() {
  if ( digitalRead(pinOfPIR) == HIGH ) {
    if ( lockLow ) {
      PIRValue = 1;
      lockLow = false;
      Serial.println( "PIR mendeteksi benda, silakan ketik Password-nya!" );
      Serial.println( "Tekan [* untuk reset], dan [# untuk submit]" );
      }
      takeLowTime = true;
      detectTyping();
    }

  if ( digitalRead(pinOfPIR) == LOW ) {
    if (takeLowTime) {
      lowIn = millis();
      takeLowTime = false;
      }
    if ( !lockLow && millis() - lowIn > pause ) {
      PIRValue = 0;
      lockLow = true;
      isPasswordMatch = false;
      Serial.println("There's nothing");
      }
    }
}

void detectTyping() {
  char key = customKeypad.getKey();
  if (key != NO_KEY){
    delay(60);
    switch (key){
     case '#': checkPassword(); break;
     case '*': resetPassword(); break;
     default: processNumberKey(key);
    }
   }
  }

void processNumberKey(char key) {
  Serial.print(key);
  currentPasswordLength++;
  password.append(key);
  if (currentPasswordLength == maxPasswordLength) {
  checkPassword();
  }
}

void checkPassword() {
  if (password.evaluate()){
    Serial.println(" OK.");
    isPasswordMatch = true;
  } else {
      Serial.println(" Wrong password!");
      isPasswordMatch = false;
    }
  resetPassword();
}

void resetPassword() {
  password.reset();
  currentPasswordLength = 0; 
}
