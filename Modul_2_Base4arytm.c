#include <stdio.h>

int main()
{
	int liczba1OK, liczba2OK;							//testing number is BASE4
	int i, temp, wybor = 4;
	int pozycji = 2;
	int number1, number2;								// variables for entered numbers
	int rest = 0;										// rest of % operation
	int dlugosc1,dlugosc2;								// quantity of digits in entered number
	int ciag1[5] = {0,0,0,0,0}, ciag2[5] = {0,0,0,0,0};	// arrays for inputing numbers in to positions
	int ciagwynik[5], ciagtemp[5];						// arrays for result and temporary value
	int wieksza;										// information about whitch of two intputed numbers si higher

	printf("\nProgram wykonuje operacje arytmetyczzne na liczbach o podstawie 4 (Base4)");
	printf("\nLiczba taka moze sie skladac wylacznie z cyfr 0,1,2,3\n Wprowadz kolejno dwie liczby, potem zdecydujesz co z nimi robic.\n");
	printf("\n Liczby moga byc maksymalnie dwupozycyjne np: 12 lub 33\n");

	do {
		liczba1OK = 1; 

		printf("\nwprowadz pierwsza liczbe max. dwucyfrowa w systemie BASE4 :");
		scanf("%d", &number1);
		wieksza = number1;
		fflush(stdin);
		dlugosc1 = 0;
		do {
			rest=number1%10;
			if ((rest > 3) || (rest < 0)) liczba1OK = 0;
			ciag1[dlugosc1] = rest;
			number1 = number1 / 10;
			dlugosc1++;
			}
		while (number1 != 0);
		if ((liczba1OK == 0) || (dlugosc1 >= 3))
			{
			printf("\n \n nieprawidlowo wprowadzona dana !!!");
			printf("\nliczbe systemu BASE4 tworzyc moga tylko cyfry 0,1,2,3\n sprobuj jeszcze raz");
			liczba1OK = 0;
			}
		fflush(stdin);	
	}
	while (liczba1OK != 1);			
				
	do	{
		liczba2OK = 1;
		printf("\n   wprowadz druga liczbe max. dwucyfrowa w systemie BASE4 :");
		scanf("%d", &number2);
		if (wieksza >= number2) wieksza = 1;
			else wieksza = 2;
		printf("większa %d",wieksza);
		fflush(stdin);
		dlugosc2 = 0;
		do {
			rest=number2 % 10;
			if ((rest > 3) || (rest < 0)) liczba2OK = 0;
			ciag2[dlugosc2] = rest;
			number2 = number2 / 10;
			dlugosc2++;
			}
		while (number2 != 0);
		if ((liczba2OK == 0) || (dlugosc2 >= 3))
			{
			printf("\n \n nieprawidlowo wprowadzona dana !!!");
			printf("\nliczbe systemu BASE4 tworzyc moga tylko cyfry 0,1,2,3\n sprobuj jeszcze raz");
			liczba2OK = 0;
			}
		fflush(stdin);	
		}
	while (liczba2OK != 1);			

				
	do
		{
		for (i = 0; i < 5; i++)				//clearing the result and temp tables
					{
					ciagwynik[i] = 0;
					ciagtemp[i] = 0;
					}	
		printf("\n\n\n WPROWADZONO LICZBA1 : ");
		for (i = dlugosc1-1; i >= 0; i--) printf("%d",ciag1[i]);
		printf(" ORAZ LICZBA2 : ");
		for (i = dlugosc2-1; i >= 0; i--) printf("%d",ciag2[i]);
		printf("\nCo chesz z tymi liczbami zdrobic? \n + aby dodac\n - aby odjac\n k aby zakonczyc\n\nTwoj wybor to: ");
		scanf("%c", &wybor);
		fflush(stdin);
		switch(wybor)
			{
			case '+':
				printf("\nWynik dodawania liczb BASE4: ");
				if (dlugosc1 >= dlugosc2) for (i = 0; i <= dlugosc1; i++)
											{
												temp = (ciagtemp[i] + ciag1[i] + ciag2[i]) % 4;
												ciagtemp[i + 1] = (ciagtemp[i] + ciag1[i] + ciag2[i]) / 4;
												ciagwynik[i] = temp;
											}
				else for (i = 0; i <= dlugosc2; i++)
											{
												temp = (ciagtemp[i] + ciag1[i] + ciag2[i]) % 4;
												ciagtemp[i + 1] = (ciagtemp[i] + ciag1[i] + ciag2[i]) / 4;
												ciagwynik[i] = temp;
											}
				printf("\n   LICZBA1 :            ");
				for (i = 1; i >= 0; i--) printf("%d",ciag1[i]);
				printf("\n + LICZBA2 :            ");
				for (i = 1; i >= 0; i--) printf("%d",ciag2[i]);
				printf("\n___________________________");
				printf("\n      SUMA =           ");
				for (i = 2; i >= 0; i--) printf("%d",ciagwynik[i]);

			break;
			case '-':
				printf("\nWynik odejmowania liczb BASE4: ");
				printf("\n   LICZBA1 :            ");
				for (i = 1; i >= 0; i--) printf("%d",ciag1[i]);
				printf("\n - LICZBA2 :            ");
				for (i = 1; i >= 0; i--) printf("%d",ciag2[i]);
				printf("\n___________________________");
				if (wieksza == 1) 
					{for (i = 0; i <=1; i++)
						if (ciag1[i] >= ciag2[i]) ciagwynik[i] = ciag1[i] - ciag2[i] + ciagtemp[i];
						else {
								ciagtemp[i] = 4;
								ciagwynik[i] = ciag1[i] + ciagtemp[i] - ciag2[i];
								ciagtemp[i+1] = -1;
							}
					}
				else 
					{for (i = 0; i <= 1; i++)
						if (ciag2[i] >= ciag1[i]) ciagwynik[i] = ciag2[i] - ciag1[i] + ciagtemp[i];
						else {
								ciagtemp[i] = 4;
								ciagwynik[i] = ciag2[i] + ciagtemp[i] - ciag1[i];
								ciagtemp[i + 1] = -1;
							}
					}	

					
				if (wieksza == 1) printf("\n   ROZNICA =            ");
					else printf("\n   ROZNICA =           -");
				for (i = 1; i >= 0; i--) printf("%d",ciagwynik[i]);		
			break;
			case 'k': 
				wybor = 'k';
			break;
			}
		fflush(stdin);
		}
		while (wybor != 'k');
	return 0;
}