#include <SoftwareSerial.h>

SoftwareSerial BTSerial(11, 12); // RX, TX
String buf;
long c=0;

int trig=2;
int echo=3;

void distancia(){
// Realizar la medición con el sensor HC-SR04
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH);
  float distance = duration * 0.034 / 2;
  Serial.println(distance);
  String dis = "Distancia: " + String(distance, 2) + " cm\n";
  BTSerial.write(dis.c_str(), dis.length());
  Serial.write(dis.c_str(), dis.length());
  
}

void setup() {

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  
  Serial.begin(9600); // velocidad de comunicación serie con el ordenador
  BTSerial.begin(38400); // velocidad de comunicación serie con el módulo Bluetooth.-
}

void loop() {
  while (BTSerial.available()) {
    Serial.write(BTSerial.read()); // envía datos recibidos por Bluetooth al ordenador
  
  }
  if (Serial.available()) {
    BTSerial.write(Serial.read()); // envía datos recibidos por el ordenador al módulo Bluetooth
  }

  delay(500);

  distancia();
  
   //Serial.write("Hola prueba\n");
  //String pru = String(c) + " Prueba Hola\n";
  //BTSerial.write(pru.c_str(), pru.length());
  //BTSerial.write("\n");
   c++;

}
