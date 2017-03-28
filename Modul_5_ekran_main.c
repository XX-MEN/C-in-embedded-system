#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUFFER_LEN 300
#define nazwaloga_LEN 80
int bufavaliable=BUFFER_LEN;
char buf[BUFFER_LEN];
char linebuf[BUFFER_LEN];
char nazwaloga[nazwaloga_LEN];
FILE* file;

#if __STDC_VERSION__ >= 199901L
#define __LOG_LINE(log_level,message) "%s | %s | %s: %d	| %s	| %s (funkcja %s)\n", __DATE__, __TIME__, __FILE__, __LINE__, log_level,message,__func__
#else
#define __LOG_LINE(log_level,message) "%s | %s | %s: %d	| %s	| %s\n", __DATE__, __TIME__, __FILE__, __LINE__, log_level,message
#endif

#define BUFOROWANIE(log_level,message) \
		{	sprintf(linebuf, __LOG_LINE(log_level,message) );\
			printf("_____\n buforze jest :\n%s",buf);\
			if(bufavaliable > strlen(linebuf)) \
				{ 	sprintf(buf, "%s%s",buf,linebuf,__LOG_LINE(log_level,message) );\
					bufavaliable-=strlen(linebuf);\
				} \
			else { 	fprintf(file ,buf); \
					printf("\n Nastapil zapis do pliku");\
					bufavaliable=BUFFER_LEN;\
					buf[0]='\0'; \
					printf("_____\n buforze jest :\n\"%s\"\n",buf);\
					sprintf(buf, __LOG_LINE(log_level,message) );\
					bufavaliable-=strlen(linebuf);\
				 }\
		}
		
#define LOG_LOW(message) BUFOROWANIE("LOW",message)
#define LOG_MEDIUM(message) BUFOROWANIE("MEDIUM",message)
#define LOG_HIGH(message) BUFOROWANIE("HIGH",message)
#define LOG_ERROR(message) BUFOROWANIE("ERROR",message)
#define LOG_INFO fprintf(file ,"Log programu %s Ver. 1.0 \n", __FILE__); 
#define LOG_END \
			{	fprintf(file ,buf);\
				buf[0]='\0'; \
				printf("\n Nastapil zapis do pliku");\
				printf("_____\n buforze jest :\n\"%s\"\n",buf);\
			}
								
int losuj_liczbe(int min, int max)
{
    LOG_HIGH("poczatek");
	int tmp;
    if (max>=min)
        max=max-min+1;
    else
		{
			tmp= min - max;	
			min= max;
			max= tmp;
		}
	LOG_HIGH("koniec");	
    return max?(rand()%max+min):min;
}

int fileExists (const char* fileName)
{
	
	FILE *plik;
	LOG_HIGH("poczatek");
    plik = fopen(fileName, "r");  
    if ( plik )
    {
		fclose(plik);
		
		LOG_MEDIUM("Plik istnieje");
		LOG_HIGH("koniec");
        return 1;
    }
    LOG_ERROR("plik nie istnieje");
	LOG_HIGH("koniec");
    return 0;
}

int main(int argc, char *argv[])
{
	int i;
	char dataiczas[32];
    time_t timer;
    struct tm* tm_info;
		
	time(&timer);
    tm_info = localtime(&timer);
	strftime(dataiczas, 32, "_%Y%m%d_%H-%M", tm_info);
	strcpy(nazwaloga,__FILE__);
	strcat(nazwaloga,dataiczas);
	strcat(nazwaloga,".log");
	
	if (fileExists(nazwaloga))  
		{
		file= fopen(nazwaloga,"a");
		printf("\n Operacje beda logowane do istniejacego pliku");
		LOG_LOW("Plik do logowania istnieje");
		LOG_MEDIUM("otwarcie pliku do Logowania");
		}
	else 
		{
		
		file = fopen(nazwaloga,"a");
		printf("\n Operacje programu beda logowane do nowego pliku: %s\n", nazwaloga);
		LOG_INFO;
		LOG_ERROR("Brak pliku, utworzono nowy plik do logowania");
		}

	LOG_MEDIUM("________ program gotowy do dzialania");
	LOG_LOW(">>>>>>> zakonczono blok programu");

	printf("\n Program teraz cos sobie wylosuje: \n");
	for (i=0;i<=3; i++) printf("Wylosowano liczby : %d\n",losuj_liczbe(1, 3000));	
	printf("\n Program sie zakonczy\n");

	LOG_LOW("_______ program zostal zamkniety");
	LOG_HIGH("********** koniec LOGa");

	LOG_END; //zrzuca bufor nieoprozniony bez komunikatu.

	printf("\nLogi z dzialania programu sa dostepne w pliku: %s\n",nazwaloga);
	
	fclose(file);
    return 0;
}

