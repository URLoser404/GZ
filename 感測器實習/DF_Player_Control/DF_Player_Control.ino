// OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
bool OLEDStatus = true;

//DF Player
#include "DFRobotDFPlayerMini.h"
#define RXD2 16 
#define TXD2 17
HardwareSerial myHardwareSerial(1); //ESP32可宣告需要一個硬體序列，軟體序列會出錯
DFRobotDFPlayerMini myDFPlayer;//啟動DFPlayer撥放器
void printDetail(uint8_t type, int value);//宣告播放控制程式

// Button 
int btnPins[] = {34 , 35 , 36 , 39};

// variable & function init
int mp3NO = 1;
int volume = 15;

void OLED_Display();
void playMusic();


void setup()
{
  // DF Player init
  Serial.begin(115200);
  myHardwareSerial.begin(9600, SERIAL_8N1, RXD2, TXD2); 
  Serial.println("Initializing DFPlayer ... (May take 1-2 seconds)");
  myDFPlayer.begin(myHardwareSerial);
  delay(1000);
  myDFPlayer.volume(15); 

  // OLED init
  Wire.begin(21, 22);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c))
  {
      Serial.println(F("SSD1306 allocation failed"));
      OLEDStatus = false;
  }
  display.clearDisplay();

  // Button
  for (auto i : btnPins){
    pinMode(i,INPUT);
  }
}

void loop()
{
  bool btnStatus[] = {0};
  for (int i = 0; i <4 ; i++){
    btnStatus[i] = digitalRead(btnPins[i]);
  }

  if (btnStatus[0]){
    mp3NO--;
    playMusic();
  }
  if (btnStatus[1]){
    volume++;
  }
  if (btnStatus[2]){
    mp3NO++;
    playMusic();
  }
  if (btnStatus[3]){
    volume--;
  }

  OLED_Display();
}

void playMusic(){
  if (mp3NO > 0){
    myDFPlayer.playMp3Folder(mp3NO);
  }else{
    myDFPlayer.pause();
  }
}


void OLED_Display()
{
    display.clearDisplay();

    // set pm2.5 value
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.printf("Playing:", mp3NO);

    // set temperature value
    display.setCursor(0, 24);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.printf("Volume:", volume);
    
    display.display();
}
 
