//DFRobotDFPlayerMini函式庫下載：https://github.com/DFRobot/DFRobotDFPlayerMini
#include "DFRobotDFPlayerMini.h"

#define RXD2 16 
#define TXD2 17

HardwareSerial myHardwareSerial(1); //ESP32可宣告需要一個硬體序列，軟體序列會出錯
DFRobotDFPlayerMini myDFPlayer;//啟動DFPlayer撥放器
void printDetail(uint8_t type, int value);//宣告播放控制程式

void setup()
{
  Serial.begin(115200);
  //啟動mp3連線
  myHardwareSerial.begin(9600, SERIAL_8N1, RXD2, TXD2); // Serial的TX,RX
  //實際上只用到TX傳送指令，因此RX可不接（接收player狀態）
  Serial.println("Initializing DFPlayer ... (May take 1-2 seconds)");
  myDFPlayer.begin(myHardwareSerial);//將DFPlayer播放器宣告在HardwareSerial控制
  delay(1000);
  myDFPlayer.volume(30);  //設定聲音大小（0-30）
//  Serial.println("test1");
//  myDFPlayer.playMp3Folder(1);  //播放mp3內的0001.mp3 3秒鐘
//  delay(2000);
//  myDFPlayer.pause();

}

void loop()
{
  String s_mp3no;//x代表初始值，即網路沒有指令
  int i_mp3no = -1;//-1代表初始值，即網路沒有傳指令
  
 if (Serial.available()){                 //如果序列緩衝區有資料
     s_mp3no=Serial.readString();       //從緩衝區讀取一個字串
     i_mp3no = s_mp3no.toInt();
    if ((i_mp3no > 0)) {
      Serial.print("play"); Serial.println(i_mp3no);
      myDFPlayer.playMp3Folder(i_mp3no);
    }
    if (i_mp3no == 0) {
      Serial.print("i_mp3no=");
      Serial.println(i_mp3no);
      myDFPlayer.pause();
    }
   }
 }
