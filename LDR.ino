#define Light 27  

 void setup() {  
 Serial.begin(115200); 
 pinMode (26, OUTPUT); 
 delay(1000);  
 }  

 void loop() {  
 int val = analogRead(Light);

   if (val<1800)
   {
    digitalWrite (26, HIGH);
   }
  else
  {
    digitalWrite (26, LOW);
  }
  
 Serial.println(val);  
 delay(1000);  
 }  
