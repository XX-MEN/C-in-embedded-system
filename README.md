# C-in-embedded-system

Modul_1. Ćwiczenie przekrojowe utrwalające składnię języka C.
1. Utwórz strukturę Samochód zawierającą następujące pola:
waga - typ całkowity
cena - typ całkowity
kolor - typ wyliczeniowy, dostępne wartości (Bialy, Czarny, Czerwony, Niebieski)
wyposazenie - typ wyliczeniowym dostępne wartości (Podstawowe, Standard, Premium)
2. Napisz funkcję losującą liczbę z dowolnego zakresu.
int losuj_liczbe(int min, int max)
3. Wykorzystaj funkcje losuj_liczbę, aby zainicjalizować 10-elementową tablicę struktur Samochód w następujących zakresach:
waga - <500-1500>
cena - <20000-30000>
kolor - dowolna wartość tego typu wyliczeniowego
wyposazenie - dowolna wartość tego typu wyliczeniowego
4. Napisz funkcję sortuj_samochody sortującą tablicę struktur Samochód według dowolnego kryterium będącym elementem składowym struktury Samochód.
5. Przeorganizuj kod w następujący sposób:
<nazwa_pliku>.h - deklaracja typów danych, funkcji, makra itp
<nazwa_pliku>.c - definicje funkcji
<nazwa_pliku_main>.c – definicja tablicy struktur, jej inicjalizacja, oraz sortowanie po zadanym kryterium 

Moduł_2. Bit operations
Calculator for numeric system based on the number 4 (Base4).
Write two programs as a homework. 
1. Program calculates from Decimal to Base4 and backwards.
    - The outcome of calculation should be displayed in correct order.
    - Define two different functions for the two calculations Which returns the outcome
    TIPP: Use similar approach like in example DectoBin.c
2. Program is a calculator for simple arithmetic operation like plus and minus. 
    - Two numbers should be given via console input in Base4.
    - The User should be able to choose between both operations.
    - Output shall be written  in console as a complete equation.
    - Max Input is two digits long.(Output can be higher)
    TIPP: Use bitfield declaration with width of 2 bits. 
          Check before arithmetic operations for overflows.

Module 3 - Pointer
1. Program: Napisz funkcję 'sort3' sortujaca rosnaco trzy liczby całkowite (funkcje zaimplementuj bez użycia tablic!)

2. Program: Lista podwójnego powiazana to lista, której elemty zawieraja waśkażniki do poprzedniego i następnego elementu listy. Zdefiniuj strukturę opisujca listę podwójnie powiazana i napisz nie wielki program realizujacy taka listę, a także pokazujacy jej elemety. 

3 Program: Napisz funkcję compareStrings() która porównuje dwie tablice z charami na równość.
Funkcja ma wynik w formie prawdy(1) i fałsz(0).
Funkcja ma używac tylko wskaźników! 
