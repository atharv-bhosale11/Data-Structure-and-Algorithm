/*
=====================================================================

Name            : Singly Circular Linked List - Display Operation
Program Number  : 005

Description     : This program demonstrates the Display()
                  function of a Singly Circular Linked List.

                  Nodes are inserted using InsertFirst()
                  and InsertLast() operations and then
                  displayed using circular traversal.

Concepts Used   : Structure,
                  Dynamic Memory Allocation,
                  Circular Linked List,
                  InsertFirst,
                  InsertLast,
                  Display Function

Input           : Node data

Output          : Displays all nodes of the
                  Singly Circular Linked List

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

Program Summary :

-> Created Singly Circular Linked List
-> Implemented InsertFirst operation
-> Implemented InsertLast operation
-> Implemented Display operation
-> Traversed nodes using circular traversal
-> Maintained circular connection between
   first and last nodes

=====================================================================
*/
