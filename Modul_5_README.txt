1. 
Program Modul_5_main.c loguje swoje dzia³anie do pliku o nazwie:

"nazwa_programu_RRRRMMDD_GG_MM.log"

Program sprawdza czy plik o takiej nazwie istnieje, je¿eli nie:
- generuje LOG_ERROR
- zapisuje LOG_ERROR w buforze
- tworzy nowy plik do logowania wg schematu j.w.
- zapisuje bufor do pliku w przypadku zape³nienia buforu.
- dodatkowo log zawiera informacje o tym z jakiej funkcji zosta³ wywo³any.

Je¿eli program zostanie uruchomiony wielokrotnie w przeci¹gu minuty MM
- LOG_ERROR nie zostanie wygenerowany.
- logi bêd¹ dopisywane w istniej¹cym pliku.

2. 
Program Modul_5_ekran_main.c dodatkowo pokazuje na konsoli stan bufora z logami
w trakcie dzia³ania programu.
Uwaga!!! spora iloœæ tekstu.