// File: Stack.c
// Author: Kassim Izuagbe
// Date: 26-February-2019
// File Version: 2.7
/* Purpose: This program is a stack data structure. Values can be "pushed" onto
            or "popped" off the stack.
 */

#include <stdlib.h>
#include <stdio.h>

int size = 5;           //initial stack size
int position = 0;          //"points to" where the top of the stack is
int *ptr;               //pointer

void push(int n);
int pop();
void quit();

void push(int n)
{
    if (position+1 >= size)
    {
        size *= 2;
        ptr = realloc(ptr, size * sizeof(int));
        printf("Increasing the stack size from %d to %d...\n", size/2, size);
    }

    ptr[position] = n;
    position++;
    printf("\n%d has been pushed onto the stack\n\n", n);
}

int pop()
{
    int popped;
    position--;
    if (position <= (size/4))
    {
        if (size%2 == 0)
        {
            size /= 2;
            ptr = realloc(ptr, size * sizeof(int));
            printf("Decreasing the stack size from %d to %d...\n", size*2, size);
        }
        else if (size%2 == 1)
        {
            size /= 2;
            ptr = realloc(ptr, size * sizeof(int));
            printf("Decreasing the stack size from %d to %d...\n", (size*2)+1, size);
        }
    }
    popped = ptr[position];
    ptr[position] = 0;

    printf("\n%d has been popped off the stack\n\n", popped);

    return popped;
}

void quit()
{
    free(ptr);
    ptr = NULL;
    printf("Quitting...\n\n");
}

int main()
{
    int select, value, top;

    ptr = (int*) malloc(size * sizeof(int));

    do
    {
        printf("Select one by entering the corresponding number: \n");
        printf("1. Push a value onto the stack\n");
        printf("2. Pop a value off the stack\n");
        printf("3. Quit\n\n");

        scanf("%d", &select);

        switch(select)
        {
            case 1:
            {
                printf("Enter the value being pushed onto the stack: ");
                scanf("%d", &value);
                push(value);
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                quit();
                break;
            }
        }
    }while (select > 0 && select < 3);

    top = ptr[position-1];       //value of the item at the top of the stack

    return 0;
}
