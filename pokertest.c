#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SUITS 4
#define FACES 13
#define AVAILABLE 0
#define TAKEN 1


void dealACard(char *suits[], char *faces[], int deck[][FACES]);
void dealAHand(char *suits[], char *faces[], int deck[][FACES]);
void cardsInHand(char *suits[]);

main() {
   char *suits[4] = { "Hearts", "Diamonds", "Spades", "Clubs" };
   char *faces[13] = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
   int deck[4][13] = { AVAILABLE };
   int i;

   srand(time(NULL));

   for (i = 0; i < 1; i++)
       dealAHand(suits, faces, deck);

   system("pause");
}

void dealAHand(char *suits[], char *faces[], int deck[][FACES]) {
   int i;

   for (i = 0; i < 5; i++)
       dealACard(suits, faces, deck);
   for (i = 0; i < 5; i++)
       cardsInHand(suits);
   printf("\n");
}

void dealACard(char *suits[], char *faces[], int deck[][FACES]) {
   int suitIndex, faceIndex;

   suitIndex = rand() % 4;
   faceIndex = rand() % 13;
   while (deck[suitIndex][faceIndex] == TAKEN) {
       suitIndex = rand() % 4;
       faceIndex = rand() % 13;
   }
   deck[suitIndex][faceIndex] = TAKEN;


   printf("%s of %s \n", faces[faceIndex], suits[suitIndex]);

}

void cardsInHand(char *suits[])   {
   int suitsInMyHand[4];

       if (suits[SUITS] = suits[0])   {
           suitsInMyHand[0]++;
       }
       else if (suits[SUITS] = suits[1])   {
           suitsInMyHand[1]++;
       }
       else if (suits[SUITS] = suits[2])   {
           suitsInMyHand[2]++;
       }
       else if (suits[SUITS] = suits[3])   {
           suitsInMyHand[3]++;
       }
   }
