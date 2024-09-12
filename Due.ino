#include <LiquidCrystal.h>

#define RS 8
#define EN 9
#define d4 4
#define d5 5
#define d6 6
#define d7 7

#define BL 10

LiquidCrystal lcd(RS, EN, d4, d5, d6, d7);

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("GANHEMO GURIZADA");
  lcd.setCursor(0, 1);
  lcd.print("Tecla:");
}

void loop(){
    int x;
    x = analogRead(0);
    Serial.println(x);
    delay(500);
}