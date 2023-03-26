

//GND - GND
//VCC - VCC
//SDA - Pin A4
//SCL - Pin A5


#include<SoftwareSerial.h>
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

SoftwareSerial Bluetooth(12,11);

const int mpuAddress = 0x68;  //Puede ser 0x68 o 0x69
MPU6050 mpu(mpuAddress);

int ax, ay, az;
int gx, gy, gz;

int x, y, z;

char c=' ';
bool calibrador=false;

void printTab()
{
   Serial.print(F("\t"));
}

void printRAW()
{
   //Serial.print(F("a[x y z] g[x y z]:t"));printTab();
   int a[]={ax-x, ay-y, az-z};
   Serial.print("x:");
   Serial.print(ax-x); printTab();
   Bluetooth.print("<");
   Bluetooth.print(ax-x);
   Bluetooth.print(",");
   delay(30);

   Serial.print("y");
   Serial.print(ay-y); printTab();
//   Bluetooth.print("");
   Bluetooth.print(ay-y);
   Bluetooth.print(",");
   delay(30);


   Serial.print("z:");
//   Bluetooth.print("z");
   Serial.println(az-z); printTab();
   Bluetooth.print(az-z);
   Bluetooth.print(">");
   delay(30);

   
   //Serial.print(gx); printTab();
   //Serial.print(gy); printTab();
   //Serial.println(gz);
}

void setup()
{
   Serial.begin(9600);
   Bluetooth.begin(38400);
   Wire.begin();
   mpu.initialize();
   delay(100);
   Serial.println(mpu.testConnection() ? F("IMU iniciado correctamente") : F("Error al iniciar IMU"));
   pinMode(9,INPUT);
   mpu.getAcceleration(&x, &y, &z);
   Serial.println("Calibrando");
}

void loop()
{
   // Leer las aceleraciones y velocidades angulares

   //mpu.getRotation(&gx, &gy, &gz);

   
   if(digitalRead(9)==HIGH && calibrador){
    mpu.getAcceleration(&x, &y, &z);
    Serial.println("Calibrando");
    calibrador=false;
   }
   else{
       mpu.getAcceleration(&ax, &ay, &az);
    printRAW();
   }
   if(digitalRead(9)==LOW){
    calibrador=true;
   }


    if(Bluetooth.available()){
      //c=Bluetooth.read();
      Serial.write(Bluetooth.read());
    }
    if(Serial.available()){
      //c=Serial.read();
      Bluetooth.write(Serial.read());
    }
   delay(500);

}
