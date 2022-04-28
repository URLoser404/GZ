//MX7219
//GPIO 18 -> LED CLK 
//GPIO 23 ->LED DIN（MOSI）   
//GPIO 15 ->LED CS
// Pin 12:Data in, Pin 11: Clock,  Pin 10: CS(Load)[NUO]
// Pin 23:Data in, Pin 18: Clock,  Pin 15: CS(Load)[ESP32]
//library "LedControl" by Eberhard Fahle

#include <SPI.h>
#include "LedControl.h"  
LedControl display = LedControl(23,18,15,1);
 
const uint64_t R_IMAGES[] = {   //小紅人跑歩
  0x66442c181e0c0606,
  0x42462c5a3e0c0606,
  0x4066184d3e0c0606,
  0x4063140d261e0303,
  0x47645c2d1e060303,
  0x23324c2d1e060303,
  0x141a0c2e1e060303,
  0x203828181c0c0606
};
const int R_IMAGES_LEN = sizeof(R_IMAGES)/8;

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

int i = 0;

void loop() {
   displayImage(R_IMAGES[i]);
  if (++i >= R_IMAGES_LEN ) {
    i = 0;
  }
  delay(50); 
}
