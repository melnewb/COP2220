//Melissa Newball
//February 11, 2018
//Module 5 Program 4 - interactive program using user defined functions

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //printf, scanf definitions
#define PI 3.14159

//Function prototype
int GetInteger(void) //takes integer and assigns it to radius or length
{
	int value; //user inputs integer
	scanf("%d", &value); //scans for integer
	return value; //integer from function to main p.50
}

int CalculateAreaCir(int radius) //takes radius of the circle and returns the area. Formula: pi * radius * radius
{
	return PI * radius * radius;
}

int CalculatePerimeterSquare(int length) //takes length of the side of the square and returns the perimeter. Formula: length * 4
{
	return length * 4;
}

int main()
{
	//1. Declare variables.
	int radius; //input - radius of a circle
	int length; //input - length of side of a square
	int squarePerimeter; //perimeter of the square
	double circleArea; //area of the circle

	//2 and 3. Greet user, prompt for radius
	printf("Hello and welcome.\n\nFirst we will calculate the area of a circle. Please enter the radius: ");
	radius = GetInteger(); //4. function call p118, integer is assigned to radius

	//5. Pass the radius to the CalculateAreaCir function, that function will calculate the area and return the result, the area will be assigned to the variable circleArea in main
	circleArea = CalculateAreaCir(radius); //6. used #define PI

	//7. Display the radius and area (3 dec points) of the circle onto the screen from the main function
	printf("\nThe radius of the circle is %d and the area is %.3f.\n", radius, circleArea);

	//8. Prompt for the length of a side.
	printf("\nIn order to find the perimeter of a square, please enter the length of a side: ");
	length = GetInteger(); //9. Call GetInteger, integer assigned to length

	//10. Pass to CalculatePerimeterSquare. The Perimeter will be assigned to the squarePerimeter function.
	squarePerimeter = CalculatePerimeterSquare(length);

	//11. Display the side length and perimeter of the square onto the screen.
	printf("The side length is %d and the perimeter of the square is %d.\n\n", length, squarePerimeter);

	return (0);
}