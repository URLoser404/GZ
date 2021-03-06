//https://www.23bei.com/tool-218.html 中文字轉碼
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(128, 64, &Wire, 4);
static const unsigned char PROGMEM str_1[] = {    // 二
0x00,0x00,0x00,0x00,0x00,0x10,0x3F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00
};
static const unsigned char PROGMEM str_2[] = {    // 資
0x41,0x00,0x21,0xFC,0x2A,0x44,0x14,0x48,0x20,0xA0,0xE1,0x10,0x26,0x0E,0x3F,0xF4,
0x10,0x10,0x1F,0xF0,0x10,0x10,0x1F,0xF0,0x10,0x10,0x1F,0xF0,0x0C,0x20,0x30,0x10
};
static const unsigned char PROGMEM str_3[] = {     //訊 
0x20,0x10,0x17,0xF8,0x10,0x10,0x01,0x10,0xFD,0x10,0x01,0x10,0x79,0x10,0x01,0x10,
0x7B,0xF0,0x01,0x10,0x79,0x10,0x49,0x10,0x49,0x0A,0x79,0x0A,0x49,0x06,0x01,0x00
};
static const unsigned char PROGMEM str_4[] = {    // 甲
0x00,0x08,0x3F,0xFC,0x21,0x08,0x21,0x08,0x21,0x08,0x3F,0xF8,0x21,0x08,0x21,0x08,
0x21,0x08,0x3F,0xF8,0x21,0x08,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00
};
static const unsigned char PROGMEM str_5[] = {    // 吳
0x00,0x10,0x1F,0xF8,0x10,0x10,0x10,0x10,0x1F,0xF0,0x00,0x00,0x00,0x10,0x3F,0xF8,
0x01,0x00,0x01,0x04,0xFF,0xFE,0x02,0x80,0x02,0x40,0x04,0x20,0x18,0x1C,0x60,0x08
};
static const unsigned char PROGMEM str_6[] = {     // 盛
0x00,0xA0,0x00,0x90,0x3F,0xFC,0x20,0x80,0x20,0x88,0x3E,0x88,0x22,0x50,0x22,0x50,
0x4A,0x22,0x44,0xD2,0x80,0x0E,0x1F,0xF0,0x12,0x90,0x12,0x90,0xFF,0xFE,0x00,0x00
};
static const unsigned char PROGMEM str_7[] = {    // 瑋
0x00,0x20,0x00,0x20,0xFD,0xFC,0x10,0x24,0x13,0xFE,0x10,0x00,0x11,0xFC,0x7D,0x04,
0x11,0xFC,0x10,0x20,0x13,0xFC,0x12,0x20,0x1F,0xFE,0xF0,0x20,0x40,0x20,0x00,0x20
};

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
void loop() {
display.clearDisplay();
display.drawBitmap(0, 0, str_1, 16, 16, WHITE);
display.drawBitmap(18, 0, str_2, 16, 16, WHITE);
display.drawBitmap(36, 0, str_3, 16, 16, WHITE);
display.drawBitmap(54, 0, str_4, 16, 16, WHITE);
display.drawBitmap(72, 0, str_5, 16, 16, WHITE);
display.drawBitmap(90, 0, str_6, 16, 16, WHITE);
display.drawBitmap(108, 0, str_7, 16, 16, WHITE);
display.display();
 
}
