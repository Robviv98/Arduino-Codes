#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Pin RST del módulo RC522
#define SS_PIN          10         // Pin SS del módulo RC522

MFRC522 Lector1(SS_PIN, RST_PIN);  // Crear instancia de la clase MFRC522

void setup() {
  Serial.begin(9600);             // Iniciar comunicación serial
  SPI.begin();                    // Iniciar comunicación SPI
  Lector1.PCD_Init();             // Iniciar el módulo RC522
  Serial.println("Módulo RC522 listo para leer tarjetas RFID");
}

void loop() {
  // Verificar si se ha detectado una tarjeta RFID
  if (Lector1.PICC_IsNewCardPresent() && Lector1.PICC_ReadCardSerial()) {
    // Mostrar el UID de la tarjeta RFID
    Serial.print("UID: ");
    for (byte i = 0; i < Lector1.uid.size; i++) {
      Serial.print(Lector1.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(Lector1.uid.uidByte[i], HEX);
    }
    Serial.println();
    Lector1.PICC_HaltA();         // Detener la comunicación con la tarjeta RFID
  }
}
