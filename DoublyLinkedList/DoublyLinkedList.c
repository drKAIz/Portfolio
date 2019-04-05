//File: DoublyLinkedList.c
//Author: Kassim Izuagbe;
//Date: 5-April-2019
//Version: 5.7
/* Purpose: This program is an implementation of a Doubly linked list. Values
            can be added and removed at the head or tail node. THe largest
            number in the list is kept track of, as well as the number of nodes.
*/

#include <stdlib.h>
#include <stdio.h>
#include "DoublyLinkedList.h"

int addToFront(ListTP this, int value, Datatype data)
{
    NodeTP node;

    if ((this->head) == NULL)       //Check if list is empty
    {
        if ((node = malloc(sizeof(NodeTP))) == NULL)
        {
            printf("Memory could not be allocated for this action.\n\n");
            return 0;
        }
        this->head = node;
        node->next = NULL;
        this->tail = node;
    }
    else
    {
        this->head->prev = node;
        node->next = this->head;
        this->head = node;
    }

    node->prev = NULL;
    node->number = value;
    (this->numItems)++;

    if (((this->maxValue) == 0) || ((this->maxValue) <= (node->number)))
        this->maxValue = node->number;

    node->dt = data;

    return 1;
}

int addToEnd(ListTP this, int value, Datatype data)
{
    int verdict;
    if (this->head == NULL)     //Check if list is empty
    {
        if ((verdict = addToFront(this, value, data)) == 1)
            return 1;
        else
            return 0;
    }

    NodeTP node;

    if ((node = malloc(sizeof(NodeTP))) == NULL)
        return 0;

    this->tail->next = node;
    node->next = NULL;
    node->prev = this->tail;
    this->tail = node;

    node->number = value;
    (this->numItems)++;
    if ((this->maxValue) <= (node->number)) //If the value being added is
        this->maxValue = node->number;     //greater than the current maxValue
                                         //then the value added becomes maxValue
    node->dt = data;

    return 1;
}

void traverseList(ListTP this)
{
    NodeTP nowNode;
    if ((nowNode = malloc(sizeof(NodeTP))) == NULL)
    {
        printf("Memory could not be allocated for this action.\n\n");
        return;
    }

    int tempCounter = 1;
    printf("The linked list contains these values: \n");
    for (nowNode = this->head; nowNode !=NULL; nowNode = nowNode->next)
    {
        printf("Node %d contains: %d\n", tempCounter, nowNode->number);
        tempCounter++;
    }
    printf("\n");

    free(nowNode);
    nowNode = NULL;
}

void traverseListReverse(ListTP this)
{
    NodeTP nowNode;
    if ((nowNode = malloc(sizeof(NodeTP))) == NULL)
    {
        printf("Memory could not be allocated for this action.\n\n");
        return;
    }

    printf("The linked list contains these values, in reverse order: \n");
    int tempCounter = this->numItems;
    for (nowNode = this->tail; nowNode !=NULL; nowNode = nowNode->prev)
    {
        printf("Node %d contains: %d\n", tempCounter, nowNode->number);
        tempCounter--;
    }
    printf("\n");

    free(nowNode);
    nowNode = NULL;
}

void printMax(ListTP this)
{
    printf("The max value in this linked list is: %d\n\n", (this->maxValue));
}

void deleteHeadNode(ListTP this)
{
    if ((this->head) == NULL)       //Check if list is empty
    {
        printf("The list is empty!");
        return;
    }

    if ((this->head) == (this->tail))   //Check if there is only 1 node
    {
        char YOrN;
        printf("Warning: There is only one node in the list! \n");
        printf("Remove anyway? (Y/N)\n\n");
        YOrN = getchar();

        if (YOrN == 'Y' || YOrN == 'y')
        {
            free(this->head);
            this->head = NULL;
            this->maxValue = 0;
            (this->numItems)--;
        }
        else if (YOrN =='N' || YOrN =='n')
        {
            return;
        }
    }

    if ((this->maxValue) == (this->head->number))
    {
        NodeTP nowNode;
        nowNode = malloc(sizeof(NodeTP));
        int tempMaxNum = this->head->next->number;
        for (nowNode = this->head->next; nowNode !=NULL; nowNode = nowNode->next)
        {
            if (tempMaxNum <= (nowNode->number))
                tempMaxNum = nowNode->number;
        }

        this->maxValue = tempMaxNum;
        free(nowNode);
        nowNode = NULL;
    }

    this->head = this->head->next;
    free(this->head->prev);
    this->head->prev = NULL;

    (this->numItems)--;
}

void deleteTailNode(ListTP this)
{
    if ((this->head) == NULL)       //Check if list is empty
    {
        printf("The list is empty!");
        return;
    }

    if ((this->head) == (this->tail))   //Check if there is only 1 node
    {
        char YOrN;
        printf("Warning: There is only one node in the list! \n");
        printf("Remove anyway? (Y/N)\n\n");
        YOrN = getchar();

        if (YOrN == 'Y' || YOrN == 'y')
        {
            free(this->tail);
            this->tail = NULL;
            this->maxValue = 0;
            (this->numItems)--;
            return;
        }
        else if (YOrN =='N' || YOrN =='n')
        {
            return;
        }
    }

    if ((this->maxValue) == (this->tail->number))
    {
        NodeTP nowNode;
        nowNode = malloc(sizeof(NodeTP));
        int tempMaxNum = this->tail->prev->number;
        for (nowNode = this->tail->prev; nowNode !=NULL; nowNode = nowNode->prev)
        {
            if (tempMaxNum <= (nowNode->number))
                tempMaxNum = nowNode->number;
        }

        this->maxValue = tempMaxNum;
        free(nowNode);
        nowNode = NULL;
    }

    this->tail = this->tail->prev;
    free(this->tail->next);
    this->tail->next = NULL;

    (this->numItems)--;
}

void deleteMaxNode(ListTP this)
{
    if ((this->head) == NULL)       //Check if list is empty
    {
        printf("The list is empty!");
        return;
    }

    if ((this->head) == (this->tail))   //Check if there is only 1 node
    {
        char YOrN;
        printf("Warning: There is only one node in the list! \n");
        printf("Remove anyway? (Y/N)\n\n");
        YOrN = getchar();

        if (YOrN == 'Y' || YOrN == 'y')
        {
            free(this->head);
            this->tail = NULL;
            this->head = NULL;
            this->maxValue = 0;
            (this->numItems)--;
            return;
        }
        else if (YOrN =='N' || YOrN =='n')
        {
            return;
        }
    }
    NodeTP nowNode;
    for (nowNode = this->head; nowNode !=NULL; nowNode = nowNode->next)
    {
        if ((this->maxValue) == (nowNode->number))
        {
            nowNode->prev->next = nowNode->next;
            nowNode->next->prev = nowNode->prev;
            free(nowNode);
            nowNode = NULL;
            break;
        }
    }
    (this->numItems)--;
    for (nowNode = this->head; nowNode !=NULL; nowNode = nowNode->next)
    {
        if((this->maxValue) <= (nowNode->number))  //find the new maxValue
            this->maxValue = nowNode->number;
    }
}
