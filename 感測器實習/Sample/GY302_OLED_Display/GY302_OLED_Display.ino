#include <Wire.h>
#include <BH1750.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // 設定OLED螢幕的寬度像素
#define SCREEN_HEIGHT 64 // 設定OLED螢幕的寬度像素
#define OLED_RESET     -1 // Reset pin 如果OLED上沒有RESET腳位，將它設置為-1

//OLED顯示器使用I2C連線並宣告名為display物件
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
bool OLEDStatus = true;
String DLux;
 
BH1750 lichtMeter;
 
void setup(){

 Serial.begin(9600);
 Wire.begin(21,22);    //設定ESP32 I2C腳位
 lichtMeter.begin();
   
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) { // 設定位址為0x3c
    Serial.println(F("SSD1306 allocation failed")); //F(字串)：將字串儲存在flash並非在RAM
    OLEDStatus = false;     //開啟OLED失敗
  }
  display.clearDisplay();       //清除螢幕

}
 
 
void loop() {
  uint16_t lux = lichtMeter.readLightLevel();
  DLux=String(lux);
  Serial.print("Licht: ");
  Serial.print(lux);
  Serial.println(" lux");
  if(OLEDStatus == true)  
   OLED_Display();
  delay(500);
}

void OLED_Display() {
  display.clearDisplay();       //清除螢幕
  display.setCursor(0, 0);     // 設定起始點位置(0,16)
  display.setTextSize(2);     //設定文字尺寸為2
  display.setTextColor(WHITE);    //設定文字顏色為白色(亮點)
  display.println("Licht:"); //將HH存入RAM
  display.setCursor(72, 0);     // 設定起始點位置(0,16)
  display.setTextSize(2);     //設定文字尺寸為3
  display.println(DLux); //將TT存入RAM
  display.display();      //顯示所設定文字
  //delay(2000);    //延遲2秒
}
