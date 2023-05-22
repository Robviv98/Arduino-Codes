#include "config.h"
int led=13;
int c=0;
AdafruitIO_Feed *luz = io.feed("casar.luz");
AdafruitIO_Feed *ld = io.feed("casar.led");

String mensaje;

void conectarWIFI(){
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
  Serial.println(",");

  ld->onMessage(recibirLed);
  luz->get();
  ld->get();
  //restablecer();

}




void recibirLed(AdafruitIO_Data *data) {
  if(data->toPinLevel()==HIGH){

    Serial.println("1");
  }
  else if(data->toPinLevel()==LOW){
    Serial.println("0");
  }
  
  //Serial.println("recibido estado led");
  
  //digitalWrite(led,data->toPinLevel());
}

void Recibir(){

  if(Serial.available()){
    String data="";
    while(Serial.available()){

      char c = Serial.read();
      data += c;


    }

    Enviar(data);

  }



}

void Enviar(String data){

  Serial.println("el mennsaje recibido es:  " + data);

}

void setup() {

  conectarWIFI();
  //pinMode(led, OUTPUT);
  Serial.begin(115200);

}



void loop() {

  Recibir();
  


  io.run();
}

