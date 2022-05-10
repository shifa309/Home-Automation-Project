// the setup function runs once when you press reset or power the board
int LED_BUILTIN=2;

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(15, OUTPUT);
  pinMode(19, OUTPUT);
   pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(15, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(15, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  
  digitalWrite(19, HIGH);    // turn the LED off by making the voltage LOW
  delay(500); 
  digitalWrite(19, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  // wait for a second
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500); 
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  
  
}
