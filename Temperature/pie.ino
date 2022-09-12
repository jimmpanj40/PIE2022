#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
const int BUTTON = 7;
int val = 0;
float temp=0;
const int analogPin = A0;
const int ledr = 8;
const int ledv = 9;

void setup() {
  lcd.begin(16,2);
  pinMode(BUTTON, INPUT);
  pinMode(analogPin, INPUT);
  pinMode(ledr, OUTPUT);
  pinMode(ledv, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  temp = ((analogRead(analogPin))/1024.0*5.0-0.5)*100;
  val = digitalRead(BUTTON);
  if (val == HIGH) {
    while (val== HIGH) {
    lcd.setCursor(0,0);
    lcd.print("temperature : ");
    lcd.setCursor(0,1);
    lcd.print(temp);
    if (temp > 30) {
      lcd.print(" canicule!");
      }
    val = digitalRead(BUTTON);
    }
     lcd.clear(); 
  }
  if (temp > 30) {
     digitalWrite(ledv, LOW);
     digitalWrite(ledr, HIGH);
     }
    else{  
      digitalWrite(ledv, HIGH);
      digitalWrite(ledr, LOW);
      }
}