#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

#define Light 27  
const char* ssid = "TRANSWORLD";
const char* password = "03451122";

WebServer server(80);
String page ="";
int val;

 void setup() {  
 Serial.begin(115200); 
 pinMode (26, OUTPUT); 
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
            " <h1>Light Dependent Resistor </h1>"
            "<h3>LDR value</h3>"
            "<h4>" + String(val) + "</h4>"
            "</center>"
            "</body>";
    server.send(200, "text/html", page);
  });
  server.begin();
  Serial.println("Web server started!");

  
 }  

 void loop() {  
 
  val = analogRead(Light);
  
   if (val<1800)
   {
    digitalWrite (26, HIGH);
   }
  else
  {
    digitalWrite (26, LOW);
  }
  Serial.println(val); 
 
 server.handleClient(); 
 delay(1000);  
 }  
