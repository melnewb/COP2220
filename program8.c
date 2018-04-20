//Melissa Newball
//April 20, 2018
//Create a program with user defined structure types

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#define SIZE 20

typedef struct {
	char author[SIZE];
	char bookName[SIZE];
	int pageNum;
	double cost;
}book;

//Function Prototypes

// fills the data fields of a card instance
//returns the filled card 
book FillBook();

//fills the data fields of a card instance
//by reference using a pointer to a card
void FillBookPtr(book *bookptr);

//fills an array of cards
void FillBookArray(book arrayB[], int *size);


//displays one card
void DisplayBook(book anyBook);

int main()
{

	//Declare variables
	book myBook, myBook1, myBook2;
	book manyBooks[SIZE];
	int bSize;
	int i;

	//Fill structures with a function
	myBook = FillBook();
	myBook1 = FillBook();

	//print using display function
	printf("\n---------Display myBook\n");
	DisplayBook(myBook);

	printf("\n---------Display myBook1\n");
	DisplayBook(myBook1);

	//Fill structure using pointers and dispay it
	FillBookPtr(&myBook2);
	printf("\n---------Display myBook2\n");
	DisplayBook(myBook2);

	//Fill the array with the function
	printf("\n---------Fill array manyBooks\n");
	FillBookArray(manyBooks, &bSize);

	//display an array of books
	printf("\n---------Display array manyBooks\n");
	for (i = 0; i<bSize; i++)
	{
		DisplayBook(manyBooks[i]);
	}

	return 0;
}

//Function Definitions


// fills the data fields of a book instance
//returns the filled book info 
book FillBook()
{
	//Declare local variables
	book tempB;
	//prompt and get information
	printf("\nplease enter the author of the book:  ");
	scanf("%s", tempB.author);
	//print to check
	printf("author:  %s\n", tempB.author);

	//prompt and get information
	printf("\nplease enter the title of the book:  ");
	scanf("%s", tempB.bookName);
	//print to check
	printf("title: %s\n", tempB.bookName);

	//prompt and get information
	printf("\nplease enter the number of pages of the book:  ");
	scanf("%d", &tempB.pageNum);
	printf("number of pages: %d\n", tempB.pageNum);

	//prompt and get information
	printf("\nplease enter the price of the book:  ");
	scanf("%lf", &tempB.cost);
	//print to check
	printf("price: %.2f\n", tempB.cost);

	return tempB;
}



//displays one book
void DisplayBook(book anyBook)
{
	printf("\n\nauthor:  %s\n", anyBook.author);
	printf("title:  %s\n", anyBook.bookName);
	printf("number of pages:  %d\n", anyBook.pageNum);
	printf("price: %.2f\n", anyBook.cost);
}    


//fills the data fields of a book
//by reference using a pointer to a book
void FillBookPtr(book *bookptr)
{
	//prompt and get information
	printf("\nplease enter the author of the book:  ");
	scanf("%s", (*bookptr).author);

	//prompt and get information
	printf("\nplease enter the title of the book:  ");
	scanf("%s", bookptr->bookName);

	//prompt and get information
	printf("\nplease enter the number of pages of the book:  ");
	scanf("%d", &(*bookptr).pageNum);

	//prompt and get information
	printf("\nplease enter the price of the book:  ");
	scanf("%lf", &(*bookptr).cost);
}




//fills an array of book info
void FillBookArray(book arrayB[], int *size)
{
	int i;
	//prompt the user
	printf("\nenter the number of books:  ");
	scanf("%d", size);

	//print to check
	printf("size:  %d\n", *size);

	for (i = 0; i < *size; i++)
	{
		printf("enter author:  ");
		scanf("%s", arrayB[i].author);

		printf("enter title:  ");
		scanf("%s", arrayB[i].bookName);

		printf("enter the number of pages:  ");
		scanf("%d", &arrayB[i].pageNum);

		printf("enter the price:  ");
		scanf("%lf", &arrayB[i].cost);
	}
}
