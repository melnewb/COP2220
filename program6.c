//Melissa Newball
//April 2, 2018
//Module 9 Program 6: interactive program with loops, user-defined functions, arrays, and input and output file processing.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//use 3 user-defined functions to break up the program

//FUNCTION PROTOTYPES

//use a loop to read the integers into the array from the input file (fscanf)
void arrayFile(int* txtnum, FILE *inPtr);

//use a loop to print the array onto the screen in a column
void arrayColumn(int *txtnum);

//use a loop to add up all the items in the array and store the sum
void arraySum(int *txtnum, FILE *outPtr);

//use a loop to locate the largest integer in the array and store the largest value
void arrayLarge(int *txtnum, FILE *outPtr);

int main()
{
	int txtnum[15]; //declare array of integers of size 15
	//int i;
	FILE *inPtr;
	FILE *outPtr;

	//open numInput to read
	inPtr = fopen("numInput.txt", "r");
	outPtr = fopen("resOut.txt", "w");

	//read the integers into the array from the input file
	arrayFile(txtnum, inPtr);

	//print the array onto the screen in a column
	arrayColumn(txtnum);

	//add up all the items in the array and store the sum
	arraySum(txtnum, outPtr);

	//locate the largest integer in the array and store the largest value
	arrayLarge(txtnum, outPtr);

}

//FUNCTION DEFINITIONS

//use a loop to read the integers into the array from the input file (fscanf)
void arrayFile (int* txtnum, FILE *inPtr)
{
	int i;
	
	for (i = 0; i < 15; i++)
	{
		fscanf(inPtr, "%d", &txtnum[i]);
	}
}

//use a loop to print the array onto the screen in a column
void arrayColumn(int *txtnum)
{
	int i;

	for (i = 0; i < 15; i++)
	{
		printf("%d\n", txtnum[i]);
	}
}

//use a loop to add up all the items in the array and store the sum
void arraySum(int *txtnum, FILE *outPtr)
{
	int i;
	int sum;
	sum = 0;

	for (i = 0; i < 15; i++)
	{
		sum += txtnum[i];
	}

	//printf("Test. Sum is %d", sum); Test. Works. Sum is 684.

	//print to numOutput
	fprintf(outPtr, "Sum is %d", sum);
}

//use a loop to locate the largest integer in the array and store the largest value
void arrayLarge(int *txtnum, FILE *outPtr)
{
	int i;
	int bigNum;
	bigNum = txtnum[0];

	for (i = 1; i < 15; i++)
	{
		if (bigNum < txtnum[i])
			bigNum = txtnum[i];
	}

	//printf("The largest integer in the array is %d", bigNum); test. works.
	
	fprintf(outPtr, "\n\nThe largest integer in the array is %d", bigNum);
}