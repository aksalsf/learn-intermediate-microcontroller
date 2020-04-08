void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Use +, -, *, or / as operator");
  Serial.println("Ex: 1 + 2");
}

void loop() {
  // put your main code here, to run repeatedly:
  int result;
  char operation;
  int a=0;
  int b=0;
  while(Serial.available() > 0){
    a = Serial.parseInt();
    operation = Serial.read();
    b = Serial.parseInt();
    Serial.print(a);
    Serial.print(operation);
    Serial.print(b);
  if(operation=='+') {
    result=a+b;
    }
  if(operation=='-') {
    result=a-b;
    }
  if(operation=='*') {
    result=a*b;
    }
  if(operation=='/') {
    result=a/b;
    }
  Serial.print(" = ");
  Serial.println(result);
 }
}
