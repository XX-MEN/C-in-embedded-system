#ifndef _Modul_1_H_
#define _Modul_1_H_

typedef enum Kolor
{
	Bialy = 0,
	Czarny,
	Czerwony,
	Niebieski
} Kolor;

typedef enum Wyposazenie
{
	Podstawowe = 0,
	Standard,
	Premium
} Wyposazenie;

typedef struct Samochod 
{
	int waga;
	int cena;
	Kolor kolor;
	Wyposazenie wyposazenie;
} Samochod;

int losuj_liczbe(int min, int max);
void sortuj_samochody(Samochod tablica_struktur[], int rozmiar_tablicy, int kryterium);

#endif 