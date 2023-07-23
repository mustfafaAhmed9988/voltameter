#include <LiquidCrystal.h>

const int VoltMeter = A2; 
LiquidCrystal lcd(13,7,5,4,3,2);
float V = 0.00; 
float R1 = 100000.00; 
float R2 = 10000.00; 
float vArduinoMax = 5.00; 
  float resistanceRatio =   resistanceRatio = (R2 / (R1 + R2)); 
  float averageValue = 0.00; 
  float voltage = 0.00; 
void calculate_voltage() { 
  for (int i = 0; i < 50 ; i++) 
  { 
    averageValue = averageValue + analogRead(VoltMeter);
    delay(3); 
  } 
  averageValue = averageValue / 50; 
  voltage = ((averageValue * vArduinoMax) / 1024); 
  V = voltage / resistanceRatio; 
 
} 
void setup() { 
  Serial.begin(9600);
  lcd.begin(16,2);
      
} 
void loop() { 

  calculate_voltage(); 
  delay(100);
  lcd.setCursor(0,0);
  lcd.print(V);
  lcd.print(" Volt");
  delay(100);
} 
