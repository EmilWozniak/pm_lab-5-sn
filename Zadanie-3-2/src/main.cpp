#include <Arduino.h>
#include <LiquidCrystal.h>

#define buttonUp  11 // Przycisk następny - pin 11
#define buttonOK  12
#define buttonDown  13 // Przycisk następny - pin 13

#define LedRed 3
#define LedGreen 1
#define LedBlue 2

#define wentylator 10

//Inicjalizacja obiektu klasy LiquidCrystal: RS, E, DB4, DB5, DB6, DB7
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
int menu=1; //Numer aktualnie wyświetlanego ekranu
void dispMenu(void);
void changeMenu(void);
bool psButtonUp=LOW;
bool psButtonDown=LOW;
void readTemperature(void);
float temperature;
void lcdClear(void);
void changeRGBLed(void);
void runFun(void);

void setup(void) {
  lcd.begin(16, 2); //Ustawienie liczby kolumn i wierszy
  //Konfiguracja wyprowadzeń mikrokontrolera
  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonOK, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
  pinMode(LedRed, OUTPUT);
  pinMode(LedGreen, OUTPUT);
  pinMode(LedBlue, OUTPUT);
  pinMode(wentylator, OUTPUT);
  analogWrite(wentylator, 0);
}

void loop(void) {
  dispMenu(); //Wyświetlenie menu
  changeMenu(); //Zmiana menu
  readTemperature(); //Odczyt temperaury otoczenia
  changeRGBLed(); //Zmiana koloru diody RGB
  runFun();
}

void dispMenu(void) {
  switch(menu) {
    case 1:
    lcd.setCursor(0, 0);
    lcd.print("Temperatura:");
    lcd.setCursor(0, 1);
    lcd.print(temperature);
    lcd.setCursor(7, 1);
    lcd.print("°C");
    break;
    case 2:
    lcd.setCursor(0, 0);
    lcd.print("Menu 2");
    break;
    case 3:
    lcd.setCursor(0, 0);
    lcd.print("Menu 3");
    break;
  }
}

void changeMenu(void) {
  if(digitalRead(buttonUp) == HIGH && psButtonUp == LOW) { //Przycisk UP wciśnięty
    psButtonUp = HIGH;
    menu=menu+1; //Następny ekran
    if(menu>3) {
      menu=1;
    }
    lcdClear();
  }
  if(digitalRead(buttonDown) == HIGH && psButtonDown == LOW) { //Przycisk DOWN wciśnięty
    psButtonDown = HIGH;
    menu=menu-1; //Poprzedni ekran
    if(menu<1) {
      menu=3;
    }
    lcdClear();
  }
  psButtonUp = digitalRead(buttonUp);
  psButtonDown = digitalRead(buttonDown);
}

void readTemperature(void) {
  unsigned int digital = analogRead(A5);
  float resolution = (5.0f / 1024.0f);
  float voltage = resolution * digital;
  temperature = (voltage-0.1f) * (125.0f+40.0f) / (1.75f-0.1f) - 40.0f;
}

void lcdClear(void) {
  lcd.setCursor(0, 0);
  lcd.print("..........");
  lcd.setCursor(0, 1);
  lcd.print("..........");
}

void changeRGBLed(void) {
  float change = (temperature+40.0f) * 255.0f / (125.0f+40.0f);
  analogWrite(LedRed, 0+change);
  analogWrite(LedGreen, 0);
  analogWrite(LedBlue, 255-change);
}

void runFun(void) {
  if(temperature>40){
    float duty = map(temperature, 40, 100, 100, 255);
    analogWrite(wentylator, 255);
  }
  else analogWrite(wentylator, 0);
}