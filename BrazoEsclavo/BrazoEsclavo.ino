#include <Separador.h>

#include<SoftwareSerial.h>
#include<Servo.h>

Servo base;
Servo largo;

int PINBASE = 4;
int PINLARGO = 5;
int PULSOMIN1 =500;
int PULSOMAX1= 2450;

int x;
int y;
int z;

char c;
char buf[12];
String v="";

Separador s;

SoftwareSerial miBT(11,12);

void separar(String valor){

  String xx = s.separa(v, ',',0);
  String yy = s.separa(v, ',',1);
  String zz = s.separa(v, ',',2);

  x=xx.toInt();
  y=yy.toInt();
  z=zz.toInt();

  int angulo=map(x, -20000, 20000, 0, 180);
  base.write(angulo);
  
  angulo=map(y, -25000, 20000, 180, 90);
  largo.write(angulo);
  
  Serial.println(x);
  Serial.println(y);
  Serial.println(z);
}


void setup() {

  base.attach(PINBASE, PULSOMIN1, PULSOMAX1);
  largo.attach(PINLARGO, PULSOMIN1, PULSOMAX1);
  
   Serial.begin(9600);
   Serial.println("Ready");
   miBT.begin(38400);
}

void loop() {

   
   if(miBT.available()){
     
     c=miBT.read();
     Serial.print(c);
     
    if(c=='<'){
      v="";
    }
    else if(c=='>'){
     
      Serial.println("");
      Serial.print("guardado: ");
      Serial.print(v);
      Serial.println("");
      separar(v);
    }
        else{
        v.concat(c);  

        
    }


   }
   


  
   if(Serial.available())
   miBT.write(Serial.read());

   //Serial.println(" ");

   //delay(200);

}
