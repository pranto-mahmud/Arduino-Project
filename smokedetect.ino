#include<Servo.h>
Servo myservo;
int pos = 0;
int val;int motor = 8;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
byte tx=1;


const int SPEAKER = 6;
const int LED_RED = 7;
const int LED_YELLOW = 10;
int Relay=7;
int tempC_1 = 0;
int smkC_1 = 0;
const int SensorPin1 = A0;
const int SensorPin2 = A1;
String textForSMS;
void setup()
{
  pinMode(motor, OUTPUT);
  pinMode(tx, OUTPUT);
  pinMode(Relay, OUTPUT);
  myservo.attach(13);
  pinMode(SPEAKER, OUTPUT);
  lcd.begin(14, 2);
  delay(100);
  pinMode(SensorPin1, INPUT);
  pinMode(SensorPin2, INPUT);
  pinMode(SPEAKER, OUTPUT);

pinMode(LED_RED, OUTPUT);
pinMode(LED_YELLOW, OUTPUT);
digitalWrite(LED_RED, LOW);
digitalWrite(LED_YELLOW, LOW);
mySerial.begin(9600);
Serial.begin(9600);
}
void loop()
{
  int tempC_1 = analogRead(SensorPin1);
  int SmkC_1 = analogRead(SensorPin2);
  tempC_1 = analogRead(SensorPin1); 
  tempC_1 = (5.0 * tempC_1 * 100.0) / 1024.0;
  smkC_1 = analogRead(SensorPin2);
  smkC_1 = (5.0 * smkC_1 * 100.0) / 1024.0;
  delay(25);  
  
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;
    
    if (tempC_1 >= 50 || smkC_1 >= 50) 
    {
      digitalWrite(motor, HIGH);
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, HIGH);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  THERE IS FIRE ");
      lcd.setCursor(0, 1);
      lcd.print(" NOT SAFE HERE ");
      delay(500);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("FIRE ALERT!!!");
      lcd.setCursor(0, 1);
      lcd.print(" NOT SAFE HERE ");
      delay(50);
      
      tone(SPEAKER, 1047, 500);
      delay(400);
      tone(SPEAKER, 1109, 300);
      delay(400);
      tone(SPEAKER, 1175, 100);
      delay(50);
      for (int pos = 0; pos <= 90; pos += 1) {
      myservo.write(pos);
      delay(15);
      }
      for (int pos = 90; pos >= -90; pos -= 1) {
      myservo.write(pos);
      delay(15);
      }  
    }
      else
      {
        digitalWrite(Relay,LOW);
        delay(50);
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(motor, LOW);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("    NO FIRE    ");
        lcd.setCursor(0, 1);
        lcd.print("   ALL SAFE   ");
      } 
}

