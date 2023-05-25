#include <DHT.h>

#define MAX_SENSORS 4  // Número máximo de sensores DHT
float temperatures[MAX_SENSORS];
float humidities[MAX_SENSORS];
DHT* dht[MAX_SENSORS];  // Puntero a un arreglo de objetos DHT

void iniciarDHT() {
  for (int i = 0; i < MAX_SENSORS; i++) {
    int pin = 22 + i;  // Cálculo del pin basado en el número de sensor
    dht[i] = new DHT(pin, DHT22);  // Reserva de memoria dinámica para el objeto DHT
    dht[i]->begin(); // Inicializar el objeto DHT
  }
}


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

}


void Acciones(){

  if(Serial3.available()){
    String Lec=lectura();

    

  }


}

void leds(String c){
  if(c.charAt(0)=='d'){
    digitalWrite(c.charAt(1)-'0',c.charAt(2)-'0');

  }


}

void TemHum(){

  for (int i = 0; i < MAX_SENSORS; i++) {

    float temperatura = dht[i]->readTemperature();
    float humedad = dht[i]->readHumidity();

    Serial3.print(String("t"+String(temperatura)+","));
    Serial3.print(String("h"+String(humedad)+","));

  }

}

void Iniciar(){

  



}

/*
Codigos:
Led-> primero una d seguido de un numero, seguido de otro numero que indique su estado, ejemplo para prender led habitacion 3 seria d31 y para apagarlo d30




*/