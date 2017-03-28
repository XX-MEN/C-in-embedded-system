#include <stdio.h>
#include <stdlib.h>
#include "Modul_1.h"

int losuj_liczbe(int min, int max)
{
    int tmp;
    if (max>=min)
        max=max-min+1;
    else
		{
			tmp= min - max;	
			min= max;
			max= tmp;
		}
    return max?(rand()%max+min):min;
}

void sortuj_samochody(Samochod tablica_struktur[], int rozmiar_tablicy, int kryterium)
{
	Samochod temp;
	int i;
	for (int i=0; i<rozmiar_tablicy-1; i++)
		{
			for (int j=0; j<rozmiar_tablicy-1; j++)
				{
					if (kryterium==0&&tablica_struktur[j].waga>tablica_struktur[j+1].waga ||
					kryterium==1&&tablica_struktur[j].cena>tablica_struktur[j+1].cena ||
					kryterium==2&&tablica_struktur[j].kolor>tablica_struktur[j+1].kolor ||
					kryterium==3&&tablica_struktur[j].wyposazenie>tablica_struktur[j+1].wyposazenie)
					{
						temp=tablica_struktur[j+1];
						tablica_struktur[j+1]=tablica_struktur[j];
						tablica_struktur[j]=temp;
					}		
				}
		}
		
	for (i=0; i<=rozmiar_tablicy-1; i++) printf(" Waga %d,	| cena %d,	| kolor %d,	| wyposazenie %d\n", tablica_struktur[i].waga, tablica_struktur[i].cena, tablica_struktur[i].kolor, tablica_struktur[i].wyposazenie);
}
