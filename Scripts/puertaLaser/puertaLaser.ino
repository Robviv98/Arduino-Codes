int uno = 2;
int dos = 3;

int luz=4;

int personas = 0;


bool entrada = false;
bool salida = false;

void deteccion() {
  if (entrada == false and salida == false) {
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
      while(digitalRead(dos) == LOW){

      }
    }
  }
  if (salida) {
    if (digitalRead(uno) == LOW) {
      personas--;
      salida = false;
      Serial.println("Personas en la habitacion: " + String(personas));
      while(digitalRead(uno) == LOW){
        
      }
    }
  }
}

void proteccion(){
  if(personas<0){
    personas=0;
    Serial.println("error Conteo de personas negativo, se restablecera a 0");
  }
}

void luces(){
  if(personas>0){
    digitalWrite(luz,HIGH);
    
  }
  else{
    digitalWrite(luz,LOW);

  }
}

void setup() {
  Serial.begin(9600);
  pinMode(uno, INPUT);
  pinMode(dos, INPUT);
  pinMode(luz, OUTPUT);
}

void loop() {
  luces();
  proteccion();
  deteccion();
  

}
