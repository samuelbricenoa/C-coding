#include <stdio.h>
#include <stdlib.h>
//This code is for a tic tac toe game using 2D arrays.
//Samuel Briceno Due 6/26/19

int main(){
	char tictac [3][3];
	char a = ' ';
	int x, y, row, column, i; 
	int turns = 0;
//creates the initial tic tac game board with empty spaces.
	for(x=0;x<3;x++){
		for(y=0;y<3;y++){
		tictac[x][y] = a;
		printf("| %c |", tictac[x][y]);
		}
		printf("\n");
		printf("---------------");
		printf("\n");
	}
	//Since there are 9 turns in tic tac toe, the code stops after 9 turns.
	while (turns<9){
		//First is the X player's turn, the code takes the input then prints a new board with the input added in replacing the empty spaces.
		printf("X - player turn:\n");
		printf("Enter your row.\n");
		scanf("%d", &row);
		printf("Enter your column.\n");
		scanf("%d", &column);
		row = row - 1;
		column = column - 1;
		tictac[row][column] = 'X';
		turns++;
		system("cls");
		
		for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			printf("| %c |", tictac[x][y]);
			}
		
			printf("\n");
			printf("---------------");
			printf("\n");
		}
		//This part of the code checks for a winner after each turn.
		//Each possible winning condition is checked. (rows, columns, and diagonals.)
		for(i=0; i<3; i++)
    	if(tictac[i][0]== 'X' && tictac[i][1] == tictac[i][0] && tictac[i][2]==tictac[i][0]){
		printf("X player Wins!!!\n");
		return 0;}
		for(i=0; i<3; i++)
    	if(tictac[0][i]== 'X' && tictac[1][i] == tictac[0][i] && tictac[2][i]==tictac[0][i]){
		printf("X player Wins!!!\n");
		return 0;}
		for(i=0; i<3; i++)
    	if(tictac[0][0]== 'X' && tictac[1][1] == tictac[0][0] && tictac[2][2]==tictac[0][0]){
		printf("X player Wins!!!\n");
		return 0;}
		if(tictac[0][2]== 'X' && tictac[1][1] == tictac[0][2] && tictac[2][0]==tictac[0][2]){
		printf("X player Wins!!!\n");
		return 0;}
		
		
		if(turns<9){
		//Next is the O player's turn, the code takes the input then prints a new board with the input added in.
		printf("O - player turn:\n");
		printf("Enter your row.\n");
		scanf("%d", &row);
		printf("Enter your column.\n");
		scanf("%d", &column);
		row = row - 1;
		column = column - 1;
		tictac[row][column] = 'O';
		turns++;
		system("cls");
		
		for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			printf("| %c |", tictac[x][y]);
			}
		
			printf("\n");
			printf("---------------");
			printf("\n");
		}
		for(i=0; i<3; i++)
    	if(tictac[i][0]== 'O' && tictac[i][1] == tictac[i][0] && tictac[i][2]==tictac[i][0]){
		printf("O player Wins!!!\n");
		return 0;}
		for(i=0; i<3; i++)
    	if(tictac[0][i]== 'O' && tictac[1][i] == tictac[0][i] && tictac[2][i]==tictac[0][i]){
		printf("O player Wins!!!\n");
		return 0;}
		for(i=0; i<3; i++)
    	if(tictac[0][0]== 'O' && tictac[1][1] == tictac[0][0] && tictac[2][2]==tictac[0][0]){
		printf("O player Wins!!!\n");
		return 0;}
		if(tictac[0][2]== 'O' && tictac[1][1] == tictac[0][2] && tictac[2][0]==tictac[0][2]){
		printf("O player Wins!!!\n");
		return 0;}	
	}
	//if there is no winner, then the code prints that it was a tie game.
	else
	printf("Tie Game!\n");
	}
		
}
