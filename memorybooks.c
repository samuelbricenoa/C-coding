#include <stdio.h>
#include <stdlib.h>

typedef struct author_t
{
	char name[20];
	int birthYear;
	int publishings;

} author_t;

typedef struct book_t
{
	char name[20];
	int year;
	int numAuthors;
	author_t * authors;
} book_t ;
int main () {
	int numbooks, i, j;
	book_t* bookarray;
	scanf("%d", &numbooks);

	bookarray = (book_t*) calloc (numbooks, sizeof(book_t));
	
	for(i=0; i < numbooks; i++){
		scanf("%s", bookarray[i].name);
		scanf("%d", &bookarray[i].year);
		scanf("%d", &bookarray[i].numAuthors);
		bookarray[i].authors = (author_t*) calloc(bookarray[i].numAuthors, sizeof(author_t) );
			for(j = 0; j < bookarray[i].numAuthors; j++)
			{
			scanf("%s", bookarray[i].authors[j].name);
			scanf("%d", &bookarray[i].authors[j].birthYear);
			scanf("%d", &bookarray[i].authors[j].publishings);
				
			}
	}
	
	for(i=0; i < numbooks ; i++){
		
		free(bookarray[i].authors);
		bookarray[i].authors = NULL;
		
	}
	free(bookarray);
	bookarray = NULL;
	return 0;
}

