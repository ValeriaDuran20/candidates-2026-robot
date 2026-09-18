/*
  Fecha: 18/09/2026
  Valeria Duran Vasquez, A00846220
 Candidates 2026 RoBorregos

  QUE HACE ESTE PROGRAMA
  Solo lee los tres numeros que da el sensor y los escribe en la pantalla.
  No decide colores todavia. Es nada mas para comprobar que el sensor esta
  bien conectado y que si responde.

  COMO SE CONECTA
    Sensor VIN  3V3
    Sensor GND GND
    Sensor SDA  pin 21
    Sensor SCL  pin 22


*/

#include <Wire.h>
#include <Adafruit_TCS34725.h>

Adafruit_TCS34725 sensor = Adafruit_TCS34725();

void setup() {
  Serial.begin(115200);
  delay(1000);

  if (sensor.begin() == true) {
    Serial.println("Sensor encontrado, si funciona");
  }
  else {
    Serial.println("No encontre el sensor, revisa los cables");
    // Se queda aqui parado para que alcance a leerse el mensaje
    while (true) {
      delay(1000);
    }
  }
}

void loop() {

  // El simbolo & quiere decir que el sensor guarda
  // el resultado dentro de estas tres variables
  float rojo;
  float verde;
  float azul;
  sensor.getRGB(&rojo, &verde, &azul);

  Serial.print("rojo = ");
  Serial.print(rojo);
  Serial.print("    verde = ");
  Serial.print(verde);
  Serial.print("    azul = ");
  Serial.println(azul);

  delay(1000);
}
