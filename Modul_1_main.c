#include <stdio.h>
#include "Modul_1.h"

int main()
{
 	int i,wybor=5; 
	int rozmiar_tablicy=10;
	Samochod samochody[rozmiar_tablicy];

	printf("\n Program generuje tablice struktur \"Samochod\"\n");
	for (i=0; i<=rozmiar_tablicy-1; i++)
		{
			samochody[i].waga=losuj_liczbe(500,1500);
			samochody[i].cena=losuj_liczbe(20000,30000);
			samochody[i].kolor=losuj_liczbe(0,3);
			samochody[i].wyposazenie=losuj_liczbe(0,2);
		}
	printf(" Losowo wygenerowana %d elementowa tablica: \n\n", rozmiar_tablicy);	
for (i=0; i<=rozmiar_tablicy-1; i++) printf(" Waga %d,	| cena %d,	| kolor %d,	| wyposazenie %d\n", samochody[i].waga, samochody[i].cena, samochody[i].kolor, samochody[i].wyposazenie);
	do
		{
		printf("\n Program moze posortowac tablice struktur \"Samochod\"\n");
		printf("\n Wybierz element skladowy struktury bedacy kryterium sortowania tablicy\n");
		printf("\n ___________________________________________________________________________\n");
		printf("1. Waga  2. Cena  3. Kolor  4. Wyposazenie  5.Koniec programu.   Twoj wybor : ");
		scanf("%d", &wybor);
		switch(wybor)
			{
			case 1:
				printf("\n Wybrano kryterium WAGA\n");
				sortuj_samochody(samochody,rozmiar_tablicy, 0);
			break;
			case 2:
				printf("\n Wybrano kryterium CENA\n");
				sortuj_samochody(samochody,rozmiar_tablicy, 1);
			break;
			case 3: 
				printf("\n Wybrano kryterium KOLOR\n");
				sortuj_samochody(samochody,rozmiar_tablicy, 2);
			break;
			case 4: 
				printf("\n Wybrano kryterium WYPOSAZENIE\n");
				sortuj_samochody(samochody,rozmiar_tablicy, 3);
			break;
			case 5: 
				printf("\nBYE!\n");
				wybor=5;
			break;
			}
		fflush(stdin);
		}
	while(wybor!=5);

	return 0;
}

/* 
gcc -c Modul_1.c
gcc -c Modul_1_main.c
gcc -o main.exe Modul_1.o Modul_1_main.o
*/
