# C-in-embedded-system

_____________________________________________________________________________
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

_____________________________________________________________________________
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

_____________________________________________________________________________
Module 3 - Pointer
1. Program: Napisz funkcję 'sort3' sortujaca rosnaco trzy liczby całkowite (funkcje zaimplementuj bez użycia tablic!)

2. Program: Lista podwójnego powiazana to lista, której elemty zawieraja waśkażniki do poprzedniego i następnego elementu listy. Zdefiniuj strukturę opisujca listę podwójnie powiazana i napisz nie wielki program realizujacy taka listę, a także pokazujacy jej elemety. 

3 Program: Napisz funkcję compareStrings() która porównuje dwie tablice z charami na równość.
Funkcja ma wynik w formie prawdy(1) i fałsz(0).
Funkcja ma używac tylko wskaźników! 

_____________________________________________________________________________
Module_4 - Strings
1. Napisz funkcję intToStr zamieniajacją liczbę całkowitą na łańcuch znakowy. Pamiętaj o prawidłowej obsłudze liczb ujemnych. Używaj dynamiczną allokację i wskaźniki
    intToStr(int, char*)

2. Napisz funkcję substring pobierającą część łańcucha. Funkcja ma być wywołana następująco:
    substring(source, beginning, number, result)
source:     Źródło z kat pobieramy
beginning: Od którego elementu zaczynamy(indeks)
number:    Ilość pobieranych znaków
result:       Jest naszym wynikiem

3. Napisz funkcję strToFloat, zamieniającją łańcuch znakowy na wartość zmiennoprzecinkowa. Niech ta funkcja uwzględnia także liczbę ujemną.
    strToFloat(char*)

_____________________________________________________________________________
Module_5 - System do logowania
Napisz program, który będzie działał jak loger – zapisywał informacje o stanie programu do pliku. Log ma mieć następującą składnię:
<data> | <czas> | <nazwa_pliku>:<numer_lini> | MEDIUM,LOW,HIGH,ERROR} | <text>

1.Do logowania mają być dostępne następujące makra:
LOG_LOW, LOG_MEDIUM, LOG_HIGH, LOG_ERROR

2. Wywołanie makr ma zastępować wywołanie funkcji do logowania, która:
-zapisuje log do lokalnego buforu o rozmiarze BUFFER_LEN
-zapis do pliku następuje kiedy nie ma już miejsca do zapisu w lokalnym buforze

Przykład:
użycie makr:
LOG_HIGH(”jakis wpis 1”);
LOG_ERROR(”jakis wpis 2”);

spowoduje wygenerowanie takich logów:
Oct 3 2016 | 12:01:31 | 009_logger.c:57 | HIGH | jakis wpis 1
Oct 3 2016 | 12:01:31 | 009_logger.c:58 | ERROR| jakis wpis 1
