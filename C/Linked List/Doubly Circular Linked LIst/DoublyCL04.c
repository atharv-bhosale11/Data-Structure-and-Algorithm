/*
=====================================================================

Name            : Doubly Circular Linked List - InsertLast
Program Number  : 004

Description     : This program demonstrates insertion of
                  nodes at the beginning and end of a
                  Doubly Circular Linked List.

                  The list maintains circular links
                  using both next and prev pointers.

Concepts Used   : Doubly Circular Linked List,
                  Dynamic Memory Allocation,
                  InsertFirst,
                  InsertLast,
                  Pointer Manipulation

Input           : Node data

Output          : Linked List after insertion operations

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
*/

// Doubly Circular Linked List

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE first, PNODE last)
{

}

int Count(PNODE first, PNODE last)
{
    return 0;
}

void InsertFirst(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn -> next = *first;
        (*first)->prev = newn;
        *first = newn;
    }

    (*last)->next = *first;
    (*first)->prev = *last;
}

void InsertLast(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last)->next = newn;
        newn->prev = *last;
        *last = newn;
    }

    (*last)->next = *first;
    (*first)->prev = *last;
}

void InsertAtPos(PPNODE first, PPNODE last, int iNo, int iPos)
{

}

void DeleteFirst(PPNODE first, PPNODE last)
{

}

void DeleteLast(PPNODE first, PPNODE last)
{

}

void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
{

}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);

    return 0;
}

/*
=====================================================================

Sample Output :

Nodes inserted successfully in the
Doubly Circular Linked List.

=====================================================================

Functions Implemented :

1. InsertFirst()
2. InsertLast()

Pending Functions :

1. Display()
2. Count()
3. InsertAtPos()
4. DeleteFirst()
5. DeleteLast()
6. DeleteAtPos()

=====================================================================

Notes :

1. InsertFirst inserts a node at the beginning.
2. InsertLast inserts a node at the end.
3. last->next always points to first.
4. first->prev always points to last.
5. Circular doubly linked structure is maintained
   after every insertion.

=====================================================================
End of Program
=====================================================================
*/
```
