/*
=====================================================================

Name            : Doubly Linked List - InsertFirst Operation
Program Number  : 010
Description     : This program demonstrates insertion of nodes at
                  the beginning of a Doubly Linked List.

                  A new node is dynamically allocated and inserted
                  before the existing first node. The next and prev
                  links are updated appropriately to maintain the
                  doubly linked structure.

Concepts Used   : Doubly Linked List, Dynamic Memory Allocation,
                  InsertFirst Operation, Self-Referential Structure,
                  Pointer to Pointer, Memory Management

Input           : Integer values to be inserted

Output          : Nodes inserted successfully at the beginning
                  of the Doubly Linked List

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
*/

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

void Display(PNODE first)
{

}

int Count(PNODE first)
{
    return 0;
}

void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(NULL == *first)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;
    }
}

void InsertLast(PPNODE first, int iNo)
{

}

void InsertAtPos(PPNODE first, int iNo, int iPos)
{

}

void DeleteFirst(PPNODE first)
{

}

void DeleteLast(PPNODE first)
{

}

void DeleteAtPos(PPNODE first, int iPos)
{

}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    return 0;
}

/*
=====================================================================

Insertion Sequence :

InsertFirst(&head,51);
InsertFirst(&head,21);
InsertFirst(&head,11);

Final Linked List :

NULL <- |11| <=> |21| <=> |51| -> NULL

=====================================================================

Note :

- New node is always inserted at the beginning.
- next pointer points to the old first node.
- prev pointer of old first node is updated.
- Head pointer is shifted to the new node.
- Time Complexity : O(1)

=====================================================================
*/
