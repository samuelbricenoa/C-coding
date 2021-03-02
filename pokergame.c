#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void pickCard(char *suits[], char *faces[], int deck[][13], int suitsInHand[], int facesInHand[]);
void PickCard5x(char *suits[], char *faces[], int deck[][13], int suitsInHand[], int facesInHand[]);
void PointCalc(int suitsInHand[], int facesInHand[], int *pStraight, int *pFlush, int *pFour, int *pThree, int *pPairs);
void WinnerCalc(int score[]);
int main ()
{
	srand(time(NULL));
	char *suits[4] = {"Hearts", "Diamonds", "Spades", "Clubs"};
	char *faces[13] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
	int deck[4][13] = {0};
	int suitsInHand[4]= {0};
	int facesInHand[13]={0};
	int straight = 0, flush = 0, four = 0, three = 0, pairs = 0;
	int score[2]={0};
	int i,j;
	
	
	for (i = 0; i < 2; i++){
	PickCard5x(suits, faces, deck, suitsInHand, facesInHand);
	PointCalc(suitsInHand, facesInHand, &straight, &flush, &four, &three, &pairs);
		if (straight && flush){
           printf("Player %d has a Straight flush\n\n", i+1);
           score[i]= 9;
		   }
       else if (four){       
           printf("Player %d has Four of a kind\n\n", i+1);
           score[i] = 8;
		   }
       else if (three && pairs == 1){
           printf("Player %d has a Full house\n\n", i+1);
           score[i] = 7;
		   }
       else if (flush){      
           printf("Player %d has a Flush\n\n", i+1);
           score[i] = 6;
		   }
       else if (straight){   
           printf("Player %d has a Straight\n\n", i+1);
           score[i] = 5;
		   }
       else if (three){      
           printf("Player %d has Three of a kind\n\n", i+1);
           score[i] = 4;
		   }
       else if (pairs == 2){
           printf("Player %d has Two pairs\n\n", i+1);
           score[i] = 3;
		   }
       else if (pairs == 1){
           printf("Player %d has a Pair\n\n", i+1);
           score[i] = 2;
		   }
       else{                 
           printf("Player %d has a High card\n\n", i+1);
           score[i]= 1;
		   }
	printf("Player %d score: %d\n", i+1, score[i]);
	       for( j= 0;  j< 4; j++){ // resets for player 2.
           suitsInHand[j] = 0;
       }
       for(j = 0; j < 13; j++){ // resets for player 2.
           facesInHand[j] = 0;
       }
	
}
	WinnerCalc(score);
	return 0;
}
//this function picks a random card for the user and uses an array to make sure that a repeat card is not picked twice.
void pickCard(char *suits[], char *faces[], int deck[][13], int suitsInHand[], int facesInHand[])
{
	int Suitnum, Facenum, i;
	
	Suitnum = rand()% 4;
	Facenum = rand()% 13;
	while (deck[Suitnum][Facenum] == 1)
	{
		Suitnum = rand()% 4;
		Facenum = rand()% 13;
	}
	deck[Suitnum][Facenum] = 1;
	suitsInHand[Suitnum] ++;
	facesInHand[Facenum] ++;	
	printf("%s of %s\n", faces[Facenum], suits[Suitnum]);

}
//This function uses the pickcard function to create a hand of 5 cards for each player and then prints the ammount of each suit and face.
void PickCard5x(char *suits[], char *faces[], int deck[][13], int suitsInHand[], int facesInHand[])
{
	int i, j, k;
	for(i=0; i<5; i++)
		pickCard(suits, faces, deck, suitsInHand, facesInHand);
	for(j=0; j<4;j++)	
		printf("%d ", suitsInHand[j]);
	printf("\n");
	for(k=0; k<13; k++)
		printf("%d ", facesInHand[k]);
	printf("\n");
	
}
//This function looks for winning hands in the players hand and assigns points to them.
void PointCalc(int suitsInHand[], int facesInHand[], int *pStraight, int *pFlush, int *pFour, int *pThree, int *pPairs)
{
	
	int cardinrow = 0;
	int rank, suit;

	int straight = 0;
	int flush = 0;
	int four = 0;
	int three = 0;
	int pairs = 0;

	// checks for a flush
	for (suit = 0; suit < 4; suit++)
		if (suitsInHand[suit] == 5)
			flush = 1;


	//checks for a straight by finding the first card in the hand then uses a loop to count if there are consecutive matches.
	rank = 0;
	while (facesInHand[rank] == 0) 
		rank++;

	//     count the consecutive cards.
	for (; rank < 13 && facesInHand[rank]; rank++)
		cardinrow++;
	//if there are 5 consecutive cards then it is a straight.
	if (cardinrow == 5) {
		straight = 1;
		return;
	}

	//checks for four of kind 3 of kind and pair
	for (rank = 0; rank < 13; rank++) {
		if (facesInHand[rank] == 4) 
			four = 1;
		if (facesInHand[rank] == 3) 
			three = 1;
		if (facesInHand[rank] == 2) 
			pairs++;
	}
			
   *pStraight = straight;
   *pFlush = flush;
   *pFour = four;
   *pThree = three;
   *pPairs = pairs;
   
   return;

}
//this function evaluates the score for each player and picks a winner, if no player has more points, then it is a tie.
void WinnerCalc(int score[])
{
	if(score[0]>score[1])
		printf("\nPlayer 1 has won.");
	else if (score[0]<score[1])
		printf("\nPlayer 2 has won.");
	else 
		printf("\nIt was a tie");
}
