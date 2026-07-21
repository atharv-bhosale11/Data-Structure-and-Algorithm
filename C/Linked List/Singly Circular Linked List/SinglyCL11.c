/*
=====================================================================

Name            : Singly Circular Linked List - InsertAtPos and
                  DeleteLast Operations
Program Number  : 011

Description     : This program demonstrates the implementation
                  of InsertAtPos() and DeleteLast() operations
                  in a Singly Circular Linked List.

                  The program performs:
                  1. InsertFirst()
                  2. InsertLast()
                  3. InsertAtPos()
                  4. DeleteFirst()
                  5. DeleteLast()
                  6. Display()
                  7. Count()

Concepts Used   : Structures,
                  Dynamic Memory Allocation,
                  Circular Linked List,
                  Node Insertion,
                  Node Deletion,
                  Position-Based Operations

Input           : Integer values and position

Output          : Displays the linked list after various
                  insertion and deletion operations

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
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCount = 0;
    int i = 0;

    iCount = count(*first,*last);

    if(iPos < 1 || iPos > iCount + 1)
    {
        printf("Invalid Positions");
    }

    if(iPos == 1)
    {
        InsertFirst(first,last,iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(first,last,iNo);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = iNo;
        newn -> next = NULL;

        temp = *first;
        
        for(i = 1 ; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }
        
        newn -> next = temp -> next;
        temp -> next = newn;
    }
}

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
        PNODE temp = NULL;
        
        temp = *first;

        while(temp -> next != *last)
        {
            temp = temp -> next;
        }
        free(*last);                        // also write free(temp -> next);
        *last = temp;

        (*last) -> next = *first;
    }
}

void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
{
    
}

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

    DeleteLast(&head,&tail);
    Display(head,tail);
    iRet = count(head,tail);
    printf("Number of Nodes are: %d\n",iRet);

    InsertAtPos(&head,&tail,4,105);
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

|21| -> |51| -> |101| -> |111| ->
Number of Nodes are: 4

|21| -> |51| -> |101| -> |105| -> |111| ->
Number of Nodes are: 5

=====================================================================

Functions Implemented :

1. Display()
2. Count()
3. InsertFirst()
4. InsertLast()
5. InsertAtPos()
6. DeleteFirst()
7. DeleteLast()

=====================================================================

Notes :

1. InsertAtPos() inserts a node at the specified position.
2. DeleteLast() removes the last node from the list.
3. First and Last pointers are updated whenever required.
4. Circular linkage is maintained after every operation.
5. Position validation is performed before insertion.
6. Traversal is done using a do-while loop.

=====================================================================
*/

