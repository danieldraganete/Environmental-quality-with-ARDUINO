#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#define LED_PIN   3
#define LED_COUNT 4

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
const int buzzerPin = 2;

const int photoresistorPin = A0;  
const int temperaturePin = A1;
const int buttonPin = 6;
const int gasSensorPin = A4;

bool isBuzzing = false;
int displayMode = 0;


unsigned long previousMillis = 0;
const long interval = 250;  
bool ledOn = false;

void blikLed3() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (ledOn) {
      strip.setPixelColor(2, 255, 255, 0);  
      ledOn = false;
    } else {
      strip.setPixelColor(2, 255, 0, 0);  
      ledOn = true;
    }

  }
}


void setup() {
  lcd.begin(16, 2);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  strip.begin();
  strip.show();
}

void loop() {
  strip.setPixelColor(0, 254, 255, 254);
  
  int lightValue = analogRead(photoresistorPin);  
  int temperatureValue = analogRead(temperaturePin);
  int gasSensorValue = analogRead(gasSensorPin);  

  int buttonState = digitalRead(buttonPin);	
  float voltage = (temperatureValue / 1024.0) * 5.0;
  float temperatureC = (voltage - 0.5) * 100.0;
  
  lcd.setCursor(0, 0);

  
  if (buttonState == LOW) {
    displayMode++;
    delay(500); // Debouncing
  }

// strip.setPixelColor(n, red, green, blue);
  
  
  if(temperatureC <=18){
	strip.setPixelColor(1, 0, 0, 255);;
  }else if(temperatureC >18 && temperatureC <=28){
	strip.setPixelColor(1, 0, 255, 0);
  }else if(temperatureC >28){
	strip.setPixelColor(1, 255, 0, 0);  
  }
  
  strip.show();
  

  switch (displayMode % 3) {
    case 0:
     lcd.print("Temp: ");
     lcd.print(temperatureC);
     lcd.print(" C   ");
      break;
    case 1:
      lcd.print("Gas: ");
      lcd.print(gasSensorValue);
      lcd.print("           ");
      break;
    case 2:
      lcd.print("Light: ");
      lcd.print(lightValue);
      lcd.print("           ");
      break;
  }
	if (gasSensorValue >= 300 || temperatureC >= 50) {
    
      tone(buzzerPin, 500);
      delay(500);
      noTone(buzzerPin);
      isBuzzing = true;
      strip.setPixelColor(2, 255, 0, 0);
      
  }else if (gasSensorValue >= 200 && gasSensorValue <300){

      blikLed3();
  
  }else if(gasSensorValue > 120 && gasSensorValue <200){
      
      strip.setPixelColor(2, 255, 255, 0);
    
  } else {
    isBuzzing = false;
    strip.setPixelColor(2, 0, 255, 0);
  }
  
  
  if(lightValue < 100){
    strip.setPixelColor(3, 160,32,240);
   
 
  }else {
    strip.setPixelColor(3, 254,255, 254);
  }
}  