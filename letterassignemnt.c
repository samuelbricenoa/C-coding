#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
int numwords, i, j, k, letterposition;
char wordarray[101];
//I created a 2D array so that I can store each word if there are multiple. 
char printarray[10][101];
	
//reads in the first integer to find the number of words there are.
scanf("%d", &numwords);
	
//for loop that reads in the words.
for(i=0; i<numwords; i++){
	scanf("%s", wordarray);
	
	//integer for the length of the word being processed.
	int wordlength = strlen(wordarray);
	
		//for loop that will encrypt each letter of the word.
		for (j=0; j<wordlength; j++){
			
				//this if statement checks whether the current letter is a vowel.	
				if(wordarray[j] == 'a' || wordarray[j] == 'e' || wordarray[j] == 'i' || wordarray[j] == 'o'|| wordarray[j] == 'u'){
					
					//if it is a vowel the code ectrypts the current letter moving it 13 values up in the alphabet
					//it also moves the next letter up 14 letters.
					letterposition = wordarray[j] - 'a';
					//if the letter would go past 'z' after being encrpyted this part of the code makes it so it starts at 'a' and continues from there.
					if (letterposition + 13 > 26){
						letterposition -= 26;}		
					wordarray[j] = letterposition + 13 + 'a';
				
					letterposition = wordarray[j+1] - 'a';	
					if (letterposition + 14 > 26){
						letterposition -= 26;}		
					wordarray[j+1] = letterposition + 14 + 'a';
					//since this part of the code did the current AND next letter, it increases the loop counter so the next instance 
					//of the loop 2 letters ahead of the current loop.
					j+=1;
					}
				//if the letter is not a vowel, then the code encrypts the letter by 13 places normally.	
				else{
				
				letterposition = wordarray[j] - 'a';	
				if (letterposition + 13 > 26){
					letterposition -= 26;}		
				wordarray[j] = letterposition + 13 + 'a';
				
				}
				
		}
		//this assigns the encrypted word to the 2D array each time the loop is completed.
		for (k=0; k<wordlength;k++)	
			printarray[i][k] = wordarray[k];
		
			
	}
//I use a for loop to make it so that all words are printed at the end rather than after each time a word is entered.	
for(i=0; i<numwords; i++)
printf("%s\n", printarray[i]);	
	
return 0;	
}
	


