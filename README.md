# Parametry projektu

Nazwa: pm-lab-5  
Autor: Paweł Dąbal (pawel.dabal@wat.edu.pl)  
Opis: Projekt bazowy repozytorium na piąte spotkanie laboratoryjne z przedmiotu _Techniki mikroprocesorowej_.  
Wersja: v1.0  
Data: 25.01.2021 r.

# Informacje o studencie

Imię i nazwisko studenta: Emil  Woźniak
Numer albumu: 72558
Grupa studencka: WEL18DE1S1

# Odpowiedzi do pytań z instrukcji
1. Weryfikacja działania programu z zadania 3.2.1. - Program wyświetla po kolei Menu 1, Menu 2 i Menu 3 (zmiana co 1 sek.).
2. Weryfikacja działania programu z zadania 3.2.2. - Program powoduje zmianę wyświetlanego menu przez naciśnięcię przycisku (pierwszy z prawej powoduje zmianę ekranu na następny, natomiast pierwszy z lewej cofnięcie ekranu).
3. Weryfikacja działania programu z zadania 3.2.3. - Program działa podobnie jak 3.2.2., jednakże poprzez jednokrotne naciśnięcie przycisku, ekran zmienia się o jeden, a nie jak poprzednio - wielokrotnie.
Weryfikacja działania programu z zadania 3.2.4. - Program wyświetla aktualną wartość temperatury. Aby było to możliwe zdefiniowałem funkcję void readTemperature(void), funkcję void lcdClear(void), zadeklarowałem zmiennę globalną float temperature. Aby program wyświetlał symbol stopni, skorzystałem z tablicy znaków ASCII i posłużyłem się kodem ALT+0176.
4. Weryfikacja działania programu z zadania 3.2.5. - Zadaniem programu jest zmiana koloru diody, rozpoczynając od koloru niebieskiego do koloru czerwonego, w zależności od zmiany temepratury otoczenia. Na wykonanym screenie widać że dioda przyjmuje kolor różowy dla temepraury 24.71 °C. Zmianę temperaury dokonujemy za pomocą suwaka, który ujawnia się po naciśnięciu na czujnik temperatury.
5. Zadanie 3.2.6.: Tranzystor został zastosowany ponieważ jest jednym ze sposobów wysterowania silnika DC. Silnik zużywa więcej mocy niż może dać wyjście cyfrowe. Tranzystor został zastosowany jako przełącznik zużywający mniej pradu z wyjścia cyfrowego w celu wysterowania bardziej pradożernego silnika. Silnik zmienia swoją prędkość obrotową wraz ze zmianą temperatury otoczenia. Po przekroczeniu granicznej temepratury, załącza się wentylator.