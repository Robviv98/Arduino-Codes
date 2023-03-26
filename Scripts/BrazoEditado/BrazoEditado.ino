#include "Simple_MPU6050.h"          // incluye libreria Simple_MPU6050
#define MPU6050_ADDRESS_AD0_LOW     0x68      // direccion I2C con AD0 en LOW o sin conexion
#define MPU6050_ADDRESS_AD0_HIGH    0x69      // direccion I2C con AD0 en HIGH
#define MPU6050_DEFAULT_ADDRESS     MPU6050_ADDRESS_AD0_LOW // por defecto AD0 en LOW

Simple_MPU6050 mpu;       // crea objeto con nombre mpu
// ENABLE_MPU_OVERFLOW_PROTECTION();    // activa proteccion, ya no se requiere

// #define OFFSETS  -5114,     484,    1030,      46,     -14,       6  // Colocar valores personalizados




void setup() {

//attachInterrupt(digitalPinToInterrupt(2), velocidadMenos, RISING);
  
  uint8_t val;
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE  // activacion de bus I2C a 400 Khz
  Wire.begin();
  Wire.setClock(400000);
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
  Fastwire::setup(400, true);
#endif
  
  Serial.begin(115200);     // inicializacion de monitor serie a 115200 bps
  while (!Serial);      // espera a enumeracion en caso de modelos con USB nativo
  Serial.println(F("Inicio:"));   // muestra texto estatico


}

void loop() {
  Quaternion q;  
  float ypr[3] = { 0, 0, 0 };
  mpu.GetQuaternion(&q, quat);    // funcion para obtener valor para calculo posterior
  mpu.GetGravity(&gravity, &q);
  mpu.GetYawPitchRoll(ypr, &q, &gravity);
  
 delay(500);
} 
