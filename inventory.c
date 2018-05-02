//Melissa Newball
//April 26, 2018
//Interactive menu driven program broken up into user defined functions that
//manages a list of data using arrays and user defined structure types.

#define _CRT_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 50

//define structure
typedef struct {
	char name[30];
	char title[50];
	int id;
	int pages;
	double retailValue;
	double storePrice;
}book;

//function prototypes

//greets the user
void HelloWorld();

//hardcode five entries
void HardCode (book list[]);

//menu function, get input from the user on a menu item
char MainMenu();

//prints the list of the contents onto the screen
void PrintToScreen(book list[], int count);

//adds an item to the list
void AddBook(book list[], int count);

//prints a report to the file
void SaveToFile(book list[], int count);

//displays the ids in the list, gets the id from the user and returns it
int DisplayIDs(book list[], int count);

//searches the list by id and returns the index if there is a match
//or returns -1 if no match
//three arguments: list, number of items, id
int SearchIDs(book list[], int count, int id);

int main()
{
	book list[SIZE];
	int count = 0;
	char letter;
	int id;
	int index;
	int i;
	
	//Step 6. Implement the greeting function from inside main.
	HelloWorld();

	HardCode(list);
	count = 6;

	//displays menu and executes directives while the user does not choose Quit.
	//letter = MainMenu(); //initialization
	do {
		
		letter = MainMenu();

		if (letter == 'P') {
			printf("\nYou chose P >> Print inventory to screen.");
			//printf("\nThis is where the print function will be called.");
			PrintToScreen(list, count);
		}
		else if (letter == 'A') {
			printf("\nYou chose A >> Add a new entry.");
			//printf("\nThis is where the add function will be called.");
			AddBook(list, count);
			count = count + 1;
		}
		else if (letter == 'C') {
			printf("\nYou chose C >> Clear all records.");
			//printf("\nThis is where the clear function will be called.");
			count = 0;
			printf("\nAll records have been cleared.");
		}
		else if (letter == 'S') {
			printf("\nYou chose S >> Save report to file.");
			//printf("\nThis is where the save report function will be called.");
			SaveToFile(list, count);
			printf("\nFile has been saved to INVENTORY.txt");
		}
		else if (letter == 'D') {
			printf("\nYou chose D >> Delete an item from the list.");
			//printf("\nThis is where the delete function will be called.");
			printf("\nPlease choose an ID below to delete.\n");
			id = DisplayIDs(list, count);
			printf("\nYou chose: %d", id);
			index = SearchIDs(list, count, id);
			printf("\nIndex is %d", index);
			if (index == -1)
				printf("\nEntry not found.");
			else
			{
				list[index] = list[count - 1];
				count = count - 1;
				printf("\nEntry has been deleted.");
			}
		}
		else if (letter == 'U') {
			printf("\nYou chose U >> Update the store price.");
			//printf("\nThis is where the update function will be called.");
			printf("\nPlease choose an ID below to update.\n");
			id = DisplayIDs(list, count);
			printf("\nYou chose: %d", id);
			index = SearchIDs(list, count, id);
			printf("\nIndex is %d", index);
			if (index == -1)
				printf("\nEntry not found.");
			else
			{
				//prompts user to enter new Store Price, stores it, and displays new info
				printf("\nCurrent store price is: %.2f", list[index].storePrice);
				printf("\nPlease enter the new store price: ");
				scanf("%lf", &list[index].storePrice);
				printf("\nStore price has been updated. Modified entry:");
				printf("\nAuthor name: %s", list[index].name);
				printf("\nTitle: %s", list[index].title);
				printf("\nID: %d", list[index].id);
				printf("\nNumber of Pages: %d", list[index].pages);
				printf("\nRetail Value: $%.2f", list[index].retailValue);
				printf("\nStore Price: $%.2f", list[index].storePrice);
			}
		}
		else if (letter == 'Q') {
			printf("\nYou chose Q >> Quit.");
			printf("\nGoodbye");
		}
		else printf("Not a valid selection.");

	} while (letter != 'Q');
}

//greets the user
void HelloWorld()
{
	printf("This program manages the store list of books.\n");
	printf("Each book has a unique store ID.\n");
	printf("Follow the promps on the menu.\n");
}

//step 8. hardcode five entries
void HardCode(book list[])
{
	//entry #1
	strcpy(list[0].name, "JKRowling");
	strcpy(list[0].title, "HarryPotter");
	list[0].id = 96;
	list[0].pages = 595;
	list[0].retailValue = 15.99;
	list[0].storePrice = 5.45;

	//entry #2
	strcpy(list[1].name, "NirEyal");
	strcpy(list[1].title, "Hooked");
	list[1].id = 924;
	list[1].pages = 238;
	list[1].retailValue = 18.99;
	list[1].storePrice = 9.99;

	//entry #3
	strcpy(list[2].name, "MalcolmGladwell");
	strcpy(list[2].title, "Outliers");
	list[2].id = 749;
	list[2].pages = 281;
	list[2].retailValue = 13.99;
	list[2].storePrice = 12.99;

	//entry #4
	strcpy(list[3].name, "JackWelch");
	strcpy(list[3].title, "Winning");
	list[3].id = 284;
	list[3].pages = 582;
	list[3].retailValue = 17.99;
	list[3].storePrice = 8.99;

	//entry #5
	strcpy(list[4].name, "CarolDweck");
	strcpy(list[4].title, "Mindset");
	list[4].id = 191;
	list[4].pages = 201;
	list[4].retailValue = 14.99;
	list[4].storePrice = 12.99;

	//entry #6
	strcpy(list[5].name, "MaryOliver");
	strcpy(list[5].title, "Upstream");
	list[5].id = 600;
	list[5].pages = 115;
	list[5].retailValue = 18.99;
	list[5].storePrice = 13.45;
}

//menu function, get input from the user on a menu item
char MainMenu()
{
	char choice;
	
	printf("\n- - - - - - - - - - - -\n\n");
	printf("MAIN MENU\n\n");
	printf("P >> Print the inventory list onto the screen.\n");
	printf("A >> Add a new entry.\n");
	printf("C >> Clear all records.\n");
	printf("S >> Create a current report and save to a file.\n");
	printf("D >> Delete an item from the list (inventory).\n");
	printf("U >> Update the store price.\n");
	printf("Q >> Quit the program.\n\n");

	printf("Select an option: ");
	scanf(" %c", &choice);
	choice = toupper(choice);

	//printf("You chose %c", choice); test. toupper works.
	
	return choice;
}

//prints the list of the contents onto the screen
void PrintToScreen(book list[], int count)
{
	int i;

	if (count == 0) printf("\nThere are no records in the inventory.");

	for (i = 0; i < count; i++)
	{
		printf("\n\nAuthor name: %s", list[i].name);
		printf("\nTitle: %s", list[i].title);
		printf("\nID: %d", list[i].id);
		printf("\nNumber of Pages: %d", list[i].pages);
		printf("\nRetail Value: $%.2f", list[i].retailValue);
		printf("\nStore Price: $%.2f", list[i].storePrice);
	}
}

//adds an item to the list
void AddBook(book list[], int count)
{
	//directions
	printf("\n\nPlease enter the book information below.");
	printf("\nPlease omit ALL spaces in book title and author name.");
	printf("\nFor example: Carol Dweck should be registered as CarolDweck.");

	//prompts user for new book information and stores it in last cell of the inventory
	printf("\n\nPlease enter the name of the author: ");
	scanf(" %s", list[count].name);
	printf("Please enter the title of the book: ");
	scanf(" %s", list[count].title);
	printf("Please enter the ID number: ");
	scanf("%d", &list[count].id);
	printf("Please enter the number of pages: ");
	scanf("%d", &list[count].pages);
	printf("Please enter the retail value: ");
	scanf("%lf", &list[count].retailValue);
	printf("Please enter the store price: ");
	scanf( "%lf", &list[count].storePrice);
}

//prints a report to the file
void SaveToFile(book list[], int count)
{
	FILE *outPtr;
	outPtr = fopen("INVENTORY.txt", "w");

	int i;

	for (i = 0; i < count; i++)
	{
		fprintf(outPtr, "Author name: %s\n", list[i].name);
		fprintf(outPtr, "Title: %s\n", list[i].title);
		fprintf(outPtr, "ID: %d\n", list[i].id);
		fprintf(outPtr, "Number of Pages: %d\n", list[i].pages);
		fprintf(outPtr, "Retail Value: $%.2f\n", list[i].retailValue);
		fprintf(outPtr, "Store Price: $%.2f\n", list[i].storePrice);
		fprintf(outPtr, " \n");
	}

	fclose(outPtr);
}

//displays the ids in the list, gets the id from the user and returns it
int DisplayIDs(book list[], int count)
{
	int i;
	int currentid;

	for (i = 0; i < count; i++)
	{
		printf("\nID: %d || Author: %s", list[i].id, list[i].name);
	}

	//user chooses an id
	printf("\nPlease choose an ID: ");
	scanf("%d", &currentid);

	return currentid;
}

//searches the list by id and returns the index if there is a match
//or returns -1 if no match
//three arguments: list, number of items, id
int SearchIDs(book list[], int count, int id)
{
	int i;

	//if there is a match, return the index of the match
	for (i = 0; i < count; i++)
	{
		if (id == list[i].id)
			return i;
	}

	//if there is no match, return -1
	if (id != list[i].id)
		return -1;
}