 #include<Servo.h>

Servo servo1;

int PINSERVO1 = 4;
int PULSOMIN1 =500;
int PULSOMAX1= 2000;

int base=0;

//garra 30 cerrada, 0 abierta
//base puede ser de 0 a 180
//int PINSERVO1 = 4;
//int PULSOMIN1 =500;
//int PULSOMAX1= 2450;

void setup(){
  servo1.attach(PINSERVO1, PULSOMIN1, PULSOMAX1);
  Serial.begin(9600);
  Serial.println("Vivo");
}
//garra 30 cerrada, 0 abierta
//base puede ser de 0 a 180
void loop(){

  map(base, -16000, 20000, 0, 180);
  servo1.write(0);
  Serial.println("0 grados");
  delay(2000);
  //servo1.write(0);
  Serial.println("80 grados");
  //delay(2000);
  servo1.write(180);
  Serial.println("180 grados");
  delay(2000);
}
