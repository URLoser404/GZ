// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
bool OLEDStatus = true;

// Joystick
#define xposPin 36
#define yposPin 39
#define buttonPin 34
int vrx, vry, sw;

void OLED_Display();

void setup()
{
	// OLED init
	Serial.begin(9600);
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
	// Joystick
	vrx = analogRead(xposPin);
	vry = analogRead(yposPin);
	sw = analogRead(buttonPin);
	char buf[100];
	sprintf(buf, "VRx=%d, VRy=%d, SW=%d", vrx, vry, sw);
	Serial.println(buf);

	OLED_Display();

	delay(100);
}

void OLED_Display()
{

	display.clearDisplay();
	display.setCursor(0, 0);
	display.setTextSize(2);
	display.setTextColor(WHITE);

	if (!vrx)
	{
		display.println("PosY:down");
	}
	else if (vrx == 4095)
	{
		display.println("PosY:up");
	}
	else
	{
		display.println("PosY:mid");
	}

	display.setCursor(0, 24);
	display.setTextSize(2);
	display.setTextColor(WHITE);
	if (!vry)
	{
		display.println("PosX:left");
	}
	else if (vry == 4095)
	{
		display.println("PosX:right");
	}
	else
	{
		display.println("PosX:mid");
	}

	display.setCursor(0, 48);
	display.setTextSize(2);
	display.setTextColor(WHITE);
	if (!sw)
	{
		display.println("Sw:true");
	}
	else if (sw == 4095)
	{
		display.println("Sw:false");
	}

	display.display();
}
