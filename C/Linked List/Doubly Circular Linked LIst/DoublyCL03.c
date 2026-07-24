/*
=====================================================================

Name            : Doubly Circular Linked List - InsertFirst
Program Number  : 003

Description     : This program demonstrates insertion of
                  nodes at the beginning and end of a
                  Doubly Circular Linked List.

Concepts Used   : Dynamic Memory Allocation,
                  Doubly Circular Linked List,
                  InsertFirst,
                  InsertLast,
                  Circular Linking

Input           : Node data

Output          : Displays linked list after insertions

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
    if(first == NULL && last == NULL)
    {
        return;
    }

    printf("<=> ");

    do
    {
        printf("|%d| <=> ",first->data);
        first = first->next;
    }while(first != last->next);

    printf("\n");
}

void InsertFirst(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
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

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
      
    }

    (*last)->next = *first;
    (*first)->prev = *last;
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

    Display(head,tail);

    return 0;
}

/*
=====================================================================

Sample Output :

<=> |11| <=> |21| <=> |51| <=> |101| <=> |111| <=> |121| <=>

=====================================================================

Functions Implemented :

1. Display()
2. InsertFirst()
3. InsertLast()

=====================================================================

Notes :

1. InsertFirst inserts node at beginning.
2. InsertLast inserts node at end.
3. next pointer of last node points to first node.
4. prev pointer of first node points to last node.
5. Circular structure is maintained after every insertion.

=====================================================================
End of Program
=====================================================================
*/
