#include <stdio.h>
#include "Modul_3.h"

int main()
{
	int L1, L2, L3, wybor = 0;  		//variables for part1
	int *L1p,*L2p,*L3p;		
	
	struct entry n1, n2, n3, n4; 		//variables for part2
	struct entry *list_pointer = &n1;

	n1.prev = (struct entry *) 0;
	n1.value = 100;
	n1.next = &n2;

	n2.prev = &n1;
	n2.value = 200;
	n2.next = &n3;

	n3.prev = &n2;
	n3.value = 300;
	n3.next = &n4;

	n4.prev = &n3;
	n4.value = 400;
	n4.next = (struct entry *) 0; 
	
	char ciag1[30], ciag2[30];			//variables for part3
	char *c1pointer, *c2pointer;
	c1pointer = &ciag1[0];
	c2pointer = &ciag2[0];
	
	do
		{
		printf("\n___________________\n\n Homework Module 3\n___________________\n");
		printf("\n 1. Realizacja funkcji sort3\n 2. Lista podwojnego powiazania");
		printf("\n 3. Realizacja funkcji compareStrings()\n 4. Wyjscie z programu\nTwoj wybor :");
		scanf("%d", &wybor);
		switch(wybor)
			{
			case 1:
				printf("\n Realizacja funkcji sort3 - sortujaca trzy liczby bez uzycia tablicy\n");
				printf(" Wprowadz liczbe 1:");
				scanf("%d", &L1);
				L1p = &L1;
				printf(" Wprowadz liczbe 2:");
				scanf("%d", &L2);
				L2p = &L2;
				printf(" Wprowadz liczbe 3:");
				scanf("%d", &L3);
				L3p = &L3;
				printf("Wprowadzone liczby z adresami:\nL1 =	%d	%u	|  L2 =	%d	%u	|  L3 =	%d	%u\n", L1, L1p, L2, L2p, L3, L3p);
				sort3(L1p, L2p, L3p);
				printf("Posortowane liczby z adresami:\nL1 =	%d	%u	|  L2 =	%d	%u	|  L3 =	%d	%u\n", L1, L1p, L2, L2p, L3, L3p);
			break;

			case 2:
				printf("\n Lista podwojnego powiazania:");
				printf(" \nDrukowanie elementu od pierwszego do ostatniego (do ogona)\n_____________________________________________________________\n");
				while (list_pointer != (struct entry *)0)
					{
					printf("element %i | ", list_pointer -> value);
					list_pointer = list_pointer -> next;
					if (list_pointer == NULL) printf("Ogon\n_____________________________________________________________\n");
					}
			 
				printf("\n Teraz w druga strone (go glowy) \n");
				list_pointer =&n4; 
				printf("Drukowanie elementu od ostatniego do pierwszego\n_____________________________________________________________\n");

				while (list_pointer != (struct entry *)0)
					{
					printf("element %i | ", list_pointer -> value);
					list_pointer = list_pointer -> prev;
					if (list_pointer == NULL) printf("Glowa\n_____________________________________________________________\n");
					}
			break;

			case 3: 
				printf("\n Realizaja funkcji compareStrings()\n");
				printf("\n Wprowadz pierwszy ciag znakow :");
				scanf("%s", ciag1);
				fflush(stdin);			

				printf("    Wprowadz drugi ciag znakow :");
				scanf("%s", ciag2);
				fflush(stdin);
				
				if (compareStrings(c1pointer,c2pointer))
					printf("\n ciagi \"%s\" i \"%s\" sa sobie rowne", &ciag1, &ciag2);
				else printf("\n ciagi \"%s\" i \"%s\" nie sa sobie rowne", &ciag1, &ciag2);
			break;

			case 4: 
				printf("\n BYE!\n");
				wybor = 4;
			break;

			}
		fflush(stdin);
		}
	while(wybor != 4);

	return 0;
}

/* 
gcc -c Modul_3.c
gcc -c Modul_3_main.c
gcc -o main.exe Modul_3.o Modul_3_main.o
*/
