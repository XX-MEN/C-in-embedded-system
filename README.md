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
