// OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
bool OLEDStatus = true;

// dht11
#include "DHTesp.h"
DHTesp dht;
const byte dhtPin = 19;

// variable & function init
void GetPM25Data();
void GetDH11Data();
void OLED_Display();

float pm25Data = 0;
float temperatureData = 0;
float humidityData = 0;

void setup()
{
	Serial.begin(9600);
    Serial2.begin(2400);

    // dht11 setup
    dht.setup(dhtPin, DHTesp::DHT11);

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
    GetDH11Data();
    OLED_Display();
    delay(2000);
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

    pmval = readcmd[1];          // Vout(H) = data[1]
    pmval <<= 8;                 // Vout(H) *= 256
    pmval += readcmd[2];         // Vout(H) += Vout(L)
    pm25 = pmval * 5.0 / 1024.0; // pm2.5 value : Vout=(Vout(H)*256+Vout(L))/1024*5
    pm25 /= 3.5;
    pm25Data = pm25;
}
void GetDH11Data()
{
    TempAndHumidity lastValues = dht.getTempAndHumidity();
    temperatureData = lastValues.temperature;
    humidityData = lastValues.humidity;
}

void OLED_Display()
{
    display.clearDisplay();

    // set pm2.5 value
    display.setCursor(0, 0);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("pm2.5:%.3f mg/m3", pm25Data);

    // set temperature value
    display.setCursor(0, 24);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("temperature:%.3f C", temperatureData);

    // set humdity value
    display.setCursor(0, 48);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("humidity:%.3f RH", humidityData);

    display.display();
}
