#include <SoftwareSerial.h>

SoftwareSerial BTSerial(11, 12); // RX, TX

void setup() {
  Serial.begin(9600); // velocidad de comunicación serie con el ordenador
  BTSerial.begin(38400); // velocidad de comunicación serie con el módulo Bluetooth
}

void loop() {
  if (BTSerial.available()) {
    Serial.write(BTSerial.read()); // envía datos recibidos por Bluetooth al ordenador
  }
  if (Serial.available()) {
    BTSerial.write(Serial.read()); // envía datos recibidos por el ordenador al módulo Bluetooth
  }
}
