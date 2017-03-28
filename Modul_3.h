#ifndef _Modul_3_H_
#define _Modul_3_H_

struct entry
	{
		int value;
		struct entry *prev;
		struct entry *next;
	};

void zamien(int *a, int *b);
void sort3(int *l1, int *l2, int *l3);
int stringLength(char *cpointer);
int compareStrings(char *cpointer1, char *cpointer2);

#endif 