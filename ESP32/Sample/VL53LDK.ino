
#include <Wire.h>
#include <VL53L0X.h>;

VL53L0X sensor;  // 宣告VL53L0X類型物件

void setup() {
  Serial.begin(9600);
  Wire.begin();  // 啟動I<sup>2</sup>C通訊

  sensor.setTimeout(500);  // 設定感測器超時時間
  // 若無法初始化感測器（如：硬體沒有接好），則顯示錯誤訊息。
  if (!sensor.init()) {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }
}

void loop() {
  // 在序列埠監控視窗顯示測距值
  Serial.print(sensor.readRangeSingleMillimeters());
  // 若發生超時（感測器沒有回應），則顯示“TIMEOUT”。
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
  Serial.println();
  delay(500);
}
