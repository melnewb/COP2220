//Melissa Newball
//February 19, 2018
//Large Program 1 - user defined functions, library functions from stdio.h and ctype.h, simple loops, conditions, and file input processing


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#define MAXGUESSES 5


//paste all the function prototypes here
//with the comments

//this function provides instructions to the user on how to play the game 
void LetterGuessRules();

//this function asks, gets, and //returns the number of games the user wants to play 
int GameCount();

//this function runs one game. 
//input: character from the file, void return type
void PlayOneGame(char solution);

//this function prompts the player to make a guess and returns that guess 
//this function is called from inside the PlayOneGame( ) function described above 
char GetGuess();

//this function takes two arguments, the guess from the player 
//and the solution letter from the file. 
//The function returns 1 if the guess matches the solution and returns a 0 if they do not match 
//This function also lets the user know if the guess comes alphabetically before or after the answer 
int CompareGuessAndSolution(char guess, char solution);


int main()
{
	//declare additional variables
	//declare FILE pointer
	FILE *inPtr;
	int numGames, i = 0;

	char solution; //letter from file

	LetterGuessRules(); //display game rules

	numGames=GameCount(); //Ask and get number of games to play (GameCount function)

	inPtr = fopen("letters.txt", "r"); //connect to the file HINT: use fopen

	//this for loop will allow the player to play more than one game
	//without recompiling
	for (i = 0; i < numGames; i++)
	{
		fscanf(inPtr, " %c", &solution); //get a solution letter from file - use fscanf

		solution = toupper(solution); //change the solution to uppercase

		//printf("\nThe letter is %c", solution); //print the solution back onto the screen to test<-Step 14. THIS WORKS!

		printf("\n******************\n");
		printf("\nLet's play game %d.\n", i+1); //shows user what round they are on.

		//call the PlayOneGame function and pass it the solution
		PlayOneGame(solution);

	}

	//close file pointer
	fclose(inPtr);
	return 0;
}

//this function provides instructions to the user on how to play the game 
void LetterGuessRules()
{
	printf("Welcome to the Letter Guessing Game!\n\n");
	printf("First, you will enter the number of games you want to play (1-8 games).\n");
	printf("For each game you will have 5 chances to guess each letter.\n");
	printf("Let's begin.\n\n");
}

//this function asks, gets, and //returns the number of games the user wants to play 
int GameCount()
{
	int numGames; //input from user amount of games to play
	printf("\nHow many games do you want to play? (1-8) ");
	scanf("%d", &numGames);
	printf("\nYou want to play %d games.\n", numGames); //repeats back to user how many games they want to play.
	return numGames;
}

//this function runs one game. 
//input: character from the file, void return type
void PlayOneGame(char solution)
{

	int win = 0;
	int numGuesses = 0;
	//declare additional variables
	char guess; //user's letter guess

	//printf("\nThe letter is %c", solution);<-Step 16 works and letters are uppercase.

	while (numGuesses < MAXGUESSES && win == 0)
	{
		//get a guess from the user by calling the GetGuess function
		guess = GetGuess();

		//change the guess to uppercase.
		guess = toupper(guess);
		
		//printf("Your guess is %c.", guess);<-STEP 21. This works and letter is uppercase.
		
		//win = call the function to compare the guess with the solution
		win = CompareGuessAndSolution(guess, solution);

		numGuesses++;//count the number of guesses so far
	}
	//use conditions to let the user know if they won or lost the round of the game
	if (numGuesses < MAXGUESSES && solution == guess) //If they guess correctly and win the round.
	{
		printf(" You've won this round!\n");
	}
	else if (numGuesses == MAXGUESSES && solution != guess) //If they run out of guesses for the round.
	{
		printf("You've run out of guesses for this round.\n");
	}
	else if (numGuesses == MAXGUESSES && solution == guess) //If they guess correctly on the last available guess and win.
	{
		printf(" You won that round on your last guess!\n");
	}

}

//this function prompts the player to make a guess and returns that guess 
//this function is called from inside the PlayOneGame( ) function described above 
char GetGuess()
{
	char guess; //user's letter guess

	printf("\nPlease make a guess: ");
	scanf(" %c", &guess);

	return guess;
}

//this function takes two arguments, the guess from the player 
//and the solution letter from the file. 
//The function returns 1 if the guess matches the solution and returns a 0 if they do not match 
//This function also lets the user know if the guess comes alphabetically before or after the answer 
int CompareGuessAndSolution(char guess, char solution)
{
	//correct guess
	if (guess == solution)
	{
		printf("\nThat is correct!");
		return 1;
	}
	//incorrect guess: pick letter before user guess
	else
		if (guess > solution)
		{
			printf("\nThe solution comes alphabetically before your guess (%c).\n", guess);
			return 0;
		}
	//incorrect guess: pick letter after user guess
	else
		if (guess < solution)
		{
			printf("\nThe solutions comes alphabetically after your guess (%c).\n", guess);
			return 0;
		}
		else return 0;
}