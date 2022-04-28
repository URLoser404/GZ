# Arduino Sensor Modules

說好聽一點是放各種的模組

其實只是我拿來放感測器實習的作業的啦哈哈

如果你懶得寫的話歡迎拿去用

助看到這一份的人都可以拿到 GZ 的三學分
## 說明

下面有作業對照表 

阿裡面是所有的作業 

如果我有寫或是我有補我之前沒來的作業的話

可以點下面旁邊藍藍的就是程式碼

或是按 `CODE` 把它整份下載下來

我懶得把它弄得美美的 所以接角甚麼的就自己判斷一下吧

還有在 [Sample](Sample) 資料夾裡有 GZ 給的所有範例檔

## 作業對照表

- [x] 氣體偵測器 - [MQ_Display](MQ_Display/MQ_Display.ino)
- [x] OLED顯示實習 
    - 顯示名字 - [OLED_Dispay](OLED_Display/OLED_Display.ino)
    - 顯示圖案 - [OLED_Picture](OLED_Picture/OLED_Picture.ino)
- [x] LED亮度感測器控制實習 - [BH1750_Display](BH1750_Display/BH1750_Display.ino)
- [x] 利用RFID讀卡機謮取實習 - [MFRC522_Display](MFRC522_Display/MFRC522.ino)
- [x] 利用搖桿搖動方向並顯示於OLED上 - [Joystick_Display](Joystick_Display/Joystick_Display.ino)
- [x] 利用搖桿控制8*8矩陣光點位移 - [Joystick_LEDmatrix](Joystrick_LEDmartix/Joystrick_LEDmartix.ino) 
- [x] 利用OLED顯示紅外線遙控器所按的數字 - [IR_Display](IR_Display/IR_Display.ino)
- [x] 使用PM2.5感測器及DH11完成氣象盒子實習 [Air_Display](Air_Display/Air_Display.ino)

## 注意

- 要拿去用的話記得改個幾行 我不想也被GZ打零分
- 如果有做LED矩陣的話
    在用`LedControl.h`的時候
    記得把裡面的
    ```cpp
    #include <avr\pgmspace.h>
    ```
    改成 
    ```cpp
    #if (defined(__AVR__))
    #include <avr\pgmspace.h>
    #else
    #include <pgmspace.h>
    #endif
    ```
- Windows11 記得裝[CP210](https://www.silabs.com/documents/public/software/CP210x_Windows_Drivers.zip)