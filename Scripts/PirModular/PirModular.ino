#define MAX_SENSORS 2

bool seguridad=true;
bool alarma=false;
int tiempo=0,espera=5;//tiempo de espera en segundos
int buzzer=2;
int led=3;


void InicializarPir(){
  for(int c=0;c<MAX_SENSORS;c++){
    pinMode(c+28,INPUT);
  }
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
}

void estadoPIR(){

  if(seguridad & ((tiempo+espera))<millis()){
    alarma=false;
    for(int c=0;c<MAX_SENSORS;c++){
      if(digitalRead(c+28)){
        Serial.println("Se detecta movimiento en la habitacion: "+String(c));
        tiempo=millis();
        alarma=true;

      }
    }
  }

  if(alarma){
    tone(buzzer, 1000);
    digitalWrite(led,HIGH);

  }
  else{
    noTone(buzzer);
    digitalWrite(led, LOW);

  }

}

void setup() {

  InicializarPir();

}

void loop() {
  
  estadoPIR();
  
}
