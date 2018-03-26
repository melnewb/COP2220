//Melissa Newball
//March 19, 2018
//Interactive program using loops and user defined functions with pass by references and pass by copy arguments

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //printf, scanf definitions

//FUNCTION PROTOTYPES

//takes integer and assigns it to radius or length
int GetInteger(void);

//takes one integer argument and two integer pointer arguments
//1. calculate the area of the square and store the result in areaPtr
//2. calculate the perimeter of the square and store the result in perimeterPtrj
void CalculateBothSquare(int side, int *areaPtr, int *perimeterPtr);

int main()
{
	int number; //user input - used for sum and product of squares
	int sumTotal = 0; //sum total of squares
	int productTotal = 1; //product total of squares
	int i; //numbers 1 - num1
	int length; //part 2
	int squareArea; //part 2
	int squarePerimeter; //part 2

	//PART 1

	printf("PART 1\n");
	
	number = GetInteger();
	//Calculating sum total of squares with a for loop
	for (i = 1; i <= number; i++) {
		sumTotal = sumTotal + (i * i);
	}

	//Calculating product total of squares with a while loop
	i = 1; //initialize
	while (i <= number) { //condition
		productTotal = productTotal * (i * i); //update
		i++;
	}

	printf("\nThe sum total is %d and the product total is %d.\n", sumTotal, productTotal);

	//PART 2
	printf("\nPART 2\nYou will be entering the length of the side of a square:\n");
	length = GetInteger();

	CalculateBothSquare(length, &squareArea, &squarePerimeter);  //length is pass by copy and squareArea and squarePerimeter is pass by reference

	printf("\nThe calculation results back inside the main function:\n");
	printf("The area is %d and the perimeter is %d.\n", squareArea, squarePerimeter);

}

//FUNCTION DEFINITIONS
int GetInteger(void) //takes integer and assigns it to radius or length
{
	int value; //user inputs integer
	printf("Enter an integer:"); //Get integer from user.
	scanf("%d", &value); //scans for integer
	return value; //integer from function to main
}

//takes one integer argument and two integer pointer arguments
//1. calculate the area of the square and store the result in areaPtr
//2. calculate the perimeter of the square and store the result in perimeterPtr
void CalculateBothSquare(int side, int *areaPtr, int *perimeterPtr)
{
	//Calculate the area and store the result in the "value at" areaPtr
	*areaPtr = side * side;

	//Calculate the perimeter and store the result in the "value at" perimeterPtr
	*perimeterPtr = 4 * side;

	printf("\nInside the CalculateBothSquare function\n");
	printf("The calculation results inside the CalculateBothSquare function:\n");
	printf("The area is %d and the perimeter is %d.\n", *areaPtr, *perimeterPtr);
}