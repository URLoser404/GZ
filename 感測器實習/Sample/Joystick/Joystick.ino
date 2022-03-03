int xposPin = 36;         // 雙軸按鍵搖桿 VRx 接 Arduino Analog pin 36
int yposPin = 39;         // 雙軸按鍵搖桿 VRy 接 Arduino Analog pin 39
int buttonPin = 34;        // 搖桿按鍵輸出 SW 接 Arduino pin 34

void setup() {
  Serial.begin(9600);
}
 
void loop() {
  int vrx, vry, sw;
 
  vrx = analogRead(xposPin);
  vry = analogRead(yposPin);
  sw = analogRead(buttonPin);
 
  char buf[100];
  sprintf(buf, "VRx=%d, VRy=%d, SW=%d", vrx, vry, sw);
  Serial.println(buf);
  delay(100);
}
