//The pinout is as follows (left side RC522, right side ESP32):
// Vcc <-> 3V3 (or Vin(5V) depending on the module version)
// RST (Reset) <-> D0
// GND (Masse) <-> GND
// MISO (Master Input Slave Output) <-> 19
// MOSI (Master Output Slave Input) <-> 23
// SCK (Serial Clock) <-> 18
// SS/SDA (Slave select) <-> 5

// OLED
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 22
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
bool OLEDStatus = true;

// MFRC522
#include <SPI.h>	 //https://www.arduino.cc/en/reference/SPI
#include <MFRC522.h> //https://github.com/miguelbalboa/rfid
#define SS_PIN 5
#define RST_PIN 0
const int ipaddress[4] = {103, 97, 67, 25};
byte nuidPICC[4] = {0, 0, 0, 0};   // current read RFID
byte passId[4] = {5, 242, 82, 39}; // RFID allow to pass
bool pass = 1;					   // current Pass Status
MFRC522::MIFARE_Key key;
MFRC522 rfid = MFRC522(SS_PIN, RST_PIN);

void setup()
{
	Serial.begin(115200);

	// MFRC522 init
	Serial.println(F("Initialize System"));
	SPI.begin();
	rfid.PCD_Init();
	Serial.print(F("Reader :"));
	rfid.PCD_DumpVersionToSerial();

	// OLED init
	if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c))
	{
		Serial.println(F("SSD1306 allocation failed"));
		OLEDStatus = false;
	}
}

void loop()
{
	readRFID();
	oledShowText();
}

void readRFID(void)
{

	for (byte i = 0; i < 6; i++)
	{
		key.keyByte[i] = 0xFF;
	}

	if (!rfid.PICC_IsNewCardPresent())
		return;
	if (!rfid.PICC_ReadCardSerial())
		return;

	// check if pass
	bool check = true;
	for (byte i = 0; i < 4; i++)
	{
		nuidPICC[i] = rfid.uid.uidByte[i];
		check = nuidPICC[i] == passId[i]
	}
	pass = check;

	rfid.PICC_HaltA();
	rfid.PCD_StopCrypto1();
}

void oledShowText()
{
	display.clearDisplay();

	// display RFID
	display.setTextSize(2);
	display.setCursor(0, 0);
	display.setTextColor(WHITE, BLACK);
	display.println("RFID :");
	for (int i = 0; i < 4; i++)
	{
		display.setTextSize(1);
		display.setCursor(i * 24, 24);
		display.setTextColor(WHITE, BLACK);
		display.println(nuidPICC[i]);
	}

	// display pass status
	display.setCursor(0, 48);
	display.setTextColor(WHITE, BLACK);
	if (pass)
	{
		display.println("[passed]");
	}
	else
	{
		display.println("[deline]");
	}

	display.display();
}