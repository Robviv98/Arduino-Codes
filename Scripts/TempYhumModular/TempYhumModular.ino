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

void MedirTempyHum() {
  for (int i = 0; i < MAX_SENSORS; i++) {
    temperatures[i] = dht[i]->readTemperature();  // Acceso al objeto DHT a través del puntero
    humidities[i] = dht[i]->readHumidity();  // Acceso al objeto DHT a través del puntero
    Serial.println("Habitacion numero "+ String(i)+ " Temperatura: "+ String(temperatures[i])+ " Humedad: "+String(humidities[i]));
  }
}

void setup() {

  iniciarDHT();
}

void loop() {

  MedirTempyHum();
  delay(500);
}
