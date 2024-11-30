#include <OneWire.h>
#include <DallasTemperature.h>

#define pinoSensor 31

OneWire oneWire(pinoSensor);
DallasTemperature sensor(&oneWire);
DeviceAddress endTemp;


void setup() {
  Serial.begin(9600);
  sensor.begin();
}
void loop() {
  sensor.requestTemperatures();
  sensor.getAddress(endTemp,0);
  Serial.print("Temperatura: ");
  Serial.print(sensor.getTempC(endTemp),1);
  Serial.println("°C");
  delay(1000);
}
