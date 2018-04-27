//Melissa Newball
//April 22, 2018
//Hangman game with user defined functions, character arrays, and c style string member functions

#define _CRT_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXGUESSES 6

//this function provides instructions to the user on how to play the game
void HangmanRules();

//this function asks the user if they want to play another game (y or n)
void PlayAgain(char *againPtr);

//this function changes a character array to all uppercase letters
void UpperCaseWord(char word[]);

//this function runs one game. 
//input: character from the file, void return type
//all other functions to Play one round of a game 
//are called from within the PlayOneGame function
void PlayOneGame(char solution[]);

//this function creates the starword array
void CreateStarword(char starword[], int length);

//this function gets the users guess letter and adds it to the lettersGuessed array
//returns the letter entered by the user
char GetTheLetterGuess(char guessedletters[], int *numPtr);

//this function replaces any asterik in the starword with the current character enteed by the user
int ReplaceStars(char solution[], char starword[], char letter);

//this function gets the guess word,
//compares the solution and the guess word 
//tells the user if they have won and returns a 1
//otherwise it returns a 0
int DidYouWin(char solution[]);

int main()
{
	FILE *inPtr; //step 8
	char again; //for PlayAgain function y/n
	char solution[25];

	//step 8 - connect to the input file and use fscanf to read a word from the file
	inPtr = fopen("hangmanWords.txt", "r");
	
	//Step 5 - display Hangman rules.
	HangmanRules();

	do {
		//get a word from the file
		fscanf(inPtr, " %s", solution);

		//change word to uppercase
		UpperCaseWord(solution);
		//printf("Test file: Solution is %s", solution); //STEP 11. Test, solution works. //Step 12. Works.

		//pass that word to PlayOneGame
		PlayOneGame(solution);

		//PlayAgain y or n
		PlayAgain(&again);
		//printf("\nIn Main function: you entered %c", again); Test, works.

	} while (again == 'Y');

	//close file
	fclose(inPtr);

}

//this function provides instructions to the user on how to play the game
void HangmanRules()
{
	printf("WELCOME TO HANGMAN!\n\n");
	printf("\nPlease read the following instructions before you play.\n");
	printf("\n- You will be presented with a word to be guessed.");
	printf("\n- Guess letters one at a time.");
	printf("\n- You can have up to six incorrect letter guesses.");
	printf("\n- You can only guess the word when you have made a correct letter guess.");
	printf("\n\nThe game will be OVER when you have guessed the word correctly\nOR when you have guessed letters incorrectly SIX times.");
	printf("\n\nHAVE FUN!\n");
}

//this function asks the user if they want to play another game (y or n)
void PlayAgain(char *againPtr)
{
	printf("\nWould you like to play another round (y or n)? ");
	scanf(" %c", againPtr);
	*againPtr = toupper(*againPtr);
	//printf("\n(In PlayAgain Function: You've entered %c", *againPtr); test, works.
}

//this function changes a character array to all uppercase letters
void UpperCaseWord(char word[])
{
	int length = strlen(word);
	int i;
	for (i = 0; i < length; i++)
	{
		word[i] = toupper(word[i]);
	}
}

//this function runs one game. 
//input: character from the file, void return type
//all other functions to Play one round of a game 
//are called from within the PlayOneGame function
void PlayOneGame(char solution[])
{
	char starword[25] = "";
	char guessedletters[25] = "";
	char letter; //step 16 part 3. letter the user is going to guess.
	int length = strlen(solution);
	int count = 0; //count of the guessed letters
	int win = 0;
	int numGuesses = 0;
	int test;

	//printf("Inside PlayGame solution: %s", solution); Step 12 works within game function.

	//create star word
	CreateStarword(starword, length);
	//printf("%s", starword); Step 15 Test works.

	while ((win == 0) && (numGuesses < MAXGUESSES)) //(numGuesses < MAXGUESSES) test count works.
	{
		//1 present star word
		printf("\nThe word is: %s", starword); //works

		//2 present letters guessed so far
		printf("\n\nHere are the letters guessed so far: %s", guessedletters); //works

		//3 get a character guess
		letter = GetTheLetterGuess(guessedletters, &count);
		//printf("Letter is %c and count is %d", letter, count); test works.
		//numGuesses++; test, count works.

		//4 see if character is in word/replace the star
		test = ReplaceStars(solution, starword, letter);
		//printf("\nTest: %d is returnvalue", test); works.
		//printf("\nTest: %s is starword", &starword); works.

		if (test == 1)
		{
			printf("\nThe letter was in the word! Now you can guess the word.");
			printf("\nThe word is: %s\n", starword);
			win = DidYouWin(solution);
		}
		else
		{
			numGuesses++;
			printf("\nThe letter was not in the word. Number of guesses used: %d out of 6.\n", numGuesses);
		}

	}

}

//this function creates the starword array
void CreateStarword(char starword[], int length)
{
	int count;

	for (count = 0; count < length; count++)
	{
		starword[count] = '*';
	}
}

//this function gets the users guess letter and adds it to the lettersGuessed array
//returns the letter e  ntered by the user
char GetTheLetterGuess(char guessedletters[], int *numPtr)
{
	char temp;

	//ask, get, and change temporary to uppercase
	printf("\n\nPlease enter a guess: ");
	scanf(" %c", &temp);
	temp = toupper(temp);

	guessedletters[*numPtr] = temp; //puts users guess to location 0

	*numPtr = *numPtr + 1;

	guessedletters[*numPtr] = '\0';

	return temp; //returns to PlayOneGame function
}

//this function replaces any asterik in the starword with the current character enteed by the user
int ReplaceStars(char solution[], char starword[], char letter)
{
	int length = strlen(solution);
	int i;
	int returnvalue = 0;

	for (i = 0; i < length; i++)
	{
		if (solution[i] == letter)
		{
			starword[i] = letter;
			returnvalue = 1;
		}
	}
	return returnvalue;
}

//this function gets the guess word,
//compares the solution and the guess word 
//tells the user if they have won and returns a 1
//otherwise it returns a 0
int DidYouWin(char solution[])
{
	char guess[25];
	int returnvalue = 0;

	printf("Your word guess: ");
	scanf(" %s", guess);

	//change guess to uppercase with upper case function
	UpperCaseWord(guess);
	//printf("\nTEST: The word in uppercase is: %s", guess);

	if (strcmp(solution, guess) == 0)
	{
		printf("\nCongratulations, you won that round!\n");
		returnvalue = 1;
	} 
	return returnvalue;
}