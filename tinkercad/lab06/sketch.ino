#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd_1(0x20, 16, 2);

void setup() {
    lcd_1.init();
    lcd_1.backlight();
    lcd_1.setCursor(0,0);
    lcd_1.print("Name: Alhaan");
    lcd_1.setCursor(0, 1);
    lcd_1.print("22F-BSCS-88");

}

void loop() {

}
