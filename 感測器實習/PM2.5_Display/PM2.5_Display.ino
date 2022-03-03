// OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
bool OLEDStatus = true;

// function & variable init
void GetPM25Data();
void OLED_Display();
float pm25Data;

void setup()
{
	Serial.begin(115200);

	// to read pm2.5 data
	Serial2.begin(2400);

	// OLED init
	Wire.begin(21, 22);
	if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c))
	{
		Serial.println(F("SSD1306 allocation failed"));
		OLEDStatus = false;
	}
	display.clearDisplay();
}

void loop()
{
	GetPM25Data();
	OLED_Display();
	delay(200);
}

void GetPM25Data()
{
	int cnt, pmval, readcmd[7];
	unsigned char gdata, eFlag, rbytes = 0;
	float pm25;
	cnt = 0;
	eFlag = 0;
	while (Serial2.available() > 0)
	{
		gdata = Serial2.read();

		if (gdata == 0xAA && eFlag == 0)
			eFlag = 1;
		if (eFlag == 1)
			readcmd[rbytes++] = gdata;
		cnt++;
		if (cnt > 100)
			return;
		if (rbytes == 7)
			break;
	}
	if (rbytes == 0)
		return;
	if (readcmd[6] != 0xFF)
		return;

	pmval = readcmd[1];			 // Vout(H) = data[1]
	pmval <<= 8;				 // Vout(H) *= 256
	pmval += readcmd[2];		 // Vout(H) += Vout(L)
	pm25 = pmval * 5.0 / 1024.0; // pm2.5 value : Vout=(Vout(H)*256+Vout(L))/1024*5
	pm25 /= 3.5;
	pm25Data = pm25;
}

void OLED_Display()
{
	// display pm2.5 value
	display.clearDisplay();
	display.setCursor(0, 0);
	display.setTextSize(1);
	F
		display.setTextColor(WHITE);
	display.printf("pm2.5:%.3fmg/m3", pm25Data);
	display.display();
}
