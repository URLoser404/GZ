//MX7219
//GPIO 18 -> LED CLK 
//GPIO 23 ->LED DIN（MOSI）   
//GPIO 15 ->LED CS
// Pin 12:Data in, Pin 11: Clock,  Pin 10: CS(Load)[NUO]
// Pin 23:Data in, Pin 18: Clock,  Pin 15: CS(Load)[ESP32]
//library "LedControl" by Eberhard Fahle

// LedMatrix
#include <SPI.h>
#include <LedControl.h> 
LedControl display = LedControl(23,18,15,1); 
uint64_t current = 0x0000000000000002;
const int R_IMAGES_LEN = sizeof(current)/8;

//JoyStick
#define xposPin 36         
#define yposPin 39         
#define buttonPin 34       

void setup()
{
  display.clearDisplay(0);    // 清除螢幕
  display.shutdown(0, false);  // 關閉省電模式
  display.setIntensity(0, 10); // 設定亮度為 8 (介於0~15之間)

}
void displayImage(uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      display.setLed(0, i, j, bitRead(row, j));
    }
  }
}



void loop() {
  int vrx, vry, sw;
  vrx = analogRead(xposPin);
  vry = analogRead(yposPin);
  sw = analogRead(buttonPin);


  if (vrx == 4095)  current >>= 1; 
  if (vrx == 0 ) current <<= 1;
  if (vry == 4095) current >>= 8;
  if (vry == 0 ) current <<= 8;

  
  displayImage(current);
  delay(200); 
}
