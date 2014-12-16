char valor;
boolean lec;
boolean luz;
int pot;

void setup() {
  
  Serial.begin(115200);
  pinMode(13,OUTPUT);
  pinMode(12,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 

valor=' ';

if (Serial.available()>0){
  valor=Serial.read();
  
  if (valor=='1'){
   digitalWrite(13,HIGH);
  }
  if (valor=='0'){
   digitalWrite(13,LOW);
  
  }
  
  }
else{
  pot=analogRead(A0);
  pot=map(pot,0,1023,0,120);
  lec=digitalRead(12);
  
  if (lec==HIGH){
   if (luz==HIGH){
    luz=LOW;
   }
   else{
    luz=HIGH;
  }
  delay(200);
  }
  
  String dato=("Estado='"+String(luz)+"' nivel='"+String(pot)+"'");
  delay(200);
  Serial.println(dato);
  
}



}

