#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int pinArray[] = {7, 8, 9, 6};
int count = 0;
int timer = 100;

void setup(){


  // blue led - power / status
  pinMode(6, OUTPUT);
  // green led - gps good
  pinMode(7, OUTPUT);
  // yellow led - gps weak
  pinMode(8, OUTPUT);
  // red led - cart dumping 
  pinMode(9, OUTPUT);

    lcd.begin(16, 2);  
  lcd.setCursor(0, 0);
  lcd.print("YM Box Demo");
  lcd.setCursor(0,1);
  lcd.print("Test Mode");

  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
    delay(5000);

  // we make all the declarations at once
  for (count=0;count<4;count++) {
    pinMode(pinArray[count], OUTPUT);
  }


}

void loop() {
  // put your main code here, to run repeatedly:
for (count=0;count<4;count++) {
   digitalWrite(pinArray[count], HIGH);
   delay(timer);
   digitalWrite(pinArray[count], LOW);
   delay(timer);
  }
  for (count=3;count>=0;count--) {
   digitalWrite(pinArray[count], HIGH);
   delay(timer);
   digitalWrite(pinArray[count], LOW);
   delay(timer);
  }
}
