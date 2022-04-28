/*
PIR("Passive Infrared Sensor") Motion Sensor,
紅外線動作感測器, 或稱人體紅外線感測器
*/

const int PIRSensor = 27; // 紅外線動作感測器連接的腳位
const int ledPin = 4; // LED 腳位
const int SSR=17;
int sensorValue = 0; // 紅外線動作感測器訊號變數

void setup() {
  Serial.begin(9600);
  pinMode(PIRSensor, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(SSR, OUTPUT);
}

void loop(){

// 讀取 PIR Sensor 的狀態
sensorValue = digitalRead(PIRSensor);
  Serial.print("Lighting: ");
  Serial.println(sensorValue);


// 判斷 PIR Sensor 的狀態
if (sensorValue == HIGH) {
 digitalWrite(ledPin, HIGH); // 有人，開燈
 digitalWrite(SSR, HIGH);
  }
else {
digitalWrite(ledPin, LOW); // 沒人，關燈
digitalWrite(SSR, LOW);
}
delay(1000);
}
