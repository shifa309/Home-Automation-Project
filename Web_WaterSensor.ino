#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

#define POWER_PIN  17
#define SIGNAL_PIN 36

int value = 0; // variable to store the sensor value
String page = "";

const char* ssid = "TRANSWORLD";
const char* password = "03451122";
WebServer server(80);


void setup() {
  Serial.begin(115200);
  pinMode(POWER_PIN, OUTPUT);   // configure D17 pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW); // Set to LOW so no power flows through the sensor
  pinMode(5, OUTPUT);   

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
            " <h1>Water Level Sensor</h1>"
            "<h3>Water Level</h3>"
            "<h4>" + String(value) + "</h4>"
            "</center>"
            "</body>";
    server.send(200, "text/html", page);
  });
  server.begin();
  Serial.println("Web server started!");
          
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  
  // just setting a condition to indicate that if water level is very low or tank is about to be empty, turn LED ON.
  if(value>=800)
  {
  
  digitalWrite (5 ,LOW);
  }
  else 
  {
  digitalWrite (5 ,HIGH);
  }

  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  Serial.print("Water Sensor value: ");
  Serial.println(value);
  server.handleClient();

  delay(1000);
}
