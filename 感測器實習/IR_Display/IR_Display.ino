// OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
bool OLEDStatus = true;

// IR
#include <IRremote.h>
#define RECV_PIN 25
unsigned long long int last;
int show;
unsigned int recvData;
IRrecv irrecv(RECV_PIN);
decode_results results;

// receive data to number table
typedef struct HexToNum
{
	unsigned int hex;
	int value;
};
const HexToNum hexTable[]{
	{0xFF6897, 0},
	{0xFF30CF, 1},
	{0xFF18E7, 2},
	{0xFF7A85, 3},
	{0xFF10EF, 4},
	{0xFF38C7, 5},
	{0xFF5AA5, 6},
	{0xFF42BD, 7},
	{0xFF4AB5, 8},
	{0xFF52AD, 9},
	{0xFF9867, 100},
	{0xFFB04F, 200},
};

void setup()
{
	// IR init
	Serial.begin(9600);
	Serial.println("Enabling IRin");
	irrecv.enableIRIn();
	Serial.println("Enabled IRin");

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

	// IR receive
	unsigned long long int tmp;

	// Data get
	if (irrecv.decode(&results))
	{
		if (results.value != 0xFFFFFFFF)
			recvData = results.value;
		Serial.println(recvData, HEX);
		irrecv.resume();

		tmp = millis() - last;
		last = millis();

		// transform receive data to number
		int num;
		for (auto i : hexTable)
		{
			if (i.hex == recvData)
			{
				num = i.value;
				if (tmp < 2000 && show < 100)
				{
					show *= 10;
					show += num;
				}
				else
				{
					show = num;
				}
				break;
			}
		}
		//
	}

	OLED_Display();
	delay(100);
}

void OLED_Display()
{
	display.clearDisplay();

	// show receive data
	display.setCursor(0, 0);
	display.setTextSize(2);
	display.setTextColor(WHITE);
	display.println(recvData, HEX);

	// show transform number
	display.setCursor(0, 24);
	display.setTextSize(2);
	display.setTextColor(WHITE);
	display.println(show);

	display.display();
}
