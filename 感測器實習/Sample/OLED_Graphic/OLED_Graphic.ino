//https://marlinfw.org/tools/u8glib/converter.html

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED 寬度像素
#define SCREEN_HEIGHT 64 // OLED 高度像素

// 設定OLED
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

static const unsigned char PROGMEM logo_bmp[] =
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFA,0x11,0x00, // .......................................................................................................######.#....#...#........
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x42,0x31,0x00, // .........................................................................................................#....#...##...#........
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x31,0x00, // .........................................................................................................#........##...#........
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x41,0x20,0x00, // .........................................................................................................#.....#..#.............
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x41,0x02,0x00, // .........................................................................................................#.....#......#.........
  0x00,0x01,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x41,0x02,0x00, // ...............###########...............................................................................#.....#......#.........
  0x00,0x7F,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x41,0x42,0x00, // .........#######################.................................................###.....................#.....#.#....#.........
  0x00,0xFF,0xFF,0xFF,0x83,0x86,0x00,0x00,0xFF,0x00,0x70,0x00,0x00,0x40,0x42,0x00, // ........#########################.....###....##.................########.........###.....................#.......#....#.........
  0x01,0xFF,0xFF,0xFF,0xC3,0x8E,0x00,0x00,0xFF,0x00,0x70,0x00,0x00,0x40,0x84,0x00, // .......###########################....###...###.................########.........###.....................#......#....#..........
  0x01,0xFF,0xFF,0xFF,0xC1,0x8E,0x00,0x00,0xFF,0x00,0x70,0x00,0x00,0x40,0x84,0x00, // .......###########################.....##...###.................########.........###.....................#......#....#..........
  0x03,0xFF,0xFF,0xFF,0xC1,0x8E,0x00,0x00,0x38,0x00,0x70,0x00,0x00,0x40,0x84,0x00, // ......############################.....##...###...................###............###.....................#......#....#..........
  0x03,0xFF,0xFF,0xFF,0xE1,0xCE,0x00,0x00,0x18,0x00,0x70,0x00,0x00,0x00,0x00,0x00, // ......#############################....###..###....................##............###............................................
  0x03,0xFF,0xBF,0xFF,0xE1,0xCC,0x00,0x00,0x18,0x00,0x70,0x00,0x00,0x00,0x00,0x00, // ......###########.#################....###..##.....................##............###............................................
  0x03,0xFF,0x9F,0xFF,0xE1,0xCC,0x70,0x63,0x18,0xC6,0x77,0x07,0x00,0x00,0x00,0x00, // ......###########..################....###..##...###.....##...##...##...##...##..###.###.....###................................
  0x03,0xFF,0x8F,0xFF,0xE0,0xCC,0xFC,0xE7,0x19,0xCE,0x7F,0x1F,0x80,0x00,0x00,0x00, // ......###########...###############.....##..##..######..###..###...##..###..###..#######...######...............................
  0x03,0xFF,0x87,0xFF,0xE0,0xDC,0xFC,0x67,0x19,0xCE,0x7F,0x9F,0xC0,0x00,0x00,0x00, // ......###########....##############.....##.###..######...##..###...##..###..###..########..#######..............................
  0x03,0xFF,0x81,0xFF,0xE0,0xDD,0xCE,0x67,0x19,0xCE,0x73,0x99,0xC0,0x00,0x00,0x00, // ......###########......############.....##.###.###..###..##..###...##..###..###..###..###..##..###..............................
  0x03,0xFF,0x80,0xFF,0xE0,0xF9,0xCE,0x67,0x19,0xCE,0x73,0xB9,0xC0,0x00,0x00,0x00, // ......###########.......###########.....#####..###..###..##..###...##..###..###..###..###.###..###..............................
  0x03,0xFF,0x80,0x7F,0xE0,0x79,0xCE,0x67,0x19,0xCE,0x73,0x99,0xC0,0x00,0x00,0x00, // ......###########........##########......####..###..###..##..###...##..###..###..###..###..##..###..............................
  0x03,0xFF,0x80,0xFF,0xE0,0x79,0xCE,0x67,0x19,0xCE,0x73,0xB9,0xC0,0x00,0x00,0x00, // ......###########.......###########......####..###..###..##..###...##..###..###..###..###.###..###..............................
  0x03,0xFF,0x81,0xFF,0xE0,0x79,0xCE,0x67,0x19,0xCE,0x73,0xB9,0xC0,0x00,0x00,0x00, // ......###########......############......####..###..###..##..###...##..###..###..###..###.###..###..............................
  0x03,0xFF,0x87,0xFF,0xE0,0x71,0xCE,0x67,0x19,0xCE,0x73,0xBF,0xC0,0x00,0x00,0x00, // ......###########....##############......###...###..###..##..###...##..###..###..###..###.########..............................
  0x03,0xFF,0x87,0xFF,0xE0,0x71,0xCE,0x67,0x19,0xCE,0x73,0xBF,0xC0,0x00,0x00,0x00, // ......###########....##############......###...###..###..##..###...##..###..###..###..###.########..............................
  0x03,0xFF,0x9F,0xFF,0xE0,0x71,0xCE,0x67,0x19,0xCE,0x73,0xB8,0x00,0x00,0x00,0x00, // ......###########..################......###...###..###..##..###...##..###..###..###..###.###...................................
  0x03,0xFF,0xBF,0xFF,0xE0,0x71,0xCE,0x67,0x19,0xCE,0x73,0xB8,0x00,0x00,0x00,0x00, // ......###########.#################......###...###..###..##..###...##..###..###..###..###.###...................................
  0x03,0xFF,0xFF,0xFF,0xE0,0x71,0xCE,0x67,0x19,0xCE,0x73,0x99,0xC0,0x00,0x00,0x00, // ......#############################......###...###..###..##..###...##..###..###..###..###..##..###..............................
  0x03,0xFF,0xFF,0xFF,0xC0,0x71,0xCE,0x67,0x19,0xCE,0x73,0x99,0xC0,0x00,0x00,0x00, // ......############################.......###...###..###..##..###...##..###..###..###..###..##..###..............................
  0x01,0xFF,0xFF,0xFF,0xC0,0x71,0xDC,0x77,0x19,0xEE,0x77,0x9D,0xC0,0x00,0x00,0x00, // .......###########################.......###...###.###...###.###...##..####.###..###.####..###.###..............................
  0x01,0xFF,0xFF,0xFF,0xC0,0x70,0xFC,0x7F,0x38,0xF6,0x7F,0x1F,0x80,0x00,0x00,0x00, // .......###########################.......###....######...#######..###...####.##..#######...######...............................
  0x01,0xFF,0xFF,0xFF,0xC0,0x30,0x78,0x7B,0x18,0xE6,0x67,0x0F,0x00,0x00,0x00,0x00, // .......###########################........##.....####....####.##...##...###..##..##..###....####................................
  0x00,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........#########################...............................................................................................
  0x00,0x0B,0xFF,0xE8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ............#.#############.#...................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ................................................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00  // ................................................................................................................................
};


void setup() {
  Serial.begin(9600);

  // 偵測是否安裝好OLED了
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 一般1306 OLED的位址都是0x3C
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // 顯示Adafruit的LOGO，算是開機畫面
  //display.display();
  //delay(1000); // 停1秒

  // 清除畫面
  display.clearDisplay();

  testdrawbitmap();    // 顯示圖形

}

void loop() {
}

void testdrawbitmap(void) {
  //display.clearDisplay();
  //顯示圖形，x,y,圖形文字,寬,高,1:OLED預設的顏色(這個會依該OLED的顏色來決定)
  display.drawBitmap(0,0,logo_bmp, 128, 64,WHITE);
  display.display();  // 要有這行才會把文字顯示出來
  delay(1000);
}
