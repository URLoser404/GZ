/*
Example of BH1750 library usage.
This example initalises the BH1750 object using the default
high resolution mode and then makes a light level reading every second.
Connection:
 VCC-5v
 GND-GND
 SCL-SCL  (A5 on Arduino Nano, Uno, Leonardo, etc or 21 on Mega and Due, on esp8266 free selectable or 22 on ESP32)
 SDA-SDA   (A4 on Arduino Nano, Uno, Leonardo, etc or 20 on Mega and Due, on esp8266 free selectable or 21 on ESP32)
 ADD-NC or GND

*/
#include <Wire.h>
#include <BH1750.h>
 
BH1750 lichtMeter;
 
void setup(){
  Serial.begin(9600);
 Wire.begin(21,22);                             //設定ESP32 I2C腳位
  lichtMeter.begin();
}


void loop() {
  uint16_t lux = lichtMeter.readLightLevel();
  Serial.print("Licht: ");
  Serial.print(lux);
  Serial.println(" lux");
  delay(500);
}
