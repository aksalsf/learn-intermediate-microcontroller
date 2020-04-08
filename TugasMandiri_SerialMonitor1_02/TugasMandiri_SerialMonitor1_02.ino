char Char[15]={'n','y','e','b','a','r','i','l','m','u','.','c','o','m','\n'};

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

 for (int i=0;i<15;i++){
 Serial.print("Karakter: ");
 Serial.print(Char[i]);
 Serial.print(", ASCII: ");
 Serial.print(Char[i],DEC);
 Serial.print(", Oktal: ");
 Serial.print(Char[i],OCT);
 Serial.print(", Heksa: ");
 Serial.print(Char[i],HEX);
 Serial.print(", Biner: ");
 Serial.println(Char[i],BIN);
 delay(10000); 
}
}
