#include <SoftwareSerial.h>

SoftwareSerial bluetooth(11, 12); // RX, TX

void setup() {
  Serial.begin(9600); // Inicializar el puerto serial para la salida de depuración
  bluetooth.begin(38400); // Inicializar la comunicación con el módulo HC-06
}

void loop() {
  if (bluetooth.available()) { // Si hay datos disponibles en el módulo HC-06
    char c = bluetooth.read(); // Leer el dato recibido
    Serial.write(c); // Escribir el dato en el puerto serial de la placa Arduino
  }
  if (Serial.available()) { // Si hay datos disponibles en el puerto serial de la placa Arduino
    char c = Serial.read(); // Leer el dato recibido
    bluetooth.write(c); // Escribir el dato en el módulo HC-06
  }
}
