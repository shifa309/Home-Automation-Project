# Home-Automation-Project
IOT project with sensors and leds.

                               Home Automation System
This Project interfaces some of sensors for IOT application also known as Home automation.

Sensors include:

1. Humidity-Temperature Sensor -- DHT 11 : Digital sensor for sensing temperature and humidity.
2. Water Level Sensor : Detect the presence of water and, when placed in locations where water should not be present, a leak. 
    The resistance is inversely proportional to the height of the water. The sensor produces an output voltage according to the resistance, which by measuring we can determine the water level.
3. Ultrasonic Sensor -- HCSR04: It work by emitting sound waves. They then wait for the sound to be reflected back, calculating distance based on the time required.
4. Light Dependent Resistor – LDR : Component that has a (variable) resistance that changes with the light intensity that falls upon it. This resistor works on the principle of photo conductivity.
5. Radio Frequency Identification -- RFID : The protocol followed by it is SPI (Serial Peripheral Interface)-commonly used to send data between microcontrollers and small peripherals such as shift registers, sensors.
(Note: RFID is implemented throught Arduino microprocessor)



Note: The above files here include .ino files separate for each sensor, with web server and then combined sensors code. 
      You just need to pass network credentials (ssid, password) according to the wifi you are using.



            Hardware -Wiring and LEDs (Inputs & Outputs)

                   Humidity/Temperature	

Pin Configuration -- Data Pin: 15	
      Cable Color
With Esp32 -- Data Pin: Purple	
With sensors -- Data Pin: Brown	
       OUTPUT
Humidity -- Pin 33,  LED: Red
Temperature -- Pin 32,  LED: Green



                   Water Level
     
Pin Configuration -- Power Pin: 17 (TX2), Signal Pin: 36,	
          Cable Color
With Esp32 -- Power Pin: Yellow, Signal Pin: Green
With sensors --   GND: Brown, Power Pin: Red, Signal Pin: Orange
    OUTPUT	
Pin 5, LED: Yellow


                 Light Dependent Reisistor (LDR)
	
Pin Configuration -- Terminal 1: Vcc, Terminal 2: Pin 27, (10ohms Resistor)
	
       Cable Color
With Esp32 -- Terminal 2: Green	
With sensors -- Terminal 2: Green

    OUTPUT	
Pin 26, LED: Red



                   Ultrasonic	

Pin Configuration -- Trigger Pin: 13, Echo Pin: 12

    Cable Color
With Esp32 -- Trigger: Yellow, Echo: Green
With sensors -- VCC: Yellow, Trigger: Green, Echo: Blue, GND: Purple	

    OUTPUT	
Pin 25, Buzzer











