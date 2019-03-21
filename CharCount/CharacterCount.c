//File: CharacterCount.c
//Author: Kassim Izuagbe
//Date: 25-January-2019
//Version: 1.3
/* Purpose: This program counts the number of characters in a given file and
			prints it out in a table-like fashion.
*/



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

FILE *infile;
int digitCount, charCount, punCount, otherCount;
char c;
char *str;

int main(int argc, char *argv[])
{
	//If there is more than 1 argument entered, returns EXIT_FAILURE
	if (argc > 2)
	{
		printf("Only one argument is acceptable.\n");
		return EXIT_FAILURE;
	}
	//If no argument is entered, returns EXIT_FAILURE
	else if (argc < 2)
	{
		printf("Please enter an argument.\n");
		return EXIT_FAILURE;
	}

	str=argv[1];

    if ((infile = fopen(str, "r")) == NULL)
    {
    	fprintf(stderr, "File \'%s\' failed to open.\n", str);
    	return EXIT_FAILURE;
    }

    while ((c = fgetc(infile)) != EOF)
    {
    	if (isalpha(c))			//Checks if the character is an alphabetic one
    	{						//and increments its count.
    		charCount++;
    	}
    	else if (isdigit(c))	//Checks if the character is a numeric char
    	{						//and increments its count.
    		digitCount++;
    	}
    	else if (ispunct(c))	//Checks if the character is a punctuation char
    	{						//and increments its count.
    		punCount++;
    	}
    	else					//All other characters are treated as one type,
    	{						//'other' and its count is incremented.
    		otherCount++;
    	}
    }

    if (fclose(infile) == EOF)
    {
    	fprintf(stderr, "File \'%s\' failed to close.\n", str);
    	return EXIT_FAILURE;
    }

	printf("   Item			  Count\n\n");
	printf("Characters		  %d\n", charCount);
	printf("Digits			  %d\n", digitCount);
	printf("Punctuation		  %d\n", punCount);
	printf("Other Chars     	  %d\n", otherCount);

    return 0;
}
