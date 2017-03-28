#include <stdio.h>
#include <stdlib.h>
#include "Modul_3.h"

void zamien(int *a, int *b)
{
    int temp = *a;
        *a = *b;
        *b = temp;
}

void sort3(int *l1, int *l2, int *l3)
{
        if(*l1 > *l2)
                zamien(l1,l2);
        if(*l1 > *l3)
                zamien(l1,l3);
        if(*l2 > *l3)
                zamien(l2,l3);
}

int stringLength(char *cpointer)
{
    int count=0;
    while  (*(cpointer + count) != '\0')
		{
        count++;
		}
    return count;
}

int compareStrings(char *cpointer1, char *cpointer2)
{	
	int i,count,sarowne;
	
	if (stringLength(cpointer1) == stringLength(cpointer2))	
		count = stringLength(cpointer1);
	else return 0;

	for (i=0 ;i <= count - 1; i++)
		if (*(cpointer1+i) == *(cpointer2+i))
			sarowne=1;
		else 
			{
				sarowne=0;
				break;
			}
	return sarowne;
}
