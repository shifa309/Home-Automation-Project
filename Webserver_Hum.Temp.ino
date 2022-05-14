#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <DHT.h>

#define DHT_SENSOR_PIN  15 // ESP32 pin GIOP15 connected to DHT11 sensor
#define DHT_SENSOR_TYPE DHT11
DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

const char* ssid = "TP-Link_0350";
const char* password = "60740311";

WebServer server(80);
String page = "";
float humi;
float tempC;
float tempF;

void setup() {

  pinMode (32, OUTPUT);
  pinMode (33, OUTPUT);
  
  Serial.begin(115200);
  dht_sensor.begin(); // initialize the DHT sensor
  
  delay(1000);

  WiFi.begin(ssid, password);
  Serial.println("");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

 server.on("/", []() {
     page = "<head>"
            "<meta http-equiv=\"refresh\" content=\"3\">"
            "</head>"
            " <body>"
            "<center>"
            " <h1>Temperature | Humidity Sensor</h1>"
            "<h3>Humidity:</h3>"
            "<h4>" + String(humi) + "</h4>"
            "<h3>Temperature(celsius):</h3>"
            "<h4>" + String(tempC) + "</h4>"
            "<h3>Temperature (Farenheit):</h3>"
            "<h4>" + String(tempF) + "</h4></center>";
            "</body>";
   
    server.send(200, "text/html", page);
  });
  
  server.begin();
  Serial.println("Web server started!");

}

void loop() {
  // read humidity
  humi  = dht_sensor.readHumidity();
  // read temperature in Celsius
   tempC = dht_sensor.readTemperature();
  // read temperature in Fahrenheit
   tempF = dht_sensor.readTemperature(true);

 //turn Green LED ON if Temperature is above 20°C
   if(tempC>20)
     digitalWrite(32, HIGH);
  else
     digitalWrite(32,  LOW);

//turn red LED on if Humidity is above 50%
  if(humi>50)
     digitalWrite(33, HIGH);
  else
    digitalWrite(33,  LOW);

  // check whether the reading is successful or not
  if ( isnan(tempC) || isnan(tempF) || isnan(humi)) {    // isnan means not a number
    Serial.println("Failed to read from DHT sensor!");
  } 
  else {
    Serial.print("Humidity: ");
    Serial.print(humi);
    Serial.print("%");

    Serial.print("  |  ");

    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print("°C  ~  ");
    Serial.print(tempF);
    Serial.println("°F");
    server.handleClient();
  }

  // wait a 2 seconds between readings
  delay(2000);
}
 

  
