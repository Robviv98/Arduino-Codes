int c=0;
int ang;
int dist;

void setup() {
  Serial.begin(9600);
  Serial.println("Conectado");
  

}

void loop() {
  
  ang=random(0,360);
  dist=random(5,30);
  
  delay(1000);
  Serial.println(String(ang) + "_" + String(dist));
  c++;
}
