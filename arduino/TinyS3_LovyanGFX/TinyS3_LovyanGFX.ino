
/*
 *  Unexpected Maker TinyS3 + 1.3" TFT 240x240 - ST7789 SPI
 *
 */
#define LGFX_USE_V1

#include <LovyanGFX.hpp>
#include "displayconfig.h"

// create an instance of the class that you prepared.
static LGFX lcd;


void setup(void)
{
  lcd.init();

  if (lcd.width() < lcd.height())
    lcd.setRotation(lcd.getRotation() ^ 3);
}

uint32_t count = ~0;
void loop(void)
{
  delay(10);
  lcd.startWrite();
  lcd.setRotation(++count & 7);
  lcd.setColorDepth((count & 8) ? 16 : 24);

  lcd.setTextColor(random(65536));
  lcd.drawNumber(lcd.getRotation(), 16, 0);

  lcd.setTextColor(0xFF0000U);
  lcd.drawString("R", 30, 16);
  lcd.setTextColor(0x00FF00U);
  lcd.drawString("G", 40, 16);
  lcd.setTextColor(0x0000FFU);
  lcd.drawString("B", 50, 16);

  lcd.drawRect(30,30,lcd.width()-60,lcd.height()-60,random(65536));

  lcd.endWrite();

}
