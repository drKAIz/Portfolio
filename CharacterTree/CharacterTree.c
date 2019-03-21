//File: CharacterTree.c
//Author: Kassim Izuagbe
//Date: 1-February-2019
//Version: 2.1
/* Purpose: This program takes a character and an integer and prints the
			character: In a left-justified "tree" that is upside down,
			a centered "tree" that is upside down, and
			a centered "tree" that is right-side up.
*/


#include <stdio.h>
#include <stdlib.h>

FILE *infile;
char ch;
int num, k, i, j, space;

int main()
{
	printf("Please enter a single character (i.e. 'A', '5', '!', 'q'):\n");
	ch = getchar();
	printf("Please enter an integer: \n");
	scanf("%d", &num);

	printf("\n");
	for (k = num; k > 0; k--)
	{
		for (i = 0; i < k; i++)
		{
			putchar(ch);
		}
		printf("\n");
	}
	printf("\n");

	space = 0;
	for (k = num; k > 0; k-=2)
	{
	    for (i = 0; i < k; i++)
	    {
			putchar(ch);
		}
		printf("\n");
		space++;
		for (j = 0; j < space; j++)
		{
		    printf(" ");
		}
	}
	printf("\n");

	if (num%2 == 1)
	{
	    for (k = 1; k <= num; k+=2)
		{
		    space--;
		    for (j = space; j > 0; j--)
			{
			    printf(" ");
			}
			for (i = 0; i < k; i++)
			{
				putchar(ch);
			}
			printf("\n");
		}
	}
	else
	{
	    for (k = 2; k <= num; k+=2)
	    {
		    space--;
		    for (j = space; j > 0; j--)
		    {
			    printf(" ");
		    }

		    for (i = 0; i < k; i++)
		    {
			    putchar(ch);
		    }
		    printf("\n");
	    }
	}
	printf("\n");

    return 0;
}
