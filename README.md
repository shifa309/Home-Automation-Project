# Home-Automation-Project
IOT project with sensors and leds.

                               Home Automation System

Working of Ultrasonic Sensor – HCSR04:
Ultrasonic sensors work by emitting sound waves at a frequency too high for humans to hear. They then wait for the sound to be reflected back, calculating distance based on the time required.
Trig (Trigger) Pin is used to trigger the ultrasonic sound pulses. This is an input pin, used to initialize measurement by transmitting ultrasonic waves by keeping this pin high for 10us.  
Echo pin produces a pulse when the reflected signal is received. The length of the pulse is proportional to the time it took for the transmitted signal to be detected. This is an output pin, which goes high for a specific time period and it will be equivalent to the duration of the time for the wave to return back to the sensor.
To measure the distance the sound has travelled we use the formula: Distance = (Time x Speed Of Sound) / 2. The "2" is in the formula because the sound has to travel back and forth. First the sound travels away from the sensor, and then it bounces off of a surface and returns back. 



Working of Water Sensor – HCSR04:
Water sensors detect the presence of water and, when placed in locations where water should not be present, a leak. 
The change in resistance corresponds to the distance from the top of the sensor to the surface of the water. The resistance is inversely proportional to the height of the water. The more water the sensor is immersed in, results in better conductivity and will result in a lower resistance. The sensor produces an output voltage according to the resistance, which by measuring we can determine the water level.



Working of Humidity|Temperature Sensor – DHT11:
DHT11 is a low-cost digital sensor for sensing temperature and humidity. DHT11 sensor consists of a capacitive humidity sensing element and a thermistor for sensing temperature. 
The temperature range of DHT11 is from 0 to 50 degree Celsius with a 2-degree accuracy. Humidity range of this sensor is from 20 to 80% with 5% accuracy. 
It has three pins and is mounted to a small PCB. The PCB mounted version is nice because it includes a surface mounted 10K Ohm pull up resistor for the signal line.

The issue that was coming was that it was not determining the dht type and some issues with dht libraries on Arduino IDE too.



Working of Radio Frequency Identification - RFID:
RFID or Radio Frequency Identification system consists of two main components, a transponder/tag attached to an object to be identified, and a Transceiver also known as interrogator/Reader.
A Reader consists of a Radio Frequency module and an antenna which generates high frequency electromagnetic field. On the other hand, the tag is usually a passive device, meaning it doesn’t contain a battery. Instead it contains a microchip that stores and processes information, and an antenna to receive and transmit a signal.
For example, only the person with the right information on his card is allowed to enter. An RFID system uses:
•	tags attached to the object to be identified, in this example we have a keychain and an electromagnetic card. Each tag has his own identification (UID).

•	two-way radio transmitter-receiver, the reader, that send a signal to the tag and read its response.

Serial Peripheral Interface (SPI) is an interface bus commonly used to send data between microcontrollers and small peripherals such as shift registers, sensors.
The RC522 module has total 8 pins that interface it to the outside world.
•	MISO pin and MOSI pin is used for SPI communication.
•	SCK: Serial Clock pin – used to provide clock source.
•	SS: Acts as Serial input for SPI communication,



Working of Light Dependent Resistor – LDR:
An LDR is a component that has a (variable) resistance that changes with the light intensity that falls upon it.
When the light level decreases, the resistance of the LDR increases. As this resistance increases in relation to the other Resistor, which has a fixed resistance, it causes the voltage dropped across the LDR to also increase.
This resistor works on the principle of photo conductivity. It is nothing but, when the light falls on its surface, then the material conductivity reduces and also the electrons in the valence band of the device are excited to the conduction band. These photons in the incident light must have energy greater than the band gap of the semiconductor material. This makes the electrons to jump from the valence band to conduction.






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











