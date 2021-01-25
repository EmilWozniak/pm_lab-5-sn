# Parametry projektu

Nazwa: pm-lab-5  
Autor: Paweł Dąbal (pawel.dabal@wat.edu.pl)  
Opis: Projekt bazowy repozytorium na piąte spotkanie laboratoryjne z przedmiotu _Techniki mikroprocesorowej_.  
Wersja: v1.0  
Data: 25.01.2021 r.

# Informacje o studencie

Imię i nazwisko studenta: Emil Woźniak
Numer albumu: 72558
Grupa studencka: WEL18DE1S1

# Odpowiedzi do pytań z instrukcji
Weryfikacja działania programu z zadania 3.2.1. - Program wyświetla po kolei Menu 1, Menu 2 i Menu 3 (zmiana co 1 sek.).
Weryfikacja działania programu z zadania 3.2.2. - Program powoduje zmianę wyświetlanego menu przez naciśnięcię przycisku (pierwszy z prawej powoduje zmianę ekranu na następny, natomiast pierwszy z lewej cofnięcie ekranu).
Weryfikacja działania programu z zadania 3.2.3. - Program działa podobnie jak 3.2.2., jednakże poprzez jednokrotne naciśnięcie przycisku, ekran zmienia się o jeden, a nie jak poprzednio - wielokrotnie.
Weryfikacja działania programu z zadania 3.2.4. - Program wyświetla aktualną wartość temperatury. Aby było to możliwe zdefiniowałem funkcję void readTemperature(void), funkcję void lcdClear(void), zadeklarowałem zmiennę globalną float temperature. Aby program wyświetlał symbol stopni, skorzystałem z tablicy znaków ASCII i posłużyłem się kodem ALT+0176.
Weryfikacja działania programu z zadania 3.2.5. - Zadaniem programu jest zmiana koloru diody, rozpoczynając od koloru niebieskiego do koloru czerwonego, w zależności od zmiany temepratury otoczenia. Na wykonanym screenie widać że dioda przyjmuje kolor różowy dla temepraury 24.71 °C.