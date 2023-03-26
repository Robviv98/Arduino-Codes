 #include<Servo.h>

Servo servo;
int ECO1 =2;
int TRIG1=3;
int DUR1;
int DIS1;


int ECO2=4;
int TRIG2=5;

int ECO3=6;
int TRIG3=7;

int ECO4=8;
int TRIG4=9;

int PINSERVO1 = 10;
int PULSOMIN1 =510;
int PULSOMAX1= 2050;

int base=0;

void mapeo(){

  for(int c=0;c<181;c++){
    delay(10);
    servo.write(c);
    delay(10);
    digitalWrite(TRIG1, HIGH);
    delay(1);
    digitalWrite(TRIG1, LOW);
    DUR1=pulseIn(ECO1,HIGH);
    DIS1=DUR1/58.2;
    Serial.print("Distancia 1:  ");
    Serial.println(float(DIS1)/100);
    delay(100);
  }

  
}

void setup(){
  servo.attach(PINSERVO1, PULSOMIN1, PULSOMAX1);
  Serial.begin(9600);
  Serial.println("Vivo");
  
  //distancia
  pinMode(TRIG1, OUTPUT);
  pinMode(ECO1, INPUT);
  
}
//garra 30 cerrada, 0 abierta
//base puede ser de 0 a 180
void loop(){

  mapeo();
  delay(2000);
}
