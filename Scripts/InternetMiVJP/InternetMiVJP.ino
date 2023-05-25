
#include "config.h"
int led=13;
int c=0;

//iniciar Feed

AdafruitIO_Feed *ld1 = io.feed("casajm.luz-1");
AdafruitIO_Feed *ld2 = io.feed("casajm.luz-2");
AdafruitIO_Feed *ld3 = io.feed("casajm.luz-3");

AdafruitIO_Feed *t1 = io.feed("casajm.Temperatura-1");
AdafruitIO_Feed *t2 = io.feed("casajm.Temperatura-2");
AdafruitIO_Feed *t3 = io.feed("casajm.Temperatura-3");

AdafruitIO_Feed *h1 = io.feed("casajm.Humedad-1");
AdafruitIO_Feed *h2 = io.feed("casajm.Humedad-2");
AdafruitIO_Feed *h3 = io.feed("casajm.Humedad-3");




//terminar iniciar Feed



String mensaje;

void conectarWIFI(){
  Serial.print("Connecting to Adafruit IO");
  io.connect();
  delay(100);
  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
  Serial.println(",");

  iniciarFeeds();


}

void iniciarFeeds(){


  ld1->onMessage(recibirIOT);
  ld2->onMessage(recibirIOT); 
  ld3->onMessage(recibirIOT);
  ld1->get();

}


void recibirIOT(AdafruitIO_Data *data) {


  Serial.print(data->toString()+",");
  
}



void Recibir(){

  if(Serial.available()){
    String data="";
    while(Serial.available()){

      char c = Serial.read();
      data += c;

    }

  }

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