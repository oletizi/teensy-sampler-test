#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/Inconsolata9pt7b.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define LINE_HEIGHT 12
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void setup()
{
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }

  display.clearDisplay();
  display.setFont(&Inconsolata_Regular8pt7b);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, LINE_HEIGHT);
}

unsigned long checkpoint = 0;
unsigned long now = 0;

void loop()
{
  now = millis();
  if (now - checkpoint >= 1000)
  {
    checkpoint = now;
    Serial.printf("Now: %lu\n", now);
    display.clearDisplay();
    display.setCursor(0, LINE_HEIGHT);
    display.printf("Now: %lu\n", now);
    display.display();
  }
}
