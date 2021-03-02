#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE (1<2)
#define FALSE (!TRUE)
void mergeSort(int start, int end, char**Names, char alphabet[]);
int cmp(char* word, char* word2, char alphabet[]);

int main(){

char alphabet[26], spaces;
char ** Names;
int i, numnames;
	
	for(i=0;i<26;i++)
	{
	scanf("%c", &alphabet[i]);
	scanf("%c", &spaces);
	}
	
	scanf("%d", &numnames);
	Names = calloc(numnames, sizeof(char*));
	for(i=0; i<numnames;i++)
	{
		Names[i] = calloc(100, sizeof(char));
		if( Names[i] == NULL)
		return 1;
	}
		
	for(i=0;i<numnames; i++)
	{
		scanf("%s", Names[i]);
	
	}
		
	if(numnames == 1)
	{
		printf("%s", Names[0]);
	}
	else
		printf("works");
		mergeSort(0, numnames-1, Names, alphabet);
	
	for(i=0; i<numnames; i++);
	{
	printf("FINALSTEP");
	printf("%s", Names[i]);
	}
free(Names);
	return 0;
}


void mergeSort(int start, int end, char**Names, char alphabet[])
{
	int mid = (start + end)/ 2, i;
	int frontPtr = start;
	int backPtr = mid +1;
	int mergedPtr = 0;
	char vals[end - start +1][100];
	if (start == end)
	return;
	mergeSort(start, mid, Names, alphabet); mergeSort(mid +1, end, Names, alphabet);
	
	while(mergedPtr <= end - start)
	{
		if ((frontPtr == mid +1) || (backPtr != end + 1) && cmp(Names[frontPtr], Names[backPtr], alphabet)<1)	
		{
			printf("works2");
			strcpy(vals[mergedPtr++] ,Names[backPtr++]);
			printf("%s\n", Names[backPtr]);
			
		}
		else
			printf("works3");
			strcpy(vals[mergedPtr++], Names[frontPtr++]);
			printf("%s\n", Names[frontPtr]);
			
	}
	for(i=start; i<= end; i++)
	{
		printf("works4");
		strcpy(Names[i], vals[i-start]);	
	}
	
}

int cmp(char* word, char* word2, char alphabet[])
{
	printf("works5");
	int i,j, wordone, wordtwo;
	wordone = strlen(word);
	wordtwo = strlen(word2);
	if (strcmp(word, word2) == 0)
		return 0;
	if (wordone >= wordtwo)
		wordone = wordtwo;
	for(i=0; i<wordone; i++)
		{
			if( word[i] == word2[i])
				continue;
			else if(word[i] == '\0')
			return 0;
			else if(word2[i] == '\0')
			return 1;
			else if( word[i] != word2[i])
			{
				for(j=0; j<26; j++)
				{
					if(word[i] == alphabet[j])
						return 0;
					else if (word2[i] == alphabet[j])
						return 1;
				}
				
			}
		}
}
