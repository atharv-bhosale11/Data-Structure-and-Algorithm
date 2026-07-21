/*
=====================================================================

Name            : Singly Circular Linked List - Count Operation
Program Number  : 007

Description     : This program demonstrates the implementation
                  of Count() function in a Singly Circular
                  Linked List.

                  The program performs:
                  1. InsertFirst()
                  2. InsertLast()
                  3. Display()
                  4. Count()

Concepts Used   : Structures,
                  Dynamic Memory Allocation,
                  Circular Linked List,
                  Traversal,
                  Node Counting

Input           : Integer values for insertion

Output          : Displays all nodes and total number
                  of nodes present in the linked list

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
*/

// Singly Circular Linked List

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE first, PNODE last)
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    do
    {
        printf(" |%d| -> ",first -> data);
        first = first -> next;
    }while(first != last -> next);
    printf("\n");
}


int count(PNODE first, PNODE last)
{
    int iCount = 0;
    if(first == NULL && last == NULL)
    {
        return iCount;
    }

    do
    {
        iCount++;
        first = first -> next;
    }while(first != last -> next);
    
    return iCount;
}

void InsertFirst(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn -> next = *first;
        *first = newn;
    }
    (*last) -> next = *first;
}

void InsertLast(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last) -> next = newn;
        *last = (*last) -> next;
    }
    (*last) -> next = *first;
}

void InsertAtPos(PPNODE first, PPNODE last, int iPos, int iNo)
{}

void DeleteFirst(PPNODE first, PPNODE last)
{}

void DeleteLast(PPNODE first, PPNODE last)
{}

void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
{}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;
    
    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);
   
    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);
     
    Display(head,tail);

    iRet = count(head,tail);
    printf("Number of Nodes are: %d",iRet);

    return 0;
}

/*
=====================================================================

Sample Output :

|11| -> |21| -> |51| -> |101| -> |111| -> |121| ->

Number of Nodes are: 6

=====================================================================

Notes :

1. Count() traverses the complete circular list.
2. A do-while loop is used for traversal.
3. Traversal stops when the first node is reached again.
4. Count variable is incremented for every node visited.
5. Returns total number of nodes present in the list.

=====================================================================
*/
