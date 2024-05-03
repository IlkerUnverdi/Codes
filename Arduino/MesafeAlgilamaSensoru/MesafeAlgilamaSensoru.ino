#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int trigpin = 10, echopin = 9;
long uzaklik, sure;
void setup(){
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

}
void loop(){
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  sure = pulseIn(echopin, HIGH);
  uzaklik = sure/2/29.154;
  
  Serial.print("Mesafe: ");
  Serial.print(uzaklik);
  Serial.println(" CM");
  delay(500);
  if (uzaklik >= 30)
  {
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    delay(1);
  }
  else if (uzaklik < 30 && uzaklik > 15)
  {
    digitalWrite(3, HIGH);
    delay(1000);
    digitalWrite(3, LOW);
    delay(1);
  }
  else
  {
    digitalWrite(4, HIGH);
    delay(1000);
    digitalWrite(4, LOW);
    delay(1);
  }
  lcd.setCursor(0, 0);
  lcd.print(uzaklik);
  lcd.print("CM");
  delay(2000);
  lcd.clear();
}
