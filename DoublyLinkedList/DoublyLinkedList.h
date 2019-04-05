#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H


typedef struct
{
    char name[50];
    int age;
}*Datatype;

typedef struct Node
{
    int number;
    struct Node *next;  //pointer to next node
    struct Node *prev;  //pointer to previous node
    Datatype dt;
}NodeT, *NodeTP;

typedef struct
{
    NodeTP head;
    NodeTP tail;
    int numItems;
    int maxValue;
}ListT, *ListTP;

int addToFront(ListTP this, int value, Datatype data); //add a value to the head
int addToEnd(ListTP this, int value, Datatype data);  //add a value to the tail
void traverseList(ListTP this);     //traverse & print the list in normal order
void traverseListReverse(ListTP this);  //same as above, but in reverse
void printMax(ListTP this); //As the name implies, the max value is printed
void deleteHeadNode(ListTP this);   //Deletes the head node
void deleteTailNode(ListTP this);   //Deletes the tail node
void deleteMaxNode(ListTP this);    //Deletes the node containing the max value

#endif
