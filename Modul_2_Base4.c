#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int stringLength(char string[])
{
    int count = 0;
    while  (string[count] != '\0') count++;
    return count;
}

int decimal_to_base4(int liczba)	
{
	char ciag[16] = {0,0,0,0,0,0,0,0};
	int i;
	int reszta;

	for (i=15; i>=0; i--)  			
		{
		reszta = liczba % 4;
		liczba /= 4;
		switch(reszta)
			{
			case 0: ciag[i] = '0'; break;
			case 1: ciag[i] = '1'; break;
			case 2: ciag[i] = '2'; break;
			case 3: ciag[i] = '3'; break;
			}
		}
	return atoi(ciag);					// conversion to int return
}

int baseN_to_decimal(int liczba, int baza)	
{
	char ciag[16];
	long int kopia=liczba;
	int i, potega, dlugosc, temp, wynik;
	itoa(liczba, ciag, 10); 			// Funkcja konwertuje liczbę całkowitą na łańcuch znaków.
										// Liczba zostanie zapisana w łańcuchu znaków w postaci określonego przez argument base 
										// systemu liczbowego. 
	dlugosc=stringLength(ciag);			// długość wpisanego ciągu
	wynik=i=0;							// wynik
	
	potega=dlugosc-1;

    while  (ciag[i] != '\0')
    {
		temp = (ciag[i]) - 48;
		wynik += ((ciag[i] - 48) * pow(4, potega));
		i++;
		potega--;
    }

	return wynik;		// conversion to int return
}


int main()
{
	int liczba;
	int test, testOK, result, result2;
	int wybor = 4;
	 
	do
		{
		printf("\n Program zamienia liczby o podstawie 10 (Base10) ");
		printf("\n na liczby o podstawie 4 (Base4) z i odwrotnie\n");
		printf("        Wybierz co chcesz zrobic\n\n");
		printf("1. Zmiana liczby z Base10 na Base4\n2. Zmiana liczby Base 4 na Base10\n3. Mini testowanie konwersji\n4. Wyjscie\nTwoj wybor : ");
		scanf("%d", &wybor);
		switch(wybor)
			{
			case 1:
				printf("\nProsze wprowadz liczbe w systemie dziesietnym: ");
				scanf("%d", &liczba);
				printf("%d", liczba);
				printf("\n Liczba w systemie dziesietnym - Base10 : %d\nto liczba w systemie czworkowym - Base4 : %d\n\n", liczba, decimal_to_base4(liczba));
			break;
			case 2:
				printf("\nProsze wprowadz liczbe w systemie czorkowym: ");
				scanf("%d", &liczba);
				printf("\n Liczba w systemie czworkowym - Base4 : %d\nto liczba w systemie dziesietnym - Base10 : %d\n\n", liczba, baseN_to_decimal(liczba,4));
			break;
			case 3: 
				testOK = 0;
				for (test = 0; test <= 1000; test++)  	// np:1000
					{
					result=decimal_to_base4(test);
					result2=baseN_to_decimal(result,4);
					printf(" Liczba BASE10 = %d > po konwerscji na BASE4 = %d > po ponownej konwersji na BASE10 = %d\n ",test, result, result2);
					if (result2==test) testOK+=1;
					}
				printf("\n Liczba wykonanych testow konwersji: %d\n Lista prawidlowych konwesji: %d\n\n", test, testOK);
				
			break;
			case 4: 
				wybor = 4;
			break;
			}
		fflush(stdin);
		}
	while (wybor != 4);

	return 0;
}
