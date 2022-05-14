#include "DHT.h"
#define DHT11_apin 2;

DHT dht;

void setup()
{
  Serial.begin(9600);
  delay(500);
  Serialprintln(DHT11 HUMIDITY );
  delay(1000);
/* Start the DHT11 Sensor */
  
}

void loop()
{
  int chk=DHT.read22(DHT11_PIN)
   Serial.print("Temperature: ");
  Serial.print(DHT.temperature);
  Serial.print("Humidity: ");
  Serial.println(DHT.Humidity);
  delay(1000);
}
