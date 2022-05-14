#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

int trigger_pin = 13;
int echo_pin   = 12;
#define buzzer 25

#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

// Replace with your network credentials
const char* ssid = "TRANSWORLD";
const char* password = "03451122";

WebServer server(80);

String page = "";
int distance_cm;
int distance_Inch;

void setup() {
  Serial.begin(115200);
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(buzzer,OUTPUT);
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
    page = "<head><meta http-equiv=\"refresh\" content=\"3\"></head><center><h1>Ultasonic Distance Monitor</h1><h3>Current distance(cm):</h3> <h4>" + String(distance_cm) + "</h4> <h3>Current distance(inch):</h3> <h4>" + String(distance_Inch) + "</h4> </center>";
    server.send(200, "text/html", page);
  });
  server.begin();
  Serial.println("Web server started!");
}

void loop() {
  digitalWrite(trigger_pin, LOW);
  delay(2000);
  digitalWrite(trigger_pin, HIGH);
  delay(2000);
  digitalWrite(trigger_pin, LOW);
  
  long duration = pulseIn(echo_pin, HIGH);
  
   // Calculate the distance
  distance_cm = duration * SOUND_SPEED/2;

  // Convert to inches
  distance_Inch = distance_cm * CM_TO_INCH;

  if (distance_Inch < 2)
     digitalWrite(buzzer, HIGH);
  else
     digitalWrite(buzzer, LOW);
  
  Serial.print("Distance (cm): ");
  Serial.println(distance_cm);
  Serial.print("Distance (inch): ");
  Serial.println(distance_Inch);
  server.handleClient();
  delay(1000);
}
