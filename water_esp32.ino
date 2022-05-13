#define POWER_PIN  17
#define SIGNAL_PIN 36

int value = 0; // variable to store the sensor value

void setup() {
  Serial.begin(9600);
  pinMode(POWER_PIN, OUTPUT);   // configure D17 pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW); // Set to LOW so no power flows through the sensor
  pinMode(5, OUTPUT);           
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  Serial.print("Water Sensor value: ");
  Serial.println(value);

  delay(1000);
}
