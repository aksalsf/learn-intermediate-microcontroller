#include <Password.h>
#include <Key.h>
#include <Keypad.h>

int LED = 6;
boolean isPasswordMatch = false;

String newPasswordString; //hold the new password
char newPassword[6]; //charater string of newPasswordString

//initialize password to 1234
//you can use password.set(newPassword) to overwrite it
Password password = Password( "1234" );

byte maxPasswordLength = 6;
byte currentPasswordLength = 0;

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
  
  Serial.println("Silakan ketik PIN Anda");
  Serial.println("* => Reset Password dan # => Submit");
}

void loop(){
  char key = customKeypad.getKey();
  if (key != NO_KEY){
    delay(60);
    switch (key){
     case '#': checkPassword(); break;
     case '*': resetPassword(); break;
     default: processNumberKey(key);
    }
   }

  if ( isPasswordMatch == true ) {
      digitalWrite(LED, HIGH);
    } else {
      digitalWrite(LED, LOW);
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

//void changePassword() {
//  newPasswordString = "123";
//  newPasswordString.toCharArray(newPassword, newPasswordString.length()+1);
//  //convert string to char array
//  password.set(newPassword);
//  resetPassword();
//  Serial.print("Password changed to ");
//  Serial.println(newPasswordString);
}
