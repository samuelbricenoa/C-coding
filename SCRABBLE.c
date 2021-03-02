#include <stdio.h>

struct tile {
  char letter;
  int score;
};

void printTiles(struct tile alltiles[],
                int length);
void printScore(struct tile alltiles[],
                int length);

int main() {

  int index;
  struct tile mine[7];
  // Read in all tiles from user.
  for (index=0; index<7; index++) {
    scanf("%c", &mine[index].letter);
    scanf("%d", &mine[index].score);
  }
  printTiles(mine, 7); 
  printScore(mine, 7);
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

