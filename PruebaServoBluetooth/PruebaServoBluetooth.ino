#include<SoftwareSerial.h>
SoftwareSerial miBT(12,11);

char c=' ';

void setup() {
   Serial.begin(9600);
   Serial.println("Ready");
   miBT.begin(38400);

}

void loop() {
      if(miBT.available())
      Serial.write(miBT.read());
    
    if(Serial.available())
      miBT.write(Serial.read());
    

}
