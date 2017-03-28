#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToStr(int liczba, char* tekst)
{
	int liczbaKopia = liczba;
	int i = 0;
	
	if (liczba < 0) liczba = liczba * -1;
	if (liczba == 0)
		{
		tekst = realloc(tekst, ((i + 2) * sizeof(char)));
		*tekst = '0';
		*(tekst + 1) = '\0';
		}

	while (liczba !=0 )
		{
		tekst = realloc(tekst, ((i + 2) * sizeof(char)));
		*(tekst + i) = (liczba % 10) + '0';
		i++;
		liczba /= 10;
		}

	if (liczbaKopia < 0)
		{
		tekst = realloc(tekst,((i + 2) * sizeof(char)));
		*(tekst + i) = '-';
		i++;
		}
	if (liczbaKopia != 0)
		{
		tekst = realloc(tekst, ((i + 2) * sizeof(char)));
		*(tekst + i) = '\0';
		strrev(tekst);
		}
	return tekst;
}


char *substring(char *zrodlo, unsigned int poczatek, unsigned int liczbaZnakow, char *wynik)
{
	if (strlen(zrodlo) <= poczatek)
		{
		printf("Error #1, index poczatku substringa nieprawidlowy! wypada poza stringiem");
		return NULL;
		}

	if (liczbaZnakow > strlen(zrodlo) - poczatek)
		{
		printf("\n Error #2, podano zbyt duza ilosc znakow!");
		return NULL;
		}

	char *wskaznikNaZnak=zrodlo;
	unsigned int i = 0;

	while (*wskaznikNaZnak != '\0' && i < liczbaZnakow)
		{
		for (i; i < liczbaZnakow; i++)
			{
			wynik = realloc(wynik, ((i + 2) * sizeof(char)));
			*(wynik + i) = *(wskaznikNaZnak + poczatek + i);
			}
		}
	*(wynik + liczbaZnakow) = '\0';
	return wynik;
}


float strToFloat(char *liczbaJakoTekst)
{
	int znak = 1;
	float wynik = 0.0;
	float liczbaPrzedPrzecinkiem = 0.0;
	float liczbaPoPrzecinku = 0.0;
	float dzielnik = 10.0;
	char *wskaznikNaCyfre = liczbaJakoTekst;
	
	if (*liczbaJakoTekst == '-') 
		{
		znak = -1;
		wskaznikNaCyfre++;
		}

	while (*wskaznikNaCyfre != '\0' && *wskaznikNaCyfre != '.')
		{
		liczbaPrzedPrzecinkiem = liczbaPrzedPrzecinkiem * 10;
		liczbaPrzedPrzecinkiem = liczbaPrzedPrzecinkiem + (*wskaznikNaCyfre - '0');
		wskaznikNaCyfre++;
		}
	if (*wskaznikNaCyfre == '.')
		{
		wskaznikNaCyfre++;
		}
	
	while (*wskaznikNaCyfre != '\0') 
		{
		liczbaPoPrzecinku = liczbaPoPrzecinku + (*wskaznikNaCyfre - '0') / dzielnik;
		dzielnik = dzielnik * 10;
		wskaznikNaCyfre++;
		}
	wynik = liczbaPrzedPrzecinkiem + liczbaPoPrzecinku;
	wynik = wynik * znak;
	return wynik;
}

int main()
{	
	int wybor = 0;
	int liczbatestowa = -123456789;								//zad.1 liczba int do zmiany
	int liczbaKopia, liczba;						
	char *liczbaJakoTekst = malloc(sizeof(char));
	*liczbaJakoTekst='\0';

	char *slowo = "Hottentottenstottertrottelmutterbeutelrattenlattengitterkofferattentater";		//zad.2 slowo do zmiany
	char *fragment = '\0';
	
	char *liczbaJakoTekst2 = "-123.456";							//zad.3 ciag do zmiany	
	float liczba2 = strToFloat(liczbaJakoTekst2);
		
	do
		{
		printf("___________________\n\n Homework Module 4\n___________________\n");
		printf("\n 1. Realizacja funkcji intToStr\n 2. Realizacja funkcji substring");
		printf("\n 3. Realizacja funkcja strToFloat\n 4. Wyjscie z programu\nTwoj wybor :");
		scanf("%d", &wybor);
		switch(wybor)
			{
			case 1:
				printf("\n Realizacja funkcji intToStr - zamieniajaca liczbe calkowita na lancuch znakowy\n\n");
				printf("Funkcja obsluguje konwersje liczb ujemnych,\n");
				printf("korzysta z dynamicznej alokacji pamieci i wskaznikow\n\n");
				printf("Przykladowe wyniki dzialania programu\n");
				printf(" wynik zmiany intToStr int : %d, string : %s\n", liczbatestowa, intToStr(liczbatestowa, liczbaJakoTekst));
			break;
			case 2:
				printf("\n Funkcja substring pobiera czesc lancucha\n   substring ( source, beginning, number, result)\n");
				printf("source:		Zrodlo skad pobieramy\nbeginning:	Od ktorego elementu zaczynamy (index)\n");
				printf("number:		Ilosc pobieranych znakow\nresult:		jest naszym wynikiem\n");
				printf("\nAnegdota Juliana Tuwima:\n	source = \"%s\"\n	beginning = 56\n	number = 6\n",slowo);
				printf("	result = \"%s\".\n" , substring(slowo, 56, 6, fragment));
			break;
			case 3: 
				printf("\n Funkcja strToFloat, zamieniajaca lancuch znakowy na wartosc zmiennoprzecinkowa\n");
				printf("Tekst: \"%s\" zamieniony na float to: %f\n", liczbaJakoTekst2, liczba2);
			break;
			case 4: 
				printf("\n BYE!\n");
				wybor = 4;
				fflush(stdin);
			break;
			};
		fflush(stdin);
		}
	while(wybor != 4);

	return 0;
}

