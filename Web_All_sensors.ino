#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

String page = "";
const char* ssid = "Galaxy A31386B";
const char* password = "shifa123";
WebServer server(80);


//LDR
#define Light 27
int val;

//ultrasonic
//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701
#define buzzer 25
const int trigPin = 13;
const int echoPin = 12;
long duration;
float distanceCm;
float distanceInch;

//dht
#include <DHT.h>
#define DHT_SENSOR_PIN  15 // ESP32 pin GIOP21 connected to DHT11 sensor
#define DHT_SENSOR_TYPE DHT11
DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);
float humi;
float tempC;
float tempF;

//waterlevel
#define POWER_PIN  17
#define SIGNAL_PIN 36
int value = 0; // variable to store the sensor value

void setup() {
  Serial.begin(115200);
  delay(2000);

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
            "<h1> Home Automation System </h1>"
            " <h2>Light Dependent Resistor </h2>"
            "<h3>LDR value</h3>"
            "<h4>" + String(val) + "</h4>"
            " <br><br>"
            "<h2>Ultasonic Distance Monitor</h2>"
            "<h3>Current distance(cm):</h3>"
            "<h4>" + String(distanceCm) + "</h4> "
            "<h3>Current distance(inch):</h3> "
            "<h4>" + String(distanceInch) + "</h4>"
            " <br><br>"
            "<h2>Temperature | Humidity Sensor</h2>"
            "<h3> Humidity:</h3>"
            "<h4>" + String(humi) + "</h4>"
            "<h3>Temperature(celsius):</h3>"
            "<h4>" + String(tempC) + "</h4>"
            "<h3>Temperature (Farenheit):</h3>"
            "<h4>" + String(tempF) + "</h4>"
            " <br><br>"
             "<h2>Water Level Sensor</h2>"
            "<h3>Water Level</h3>"
            "<h4>" + String(value) + "</h4>"
            "</center>"
            "</body>";
    server.send(200, "text/html", page);
  });
  server.begin();
  Serial.println("Web server started!");
  
  //LDR
  pinMode (26, OUTPUT);

  //ultrasonic
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  dht_sensor.begin(); // initialize the DHT sensor
  pinMode(buzzer,OUTPUT);
  
  //water level
  pinMode(POWER_PIN, OUTPUT);   // configure D7 pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
  pinMode(5, OUTPUT);

  //DHT
  pinMode (32, OUTPUT);
  pinMode (33, OUTPUT);
}

void loop() {
   LDR();
   
  Ultrasonic();

  hum_temp();

  watersensor();
}


void LDR(){
Serial.println("LIGHT DEPENDENT RESISTOR");
  val = analogRead(Light);
  
   if (val<1800)
   {
    digitalWrite (26, HIGH);
   }
  else
  {
    digitalWrite (26, LOW);
  }
  Serial.print("LDR value: ");
  Serial.println(val);
  Serial.println();
  server.handleClient();
  delay(1500);
}

void Ultrasonic()
{
  //Clears the trigPin
  Serial.println("ULTRASONIC SENSOR");
  digitalWrite(trigPin, LOW);
  delay(1000);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delay(1000);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_SPEED/2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;
  if (distanceInch < 2)
     digitalWrite(buzzer, HIGH);
  else
     digitalWrite(buzzer, LOW);
  
  // Prints the distance in the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
  Serial.println();
  server.handleClient();
  delay(1500);
}

void hum_temp()
{
Serial.println("HUMIDITY & TEMPERATURE SENSOR");
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
  if ( isnan(tempC) || isnan(tempF) || isnan(humi)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    
    Serial.print("Humidity: ");
    Serial.print(humi);
    Serial.print("%");

    Serial.print("  |  ");

    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print("°C  ~  ");
    Serial.print(tempF);
    Serial.println("°F");
    Serial.println();
    server.handleClient();
  }
  // wait a 2 seconds between readings
  delay(1500);
  }

void watersensor()
{
  Serial.println("WATER LEVEL SENSOR");
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  if(value>=800)
  {
  digitalWrite (5 ,LOW);
  }
  else 
  {
  digitalWrite (5 ,HIGH);
  }
  
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  Serial.print("Sensor value: ");
  Serial.println(value);
  Serial.println();
  Serial.println();
  server.handleClient();
  delay(2000);
}
 
