

String lectura(){

  String Lec="";

  while(Serial3.available()){
    char data=Serial3.read();
    if(data==','){
      return Lec;
    }
    Lec+=data;
    
  }
  return Lec;
}


void setup() {
  Serial3.begin(115200);
  Serial.begin(9600);
  pinMode(13,OUTPUT);

}

void loop() {
  if(Serial3.available()){
    String Lec=lectura();

    if(Lec=="1"){
      digitalWrite(13,HIGH);
    }
    else if(Lec=="0"){
      digitalWrite(13,LOW);
    }

  }
  //digitalWrite(13,!digitalRead(13));

}
