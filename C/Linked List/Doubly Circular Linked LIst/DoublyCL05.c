/*
=====================================================================

Name            : Doubly Circular Linked List - Display Function
Program Number  : 005

Description     : This program demonstrates traversal and
                  display of a Doubly Circular Linked List
                  using a do-while loop.

                  InsertFirst() and InsertLast() are used
                  to create the linked list and Display()
                  traverses all nodes exactly once.

Concepts Used   : Doubly Circular Linked List,
                  Display Function,
                  Traversal,
                  do-while Loop,
                  Dynamic Memory Allocation

Input           : Node data

Output          : Displays all nodes of the linked list

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
*/

// Doubly Circular Linked list

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


    printf("<=>");
    do
    {
        printf("| %d | <=> ",first -> data);
        first = first -> next;
    }while(first != last -> next);
    printf("\n");
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
        (*first )-> prev = newn;
        *first = newn;
    }
    (*last) -> next = *first;
    (*first) -> prev = *last;
}

void InsertLast(PPNODE first, PPNODE last,int iNo)
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
        (*last) -> next = newn;
        newn -> prev = *last;
        *last = newn;
    }
    (*last) -> next = *first;
    (*first) -> prev = *last;
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

    Display(head,tail);

    return 0;
}

/*
=====================================================================

Sample Output :

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>

=====================================================================

Functions Implemented :

1. Display()
2. InsertFirst()
3. InsertLast()

Pending Functions :

1. Count()
2. InsertAtPos()
3. DeleteFirst()
4. DeleteLast()
5. DeleteAtPos()

=====================================================================

Notes :

1. Display uses a do-while loop.
2. Traversal starts from first node.
3. Traversal stops when first node is reached again.
4. Empty linked list is handled separately.
5. Circular structure is preserved throughout traversal.

=====================================================================
End of Program
=====================================================================
*/
