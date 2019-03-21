// File: ManipulateMemory.c
// Author: Kassim Izuagbe
// Date: 23-February-2019
// File Version: 1.3
/* Purpose: A program that allows the user to:
        1. Allocate a  block of memory to store a specified number of integers
        2. Store a value at a specified index of the allocated block of memory
        3. Get the value store at the specified index of the memory block
        Memory is freed after the above instructions are carried out.
 */

#include <stdio.h>
#include <stdlib.h>

int* allocate(int n);
void set (int *b, int index, int number);
int get(int *b, int index);

//int *ptr;

int* allocate(int n)
{
    int *ptr;

    ptr = (int*) malloc(n * sizeof(int));
    return ptr;
}

void set(int *b, int index, int number)
{
    b[index] = number;
}

int get(int *b, int index)
{
    int value;

    value = b[index];
    return value;
}

int main()
{
    int select, num, *mem_adrss, index, value;

    mem_adrss = NULL;

    do
    {
        printf("Select one: \n");
        printf("1. Allocate memory\n");
        printf("2. Set value (number) at memory address\n");
        printf("3. Get value stored at memory address\n");
        printf("4. Quit\n");
        printf("\n");

        scanf("%d", &select);

        //printf("Enter a number between 1 and 4!\n");

        switch (select)
        {
            case 1:
            {
                printf("Enter the number of integers to be stored: ");
                scanf("%d", &num);
                mem_adrss = allocate(num);
                if (mem_adrss != NULL)
                    printf("\nMemory has been allocated!\n\n");
                else if (mem_adrss == NULL)
                    printf("Something went wrong with the memory allocation\n");
                break;
            }
            case 2:
            {
                if (mem_adrss == NULL)
                {
                    printf("(You should allocate some memory first.)\n\n");
                    break;
                }

                printf("Enter the value (number) to be stored: ");
                scanf("%d", &value);
                printf("\nEnter an index (0-%d) at which to store the value: ",
                        (num-1));
                scanf("%d", &index);
                set(mem_adrss, index, value);
                printf("\nValue has been stored!\n\n");
                break;
            }
            case 3:
            {
                if (mem_adrss == NULL)
                {
                    printf("(You should allocate some memory first.)\n\n");
                    break;
                }

                printf("Enter an index from which a value will be returned: ");
                scanf("%d", &index);
                value = get(mem_adrss, index);
                printf("\nThe value stored at index %d is: %d\n\n",
                        index, value);
                break;
            }
            case 4:
            {
                if (mem_adrss != NULL)
                {
                    free(mem_adrss);
                    mem_adrss = NULL;
                    printf("Memory has been freed.\n");
                }
                printf("Quitting...\n");
                break;
            }
        }
    }while (select > 0 && select < 4);
    return 0;
}
