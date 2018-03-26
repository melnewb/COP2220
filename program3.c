//Melissa Newball
//February 5, 2018
//Module 4, Program 3 - Calculate the area and circumference of a circle and the area of a square.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //printf and scanf functions
#define PI 3.14159

int main() {
	double radius;		//input - radius of a circle
	double areaCircle;	//output - area of a circle
	double circCircle;	//output - circumference of a circle
	double sideLength;	//input - length of side of a square
	double areaSquare;	//output - area of a square

	//Circle - Find radius
	printf("Enter the radius of the circle. \n");
	scanf("%lf", &radius);

	//Circle - Calculate the area
	areaCircle = PI * radius * radius;

	//Circle - Calculate the circumference
	circCircle = 2 * PI * radius;

	//Display the area and circumference
	printf("The radius of the circle is %.3f\n", radius);
	printf("The area of the circle is %.3f\n", areaCircle);
	printf("The circumference of the circle is %.3f\n", circCircle);

	//Square - Find length of side
	printf("\nEnter the length of the side of the square. \n");
	scanf("%lf", &sideLength);

	//Square - Calculate the area
	areaSquare = sideLength * sideLength;

	//Square - Display the area of the square
	printf("The side length of the square is %.1f\n", sideLength);
	printf("The area of the square is %.1f\n", areaSquare);

	return (0);
}