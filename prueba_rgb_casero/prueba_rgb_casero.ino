int ROJO=9;
int AZUL=10;
int VERDE=11;



void setup() {

pinMode(ROJO, OUTPUT);
pinMode(AZUL, OUTPUT);
pinMode(VERDE, OUTPUT);

}

void loop() {

  analogWrite(ROJO, random(0,255));
  analogWrite(AZUL, random(0,255));
  analogWrite(VERDE, random(0,255));
  
  
  delay(1000);
}
