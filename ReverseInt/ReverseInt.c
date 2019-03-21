//File: ReverseInt.c
//Author: Kassim Izuagbe
//Date: 25-January-2019
//Version: 1.7
/* Purpose: This program takes in a number specified by the user and
			prints out the number in reverse.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int num, tempNum;
int rev = 0;		//Number reversed. Initialized to zero.
char number[12];

int main(int argc, char *argv[])
{
	printf("Please type in a positive integer: ");
	do
	{
		scanf("%d", &num);
		if (num < 0)
		{
	    	printf("The number entered in not a positive integer.\n");
	    	printf("Please enter a positive integer: ");
	    	getchar();
		}
	} while (num < 0);

	tempNum = num;
	//converts the integer, num, to a string, number (of base 10).
	while (tempNum != 0)
	{
		int rem = tempNum % 10;
		rev = (rev * 10) + rem;
		tempNum /= 10;
	}

	printf("You entered: %d\n", num);
	printf("This number in reverse is: %d\n", rev);

    return 0;
}
