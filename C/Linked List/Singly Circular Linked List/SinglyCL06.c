/*
=====================================================================

Name            : Singly Circular Linked List - Basic Insert Operations
Program Number  : 006

Description     : This program demonstrates the implementation of
                  a Singly Circular Linked List using dynamic
                  memory allocation.

                  The program performs:
                  1. InsertFirst()
                  2. InsertLast()
                  3. Display()

Concepts Used   : Structures,
                  Dynamic Memory Allocation,
                  Pointers,
                  Circular Linked List,
                  Function Calling

Input           : Integer values for insertion

Output          : Nodes displayed in circular format

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
    
    if(first != NULL && last != NULL)
    {
        do
        {
            printf(" |%d| -> ",first -> data);
            first = first -> next;
        }while(first != last -> next);
        printf("\n");
    }
}

int count(PNODE first, PNODE last)
{
    return 0;
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
    
    Display(head,tail);

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);
   
    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);
     
    Display(head,tail);

    return 0;
}

/*
=====================================================================

Sample Output :

|11| -> |21| -> |51| -> |101| -> |111| -> |121| ->

=====================================================================

Notes :

1. 'first' stores the address of the first node.
2. 'last' stores the address of the last node.
3. Last node always points to first node.
4. InsertFirst() inserts a node at the beginning.
5. InsertLast() inserts a node at the end.
6. Display() traverses the list using do-while loop.
7. Traversal stops when control reaches the first node again.

=====================================================================
*/
