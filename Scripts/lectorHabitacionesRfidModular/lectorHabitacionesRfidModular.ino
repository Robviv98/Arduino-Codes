#include <SPI.h>
#include <MFRC522.h>



// Zona Rfid y identificacion de personas
      //Lectores a utilizar
  //Lector 1
#define RST_PIN1         9          // Pin RST del módulo RC522
#define SS_PIN1          10         // Pin SS del módulo RC522

MFRC522 Lector1(SS_PIN1, RST_PIN1);  // Crear instancia de la clase MFRC522

  //Lector 2
#define RST_PIN2         11          // Pin RST del módulo RC522
#define SS_PIN2          12         // Pin SS del módulo RC522

MFRC522 Lector2(SS_PIN2, RST_PIN2);  // Crear instancia de la clase MFRC522


      // Parametros para el conteo
int Fuera = 0, Dormitorio1 = 1, Dormitorio2 = 2, Salon = 3;
int PersonasI[5] ={0};/// IMPORTANTE EL LARGO DE ESTA MATRIZ DEBE SER IGUAL AL LARGO DE LA MATRIS PERSONAS[]                                  IMPORTANTE
String PersonasS[]={"Hector", "Juan", "Anna", "Fran", "Invitado"};
String HabitacionesS[] = {"Fuera", "Dormitorio1", "Dormitorio2", "Salon"};


      //Registro identificadores Rfid;
byte Registros[5][8] = {
    {0x04, 0x67, 0x8A, 0x3C, 0x00, 0x4F, 0xD4, 0x7E},//Hector
    {0x26, 0xAB, 0x7C, 0x92, 0x34, 0x00, 0x21, 0x02},//Juan
    {0xB7, 0x4F, 0x3C, 0x0A, 0x00, 0x00, 0x01, 0x01},//Anna
    {0x08, 0x01, 0xF2, 0x6D, 0x82, 0x13, 0x9A, 0xE1},//Fran
    {0xA2, 0xF8, 0xC7, 0x5B, 0xD0, 0x00, 0x52, 0x40} //Invitado
};




// Zona....






void iniciarRfid(){

  SPI.begin();                    // Iniciar comunicación SPI
  Lector1.PCD_Init();             // Iniciar el módulo RC522
  Serial.println("Módulo Lector1 listo para leer tarjetas RFID");

}

void Identificacion(MFRC522 Persona, int Habitacion){
  
  // Verificar si se ha detectado una tarjeta RFID
  if (Persona.PICC_IsNewCardPresent() && Persona.PICC_ReadCardSerial()) {
    // Obtener el UID de la tarjeta RFID
  byte uid[8];
  memcpy(uid, Persona.uid.uidByte, sizeof(uid));


    for(int x = 0; x < sizeof(Registros) / sizeof(Registros[0]); x++){
          if(memcmp(uid, Registros[x], sizeof(Registros[x])) == 0){
            Serial.println(PersonasS[x]+" Esta pasando");
            PersonasI[x]=Habitacion;

          }


    }


    Lector1.PICC_HaltA();         // Detener la comunicación con la tarjeta RFID
    Conteo();
  }
  
}

void Conteo(){

  int HabitacionesI[sizeof(HabitacionesS)/sizeof(HabitacionesS[0])] = {0};

  for(int x = 0; x < sizeof(HabitacionesS)/sizeof(HabitacionesS[0]); x++){

    Serial.println("En la habitacion " + HabitacionesS[x] + "Esta: ");

    for(int y = 0; y < sizeof(PersonasI)/sizeof(PersonasI[0]); y++){
      
      if(PersonasI[y]==x){
        HabitacionesI[x]++;
        Serial.println("    - " + PersonasS[y]);


      }

    }
    Serial.println("Con un total de: " + String(HabitacionesI[x]) + " Personas");


  }

}

void setup() {


  Serial.begin(9600);             // Iniciar comunicación serial


  //Zona Rfid
  
  iniciarRfid();



  //zona...

}

void loop() {
  Identificacion(Lector1, Dormitorio1);
  Identificacion(Lector2, Salon);

}
