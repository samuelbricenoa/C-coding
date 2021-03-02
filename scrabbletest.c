
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
struct tile {
  char letter;
  int score;
};

void printTiles(struct tile alltiles[],
                int length);
void printScore(struct tile alltiles[],
                int length);

int main() {

 int WordLength;

 
 printf("How many letters is the word?\n");
 scanf("%d", &WordLength);
  int num = (WordLength*2)-1;
 
 

  int index;
  struct tile mine[num];
  // Read in all tiles from user.
  for (index=0; index<num; index++) {
    scanf("%c", &mine[index].letter);
    scanf("%d", &mine[index].score);
  }
  printTiles(mine, num); 
  printScore(mine, num);
  return 0;
}
// Precondition: The length of the array 
// alltiles is length and each tile is 
// already initialized.
// Postcondition: All the letters on the 
// tiles will be printed with no spaces
// followed by a newline character.
void printTiles(struct tile alltiles[],
                int length) {

  int index;
  for (index=0; index<length; index++)
    printf("%c", alltiles[index].letter);
  printf("\n");
}

// Precondition: The length of the array 
// alltiles is length and each tile is 
// already initialized.
// Postcondition: The sum of the scores of
// all the tiles will be printed.
void printScore(struct tile alltiles[],
                int length) {

  int index, sum=0;
  for (index=0; index<length; index++)
    sum+=alltiles[index].score;
  printf("Score = %d\n", sum);
}

