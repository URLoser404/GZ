/******** 讀取遙控器的編碼 ********/
#include <IRremote.h>
#define RECV_PIN 25 // 紅外線接收腳位綁定 ESP32 GPIO25

unsigned int recvData;
IRrecv irrecv(RECV_PIN); // 宣告一個名為 irrecv 的物件，並綁定接收腳位
decode_results results; // 宣告一個名為 results 的物件

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // 開始接收
  Serial.println("Enabled IRin");
}
void loop() {
  if (irrecv.decode(&results)) { // 接收數據並解碼
    recvData = results.value; // 解碼後數據存入變數中
    Serial.println(recvData, HEX); // 將數據顯示於序列埠
    irrecv.resume(); // 繼續接收下一筆資料
  }
  delay(100);
}
