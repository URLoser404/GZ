// OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
bool OLEDStatus = true;

// MQ
#define MQPin 27
float AlcoholVolt;

void setup()
{
	Serial.begin(9600);

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

	// Read MQ
	int ReadValue = analogRead(MQPin);
	AlcoholVolt = ReadValue * 3.3 * 1.5 / 4095;
	Serial.print("Alcohol Volt :");
	Serial.println(AlcoholVolt);

	OLED_Display();
	delay(1000);
}
void OLED_Display()
{
	// display MQ data
	display.clearDisplay();
	display.setCursor(0, 0);
	display.setTextSize(2);
	display.setTextColor(WHITE);
	display.println(AlcoholVolt);
	display.display();
}
