#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

long randNumber;
int Count = 0;

void setup(){
  Serial.begin(9600);

  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));

  // blue led - power / status
  pinMode(6, OUTPUT);
  // green led - gps good
  pinMode(7, OUTPUT);
  // yellow led - gps weak
  pinMode(8, OUTPUT);
  // red led - cart dumping 
  pinMode(9, OUTPUT);

digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);

    lcd.begin(16, 2);  
  lcd.setCursor(0, 0);
  lcd.print("YM Box Demo #1");
  lcd.setCursor(0,1);
  lcd.print("Not Real Data");
  delay(2000);
  lcd.setCursor(0, 0);
  lcd.print("Property of:    ");
  lcd.setCursor(0,1);
  lcd.print("Tyler McGee     ");
  delay(2000);

  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void loop() {

    
  
  // print a random number from 0 to 999
  randNumber = random(1500);
  Serial.println(randNumber);  
  Serial.println(Count); 

  
  lcd.begin(16, 2);  
  lcd.setCursor(0, 0);
    if (randNumber > 300){
      lcd.print("GPS Signal: Good");
       digitalWrite(7, HIGH);
       digitalWrite(8, LOW);
      }else{
      lcd.print("GPS Signal: Weak"); 
       digitalWrite(8, HIGH);
       digitalWrite(7, LOW);
    }

if (Count < 27000){    
  //lcd.setCursor(0, 1);
  //lcd.print(randNumber); 
  lcd.setCursor(0, 1);
  lcd.print("Cart Mass: ");
  lcd.setCursor(11, 1);
  lcd.print(Count); 

} else {
  lcd.setCursor(0, 1);
  lcd.print("**DUMPING CART**");
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);   
    digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
    delay(500); 
    digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);   
    digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
    delay(500); 
    digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);   
    digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
    delay(500); 
    digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);   
    digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
    delay(500); 
    Count = 0;
 
  
}
    digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(25);   
    digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
    delay(650);

    Count = Count + randNumber;
}

