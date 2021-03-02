#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Names
{
   char * str;
   
}Names;

typedef struct ArrayList
{
   int size;
   int cap;
   Names * arr;
} ArrayList;

typedef struct FullList
{
   ArrayList * aol;
   int size, cap;
} FullList;

void expand1 (ArrayList *);




void expand1 (ArrayList * al)
{	
   if(al->cap == al->size)
   {
   int newCap = al->cap * 2;
   
   // Update the array list
   al->cap = newCap;
   ArrayList * arrayl;
   arrayl = (ArrayList *)realloc (al, newCap * sizeof(ArrayList));
   }
}




int main()
{
	

   ArrayList * al;
   FullList * symp;
   Names * N;
char letter, studorsymp[10]; 
int i,j, numcases;
int  afflictions = 0 ;


scanf("%d", &numcases);

al = (ArrayList*)calloc(numcases, sizeof(ArrayList));
symp = (FullList*)calloc(1, sizeof(FullList));

for (i=0; i<numcases; i++)
{
	

	al[i].arr = calloc(1, sizeof(Names));
	symp[i].aol = calloc(1, sizeof(ArrayList));

	scanf("%c", &letter);
	
	if(letter == 'u')
	{
	
	
	scanf("%s", symp->aol[i].arr[i]);
	scanf("%s", symp->aol[i]);
	
	
	}
	else if(letter == 'q')
	{

	scanf("%s", studorsymp);
		if(strcmp(studorsymp, "student") == 0)
		{
		
		strcpy(studorsymp, "");
		scanf("%s", studorsymp);
			for (j=0; j<numcases; j++)
			{
			
			if(strcmp(studorsymp, al[j].arr[i].str) == 0 )
			afflictions++;
			if(strcmp(studorsymp, al[j].arr[i].str) == 0 )
			printf("%d", afflictions);
			printf("%s", symp->aol[j]);
			}
			
		}
		strcpy(studorsymp, "");	
	}
   

}
free(al);
free(symp);
free(N);
 return 0;
}
   



