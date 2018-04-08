//Melissa Newball
//April 8, 2018
//Interactive program using character arrays (strings)

#define _CRT_NO_WARNINGS
#include <stdio.h>

int main()
{
	//Declare two character arrays and character for the Y/N
	char first[25];
	char second[25];
	char choice;
	
	//Greet the user
	printf("Hello, and thank you for using the Compound-Word Program.\n");

	do
	{
		//Use strcpy to initialize the character arrays to "" (empty string/no space)
		strcpy(first, "");
		strcpy(second, "");

		//Ask and get two words from the user.
		printf("\n------------------------\n");
		printf("Please submit two words separated by a space. Press ENTER to combine.\n");
		scanf("%s %s", first, second);

		//Combine the two words into one word using strcat (you choose the order)
		strcat(first, second);

		//Print the new word onto the screen
		printf("\nThe compound word is: %s\n\n", first);

		//Ask the user if they want to enter another two words (y/n). If yes to go step 2.
		printf("Would you like to enter another two words? Y or N? ");
		scanf(" %c", &choice);
	} while (choice == 'y' || choice == 'Y');

	printf("\n------------------------");
	printf("\nThanks for playing. Goodbye!\n\n");

}