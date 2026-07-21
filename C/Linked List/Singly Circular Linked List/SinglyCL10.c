/*
=====================================================================

Name            : Singly Circular Linked List - DeleteFirst Operation
Program Number  : 010

Description     : This program demonstrates the implementation
                  of DeleteFirst() operation in a Singly
                  Circular Linked List.

                  The program performs:
                  1. InsertFirst()
                  2. InsertLast()
                  3. Display()
                  4. Count()
                  5. DeleteFirst()

Concepts Used   : Structures,
                  Dynamic Memory Allocation,
                  Circular Linked List,
                  Node Deletion,
                  Pointer Manipulation

Input           : Integer values for insertion

Output          : Displays the linked list before and
                  after deleting the first node

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
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first) -> next;

        free((*last) -> next);                      // without "temp" variable

        (*last) -> next = *first;
    }   
}

void DeleteLast(PPNODE first, PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        
    }
}

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
    printf("Number of Nodes are: %d\n",iRet);

    DeleteFirst(&head,&tail);
    Display(head,tail);
    iRet = count(head,tail);
    printf("Number of Nodes are: %d\n",iRet);

    return 0;
}

/*
=====================================================================

Sample Output :

|11| -> |21| -> |51| -> |101| -> |111| -> |121| ->
Number of Nodes are: 6

|21| -> |51| -> |101| -> |111| -> |121| ->
Number of Nodes are: 5

=====================================================================

Functions Implemented :

1. Display()
2. Count()
3. InsertFirst()
4. InsertLast()
5. DeleteFirst()

=====================================================================

Notes :

1. DeleteFirst() removes the first node from the list.
2. Handles empty list condition.
3. Handles single node condition.
4. Updates first pointer to the next node.
5. Updates last->next to maintain circularity.
6. Circular linked list structure remains intact.

=====================================================================
*/
