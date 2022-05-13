#include <esp_adc_cal.h>
#define LM35_Sensor 15     //ADC pin
 
int LM35_Raw_Sensor = 0;
float LM35_TempC_Sensor = 0.0;
float LM35_TempF_Sensor = 0.0;
float Voltage = 0.0;
 
void setup()
{
  Serial.begin(115200);
}
 
void loop()
{
  // Read LM35_Sensor ADC Pin
  LM35_Raw_Sensor = analogRead(LM35_Sensor);  
  // Calibrate ADC & Get Voltage (in mV)
  Voltage = readADC_Cal(LM35_Raw_Sensor);
  // TempC = Voltage(mV) / 10
  LM35_TempC_Sensor = Voltage / 10;
  LM35_TempF_Sensor = (LM35_TempC_Sensor * 1.8) + 32;
 
  // Print The Readings
  Serial.print("Temperature = ");
  Serial.print(LM35_TempC_Sensor);
  Serial.print(" °C , ");
  Serial.print("Temperature = ");
  Serial.print(LM35_TempF_Sensor);
  Serial.println(" °F");
  
  delay(100);
}
 
uint32_t readADC_Cal(int ADC_Raw)
{
  esp_adc_cal_characteristics_t adc_chars;
  
  esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 1100, &adc_chars);
  return(esp_adc_cal_raw_to_voltage(ADC_Raw, &adc_chars));
}
