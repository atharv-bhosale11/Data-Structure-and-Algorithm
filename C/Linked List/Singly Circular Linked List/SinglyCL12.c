/*
=====================================================================

Name            : Singly Circular Linked List - DeleteAtPos Operation
Program Number  : 012

Description     : This program demonstrates the implementation
                  of DeleteAtPos() operation in a Singly
                  Circular Linked List.

                  The program performs:
                  1. InsertFirst()
                  2. InsertLast()
                  3. InsertAtPos()
                  4. DeleteFirst()
                  5. DeleteLast()
                  6. DeleteAtPos()
                  7. Display()
                  8. Count()

Concepts Used   : Structures,
                  Dynamic Memory Allocation,
                  Circular Linked List,
                  Position-Based Deletion,
                  Pointer Manipulation

Input           : Integer values and position

Output          : Displays the linked list after
                  deleting a node from a specified
                  position

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
        return;
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
    PNODE newn = NULL;
    PNODE temp = NULL;
    PNODE target = NULL;
    int iCount = 0;
    int i = 0;

    iCount = count(*first,*last);

    if(iPos < 1 || iPos > iCount)
    {
        printf("Invalid Positions");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(iPos == iCount)
    {
        DeleteLast(first,last);
    }
    else
    {
        temp = *first;

        for(i = 1; i < iPos - 1 ; i++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp -> next = target -> next;
        free(target);
    } 
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

    DeleteAtPos(&head,&tail,4);
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

|21| -> |51| -> |101| -> |111| ->
Number of Nodes are: 4

|21| -> |51| -> |101| -> |105| -> |111| ->
Number of Nodes are: 5

|21| -> |51| -> |101| -> |111| ->
Number of Nodes are: 4

=====================================================================

Functions Implemented :

1. Display()
2. Count()
3. InsertFirst()
4. InsertLast()
5. InsertAtPos()
6. DeleteFirst()
7. DeleteLast()
8. DeleteAtPos()

=====================================================================

Notes :

1. DeleteAtPos() removes a node from a specified position.
2. Position validation is performed before deletion.
3. DeleteFirst() is called for position 1.
4. DeleteLast() is called for the last position.
5. Middle node deletion is handled separately.
6. Circular linkage remains intact after deletion.

=====================================================================
*/
