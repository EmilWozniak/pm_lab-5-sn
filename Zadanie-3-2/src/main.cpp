#include <Arduino.h>
#include <LiquidCrystal.h>

#define buttonUp  11 // Przycisk następny - pin 11
#define buttonDown  13 // Przycisk następny - pin 13

//Inicjalizacja obiektu klasy LiquidCrystal: RS, E, DB4, DB5, DB6, DB7
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
int menu=1; //Numer aktualnie wyświetlanego ekranu
void dispMenu(void);
void changeMenu(void);
bool psButtonUp=LOW;
bool psButtonDown=LOW;

void setup(void) {
  lcd.begin(16, 2); //Ustawienie liczby kolumn i wierszy
  //Konfiguracja wyprowadzeń mikrokontrolera
  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
}

void loop(void) {
  dispMenu(); //Wyświetlenie menu
  changeMenu(); //Zmiana menu
}

void dispMenu(void) {
  switch(menu) {
    case 1:
    lcd.setCursor(0, 0);
    lcd.print("Menu 1");
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
  }
  if(digitalRead(buttonDown) == HIGH && psButtonDown == LOW) { //Przycisk DOWN wciśnięty
    psButtonDown = HIGH;
    menu=menu-1; //Poprzedni ekran
    if(menu<1) {
      menu=3;
    }
  }
  psButtonUp = digitalRead(buttonUp);
  psButtonDown = digitalRead(buttonDown);
}