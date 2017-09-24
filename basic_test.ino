/* Round Force Sensing Resistor (FSR402) [S031] : http://rdiot.tistory.com/83 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
int fsrAnalogPin = A0; // FSR pin Analog 0
int fsrValue;  
 
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
 
  delay(1000);
 
  lcd.clear();
}
 
void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S031:FSR402");
 
  fsrValue= analogRead(fsrAnalogPin);
 
  lcd.setCursor(0,1);
  lcd.print("Analog=" + (String)fsrValue + "   ");
 
 
  float voltage = fsrValue* (5.0 / 1023.0);
 
  lcd.setCursor(0,2);
  lcd.print("Volt=" + (String)voltage + "   ");
 
  delay(500);
 
}
