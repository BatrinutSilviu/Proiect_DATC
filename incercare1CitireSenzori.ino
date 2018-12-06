#include "DHT.h"   //https://github.com/adafruit/DHT-sensor-library 
// Create the DHT temperature and humidity sensor object
DHT dht1(2, DHT11);

void setup(void) {
  Serial.begin(9600);
  dht1.begin();
}

void loop() {
 
  delay(3000);
  // Read DHT temperature and humidity values
  float DHT11_t = dht1.readTemperature();
  float DHT11_h = dht1.readHumidity();
    
  Serial.print("DHT11  ");
  Serial.print(DHT11_t,1); Serial.print(String(char(176))+"C  ");
  Serial.print(DHT11_h,1); Serial.println("%RH");
  Serial.println();
}
