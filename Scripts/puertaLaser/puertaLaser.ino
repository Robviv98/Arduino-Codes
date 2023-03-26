int uno = 2;
int dos = 3;

int personas = 0;
int espera = 1000;

bool entrada = false;
bool salida = false;
bool siglo=false;

void deteccion() {
  if (entrada == false and salida == false and siglo == false) {
    if (digitalRead(uno) == LOW and digitalRead(dos) == HIGH) {
      entrada = true;
    }
    if (digitalRead(uno) == HIGH and digitalRead(dos) == LOW) {
      salida = true;
    }
  }

  if (entrada) {
    if (digitalRead(dos) == LOW) {
      personas++;
      entrada = false;
      Serial.println("Personas en la habitacion: " + String(personas));
      delay(espera);
    }
  }
  if (salida) {
    if (digitalRead(uno) == LOW) {
      personas--;
      salida = false;
      Serial.println("Personas en la habitacion: " + String(personas));
      delay(espera);
    }
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(uno, INPUT);
  pinMode(dos, INPUT);
}

void loop() {
  deteccion();
  

}
