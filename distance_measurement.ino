
//Distance sensor
#define trigPin 12
#define echoPin 8
const int buzzer = 11;
const int ledPin = 10;
//Flashing LED on Arduino board
#define LEDPin 13

//LCD
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR  0x27  // Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN   3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;

LiquidCrystal_I2C     lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);


void setup ()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);  //The transmit pin of the ultrasonic sensor
  pinMode(echoPin, INPUT);   //The receive pin of the ultrasonic sensor
  pinMode(LEDPin, OUTPUT);   //The LED of the Arduino
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
  lcd.begin (20,4);  //Size of LCD
 
// Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home ();                // go home

}

void loop()
{
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance =((100-((duration/2) / 29.1))/100)*100;

  lcd.clear();
    lcd.setCursor(7,0);
  lcd.print("Current");
  lcd.setCursor(2,1);
  lcd.print("Water In Tank is");
  lcd.setCursor(4,2);
  lcd.print(distance);
  lcd.print("% Percent");
  if (distance <=95)
  {
    lcd.setCursor(6,4);
    lcd.print("");
    digitalWrite(LEDPin,HIGH);
      delay(500);
      digitalWrite(LEDPin,LOW);
      delay(500);
      digitalWrite(buzzer, LOW);
   
  }
    else
  {
      lcd.clear();
      lcd.setCursor(2,1);
      lcd.print(" Water Level is");
      lcd.setCursor(4,2);
      lcd.print(" Too High!!");
      digitalWrite(buzzer, HIGH);
  }
   if (distance <=10)
  {
   digitalWrite(ledPin, HIGH);
   
  }
    else
  {
      digitalWrite(ledPin, LOW);
  }
  

 delay(500);
}
