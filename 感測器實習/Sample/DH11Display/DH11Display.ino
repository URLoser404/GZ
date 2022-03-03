/* 
*　例6-2：DHT溫溼度感測器功能測試
*/
#include "DHTesp.h"          //引用函式庫

DHTesp dht;                  //宣告物件，名字為 dht
const byte dhtPin = 17;      //使用 GPIO 17 接收溫溼度

void setup() {
  Serial.begin(9600);
  dht.setup(dhtPin, DHTesp::DHT11);   //若使用DHT22，則把DHT11改為DHT22
}
void loop() {
  TempAndHumidity lastValues = dht.getTempAndHumidity();                //取得溫溼度值
  Serial.println("溫度: " + String(lastValues.temperature, 1) + "度C"); //列印溫度
  Serial.println("溼度: " + String(lastValues.humidity, 1) + " %RH");   //列印溼度
  delay(2000);
}
