//Melissa Newball
//January 28, 2018
//Module 3 Program 2 - interactive program using functions from stdio.h, ctype.h, and simple math in C.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //printf, scanf definitions
#include <ctype.h> //toupper, tolower function

int main()
{
	int number; //input - a random number
	int plusforty; //output - number + 40
	char letter; //input - a random letter
	char secondletter; //input - a second random letter

	printf("Hello, my name is Melissa Newball.\n"); //Displays my name onto the screen.

	//Prompting user for a number.
	printf("\nPlease enter any number. "); //Promting user for a number.
	scanf("%d", &number);
	printf("You entered %d.\n", number); //Displays number.

	//Add forty to that number and display.
	plusforty = number + 40;
	printf("%d + 40 is %d.\n", number, plusforty);

	//Print both the original number and the total on the screen.
	printf("\nOriginal number is %d.\n", number);
	printf("New total is %d.\n", plusforty);

	//Prompting user for a letter.
	printf("\nPlease enter any letter. "); //Prompting user for a letter.
	scanf(" %c", &letter);
	printf("\nYou entered %c.", letter); //Displays letter.

	//Change letter to uppercase.
	printf("\n%c in uppercase is %c.\n", letter, toupper(letter)); //Displays letter in uppercase.

	//Prompting user for another letter.
	printf("\nPlease enter another letter."); //Prompting user for another letter.
	scanf(" %c", &secondletter);
	printf("\nYou entered %c.", secondletter); //Displayes second letter.

	//Change letter to lowercase.
	printf("\n%c in lowercase is %c.\n", secondletter, tolower(secondletter)); //Displays letter in lowercase.

	//Print both the original letters and the possibly changed letters back onto the screen.
	printf("\nOriginal letters are %c and %c.", letter, secondletter);
	printf("\nPossibly changed letters are %c and %c.\n", toupper(letter), tolower(secondletter));

	return (0);
}